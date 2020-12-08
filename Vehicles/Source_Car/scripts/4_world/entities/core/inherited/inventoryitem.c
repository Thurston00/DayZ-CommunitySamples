class Source_CarWheel extends CarWheel {
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "Source_CarWheel":
				newWheel = "Source_CarWheel_Destroyed";
			break;
		}
		if ( newWheel != "" )
		{
			ReplaceWheelLambda lambda = new ReplaceWheelLambda ( this, newWheel, NULL);
			lambda.SetTransferParams(true, true, true);
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
		}
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};

class Source_CarWheel_Destroyed extends CarWheel {};
class Source_Car_Driver_door extends CarDoor {};
class Source_Car_Codriver_door extends CarDoor {};
class Source_Car_Cargo1_door extends CarDoor {};
class Source_Car_Cargo2_door extends CarDoor {};
class Source_Car_Hood extends CarDoor {};
class Source_Car_Trunk extends CarDoor {};

