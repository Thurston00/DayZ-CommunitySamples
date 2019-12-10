class CfgPatches
{
	class sample_helmet
	{
		units[]=
		{
			"sample_helmet"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Characters_Headgear",
			"DZ_Data"
		};
	};
	
};
class CfgMods
{
	class sample_helmet
	{
		dir="sample_helmet";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="sample_helmet";
		credits="Creep";
		author="Creep";
		authorID="0";
		version="1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"sample_helmet/scripts/4_World"
				};
			};
		};
	};
};
class CfgVehicles
{	
	class Clothing_Base;
   	class sample_helmet: Clothing_Base
	{	
		scope=2;
		displayName="Sample Helmet";
		descriptionShort="sample Helmet";
		model="\sample_helmet\helmet_g.p3d";
		repairableWithKits[]={5,8};
		repairCosts[]={30,25};
		rotationFlags=16;
		inventorySlot="Headgear";
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		weight=1000;
		itemSize[]={4,3};
		absorbency=0;
		heatIsolation=0.80;
		noMask=0;
		headSelectionsToHide[]=
		{
			"Clipping_Gasmask"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\sample_helmet\data\helmet_co.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] = 
                    {
                        {1.0,{"sample_helmet\data\Helmet.rvmat", "sample_helmet\data\Helmet.rvmat"}},
                        {0.7,{"sample_helmet\data\Helmet.rvmat", "sample_helmet\data\Helmet.rvmat"}},
                        {0.5,{"sample_helmet\data\Helmet_damage.rvmat", "sample_helmet\data\Helmet_damage.rvmat"}},
                        {0.3,{"sample_helmet\data\Helmet_damage.rvmat", "sample_helmet\data\Helmet_damage.rvmat"}},
                        {0.0,{"sample_helmet\data\Helmet_destruct.rvmat", "sample_helmet\data\Helmet_destruct.rvmat"}}};
                };
            };

			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.5;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.25;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.25;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.5;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\sample_helmet\helmet_m.p3d";
			female="\sample_helmet\helmet_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPot_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BallisticHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};