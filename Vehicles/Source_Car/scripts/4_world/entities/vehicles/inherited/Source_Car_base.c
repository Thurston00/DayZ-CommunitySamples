class Source_Car_base extends CarScript
{
	
	void Source_Car_base()
	{
		m_dmgContactCoef = 0.060;          //tweak this up for more damage applied to player, down for less
		
		m_EngineStartOK = "CivilianSedan_engine_start_SoundSet";
		m_EngineStartBattery = "CivilianSedan_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug = "CivilianSedan_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel = "CivilianSedan_engine_failed_start_fuel_SoundSet";
		m_EngineStopFuel = "offroad_engine_stop_fuel_SoundSet";

		m_CarDoorOpenSound = "offroad_door_open_SoundSet";
		m_CarDoorCloseSound = "offroad_door_close_SoundSet";
	}	

    override float GetActionDistanceFuel()
    {
        return 3.2;
    }
	
	override float GetActionDistanceCoolant()
    {
        return 4.2;
    }
	
	
	override float GetActionDistanceOil()
    {
        return 4.2;
    }
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.HATCHBACK;  
						   // Tweak ^^^^^^^^^ for different seating postions, search for vehicleaniminstances.c in your p drive
	}
	
// Override for car-specific light type
		override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(Source_CarRearLight) );  
															      //^^^^^^ Name of light script.c Source_Car/scripts/4world/entities/scriptedlightbase/...
	}
	
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(Source_CarFrontLight) );  
															  //^^^^^^ Name of light script.c Source_Car/scripts/4world/entities/scriptedlightbase/...
	}

	override bool CanReleaseAttachment( EntityAI attachment )									//Can Remove attachments
	{
		if( !super.CanReleaseAttachment( attachment ) )				
			return false;
		
		string attType = attachment.GetType();
		
		switch( attType )
		{
			case "CarBattery": //this attachment
				if ( GetCarDoorsState("Source_Car_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() ) //if door is shut and/or engine is on
					return false; //cant be removed
			break;
			
			case "SparkPlug":
				if ( GetCarDoorsState("Source_Car_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			case "CarRadiator":
				if ( GetCarDoorsState("Source_Car_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			
			case "Source_CarWheel_Spare":
				if ( GetCarDoorsState("Source_Car_Trunk") == CarDoorState.DOORS_CLOSED )
					return false;
			break;
		}
	
		return true;	//otherwise yes attachments can be removed																		
	}

	override bool CanDisplayAttachmentCategory( string category_name )	//Can Display Gui inventory category 
	{
		//super
		if ( !super.CanDisplayAttachmentCategory( category_name ) )
		return false;
		//
	
		category_name.ToLower();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( category_name.Contains( "engine" ) )										//If this category
		{
			if ( GetCarDoorsState("Source_Car_Hood") == CarDoorState.DOORS_CLOSED )		//If this door is shut
				return false;															//Cant Display Gui inventory category
		}
				
		return true;  //otherwise yes category can be displayed
	}
	
	override int GetCarDoorsState( string slotType )    //what are the doors doing? 
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );  //check the slot.
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;							
	
		switch( slotType )
		{
			case "Source_Car_Driver_door":								//found a door in slot
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )			// if animation phase over 0.5 (half complete)
					return CarDoorState.DOORS_OPEN;						//door is open
				else
					return CarDoorState.DOORS_CLOSED;					//else door must be closed
			break;
			
			case "Source_Car_Codriver_door":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
				
			case "Source_Car_Cargo1_door":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
				
			case "Source_Car_Cargo2_door":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "Source_Car_Hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "Source_Car_Trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
		}

		return CarDoorState.DOORS_MISSING;						//nothing there must be missing
	}
	
	override bool CrewCanGetThrough( int posIdx )				//Can a player get in?
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "Source_Car_Driver_door" ) == CarDoorState.DOORS_CLOSED )  //if this door is CLOSED
					return false;																  //Nope

				return true;																	  //Otherwise yes
			break;
			
			case 1:
				if ( GetCarDoorsState( "Source_Car_Codriver_door" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			
			case 2:
				if ( GetCarDoorsState( "Source_Car_Cargo1_door" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 3:
				if ( GetCarDoorsState( "Source_Car_Cargo2_door" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
		}

		return false;
	}
	
	override string GetDoorSelectionNameFromSeatPos(int posIdx)				
	{
		switch( posIdx )
		{
		case 0:															 	
			return "doors_driver";											
		break;
		case 1:
			return "doors_codriver";
		break;
         case 2:
			return "doors_cargo1";
		break;
		case 3:
			return "doors_cargo2";
		break;		
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "Source_Car_Driver_door";
		break;
		case 1:
			return "Source_Car_Codriver_door";
		break;
		
		case 2:
			return "Source_Car_Cargo1_door";
		break;
		
		case 3:
			return "Source_Car_Cargo2_door";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	
	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}
	
	override string GetDoorConditionPointFromSelection( string selection )
	{
		switch( selection )
		{
		case "seat_driver":
			return "seat_con_1_1";
		break;
		case "seat_codriver":
			return "seat_con_2_1";
		break;
		case "seat_cargo1":
			return "seat_con_1_2";
		break;
		case "seat_cargo2":
			return "seat_con_2_2";
		break;
		}
		
		return "";
	}
	
	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;

		}

		return 0;
	}
	
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
		break;
		
		case 1:
			if ( nextSeat == 0 )
				return true;
		break;			
		}
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		case 2:
			if (pDoorsSelection == "DoorsCargo1")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
	

		}
		
		return false;		
	}
	
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;
				
				if ( GetCarDoorsState( "Source_Car_Driver_door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				if ( GetCarDoorsState( "Source_Car_Codriver_door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "Source_Car_Cargo1_door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "Source_Car_Cargo2_door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				if ( GetCarDoorsState( "Source_Car_Hood" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.05;
				
				if ( GetCarDoorsState( "Source_Car_Trunk" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.05;
				
				if ( newValue > 1 )
					newValue = 1;
			
				return newValue;
			break;
		}

		return oldValue;
	}
	
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "Source_CarWheel" );
			entity.GetInventory().CreateInInventory( "Source_CarWheel" );
			entity.GetInventory().CreateInInventory( "Source_CarWheel" );
			entity.GetInventory().CreateInInventory( "Source_CarWheel" );
			entity.GetInventory().CreateInInventory( "Source_CarWheel" );

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );

			entity.GetInventory().CreateInInventory( "Source_Car_Driver_door" );
			entity.GetInventory().CreateInInventory( "Source_Car_Codriver_door" );
			entity.GetInventory().CreateInInventory( "Source_Car_Cargo1_door" );
			entity.GetInventory().CreateInInventory( "Source_Car_Cargo2_door" );

			entity.GetInventory().CreateInInventory( "Source_Car_Hood" );
			entity.GetInventory().CreateInInventory( "Source_Car_Trunk" );

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 50 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class Source_Car_Green extends Source_Car_base
{
		
};
class Source_Car_Blue extends Source_Car_base
{
		
};
class Source_Car_Red extends Source_Car_base
{
		
};





