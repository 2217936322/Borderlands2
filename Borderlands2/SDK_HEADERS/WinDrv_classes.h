/*
#############################################################################################
# Borderlands2 (1.0.228.55487) SDK
# Generated with KK UE3 SDK Generator v1.7.3.0 Fix by:KK QQ:2217936322
# ========================================================================================= #
# File: WinDrv_classes.h
#############################################################################################
*/

#ifdef _MSC_VER
	#pragma pack ( push, 0x4 )
#endif

/*
# ========================================================================================= #
# Constants
# ========================================================================================= #
*/


/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class WinDrv.WindowsClient
// 0x01A0 (0x01F0 - 0x0050)
class UWindowsClient : public UClient
{
public:
	unsigned char                                      UnknownData00[ 0x15C ];                           		// 0x0050 (0x015C) MISSED OFFSET
	class UClass*                                      AudioDeviceClass;                                 		// 0x01AC (0x0004) [0x0000000000004000]              ( CPF_Config )
	unsigned char                                      UnknownData01[ 0x30 ];                            		// 0x01B0 (0x0030) MISSED OFFSET
	int                                                AllowJoystickInput;                               		// 0x01E0 (0x0004) [0x0000000000004000]              ( CPF_Config )
	unsigned char                                      UnknownData02[ 0xC ];                             		// 0x01E4 (0x000C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if ( ! pClassPointer )
			pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 3568 ];

		return pClassPointer;
	};

};

UClass* UWindowsClient::pClassPointer = NULL;

// Class WinDrv.XnaForceFeedbackManager
// 0x0000 (0x0058 - 0x0058)
class UXnaForceFeedbackManager : public UForceFeedbackManager
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if ( ! pClassPointer )
			pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 3572 ];

		return pClassPointer;
	};

};

UClass* UXnaForceFeedbackManager::pClassPointer = NULL;

// Class WinDrv.FacebookWindows
// 0x0038 (0x00EC - 0x00B4)
class UFacebookWindows : public UFacebookIntegration
{
public:
	unsigned char                                      UnknownData00[ 0x38 ];                            		// 0x00B4 (0x0038) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if ( ! pClassPointer )
			pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 3574 ];

		return pClassPointer;
	};

};

UClass* UFacebookWindows::pClassPointer = NULL;


#ifdef _MSC_VER
	#pragma pack ( pop )
#endif