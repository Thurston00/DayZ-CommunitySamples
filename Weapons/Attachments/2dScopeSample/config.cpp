enum {
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	DESTRUCTNO = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

class CfgPatches {
	class DZ_Weapons_Optics 
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class cfgVehicles 
{
	class Inventory_Base;
	
	class ItemOptics : Inventory_Base 
	{
		class AnimEvents 
		{
			class SoundWeapon 
			{
				class pickup 
				{
					soundSet = "PSO11Optic_pickup_SoundSet";
					id = 797;
				};
				
				class drop {
					soundset = "PSO11Optic_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class HuntingOptic;	
	class CS_2dscope : HuntingOptic 
	{
		scope = 2;
		displayName = "2d scope sample";
		descriptionShort = "Custom 2d scope provided by DayZ Community Samples";
		model = "\2dScopeSample\2dscope.p3d";
		rotationFlags = 4;
		reversed = 0;
		weight = 900;
		itemSize[] = {4, 1};
		inventorySlot = "weaponOpticsHunting";
		simulation = "itemoptics";
		dispersionModifier = -0.00025;
		dispersionCondition = "true";
		recoilModifier[] = {1, 1, 1};
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0, {"2dScopeSample\data\body.rvmat"}},
						{0.7, {"2dScopeSample\data\body.rvmat"}},
						{0.5, {"2dScopeSample\data\body.rvmat"}},
						{0.3, {"2dScopeSample\data\body_damaged.rvmat"}},
						{0.0, {"2dScopeSample\data\body_destruct.rvmat"}}
					};
				};
			};
		};
		
		class OpticsInfo 
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			useModelOptics = 1;
			modelOptics = "\2dScopeSample\2dscope_reticle.p3d";
			preloadOpticType = "Preload2DOptic_Longrange";
			opticsDisablePeripherialVision = 0.67;
			opticsFlare = 1;
			opticsPPEffects[] = {"OpticsCHAbera3", "OpticsBlur1"};
			opticsZoomMin = 0.3926/4;
			opticsZoomMax = 0.3926/12;
			opticsZoomInit = 0.3926/4;
			discretefov[] = {0.3926/4, 0.3926/8, 0.3926/12};	
			discreteInitIndex = 0;			
			distanceZoomMin = 100;
			distanceZoomMax = 1000;
			discreteDistance[] = {200, 300, 400, 500, 600, 700, 800};
			discreteDistanceInitIndex = 0;
			PPMaskProperties[] = {0.5, 0.5, 0.43, 0.1};
			PPLensProperties[] = {0.3, 0.15, 0, 0};
			PPBlurProperties = 0.3;
		};
		
		class AnimationSources 
		{
			class hide 
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
};

class CfgNonAIVehicles 
{
	class ProxyAttachment;
	
	class ProxyOptic_Hunting : ProxyAttachment 
	{
		scope = 2;
		inventorySlot = "weaponOpticsHunting";
		model = "\2dScopeSample\2dscope.p3d";
	};
};
