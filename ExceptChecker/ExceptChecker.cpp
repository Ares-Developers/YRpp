//EXCEPTCHECKER
//=============
//This baby prints a readable except.txt file!

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif
#pragma warning(disable: 4035)	//"no return value" - there is one, just not in our code ;)

#include <stdio.h>
#include <YRPP.h>
#include "../Drawing.cpp"
#include "../Debugger.cpp"

//Hook at 0x49F5C0
EXPORT _CPY_IsLauncherRunning(REGISTERS* R)
{
	R->set_AL(1);
	return 0x49F61A;
}

//Hook at 0x49F620
EXPORT _CPY_NotifyLauncher(REGISTERS* R)
{
	R->set_AL(1);
	return 0x49F733;
}

//Hook at 0x49F7A0
EXPORT _CPY_CheckProtectedData(REGISTERS* R)
{
	R->set_AL(1);
	return 0x49F8A7;
}

//Hook at 0x531413
EXPORT _EXCEPT_Notify(REGISTERS* R)
{
	Drawing::UseSurface_Hidden();
	Drawing::PrintText(L"ExceptChecker active.",10,540,COLOR_GREEN);
	return 0;
}

//Hook at 0x4C90FC
EXPORT _EXCEPT_DisableIEWindow(REGISTERS* R)
{
	return 0x4C9135;
}

//Hook at 0x4C8B79
EXPORT _EXCEPT_Check(REGISTERS* R)
{
	char* pExcept=(char*)0x8A3A08;
	int nExceptLen=R->get_EDI();
	DWORD* pContext=(DWORD*)R->get_EBP();

	DWORD dwESP=pContext[0xC4 >> 2];
	DWORD dwEIP=pContext[0xB8 >> 2];
	DWORD dwEBP=pContext[0xB4 >> 2];
	DWORD dwEAX=pContext[0xB0 >> 2];
	DWORD dwECX=pContext[0xAC >> 2];
	DWORD dwEDX=pContext[0xA8 >> 2];
	DWORD dwEBX=pContext[0xA4 >> 2];
	DWORD dwESI=pContext[0xA0 >> 2];
	DWORD dwEDI=pContext[0x9C >> 2];
	
	char desc[0x80]="\0";

	//Declarations (required since I'm using a switch statement)
	AnimClass* pAnim=NULL;
	AnimTypeClass* pAnimType=NULL;
	WeaponTypeClass* pWeaponType=NULL;

	switch(dwEIP)
	{
	case 0x4242DB:	//Zero TrailerSeperation on AnimType
		pAnim=(AnimClass*)dwESI;
		if(pAnim)
		{
			pAnimType=pAnim->get_Type();
			if(pAnimType)
				sprintf(desc,
					"AnimType [%s] uses a TrailerAnim, but the TrailerSeperation is zero!",
					pAnimType->get_ID());
		}
		break;

	case 0x424A14:	//MakeInfantry error
		pAnim=(AnimClass*)dwESI;
		if(pAnim)
		{
			pAnimType=pAnim->get_Type();
			if(pAnimType)
				sprintf(desc,
					"AnimType [%s] has an invalid MakeInfantry value!",
					pAnimType->get_ID());
		}
		break;

	case 0x42E7AF:	//AIBuildThis=no on a ConYard
		strcpy(desc,"An AI tried to build a ConYard, but it did not find any with AIBuildThis=yes!");
		//TO DO: more info on the AI (side, country)
		break;
	
	case 0x441C28: //ShakeScreen=0
		strcpy(desc,"ShakeScreen is set to zero!");
		break;

	case 0x4D5108:	//Missing warhead on Secondary
		pWeaponType=(WeaponTypeClass*)dwECX;
		if(pWeaponType)
			sprintf(desc,
				"The Warhead of WeaponType [%s] is missing, or the WeaponType was not defined!",
				pWeaponType->get_ID());
		break;

	//AITargeting values
	case 0x50CD20:
		strcpy(desc,"AIIonCannonEngineerValue is invalid!");break;
	case 0x50CD44:
		strcpy(desc,"AIIonCannonThiefValue is invalid!");break;
	case 0x50CD79:
		strcpy(desc,"AIIonCannonConYardValue is invalid!");break;
	case 0x50CDA2:
		strcpy(desc,"AIIonCannonWarFactoryValue is invalid!");break;
	case 0x50CDCC:
		strcpy(desc,"AIIonCannonPowerValue is invalid!");break;
	case 0x50CDF0:
		strcpy(desc,"AIIonCannonBaseDefenseValue is invalid!");break;
	case 0x50CE14:
		strcpy(desc,"AIIonCannonPlugValue is invalid!");break;
	case 0x50CE38:
		strcpy(desc,"AIIonCannonTempleValue is invalid!");break;
	case 0x50CE5C:
		strcpy(desc,"AIIonCannonHelipadValue is invalid!");break;
	case 0x50CEA2:
		strcpy(desc,"AIIonCannonTechCenterValue is invalid!");break;
	case 0x50CECC:
		strcpy(desc,"AIIonCannonHarvesterValue is invalid!");break;
	case 0x50CF15:
		strcpy(desc,"AIIonCannonAPCValue is invalid!");break;
	case 0x50CF2A:
		strcpy(desc,"AIIonCannonMCVValue is invalid!");break;

	case 0x6F40A2:	//Missing warhead on Primary
		pWeaponType=(WeaponTypeClass*)dwECX;
		if(pWeaponType)
			sprintf(desc,
				"The Warhead of WeaponType [%s] is missing, or the WeaponType was not defined!",
				pWeaponType->get_ID());
		break;

	case 0x73C762:
		/*Missing SHP on a unit
		Need UnitClass definition for this!*/
		break;

	default:	//Unknown
		break;
	}
	
	if(*desc!=0)
		MessageBoxA(NULL,desc,"Yuri's Revenge - Internal Error - ExceptChecker",MB_OK|MB_ICONERROR);
	else
		MessageBoxA(NULL,
		"No error description could be found.","Yuri's Revenge - Internal Error - ExceptChecker",MB_OK|MB_ICONERROR);

	return 0;
}

