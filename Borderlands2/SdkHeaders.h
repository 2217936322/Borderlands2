/*
#############################################################################################
# Borderlands2 (1.0.228.55487) SDK
# Generated with KK UE3 SDK Generator v1.7.3.0 Fix by:KK QQ:2217936322
# ========================================================================================= #
# File: SdkHeaders.h
#############################################################################################
*/

/*
# ========================================================================================= #
# Defines
# ========================================================================================= #
*/


int BaseModule = (int)::GetModuleHandle(NULL);

#define GObjects			(BaseModule + 0x16225E0);
#define GNames				(BaseModule + 0x15E0204);
#define GProcessEvent		(BaseModule + 0x1909E0);

typedef void(__thiscall *tProcessEvent)(class UObject *, class UFunction *, void *, void *);
tProcessEvent ProcessEvent = (tProcessEvent)GProcessEvent;

/*
# ========================================================================================= #
# Structs
# ========================================================================================= #
*/

template< class T > struct TArray 
{ 
public: 
	T* Data; 
	int Count; 
	int Max; 

public: 
	TArray() 
	{ 
		Data = NULL; 
		Count = Max = 0; 
	}; 

public: 
	int Num() 
	{ 
		return this->Count; 
	}; 

	T& operator() ( int i ) 
	{ 
		return this->Data[ i ]; 
	}; 

	const T& operator() ( int i ) const 
	{ 
		return this->Data[ i ]; 
	}; 

	void Add ( T InputData ) 
	{ 
		Data = (T*) realloc ( Data, sizeof ( T ) * ( Count + 1 ) ); 
		Data[ Count++ ] = InputData; 
		Max = Count; 
	}; 

	void Clear() 
	{ 
		free ( Data ); 
		Count = Max = 0; 
	}; 

	inline T GetIndex(int i) const 
	{ 
		T Addr = (T)((unsigned long)Data[i] ^ i); 
		return Addr; 
	} 
}; 

struct FNameEntry 
{ 
	unsigned char	UnknownData[ 16 ]; 
	char			Name[ 1 ]; 
}; 

struct FName 
{ 
	int				Index; 
	unsigned char	unknownData[ 0x4 ]; 

	FName() : Index ( 0 ) {}; 

	FName ( int i ) : Index ( i ) {}; 

	~FName() {}; 

	FName ( char* FindName ) 
	{ 
		static TArray< int > NameCache; 

		for ( int i = 0; i < NameCache.Count; ++i ) 
		{ 
		if ( ! strcmp ( this->Names()->Data[ NameCache ( i ) ]->Name, FindName ) ) 
			{ 
				Index = NameCache ( i ); 
				return; 
			} 
		} 

		for ( int i = 0; i < this->Names()->Count; ++i ) 
		{ 
			if ( this->Names()->Data[ i ] ) 
			{ 
				if ( ! strcmp ( this->Names()->Data[ i ]->Name, FindName ) ) 
				{ 
					NameCache.Add ( i ); 
					Index = i; 
				} 
			} 
		} 
	}; 

	static TArray< FNameEntry* >* Names() 
	{ 
		return (TArray< FNameEntry* >*) GNames; 
	}; 

	char* GetName() 
	{ 
		return this->Names()->Data[ Index ]->Name; 
	}; 

	bool operator == ( const FName& A ) const 
	{ 
		return ( Index == A.Index ); 
	}; 
}; 

struct FString : public TArray< wchar_t > 
{ 
	FString() {}; 
	~FString() {}; 

	FString ( wchar_t* Other ) 
	{ 
		this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

		if ( this->Count ) 
			this->Data = Other; 
	}; 

	FString(const wchar_t* Other) 
	{ 
		this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 
		if (this->Count) 
		{ 
			this->Data = const_cast<wchar_t*>(Other); 
		} 
	}; 

	FString operator = ( wchar_t* Other ) 
	{ 
		if ( this->Data != Other ) 
		{ 
			this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

			if ( this->Count ) 
				this->Data = Other; 
		} 

		return *this; 
	}; 

	inline bool IsValid() const 
	{ 
		return Data != nullptr; 
	} 

	inline const wchar_t* c_str() const 
	{ 
		return Data; 
	} 
}; 

struct FScriptDelegate 
{ 
	unsigned char UnknownData[ 0xC ]; 
}; 

/*
# ========================================================================================= #
# Includes
# ========================================================================================= #
*/

#include "SDK_HEADERS\Core_structs.h"
#include "SDK_HEADERS\Core_classes.h"
#include "SDK_HEADERS\Core_f_structs.h"
#include "SDK_HEADERS\Core_functions.h"
#include "SDK_HEADERS\Engine_structs.h"
#include "SDK_HEADERS\Engine_classes.h"
#include "SDK_HEADERS\Engine_f_structs.h"
#include "SDK_HEADERS\Engine_functions.h"
#include "SDK_HEADERS\GameFramework_structs.h"
#include "SDK_HEADERS\GameFramework_classes.h"
#include "SDK_HEADERS\GameFramework_f_structs.h"
#include "SDK_HEADERS\GameFramework_functions.h"
#include "SDK_HEADERS\GFxUI_structs.h"
#include "SDK_HEADERS\GFxUI_classes.h"
#include "SDK_HEADERS\GFxUI_f_structs.h"
#include "SDK_HEADERS\GFxUI_functions.h"
#include "SDK_HEADERS\GearboxFramework_structs.h"
#include "SDK_HEADERS\GearboxFramework_classes.h"
#include "SDK_HEADERS\GearboxFramework_f_structs.h"
#include "SDK_HEADERS\GearboxFramework_functions.h"
#include "SDK_HEADERS\IpDrv_structs.h"
#include "SDK_HEADERS\IpDrv_classes.h"
#include "SDK_HEADERS\IpDrv_f_structs.h"
#include "SDK_HEADERS\IpDrv_functions.h"
#include "SDK_HEADERS\XAudio2_structs.h"
#include "SDK_HEADERS\XAudio2_classes.h"
#include "SDK_HEADERS\XAudio2_f_structs.h"
#include "SDK_HEADERS\XAudio2_functions.h"
#include "SDK_HEADERS\AkAudio_structs.h"
#include "SDK_HEADERS\AkAudio_classes.h"
#include "SDK_HEADERS\AkAudio_f_structs.h"
#include "SDK_HEADERS\AkAudio_functions.h"
#include "SDK_HEADERS\WinDrv_structs.h"
#include "SDK_HEADERS\WinDrv_classes.h"
#include "SDK_HEADERS\WinDrv_f_structs.h"
#include "SDK_HEADERS\WinDrv_functions.h"
#include "SDK_HEADERS\OnlineSubsystemSteamworks_structs.h"
#include "SDK_HEADERS\OnlineSubsystemSteamworks_classes.h"
#include "SDK_HEADERS\OnlineSubsystemSteamworks_f_structs.h"
#include "SDK_HEADERS\OnlineSubsystemSteamworks_functions.h"
#include "SDK_HEADERS\WillowGame_structs.h"
#include "SDK_HEADERS\WillowGame_classes.h"
#include "SDK_HEADERS\WillowGame_f_structs.h"
#include "SDK_HEADERS\WillowGame_functions.h"
