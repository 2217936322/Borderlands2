#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <Windows.h>
#include <stdio.h>
#include <iostream> 
#include <fstream> 
#include <vector>
#include "MinHook/MinHook.h"
#include <time.h>
#include <math.h>

#include "SdkHeaders.h"

using namespace std;

HWND g_window = NULL;

#define MakeColor(R, G, B) { B, G, R, 255 }
#define MapColorValueA(health, inMax) (unsigned char)(255 - (((((health - inMax) * 100) / inMax) * 255) / 100))
#define MapColorValueB(health, inMax) (unsigned char)((((health * 100) / inMax) * 255) / 100)

FColor Black MakeColor(0, 0, 0);
FColor White MakeColor(255, 255, 255);
FColor Red MakeColor(255, 0, 0);
FColor Green MakeColor(0, 255, 0);
FColor Blue MakeColor(0, 0, 255);
FColor Orange MakeColor(255, 128, 0);
FColor Yellow MakeColor(255, 255, 0);
FColor Cyan MakeColor(0, 255, 255);

//FPS
INT Fps = 0;
FLOAT LastTickCount = 0.0f;
FLOAT CurrentTickCount;
wchar_t FrameRate[50];


AGearboxPlayerController* pPC = nullptr;
APawn* MyPawn = nullptr;

FVector W2SLoc;
FVector MyCameraLocation;
FRotator MyCameraRotation;




void Log(const char *fmt, ...)
{
	if (!fmt)	return;

	char		text[4096];
	va_list		ap;
	va_start(ap, fmt);
	vsprintf_s(text, fmt, ap);
	va_end(ap);

	ofstream logfile("C:\\Borderlands2.txt", ios::app);
	if (logfile.is_open() && text)	logfile << text << endl;
	logfile.close();
}
float inline StrLen(UCanvas* pCanvas, FString InputString)
{
	float X, Y;
	pCanvas->StrLen(InputString, &X, &Y);
	return X;
}
float inline StrHeight(UCanvas* pCanvas, FString InputString)
{
	float X, Y;
	pCanvas->StrLen(InputString, &X, &Y);
	return Y;
}
FVector inline WorldToScreen(UCanvas* pCanvas, FVector Location)
{
	//if (!pPC->Pawn->Weapon) return { 0,0,0 };
	FVector Vector, AxisX, AxisY, AxisZ, Delta, Transformed;

	pCanvas->GetAxes(MyCameraRotation, &AxisX, &AxisY, &AxisZ);

	Delta = pPC->Subtract_VectorVector(Location, MyCameraLocation);
	Transformed.X = pPC->Dot_VectorVector(Delta, AxisY);
	Transformed.Y = pPC->Dot_VectorVector(Delta, AxisZ);
	Transformed.Z = pPC->Dot_VectorVector(Delta, AxisX);

	if (Transformed.Z < 1.00f)
		Transformed.Z = 1.00f;

	//float FOVAngle = pPC->GetALocalPlayerController()->FOVAngle;
	float FOVAngle = pPC->eventGetFOVAngle();
	FOVAngle = FOVAngle + ((FOVAngle * 16.0f) / 61.8f);

	Vector.X = (pCanvas->ClipX / 2.0f) + Transformed.X * ((pCanvas->ClipX / 2.0f) / pPC->Tan(FOVAngle * CONST_Pi / 360.0f)) / Transformed.Z;
	Vector.Y = (pCanvas->ClipY / 2.0f) + -Transformed.Y * ((pCanvas->ClipX / 2.0f) / pPC->Tan(FOVAngle * CONST_Pi / 360.0f)) / Transformed.Z;
	return Vector;
}
void inline Draw2DBoundingBox(UCanvas* canvas, APawn* Target, FColor color)
{
	if (!Target->IsAliveAndWell()) return;

	FBox Box;
	Target->GetComponentsBoundingBox(&Box);

	FVector BoxMax = WorldToScreen(canvas, Box.Max);
	FVector BoxMin = WorldToScreen(canvas, Box.Min);
	FVector BoxCenter = WorldToScreen(canvas, Target->GetPawnViewLocation());

	float Width = fabs((BoxMax.Y - BoxMin.Y) / 4);

	canvas->Draw2DLine(BoxCenter.X - Width, BoxMin.Y, BoxCenter.X + Width, BoxMin.Y, color); // низ
	canvas->Draw2DLine(BoxCenter.X - Width, BoxMax.Y, BoxCenter.X + Width, BoxMax.Y, color); // верх
	canvas->Draw2DLine(BoxCenter.X - Width, BoxMin.Y, BoxCenter.X - Width, BoxMax.Y, color); // лево
	canvas->Draw2DLine(BoxCenter.X + Width, BoxMax.Y, BoxCenter.X + Width, BoxMin.Y, color); // право
}


void inline DrawRect(UCanvas* pCanvas, float X, float Y, float Width, float Height, UTexture2D* Texture, FColor pColor)
{
	float OldCurX = pCanvas->CurX;
	float OldCurY = pCanvas->CurY;

	FColor OldColor = pCanvas->DrawColor;

	pCanvas->CurX = X;
	pCanvas->CurY = Y;
	pCanvas->DrawColor = pColor;

	pCanvas->DrawRect(Width, Height, Texture);

	pCanvas->CurX = OldCurX;
	pCanvas->CurY = OldCurY;

	pCanvas->DrawColor = OldColor;
}
void inline DrawCrosshair(UCanvas* pCanvas, FColor pColor , int w)
{
	//DrawRect(pCanvas, pCanvas->ClipX / 2 - 10, pCanvas->ClipY / 2 - 0.5f, 20, 2, pCanvas->DefaultTexture, pColor);
	//DrawRect(pCanvas, pCanvas->ClipX / 2 - 0.5f, pCanvas->ClipY / 2 - 10, 2, 20, pCanvas->DefaultTexture, pColor);
	pCanvas->Draw2DLine((pCanvas->ClipX / 2) - w, pCanvas->ClipY / 2 + 1, (pCanvas->ClipX / 2) + w + 1, pCanvas->ClipY / 2 + 1, pColor);
	pCanvas->Draw2DLine(pCanvas->ClipX / 2 + 1, (pCanvas->ClipY / 2) - w, pCanvas->ClipX / 2 + 1, (pCanvas->ClipY / 2) + w + 1, pColor);
}
void inline DrawBorderText(UCanvas* canvas, FString Text, float CoordX, float CoordY, FColor Color)
{
	//BLACK BORDER
	{
		canvas->SetPos(CoordX + 1, CoordY + 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX - 1, CoordY + 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX + 1, CoordY - 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX - 1, CoordY - 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX - 1, CoordY, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX + 1, CoordY, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX, CoordY - 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);

		canvas->SetPos(CoordX, CoordY + 1, 0);
		canvas->SetDrawColor(0, 0, 0, 255);
		canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);
	}

	canvas->SetPos(CoordX, CoordY, 0);
	canvas->DrawColor = Color;
	canvas->DrawText(Text, false, 1.0f, 1.0f, NULL);
}
void inline FPS(UCanvas* canvas)
{
	CurrentTickCount = clock() * 0.001f;
	Fps++;
	if ((CurrentTickCount - LastTickCount) > 1.0f)
	{
		LastTickCount = CurrentTickCount;
		swprintf(FrameRate, 50, L"[ FPS: %d ]", Fps);
		Fps = 0;
	}
	DrawBorderText(canvas, FrameRate, canvas->ClipX - 5 - (StrLen(canvas, FrameRate)), 2.5f, White);
}
void PostRender(UCanvas* canvas) {
	if (!canvas) return;
	DrawBorderText(canvas, L"ImKK  QQ:2217936322", 11, 11, Red);
	FPS(canvas);
	DrawCrosshair(canvas, Green, 10);
	if (!pPC || (!(MyPawn = pPC->Pawn))) return;
	//pPC->PlayerCamera->GetCameraViewPoint(&MyCameraLocation, &MyCameraRotation);
	MyCameraRotation = MyPawn->GetViewRotation();
	MyCameraLocation = MyPawn->GetPawnViewLocation();
	//printf("Rotation: X %i  Y %i    %i  %i\n", MyCameraRotation.Pitch, MyCameraRotation.Yaw, MyPawn->Rotation.Pitch, MyPawn->Rotation.Yaw);
	//printf("Location: X %f  Y %f  Z %f\n", MyCameraLocation.X, MyCameraLocation.Y, MyCameraLocation.Z);
	if (pPC->WorldInfo && pPC->WorldInfo->PawnList)
	{
		AWillowPawn* PlayerPawn = (AWillowPawn*)pPC->WorldInfo->PawnList;
		while (PlayerPawn)
		{
			if (PlayerPawn->bDeleteMe && PlayerPawn->bPlayedDeath) return;
			//printf("GetTeamNum %i  eventScriptGetTeamNum %i  IsSameTeam %i\n", PlayerPawn->GetTeamNum(), PlayerPawn->eventScriptGetTeamNum(), MyPawn->eventIsSameTeam(PlayerPawn));
			if (PlayerPawn == MyPawn) // 自身的
			{
				//printf("eventGetFOVAngle %f  FOVAngle %f  xxxxxx %f\n", pPC->eventGetFOVAngle(), pPC->FOVAngle, pPC->GetALocalPlayerController()->FOVAngle);
				//if (((AWillowWeapon*)MyPawn->Weapon)->AmmoPool.Data)
				//{
				//	((AWillowWeapon*)MyPawn->Weapon)->AmmoPool.Data->MaxValue = 1000.0f;
				//	((AWillowWeapon*)MyPawn->Weapon)->AmmoPool.Data->CurrentValue = 1000.0f;
				//}
				((AWillowWeapon*)MyPawn->Weapon)->ClipSize = 100;
				((AWillowWeapon*)MyPawn->Weapon)->Spread = 0.0f;
				((AWillowWeapon*)MyPawn->Weapon)->SpreadBaseValue = 0.0f;
				((AWillowWeapon*)MyPawn->Weapon)->AddAmmo(30);
			}
			else
			{
				W2SLoc = WorldToScreen(canvas, PlayerPawn->GetPawnViewLocation());//PlayerPawn->Location);				
				if (!MyPawn->eventIsSameTeam(PlayerPawn)) // 敌人的
				{
					//2D方框
					Draw2DBoundingBox(canvas, PlayerPawn, Green);
				}
				else // 队友的
				{
				}
			}
			PlayerPawn = (AWillowPawn*)PlayerPawn->NextPawn;
		}
	}
}
void __fastcall MyProcessEvent(class UObject *pObject, void* edx /*别瞎几把改,也别瞎几把调用!!*/, UFunction *pFunction, void* pParams, void* pResult)
{
	string v_pFunction{ pFunction->GetFullName() };
	//Log("%s", v_pFunction.c_str());
	//std::cout << v_pFunction.c_str() << std::endl;

	if (v_pFunction.find("Function WillowGame.WillowGameViewportClient.PostRender") != string::npos)
	{
		if (pParams) PostRender(((UGameViewportClient_eventPostRender_Parms*)(pParams))->Canvas);
	}
	if (v_pFunction.find("Function WillowGame.WillowPlayerController.PlayerTick") != string::npos)
	{
		if (pObject) pPC = ((AGearboxPlayerController*)(pObject));
	}
	if (v_pFunction.find("Function WillowGame.WillowMind.Destroyed") != string::npos)
	{
		if (pObject == pPC) 
		{
			std::cout << "WillowMind" << std::endl;
			pPC = nullptr;
		}
	}
	//if (v_pFunction.find("Function Engine.InventoryManager.Destroyed") != string::npos)
	//{
	//	if (pObject == pPC)
	//	{
	//		std::cout << "InventoryManager" << std::endl;
	//		pPC = nullptr;
	//	}
	//}
	//if (v_pFunction.find("Function Engine.ResourcePoolManager.Destroyed") != string::npos)
	//{
	//	if (pObject == pPC)
	//	{
	//		std::cout << "ResourcePoolManager" << std::endl;
	//		pPC = nullptr;
	//	}
	//}
	//if (v_pFunction.find("Function Engine.Actor.Destroyed") != string::npos)
	//{
	//	if (pObject == pPC)
	//	{
	//		std::cout << "Actor" << std::endl;
	//		pPC = nullptr;
	//	}
	//}
	ProcessEvent(pObject, pFunction, pParams, pResult);
}
DWORD WINAPI OnAttach(LPVOID lpParam) {

	Beep(1000, 500);

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	std::cout << "啵一个紫血!!!" << std::endl;
	//do {
	//	std::cout << "等待游戏窗口创建!" << std::endl;
	//	g_window = FindWindow(L"LaunchUnrealUWindowsClient", L"Borderlands 2 (32-bit, DX9)");
	//	if (!g_window)
	//	{
	//		Sleep(500);
	//	}
	//} while (!g_window);
	//std::cout << "游戏窗口创建完毕!!" << std::endl;

	if (MH_Initialize() != MH_OK) printf("MH_Initialize failed\n");
	if (MH_CreateHook((PVOID)ProcessEvent, MyProcessEvent, reinterpret_cast<void**>(&ProcessEvent)) != MH_OK) printf("ProcessEvent hook failed\n");
	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) { printf("MH_EnableHook failed\n"); return 1; }

	return 0;
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		//std::wstring v_exe_full_path{ GetCommandLineW() };
		//if (v_exe_full_path.find(L"Borderlands2.exe") != std::wstring::npos)
		//{
			CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OnAttach, NULL, 0, NULL));
		//}
	}
	if (dwReason == DLL_PROCESS_DETACH)
	{
		MH_DisableHook((PVOID)ProcessEvent);
		MH_Uninitialize();
	}
	return TRUE;
}
