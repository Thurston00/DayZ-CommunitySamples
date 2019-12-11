class CfgPatches
{
	class CS_Weapons_Ammunition
    {
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
        requiredAddons[] = {"DZ_Data","DZ_Weapons_Ammunition","DZ_Weapons_Projectiles","DZ_Weapons_Magazines"};
	};
};
class cfgAmmoTypes
{
	class Atype_Bullet_TestBullet
	{
		name = "Bullet_TestBullet";
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class Bullet_TestBullet: Bullet_Base
	{
		scope=2;
		lootCategory="Crafted";
		cartridge="FxCartridge_9mm";
		spawnPileType="Ammo_TestBullet";
		hit=9;
		indirectHit=0;
		indirectHitRange=0;
		tracerScale=1;
		caliber=1.2; // change this for more pentraion or less does multiply class Health, hit= 
		deflecting=30;
		airFriction=-0.00059900002;
		typicalSpeed=440;
		initSpeed=440;
		weight=0.0080000004;
		class DamageApplied
		{
			type="Projectile";
			dispersion=0;
			bleedThreshold=1;
			defaultDamageOverride[]=
			{
				{0.5,1}
			};
			class Health
			{
				damage=60;
			};
			class Blood
			{
				damage=200;
			};
			class Shock
			{
				damage=300;
			};
		};
		class NoiseHit
		{
			strength = 4;
			type = "shot";
		};
	};
};
class CfgMagazines
{
    class Ammunition_Base;
	class Ammo_TestBullet: Ammunition_Base
	{
		scope = 2;
		displayName = "TestBullet";
		descriptionShort = "TestBullet";
		model = "DayZ-CommunitySamples\Weapons\Ammunition\57x28_57x28_ss190.p3d";
		iconCartridge = 3;
		weight = 9;
		count = 40;
		ammo = "Bullet_TestBullet";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mosinclip_destruct.rvmat"}}};
				};
			};
		};
	};
	class DefaultMagazine;
	class Magazine_Base;
	class Mag_FNX45_15Rnd;
	class Mag_test_8Rnd : Mag_FNX45_15Rnd
	{
		displayName = "test";
		descriptionShort = "test";
		model = "DayZ-CommDayZ-CommunitySamples\Weapons\Ammunition\Mag_test_8Rnd.p3d";
		itemSize[] = {1,2};
		count = 8;
		ammo="Bullet_TestBullet";
		ammoItems[] = {"Ammo_TestBullet"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
    class ProxyMag_test_8Rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "DayZ-CommDayZ-CommunitySamples\Weapons\Ammunition\Mag_test_8Rnd.p3d";
	};
};
