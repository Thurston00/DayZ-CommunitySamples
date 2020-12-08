//config.cpp for your custom slots!

class CfgPatches
{
	class Source_Car_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Scripts"};
	};
};
class CfgSlots
{
	class Slot_Source_CarWheel_1_1
	{
		name="Source_CarWheel_1_1";			//slot name
		displayName="Front Left wheel";
		selection="wheel_1_1";				//selection in the model and model.cfg
		ghostIcon="wheel";					//icon in the gui, more can be found in p/scripts/config.cpp
	};
	class Slot_Source_CarWheel_1_2
	{
		name="Source_CarWheel_1_2";
		displayName="Rear Left wheel";
		selection="wheel_1_2";
		ghostIcon="wheel";
	};
	class Slot_Source_CarWheel_2_1
	{
		name="Source_CarWheel_2_1";
		displayName="Front Right wheel";
		selection="wheel_2_1";
		ghostIcon="wheel";
	};
	class Slot_Source_CarWheel_2_2
	{
		name="Source_CarWheel_2_2";
		displayName="Rear Right wheel";
		selection="wheel_2_2";
		ghostIcon="wheel";
	};
	class Slot_Source_CarWheel_Spare
	{
		name="Source_CarWheel_Spare";
		displayName="Spare wheel";
		selection="wheel_spare";
		ghostIcon="wheel";
	};
	class Slot_Source_Car_Driver_door
	{
		name="Source_Car_Driver_door";
		displayName="Drivers Door";
		selection="doors_driver";
		ghostIcon="doorfront";
	};
	class Slot_Source_Car_Codriver_door
	{
		name="Source_Car_Codriver_door";
		displayName="Passenger Door";
		selection="doors_codriver";
		ghostIcon="doorfront";
	};
	class Slot_Source_Car_Cargo1_door
	{
		name="Source_Car_Cargo1_door";
		displayName="Rear Door";
		selection="doors_Cargo1";
		ghostIcon="doorrear";
	};
	class Slot_Source_Car_Cargo2_door
	{
		name="Source_Car_Cargo2_door";
		displayName="Rear Door";
		selection="doors_Cargo2";
		ghostIcon="doorrear";
	};
	class Slot_Source_Car_Hood
	{
		name="Source_Car_Hood";
		displayName="Source_Car_Hood";
		selection="doors_hood";
		ghostIcon="hood";
	};
	class Slot_Source_Car_Trunk
	{
		name="Source_Car_Trunk";
		displayName="Source_Car_Trunk";
		selection="doors_trunk";
		ghostIcon="trunk";
	};
};