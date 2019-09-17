/*
#############################################################################################
# Borderlands2 (1.0.228.55487) SDK
# Generated with KK UE3 SDK Generator v1.7.3.0 Fix by:KK QQ:2217936322
# ========================================================================================= #
# File: XAudio2_classes.h
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

// Class XAudio2.XAudio2Device
// 0x009C (0x0360 - 0x02C4)
class UXAudio2Device : public UAudioDevice
{
public:
	unsigned char                                      UnknownData00[ 0x9C ];                            		// 0x02C4 (0x009C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if ( ! pClassPointer )
			pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 3524 ];

		return pClassPointer;
	};

};

UClass* UXAudio2Device::pClassPointer = NULL;


#ifdef _MSC_VER
	#pragma pack ( pop )
#endif