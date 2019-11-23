// ZeRoy's Destra 3000
// Thanks to Not_a_Banana for help!
// October 2019

class CfgPatches
{
	class zeroy_destra_3000
	{
		units[]={"zeroy_destra_3k"};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class FNX45;
	class zeroy_destra_3k: FNX45
	{
		scope=2;
		displayName="Destra 3000";
		descriptionShort="The Destra 3000 is a semi-automatic pistol based on the Astra 3000 (Spain Circa 1948). Chambered in .45 ACP Rounds for Dayz. Model by Sebastian Ujhazi Imported by Zeroy.";
		model="DayZ-CommunitySamples\Weapons\Firearms\Destra3000\zeroy_destra_3k.p3d";
		attachments[] = {"pistolMuzzle","pistolOptics","weaponOpticsCrossbow","pistolFlashlight"};
		magazines[]={"mag_zeroy_destra3k_9rnd"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\Destra_3000_co.paa"};
		hiddenSelectionsMaterials[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000.rvmat"}},
					{0.7,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000.rvmat"}},
					{0.5,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},
					{0.3,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},{0.0,
						{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_destruct.rvmat"}}};
				};
			};
		};
	};
    class zeroy_destra_3k_black: zeroy_destra_3k
    {
        scope = 2;
        displayName="Destra 3000 Black";
		hiddenSelectionsTextures[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\Destra_3000_black_co.paa"};
		hiddenSelectionsMaterials[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_black.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_black.rvmat"}},
					{0.7,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_black.rvmat"}},
					{0.5,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},
					{0.3,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},{0.0,
						{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_destruct.rvmat"}}};
				};
			};
		};
    };
    class zeroy_destra_3k_gold: zeroy_destra_3k
    {
        scope = 2;
        displayName="Golden Destra 3000";
		hiddenSelectionsTextures[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\Destra_3000_gold_co.paa"};
		hiddenSelectionsMaterials[] = {"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_gold.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_gold.rvmat"}},
					{0.7,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_gold.rvmat"}},
					{0.5,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},
					{0.3,{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_damage.rvmat"}},{0.0,
						{"DayZ-CommunitySamples\Weapons\Firearms\Destra3000\data\destra_3000_destruct.rvmat"}}};
				};
			};
		};
    };
};
class CfgMagazines
{
	class Mag_FNX45_15Rnd;
	class mag_zeroy_destra3k_9rnd: Mag_FNX45_15Rnd
	{
		scope=2;
		displayName="9rnd Destra 3000 Magazine";
		descriptionShort="9 rounds Magazine for the Destra 3000, loaded with .45 ACP rounds.";
		model="DayZ-CommunitySamples\Weapons\Firearms\Destra3000\mag_zeroy_destra3k_9rnd.p3d";
		weight=40;
		itemSize[]={1,2};
		count=9;
        ammoItems[]={"Ammo_45ACP"};
	};
};
class CfgNonAIVehicles
{

	class ProxyAttachment;
	class Proxy_mag_zeroy_destra3k_9rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model="DayZ-CommunitySamples\Weapons\Firearms\Destra3000\mag_zeroy_destra3k_9rnd.p3d";
	};
};