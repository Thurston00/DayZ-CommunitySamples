modded class MissionGameplay 
{
    private ref UICustomMenu myCustomMenu;

    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);
        
        Input input = GetGame().GetInput();
        if (input.LocalPress("UAUIBack", false)) 
        {
            if (myCustomMenu != NULL && GetGame().GetUIManager().GetMenu() == myCustomMenu) {
                myCustomMenu.SetMenuOpen(false);
                GetGame().GetUIManager().HideScriptedMenu(myCustomMenu);
                UnlockControls();
            }
        }

        if ( input.LocalPress("UAOpenCustomMenu", false) ) 
        {
            if ( myCustomMenu ) {
                if (myCustomMenu.IsMenuOpen()) {
                    //Hide Menu
                    myCustomMenu.SetMenuOpen(false);
                    GetGame().GetUIManager().HideScriptedMenu(myCustomMenu);
                    UnlockControls();
                } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                    //Show Menu
                    GetGame().GetUIManager().ShowScriptedMenu(myCustomMenu, NULL);
                    myCustomMenu.SetMenuOpen(true);
                    LockControls();
                }
            } else if (GetGame().GetUIManager().GetMenu() == NULL && myCustomMenu == null) {
                //Create Menu
                LockControls();
                myCustomMenu = UICustomMenu.Cast(GetUIManager().EnterScriptedMenu(UI_CUSTOM_MENU, null));
                myCustomMenu.SetMenuOpen(true);
            }
        }
    }

    private void LockControls()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetMission().GetHud().Show( false );
    }

    private void UnlockControls()
    {
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetMission().GetHud().Show( true );
    }
};