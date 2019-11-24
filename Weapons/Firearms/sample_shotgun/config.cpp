class CfgPatches
{
	class candygun
	{
		units[]=
		{
			"candygun"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Sounds_Weapons",
			"DZ_Weapons"
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoShotgun;
class cfgWeapons
{
	class Shotgun_Base;
	class Mp133Shotgun_Base: Shotgun_Base
	{
		
	};
	class Candygun: Mp133Shotgun_Base
	{
		scope=2;
		displayName="Candygun";
		descriptionShort="Yohohoh";
		model="sample_shotgun\candygun.p3d";
		animName="ShotgunMp133";
		lootTag[]=
		{
			"Civilian"
		};
		attachments[]=
		{
			"pistolOptics"
		};
		itemSize[]={9,3};
		weight=3300;
		hiddenSelectionsTextures[]=
		{
			"sample_shotgun\data\candygun_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"sample_shotgun\data\candygun.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					
				};
			};
		};
	};
};
