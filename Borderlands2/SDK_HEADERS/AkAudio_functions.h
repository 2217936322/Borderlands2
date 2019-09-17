/*
#############################################################################################
# Borderlands2 (1.0.228.55487) SDK
# Generated with KK UE3 SDK Generator v1.7.3.0 Fix by:KK QQ:2217936322
# ========================================================================================= #
# File: AkAudio_functions.h
#############################################################################################
*/

#ifdef _MSC_VER
	#pragma pack ( push, 0x4 )
#endif

/*
# ========================================================================================= #
# Functions
# ========================================================================================= #
*/

// Function AkAudio.IAkEnvironmentalEffectProvider.GetEnvironmentalEffectsForLocation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// TArray< struct FEnvironmentalEffectInfo > ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// class UAkComponent*            GameObjComponent               ( CPF_Parm | CPF_EditInline )
// struct FVector                 ListenerLocation               ( CPF_Parm )
// struct FVector                 ObjectLocation                 ( CPF_Parm )

TArray< struct FEnvironmentalEffectInfo > UIAkEnvironmentalEffectProvider::GetEnvironmentalEffectsForLocation ( class UAkComponent* GameObjComponent, struct FVector ListenerLocation, struct FVector ObjectLocation )
{
	static UFunction* pFnGetEnvironmentalEffectsForLocation = NULL;

	if ( ! pFnGetEnvironmentalEffectsForLocation )
		pFnGetEnvironmentalEffectsForLocation = (UFunction*) UObject::GObjObjects()->Data[ 37492 ];

	UIAkEnvironmentalEffectProvider_execGetEnvironmentalEffectsForLocation_Parms GetEnvironmentalEffectsForLocation_Parms;
	GetEnvironmentalEffectsForLocation_Parms.GameObjComponent = GameObjComponent;
	memcpy ( &GetEnvironmentalEffectsForLocation_Parms.ListenerLocation, &ListenerLocation, 0xC );
	memcpy ( &GetEnvironmentalEffectsForLocation_Parms.ObjectLocation, &ObjectLocation, 0xC );

	pFnGetEnvironmentalEffectsForLocation->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnGetEnvironmentalEffectsForLocation, &GetEnvironmentalEffectsForLocation_Parms, NULL );

	pFnGetEnvironmentalEffectsForLocation->FunctionFlags |= 0x400;

	return GetEnvironmentalEffectsForLocation_Parms.ReturnValue;
};

// Function AkAudio.ISpecialOcclusionAccumulator.RemoveOcclusionProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )

void UISpecialOcclusionAccumulator::RemoveOcclusionProvider ( class AActor* Source )
{
	static UFunction* pFnRemoveOcclusionProvider = NULL;

	if ( ! pFnRemoveOcclusionProvider )
		pFnRemoveOcclusionProvider = (UFunction*) UObject::GObjObjects()->Data[ 37508 ];

	UISpecialOcclusionAccumulator_execRemoveOcclusionProvider_Parms RemoveOcclusionProvider_Parms;
	RemoveOcclusionProvider_Parms.Source = Source;

	pFnRemoveOcclusionProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnRemoveOcclusionProvider, &RemoveOcclusionProvider_Parms, NULL );

	pFnRemoveOcclusionProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.ISpecialOcclusionAccumulator.SetOcclusionForProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )
// float                          Amount                         ( CPF_Parm )

void UISpecialOcclusionAccumulator::SetOcclusionForProvider ( class AActor* Source, float Amount )
{
	static UFunction* pFnSetOcclusionForProvider = NULL;

	if ( ! pFnSetOcclusionForProvider )
		pFnSetOcclusionForProvider = (UFunction*) UObject::GObjObjects()->Data[ 37505 ];

	UISpecialOcclusionAccumulator_execSetOcclusionForProvider_Parms SetOcclusionForProvider_Parms;
	SetOcclusionForProvider_Parms.Source = Source;
	SetOcclusionForProvider_Parms.Amount = Amount;

	pFnSetOcclusionForProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnSetOcclusionForProvider, &SetOcclusionForProvider_Parms, NULL );

	pFnSetOcclusionForProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundGroup.RemoveOcclusionProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )

void AWwiseSoundGroup::RemoveOcclusionProvider ( class AActor* Source )
{
	static UFunction* pFnRemoveOcclusionProvider = NULL;

	if ( ! pFnRemoveOcclusionProvider )
		pFnRemoveOcclusionProvider = (UFunction*) UObject::GObjObjects()->Data[ 37537 ];

	AWwiseSoundGroup_execRemoveOcclusionProvider_Parms RemoveOcclusionProvider_Parms;
	RemoveOcclusionProvider_Parms.Source = Source;

	pFnRemoveOcclusionProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnRemoveOcclusionProvider, &RemoveOcclusionProvider_Parms, NULL );

	pFnRemoveOcclusionProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundGroup.SetOcclusionForProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )
// float                          Amount                         ( CPF_Parm )

void AWwiseSoundGroup::SetOcclusionForProvider ( class AActor* Source, float Amount )
{
	static UFunction* pFnSetOcclusionForProvider = NULL;

	if ( ! pFnSetOcclusionForProvider )
		pFnSetOcclusionForProvider = (UFunction*) UObject::GObjObjects()->Data[ 37534 ];

	AWwiseSoundGroup_execSetOcclusionForProvider_Parms SetOcclusionForProvider_Parms;
	SetOcclusionForProvider_Parms.Source = Source;
	SetOcclusionForProvider_Parms.Amount = Amount;

	pFnSetOcclusionForProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnSetOcclusionForProvider, &SetOcclusionForProvider_Parms, NULL );

	pFnSetOcclusionForProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundGroup.GetOcclusionAmount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AWwiseSoundGroup::GetOcclusionAmount ( )
{
	static UFunction* pFnGetOcclusionAmount = NULL;

	if ( ! pFnGetOcclusionAmount )
		pFnGetOcclusionAmount = (UFunction*) UObject::GObjObjects()->Data[ 37532 ];

	AWwiseSoundGroup_execGetOcclusionAmount_Parms GetOcclusionAmount_Parms;

	pFnGetOcclusionAmount->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnGetOcclusionAmount, &GetOcclusionAmount_Parms, NULL );

	pFnGetOcclusionAmount->FunctionFlags |= 0x400;

	return GetOcclusionAmount_Parms.ReturnValue;
};

// Function AkAudio.WwiseSoundGroup.SetAkSwitchObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class UAkSwitch*               Switch                         ( CPF_Parm )

void AWwiseSoundGroup::SetAkSwitchObject ( class UAkSwitch* Switch )
{
	static UFunction* pFnSetAkSwitchObject = NULL;

	if ( ! pFnSetAkSwitchObject )
		pFnSetAkSwitchObject = (UFunction*) UObject::GObjObjects()->Data[ 37530 ];

	AWwiseSoundGroup_execSetAkSwitchObject_Parms SetAkSwitchObject_Parms;
	SetAkSwitchObject_Parms.Switch = Switch;

	pFnSetAkSwitchObject->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnSetAkSwitchObject, &SetAkSwitchObject_Parms, NULL );

	pFnSetAkSwitchObject->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundGroup.SetRTPCObjectValue
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class UAkRtpc*                 InRtpc                         ( CPF_Parm )
// float                          TargetValue                    ( CPF_Parm )

void AWwiseSoundGroup::SetRTPCObjectValue ( class UAkRtpc* InRtpc, float TargetValue )
{
	static UFunction* pFnSetRTPCObjectValue = NULL;

	if ( ! pFnSetRTPCObjectValue )
		pFnSetRTPCObjectValue = (UFunction*) UObject::GObjObjects()->Data[ 37527 ];

	AWwiseSoundGroup_execSetRTPCObjectValue_Parms SetRTPCObjectValue_Parms;
	SetRTPCObjectValue_Parms.InRtpc = InRtpc;
	SetRTPCObjectValue_Parms.TargetValue = TargetValue;

	pFnSetRTPCObjectValue->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnSetRTPCObjectValue, &SetRTPCObjectValue_Parms, NULL );

	pFnSetRTPCObjectValue->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundVolume.RemoveOcclusionProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )

void AWwiseSoundVolume::RemoveOcclusionProvider ( class AActor* Source )
{
	static UFunction* pFnRemoveOcclusionProvider = NULL;

	if ( ! pFnRemoveOcclusionProvider )
		pFnRemoveOcclusionProvider = (UFunction*) UObject::GObjObjects()->Data[ 37617 ];

	AWwiseSoundVolume_execRemoveOcclusionProvider_Parms RemoveOcclusionProvider_Parms;
	RemoveOcclusionProvider_Parms.Source = Source;

	pFnRemoveOcclusionProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnRemoveOcclusionProvider, &RemoveOcclusionProvider_Parms, NULL );

	pFnRemoveOcclusionProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundVolume.SetOcclusionForProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  Source                         ( CPF_Parm )
// float                          Amount                         ( CPF_Parm )

void AWwiseSoundVolume::SetOcclusionForProvider ( class AActor* Source, float Amount )
{
	static UFunction* pFnSetOcclusionForProvider = NULL;

	if ( ! pFnSetOcclusionForProvider )
		pFnSetOcclusionForProvider = (UFunction*) UObject::GObjObjects()->Data[ 37614 ];

	AWwiseSoundVolume_execSetOcclusionForProvider_Parms SetOcclusionForProvider_Parms;
	SetOcclusionForProvider_Parms.Source = Source;
	SetOcclusionForProvider_Parms.Amount = Amount;

	pFnSetOcclusionForProvider->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnSetOcclusionForProvider, &SetOcclusionForProvider_Parms, NULL );

	pFnSetOcclusionForProvider->FunctionFlags |= 0x400;
};

// Function AkAudio.WwiseSoundVolume.GetOcclusionAmount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AWwiseSoundVolume::GetOcclusionAmount ( )
{
	static UFunction* pFnGetOcclusionAmount = NULL;

	if ( ! pFnGetOcclusionAmount )
		pFnGetOcclusionAmount = (UFunction*) UObject::GObjObjects()->Data[ 37612 ];

	AWwiseSoundVolume_execGetOcclusionAmount_Parms GetOcclusionAmount_Parms;

	pFnGetOcclusionAmount->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnGetOcclusionAmount, &GetOcclusionAmount_Parms, NULL );

	pFnGetOcclusionAmount->FunctionFlags |= 0x400;

	return GetOcclusionAmount_Parms.ReturnValue;
};

// Function AkAudio.WwiseSoundVolume.UpdateAkComponentPosition
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// TArray< struct FVector >       ListenerPositions              ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// TArray< struct FRotator >      ListenerOrientations           ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void AWwiseSoundVolume::UpdateAkComponentPosition ( TArray< struct FVector >* ListenerPositions, TArray< struct FRotator >* ListenerOrientations )
{
	static UFunction* pFnUpdateAkComponentPosition = NULL;

	if ( ! pFnUpdateAkComponentPosition )
		pFnUpdateAkComponentPosition = (UFunction*) UObject::GObjObjects()->Data[ 37607 ];

	AWwiseSoundVolume_execUpdateAkComponentPosition_Parms UpdateAkComponentPosition_Parms;

	pFnUpdateAkComponentPosition->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnUpdateAkComponentPosition, &UpdateAkComponentPosition_Parms, NULL );

	pFnUpdateAkComponentPosition->FunctionFlags |= 0x400;

	if ( ListenerPositions )
		memcpy ( ListenerPositions, &UpdateAkComponentPosition_Parms.ListenerPositions, 0xC );

	if ( ListenerOrientations )
		memcpy ( ListenerOrientations, &UpdateAkComponentPosition_Parms.ListenerOrientations, 0xC );
};

// Function AkAudio.WwiseSoundVolume.GetEnvironmentalEffectsForLocation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// TArray< struct FEnvironmentalEffectInfo > ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// class UAkComponent*            GameObjComponent               ( CPF_Parm | CPF_EditInline )
// struct FVector                 ListenerLocation               ( CPF_Parm )
// struct FVector                 ObjectLocation                 ( CPF_Parm )

TArray< struct FEnvironmentalEffectInfo > AWwiseSoundVolume::GetEnvironmentalEffectsForLocation ( class UAkComponent* GameObjComponent, struct FVector ListenerLocation, struct FVector ObjectLocation )
{
	static UFunction* pFnGetEnvironmentalEffectsForLocation = NULL;

	if ( ! pFnGetEnvironmentalEffectsForLocation )
		pFnGetEnvironmentalEffectsForLocation = (UFunction*) UObject::GObjObjects()->Data[ 37601 ];

	AWwiseSoundVolume_execGetEnvironmentalEffectsForLocation_Parms GetEnvironmentalEffectsForLocation_Parms;
	GetEnvironmentalEffectsForLocation_Parms.GameObjComponent = GameObjComponent;
	memcpy ( &GetEnvironmentalEffectsForLocation_Parms.ListenerLocation, &ListenerLocation, 0xC );
	memcpy ( &GetEnvironmentalEffectsForLocation_Parms.ObjectLocation, &ObjectLocation, 0xC );

	pFnGetEnvironmentalEffectsForLocation->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnGetEnvironmentalEffectsForLocation, &GetEnvironmentalEffectsForLocation_Parms, NULL );

	pFnGetEnvironmentalEffectsForLocation->FunctionFlags |= 0x400;

	return GetEnvironmentalEffectsForLocation_Parms.ReturnValue;
};

// Function AkAudio.WwiseSoundVolume.CalculateFacePlanes
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AWwiseSoundVolume::CalculateFacePlanes ( )
{
	static UFunction* pFnCalculateFacePlanes = NULL;

	if ( ! pFnCalculateFacePlanes )
		pFnCalculateFacePlanes = (UFunction*) UObject::GObjObjects()->Data[ 37600 ];

	AWwiseSoundVolume_execCalculateFacePlanes_Parms CalculateFacePlanes_Parms;

	pFnCalculateFacePlanes->FunctionFlags |= ~0x400;

	ProcessEvent ((UObject*)this, pFnCalculateFacePlanes, &CalculateFacePlanes_Parms, NULL );

	pFnCalculateFacePlanes->FunctionFlags |= 0x400;
};


#ifdef _MSC_VER
	#pragma pack ( pop )
#endif