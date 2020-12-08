//Main config.cpp

class CfgPatches
{
	class Source_Car
	{
		units[]=
		{
			
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"Source_Car_Scripts",
			"Source_Car_Sounds",
			"DZ_Vehicles_Parts"
			//minimal required addons. All other required addons are called up inside these ones. So not needed.
		};
	};
};
class CfgMods
{
	class Source_Car
	{
		dir="Source_Car";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Source_Car";
		credits="Spurgle, Yoluke86"; //Add yourself if you contribute
		author="Spurgle";
		authorID="0";  //authors steam id???
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"Source_Car/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Source_Car/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Source_Car/scripts/5_mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class CarScript;
	class Crew;
	class Driver;
	class CoDriver;
	class CarDoor;
	class Front;
	class Rear;
	class Left;
	class Right;
	class AnimationSources;
	class SimulationModule;
	class Axles;
	class Wheels;
	class DamageSystem;
	class GlobalHealth;
	class DamageZones;
	class Window;
	class Health;
	class Doors;
	class CarWheel;
	class Source_CarWheel: CarWheel
	{
		scope=2;
		displayName="Source Car Wheel";
		descriptionShort="A wheel for the source car";
		model="\Source_Car\proxys\Source_CarWheel.p3d";
		weight=20000; 		//Must match mass of wheel in geomety LOD of wheel p3d and the mass of the wheel geometry in vehicle p3d.
		inventorySlot[]=
		{
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare"
		};
		rotationFlags=4;	//Change this to get your items to sit correctly on the floor. 
		repairableWithKits[]={6};
		repairCosts[]={30};
		radiusByDamage[]={0,0.308,0.30000001,0.30000001,0.99980003,0.25,0.99989998,0.2};
		radius=0.308;  	//Radius of the wheel
		width=0.216000001;		//Width of the tread
		tyreRollResistance=0.015;
		tyreTread=0.80000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat" // change these to your own rvmats. Pristine
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat" //worn
							}
						},
						
						{
							0.5,
							
							{
								"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat" //damaged
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat" //badly damaged
							}
						},
						
						{
							0.0,
							
							{
								"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_destruct.rvmat" //ruined.. kinda not needed as wheel changes to destroyed wheel upon being ruined
							}
						}
					};
				};
			};
		};
	};
	class Source_CarWheel_Destroyed: CarWheel  
	{
		scope=2;
		displayName="Source Car Wheel Ruined";
		descriptionShort="A ruined wheel for the source car";
		model="\Source_Car\proxys\Source_CarWheel_Destroyed.p3d";
		weight=20000;
		inventorySlot[]=
		{
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare"
		};
		rotationFlags=4;
		radius=0.2;
		width=0.226;
		tyreRollResistance=1;
		tyreRollDrag=70;
		tyreRoughness=1;
		tyreTread=0.5;
	};
	class SourceCar_DriverDoor: CarDoor		//base door
	{
		scope=2;
		displayName="Source Car Drivers door";
		descriptionShort="A sample door for the source car";
		model="Source_Car\proxys\Source_Car_Driver_door.p3d";
		weight=20000;
		inventorySlot[]=
		{
			"Source_Car_Driver_door"
		};
		rotationFlags=8;
		hiddenSelectionsMaterials[]=
		{
			"dz\data\data\default.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1.0,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0.0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Window
				{
					class Health
					{
						hitpoints=70;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1.0,
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0.0,
								"hidden"
							}
						};
					};
					componentNames[]=
					{
						"dmgZone_window"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Doors
				{
					class Health
					{
						RefTexsMats[]=
						{
							"dz\data\data\default.rvmat"
						};
						hitpoints=500;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									"dz\data\data\default.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\data\data\default.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
							
							{
								0.0,
								
								{
									"Source_Car\data\defaultdestruct.rvmat"
								}
							}
						};
					};
					componentNames[]=
					{
						"dmgZone_doors"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
			};
		};
	};
	class SourceCar_DriverDoor_Red: SourceCar_DriverDoor	//Colored variant of door
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"									//Selection in the model
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\pas_door_red.paa"				//Path to texture
		};
	};
	class SourceCar_DriverDoor_Blue: SourceCar_DriverDoor
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\pas_door_blue.paa"
		};
	};
	
	class SourceCar_CodriverDoor: SourceCar_DriverDoor
	{
		displayName="Source Car Codriver door";
		descriptionShort="A sample door for the source car";
		model="Source_Car\proxys\Source_Car_Codriver_door.p3d";
		inventorySlot[]=
		{
			"Source_Car_Codriver_door"
		};
		rotationFlags=4;
	}
	class SourceCar_CodriverDoor_Red: SourceCar_CodriverDoor
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\pas_door_red.paa"
		};
	};
	class SourceCar_CodriverDoor_Blue: SourceCar_CodriverDoor
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\pas_door_blue.paa"
		};
	};
	
	class SourceCar_Cargo1: SourceCar_DriverDoor
	{
		displayName="Source Car rear left door";
		descriptionShort="A sample door for the source car";
		model="Source_Car\proxys\Source_Car_Cargo1_door.p3d";
		inventorySlot[]=
		{
			"Source_Car_Cargo1_door"
		};
		rotationFlags=4;
	}
	class SourceCar_Cargo1_Red: SourceCar_Cargo1
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\rear_door_red.paa"
		};
	};
	class SourceCar_Cargo1_Blue: SourceCar_Cargo1
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\rear_door_blue.paa"
		};
	};
	
	class SourceCar_Cargo2: SourceCar_DriverDoor
	{
		displayName="Source Car rear right door";
		descriptionShort="A sample door for the source car";
		model="Source_Car\proxys\Source_Car_Cargo2_door.p3d";
		inventorySlot[]=
		{
			"Source_Car_Cargo2_door"
		};
		rotationFlags=4;
	}
	class SourceCar_Cargo2_Red: SourceCar_Cargo2
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\rear_door_red.paa"
		};
	};
	class SourceCar_Cargo2_Blue: SourceCar_Cargo2
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\rear_door_blue.paa"
		};
	};
	
	class SourceCar_Hood: CarDoor
	{
		scope=2;
		displayName="Source Car Hood";
		descriptionShort="A hood for the source car";
		model="Source_Car\proxys\Source_Car_Hood.p3d";
		weight=20000;
		inventorySlot[]=
		{
			"Source_Car_Hood"
		};
		rotationFlags=2;
		hiddenSelectionsMaterials[]=
		{
			"dz\data\data\default.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					RefTexsMats[]=
						{
							"dz\data\data\default.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									"dz\data\data\default.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\data\data\default.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
							
							{
								0.0,
								
								{
									"Source_Car\data\defaultdestruct.rvmat"
								}
							}
						};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet="hatchbackdoors_driver_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="hatchbackhood_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class SourceCar_Hood_Red: SourceCar_Hood
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\bonet_red.paa"
		};
	};
	class SourceCar_Hood_Blue: SourceCar_Hood
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\bonet_blue.paa"
		};
	};
	
	class SourceCar_Trunk: CarDoor
	{
		scope=2;
		displayName="Source Car Trunk";
		descriptionShort="A trunk for the source car";
		model="Source_Car\proxys\Source_Car_Trunk.p3d";
		weight=20000;
		inventorySlot[]=
		{
			"Source_Car_Trunk"
		};
		rotationFlags=0;
		hiddenSelectionsMaterials[]=
		{
			"dz\data\data\default.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					RefTexsMats[]=
					{
						"dz\data\data\default.rvmat"
					};
					healthLevels[]=
					{
							
						{
							1.0,
								
							{
								"dz\data\data\default.rvmat"
							}
						},
							
						{
							0.69999999,
								
							{
								"dz\data\data\default.rvmat"
							}
						},
							
						{
							0.5,
								
							{
								"Source_Car\data\defaultdamage.rvmat"
							}
						},
							
						{
							0.30000001,
								
							{
								"Source_Car\data\defaultdamage.rvmat"
							}
						},
							
						{
							0.0,
								
							{
								"Source_Car\data\defaultdestruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SourceCar_Trunk_Red: SourceCar_Trunk
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\boot_red.paa"
		};
	};
	class SourceCar_Trunk_Blue: SourceCar_Trunk
	{
		hiddenSelections[]=
		{
			"dmgzone_doors"
		};
		hiddenSelectionsTextures[]=
		{
			"Source_Car\data\boot_blue.paa"
		};
	};
	//entry for the Source_Car
	class Source_Car_base: CarScript
	{
		scope=0;  //0=base class, 1=static item (buildings ect???) 2=everything else
		displayName="Source Car";
		descriptionShort="A simple sample car";
		model=""; //file path to p3d not needed in base class
		fuelCapacity=55;  //size of fuel tank
		fuelConsumption=6.5;  //rate fuel is consummed 
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare",
			"Source_Car_Driver_door",
			"Source_Car_Codriver_door",
			"Source_Car_Cargo1_door",
			"Source_Car_Cargo2_door",
			"Source_Car_Hood",
			"Source_Car_Trunk",
		};
		hiddenSelections[]= // from model.cfg (Source_car.cfg)
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"dmgZone_chassis",
			"dmgZone_front",
			"dmgZone_back",
			"dmgZone_roof",
			"dmgZone_fender_1_1",
			"dmgZone_fender_1_2",
			"dmgZone_fender_2_1",
			"dmgZone_fender_2_2"
		};
		hiddenSelectionsTextures[]=   //textures for hidden selections, not needed in this base class, same order as hidden selections above.
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};
		hiddenSelectionsMaterials[]=        //same as rvmat assigned in p3d on the selections, same order as hidden selections above.
		{
			"dz\data\data\default.rvmat",  
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat",
			"dz\data\data\default.rvmat"
		};
		dashboardMatOn="Source_Car\data\dashlights.rvmat";    //rvmat for the lights when on
		dashboardMatOff="dz\data\data\default.rvmat";		  //rvmat for the lights when off
		frontReflectorMatOn="Source_Car\data\lights.rvmat";
		frontReflectorMatOff="dz\data\data\default.rvmat";
		brakeReflectorMatOn="Source_Car\data\taillights.rvmat";
		brakeReflectorMatOff="dz\data\data\default.rvmat";
		tailReflectorMatOn="Source_Car\data\taillights.rvmat";
		tailReflectorMatOff="dz\data\data\default.rvmat";
		reverseReflectorMatOn="Source_Car\data\lights.rvmat";
		reverseReflectorMatOff="dz\data\data\default.rvmat";
		class Crew
		{
			class Driver
			{
				actionSel="seat_driver";
				proxyPos="crewDriver";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
				isDriver=1;
			};
			class CoDriver
			{
				actionSel="seat_coDriver";
				proxyPos="crewCoDriver";
				getInPos="pos_coDriver";
				getInDir="pos_coDriver_dir";
			}
			class Cargo1
			{
				actionSel="seat_cargo1";
				proxyPos="crewCargo1";
				getInPos="pos_cargo1";
				getInDir="pos_cargo1_dir";
			};
			class Cargo2
			{
				actionSel="seat_cargo2";
				proxyPos="crewCargo2";
				getInPos="pos_cargo2";
				getInDir="pos_cargo2_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive="DRIVE_FWD";			//AWD,FWD,RWD,???
			airDragFrontTotal=0.79000002;  //Air resistance??
			braking[]={0,0.30000001,1,0.80000001,2.5,0.89999998,3,1}; // 0,0.3000001= time,amount of brake force applied. (0.1-10%)
			class Steering
			{
				increaseSpeed[]={0,45,60,25,100,10};
				decreaseSpeed[]={0,80,60,40,100,15};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.80000001;
				defaultThrust=0.89999998;
				gentleThrust=0.80000001;
				turboCoef=2.8;
				gentleCoef=0.5;
			};
			class Engine
			{
				inertia=0.15;
				torqueMax=92;
				torqueRpm=3300;
				powerMax=57;
				powerRpm=5200;
				rpmIdle=900;
				rpmMin=1000;
				rpmRedline=5750;
				rpmMax=7000;
				rpmClutch=1500;
			};
			class Gearbox
			{
				reverse=3.27;
				ratios[]={3.8,2.1199999,1.41,0.95999998};
				timeToUncoupleClutch=0.1;
				timeToCoupleClutch=0.30000001;
				maxClutchTorque=165;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle=30;
					finalRatio=3.6670001;
					brakeBias=0.75;
					brakeForce=4000;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=1000;   //how much under/over steer. or lean of the vehicle
						stiffness=46500;   //((geo mass in p3d x2)x10)+ Compression = stiffness  ((500*2)*10)+1600=11600D
						compression=12000;  //    how much it take to compress the shocks???
						damping=7700;		//   how soft the supsension is???
						travelMaxUp=0.158200003;  // how far up the wheel can move???
						travelMaxDown=0.083300002;// how far down ^^^???
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Source_CarWheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Source_CarWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle=0;
					brakeBias=0.44999999;
					brakeForce=3500;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=1100;
						stiffness=40000;	
						compression=5900; 	
						damping=5600;
						travelMaxUp=0.18200003;
						travelMaxDown=0.073300002;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Source_CarWheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Source_CarWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,30};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class DoorsCoDriver: DoorsDriver
			{
			};
			class DoorsHood: DoorsDriver
			{
			};
			class DoorsTrunk: DoorsDriver
			{
			};
			class DoorsCargo1: DoorsDriver
			{
			};
			class DoorsCargo2: DoorsDriver
			{
			};
			class damper_1_1
			{
				source="user";
				initPhase=0.5;
				animPeriod=1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2: damper_1_1
			{
			};
			class damper_2_2: damper_1_2
			{
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1.0,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0.0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=3000;
						transferToGlobalCoef=0;
					};
					inventorySlots[]={};
				};
				class Front
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front",
						"dmgZone_front_bumper"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
								
							{
								1.0,
									
								{
									"dz\data\data\default.rvmat"  //pristine same rvmat as on your model
								}
							},
								
							{
								0.69999999,
									
								{
									"Source_Car\data\defaultdamage.rvmat" //worn same rvmat as on your model
								}
							},
								
							{
								0.5,
									
								{
									"Source_Car\data\defaultdamage.rvmat" //damaged basic damage rvmat
								}
							},
								
							{
								0.30000001,
									
								{
									"Source_Car\data\2xdamage.rvmat" //badly damaged basic damage rvmat
								}
							},
								
							{
								0.0,
									
								{
									"Source_Car\data\2xdestruct.rvmat"   //ruined  basic destruct rvmat 
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_1",
						"Fender_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999,0.80000001};
					inventorySlots[]=
					{
						"Source_Car_Hood",
						"CarRadiator",
						"Source_CarWheel_1_1",
						"Source_CarWheel_2_1"
					};
					inventorySlotsCoefs[]={0.69999999,0.5,0.80000001,0.80000001};
				};
				class Reflector_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=10;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0.0,
								"hidden" 
	
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_1_1"
					};
					transferToZonesCoefs[]={1,1};
					inventorySlots[]=
					{
						"Reflector_1_1"
					};
					inventorySlotsCoefs[]={1};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_lights_2_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_2_1"
					};
					inventorySlots[]=
					{
						"Reflector_2_1"
					};
				};
				class Back
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back",
						"dmgZone_rear_bumper"
					};
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
								
							{
								1.0,
									
								{
									"dz\data\data\default.rvmat"
								}
							},
								
							{
								0.69999999,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.5,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.30000001,
									
								{
									"Source_Car\data\2xdamage.rvmat"
								}
							},
								
							{
								0.0,
									
								{
									"Source_Car\data\2xdestruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_2",
						"Fender_2_2"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999};
					inventorySlots[]=
					{
						"Source_Car_Trunk",
						"Source_CarWheel_1_2",
						"Source_CarWheel_2_2"
					};
					inventorySlotsCoefs[]={0.89999998,0.89999998,0.89999998};
				};
				class Roof
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_roof"
					};
					memoryPoints[]=
					{
						"dmgZone_roof"
					};
					class Health
					{
						hitpoints=400;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
								
							{
								1.0,
									
								{
									"dz\data\data\default.rvmat"
								}
							},
								
							{
								0.69999999,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.5,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.30000001,
									
								{
									"Source_Car\data\2xdamage.rvmat"
								}
							},
								
							{
								0.0,
									
								{
									"Source_Car\data\2xdestruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]={};
				};
				class Fender_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fender_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_fender_1_1"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
								
							{
								1.0,
									
								{
									"dz\data\data\default.rvmat"
								}
							},
								
							{
								0.69999999,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.5,
									
								{
									"Source_Car\data\defaultdamage.rvmat"
								}
							},
								
							{
								0.30000001,
									
								{
									"Source_Car\data\2xdamage.rvmat"
								}
							},
								
							{
								0.0,
									
								{
									"Source_Car\data\2xdestruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_1_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.40000001};
					inventorySlots[]=
					{
						"Source_Car_Hood",
						"Source_CarWheel_1_1",
						"Source_Car_Driver_door"
					};
					inventorySlotsCoefs[]={0.60000002,0.89999998,0.30000001};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.40000001};
					inventorySlots[]=
					{
						"Source_Car_Hood",
						"Source_CarWheel_2_1",
						"Source_Car_Codriver_door"
					};
					inventorySlotsCoefs[]={0.60000002,0.89999998,0.30000001};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_1_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999};
					inventorySlots[]=
					{
						"Source_Car_Trunk",
						"Source_CarWheel_1_2",
						"Source_Car_Cargo1_door"
					};
					inventorySlotsCoefs[]={0.69999999,0.89999998,0.30000001};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999};
					inventorySlots[]=
					{
						"Source_Car_Trunk",
						"Source_CarWheel_2_2",
						"Source_Car_Cargo2_door"
					};
					inventorySlotsCoefs[]={0.69999999,0.89999998,0.30000001};
				};
				class WindowFront
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowFront"
					};
					componentNames[]=
					{
						"dmgZone_windowFront"
					};
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0.0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class WindowBack
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowBack"
					};
					componentNames[]=
					{
						"dmgZone_windowBack"
					};
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0.0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class Engine
				{
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1.0,
								
								{
									""
								}
							},
							
							{
								0.69999999,
								
								{
									""
								}
							},
							
							{
								0.5,
								
								{
									""
								}
							},
							
							{
								0.30000001,
								
								{
									""
								}
							},
							
							{
								0.0,
								
								{
									""
								}
							}
						};
					};
					inventorySlots[]=
					{
						"CarBattery",
						"SparkPlug",
						"CarRadiator"
					};
					inventorySlotsCoefs[]={0.2,0.2,0.40000001};
				};
				class FuelTank
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=600;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1.0,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0.0,
								{}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
		};
		class ObstacleGenerator		//????
		{
			carve=1;
			timeToStationary=5;
			moveThreshold=0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius=1;
						height=1.5;
						center[]={0,0,0.69999999};
					};
					class Cyl3
					{
						radius=1;
						height=1.5;
						center[]={0,0,-0.69999999};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="cat_vehicle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"Source_Car_Driver_door",
					"Source_Car_Codriver_door",
					"Source_Car_Cargo1_door",
					"Source_Car_Cargo2_door",
					"Source_Car_Hood",
					"Source_Car_Trunk"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"Source_CarWheel_1_1",
					"Source_CarWheel_1_2",
					"Source_CarWheel_2_1",
					"Source_CarWheel_2_2",
					"Source_CarWheel_Spare"
				};
			};
		};
		class Sounds
		{
			thrust=0.60000002;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.02;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"Source_Car_Engine_Offload_Ext_Rpm1_SoundSet",
				"Source_Car_Engine_Offload_Ext_Rpm2_SoundSet",
				"Source_Car_Engine_Offload_Ext_Rpm3_SoundSet",
				"Source_Car_Engine_Offload_Ext_Rpm4_SoundSet",
				"Source_Car_Engine_Offload_Ext_Rpm5_SoundSet",
				"Source_Car_Engine_Ext_Rpm0_SoundSet",
				"Source_Car_Engine_Ext_Rpm1_SoundSet",
				"Source_Car_Engine_Ext_Rpm2_SoundSet",
				"Source_Car_Engine_Ext_Rpm3_SoundSet",
				"Source_Car_Engine_Ext_Rpm4_SoundSet",
				"Source_Car_Engine_Ext_Rpm5_SoundSet",
				"Source_Car_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
			soundSetsInt[]=
			{
				"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet",
				"Offroad_Wind_SoundSet"
			};
		};
		hornSoundSetEXT="Source_Car_Horn_Ext_SoundSet"; //custom horn sounds to work with CarHorn mod and Expansion
        hornSoundSetINT="Source_Car_Horn_Int_SoundSet";
	};
	
	class Source_Car_Green: Source_Car_base
	{
		scope=2;
		displayname="Source_Car Green ";
		Model="\Source_Car\Source_Car.p3d";
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare",
			"Source_Car_Driver_door",
			"Source_Car_Codriver_door",
			"Source_Car_Cargo1_door",
			"Source_Car_Cargo2_door",
			"Source_Car_Hood",
			"Source_Car_Trunk",
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa",
			"Source_Car\data\chasis_green.paa"
		};
	};
	class Source_Car_Red: Source_Car_base
	{
		scope=2;
		displayname="Source_Car Red ";
		Model="\Source_Car\Source_Car.p3d";
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare",
			"Source_Car_Driver_door",
			"Source_Car_Codriver_door",
			"Source_Car_Cargo1_door",
			"Source_Car_Cargo2_door",
			"Source_Car_Hood",
			"Source_Car_Trunk",
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa",
			"Source_Car\data\chasis_red.paa"
		};
	};
	class Source_Car_Blue: Source_Car_base
	{
		scope=2;
		displayname="Source_Car Blue ";
		Model="\Source_Car\Source_Car.p3d";
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare",
			"Source_Car_Driver_door",
			"Source_Car_Codriver_door",
			"Source_Car_Cargo1_door",
			"Source_Car_Cargo2_door",
			"Source_Car_Hood",
			"Source_Car_Trunk",
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa",
			"Source_Car\data\chasis_blue.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVehiclePart;
	class ProxySource_CarWheel: ProxyVehiclePart    //ProxyName must be the same as p3d with "Proxy" as a prefix
	{
		model="Source_Car\proxys\Source_CarWheel.p3d";
		inventorySlot[]=
		{
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare"
		};
	};
	class ProxySource_CarWheel_Destroyed: ProxyVehiclePart
	{
		model="Source_Car\proxys\Source_CarWheel_Destroyed.p3d";
		inventorySlot[]=
		{
			"Source_CarWheel_1_1",
			"Source_CarWheel_1_2",
			"Source_CarWheel_2_1",
			"Source_CarWheel_2_2",
			"Source_CarWheel_Spare"
		};
	};
	class ProxySource_Car_Driver_door: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Driver_door.p3d";
		inventorySlot="Source_Car_Driver_door";
	};
	class ProxySource_Car_Codriver_door: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Codriver_door.p3d";
		inventorySlot="Source_Car_Codriver_door";
	};
	class ProxySource_Car_Cargo1_door: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Cargo1_door.p3d";
		inventorySlot="Source_Car_Cargo1_door";
	};
	class ProxySource_Car_Cargo2_door: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Cargo2_door.p3d";
		inventorySlot="Source_Car_Cargo2_door";
	};
	class ProxySource_Car_Hood: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Hood.p3d";
		inventorySlot="Source_Car_Hood";
	};
	class ProxySource_Car_Trunk: ProxyVehiclePart
	{
		Model="Source_Car\proxys\Source_Car_Trunk.p3d";
		inventorySlot="Source_Car_Trunk";
	};
};
