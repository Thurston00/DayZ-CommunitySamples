//original script creator???? I got it from |RAG|Tyson & Deano

modded class DayZPlayerCamera3rdPersonVehicle extends DayZPlayerCameraBase
{
    void DayZPlayerCamera3rdPersonVehicle (DayZPlayer pPlayer, HumanInputController pInput)
    {
		if (pPlayer.GetCommand_Vehicle().GetTransport().GetType() == "Source_Car_Green")
		{
		//Print("new camera: DayZPlayerCamera3rdPersonVehicle");
		m_fDistance         = 5.0;      
		m_CameraOffsetMS    = "0.0 1.4 0.0";
		//stock cam setting
		//m_fDistance 		= 4.0;
		//m_CameraOffsetMS	= "0.0 1.3 0.0";
		}
		if (pPlayer.GetCommand_Vehicle().GetTransport().GetType() == "Source_Car_Red")
		{
		//Print("new camera: DayZPlayerCamera3rdPersonVehicle");
		m_fDistance         = 5.0; 
		m_CameraOffsetMS    = "0.0 1.4 0.0";
		}
		if (pPlayer.GetCommand_Vehicle().GetTransport().GetType() == "Source_Car_Blue")
		{
		//Print("new camera: DayZPlayerCamera3rdPersonVehicle");
		m_fDistance         = 5.0; 
		m_CameraOffsetMS    = "0.0 1.4 0.0";
		}
    }
}

//Seems you need to add each variant doesnt work from base class.