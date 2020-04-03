/*
    @DOC / Notes:

    The keybind toggle for the menu works with MissionGameplay 
    ( the quickest way to get your input functional, plenty of other methods such as creating 
    your own plugin using PluginManager to manage your entire input system, this goes the same with storing 
    the instance of your menu, MissionGameplay is not the only option )
    The menu inherits UIScriptedMenu just as any other vanilla menu in the game.
    
    This is setup very similar to the way vanilla base game script creates menus. By modding MissionBase.c you are expanding on the available menus, the const UI_CUSTOM_MENU 
    is the unique ID of your newly added menu of class UICustomMenu

    This is not the only method in creating UI, however i find this method to be most simple as all EventHandlers are attached and a load of pre-written 
    functions are there for you to use from base class UIScriptedMenu
*/

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