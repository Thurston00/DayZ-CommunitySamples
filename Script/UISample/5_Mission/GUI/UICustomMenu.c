class UICustomMenu extends UIScriptedMenu
{
    private bool                 m_Initialized;
    private bool                 m_IsMenuOpen;

    //---Elements from .layout file
    private ScrollWidget 		 m_Scroller; //Btw the m_ thingy is just a bat habbit i picked up from DayZ devs (ಠ¿ಠ)
    private GridSpacerWidget     m_Grid;
    private TextWidget           m_Title;
    private Widget               m_pnl_bg;
    private ButtonWidget         m_BtnAddChild;
    private ButtonWidget         m_BtnRemoveChild;
    //---

    //Array that stores child widgets we create during runtime
    private ref array<ref Widget> m_CustomChildrenHighIQ;

    void UICustomMenu()
    {
       /*Do something when this class is created. This is the constructor, it is the very firt thing called out of all other methods.
    		More info on Enforce syntax and functionality here:  https://community.bistudio.com/wiki/DayZ:Enforce_Script_Syntax
    	*/
    	m_CustomChildrenHighIQ = new array<ref Widget>;
    }

    /*
		This is the destructor, called when this class is deleted / destroyed
    */
    void ~UICustomMenu() 
    {
        PPEffects.SetBlurMenu( 0 );
        GetGame().GetUIManager().Back();
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );

        //Destroy root widget and all its children
        if ( layoutRoot )
        	layoutRoot.Unlink();
    }

    //after show
    override void OnShow()
    {
        super.OnShow();
        PPEffects.SetBlurMenu( 0.5 ); //Add blurr effect
    }

    //after hide
    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurMenu( 0 ); //Remove blurr effect

        //Unlock controls, this also happens in missionGameplay.c however including it here will assure control is gained back incase that method is not invoked. 
        //That can occur when other mods / scripts force a menu on screen illegally 
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );
    }

    override Widget Init()
    {
        if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
        {
            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "UISample/GUI/Layouts/MyCustomMenu.layout" ); //Create custom widget / .layout
            
            //Define elements from .layout ( you must cast each element to its according script class if you wish to use its functions see scripts\1_Core\proto\EnWidgets.c )
            m_Scroller = ScrollWidget.Cast( layoutRoot.FindAnyWidget( "Scroller" ) ); //Find the widget by its name that is defined in .layout
			m_Grid     = GridSpacerWidget.Cast( layoutRoot.FindAnyWidget( "Grid" ) );
			m_Title	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "Title" ) );
			m_pnl_bg   = layoutRoot.FindAnyWidget( "pnl_bg" );
			m_BtnAddChild    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "BtnAddChild" ) );
			m_BtnRemoveChild = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "BtnRemoveChild" ) );

            WidgetEventHandler.GetInstance().RegisterOnDoubleClick( m_Grid, this, "OnDoubleClicked" ); //Attach a double-click event on a specifc widget
            WidgetEventHandler.GetInstance().RegisterOnDoubleClick( m_Scroller, this, "OnDoubleClicked" );

            m_Initialized = true;
        }
        return layoutRoot;
    }

    bool ShouldShowScrollBar()
    {
        float x, y;
        m_pnl_bg.GetScreenSize( x, y );
        return m_Scroller.GetContentHeight() > y;
    }

    //Called on each frame, this will be paused when the menu is hidden or missiongameplay callqueue is frozen / paused
    override void Update(float timeslice)
    {
        super.Update(timeslice);

        if ( ShouldShowScrollBar() )
            m_Scroller.SetAlpha(1.0);
        else
            m_Scroller.SetAlpha(0.0);
    }

    //Click event triggers when you click on a widget, this method wont get called if your widget has the "IgnorePointer" property toggled in your .layout
    override bool OnClick(Widget w, int x, int y, int button)
    {
    	switch(w)
    	{
    		case m_BtnAddChild:
    		ref ImageWidget child = ImageWidget.Cast( GetGame().GetWorkspace().CreateWidgets( "UISample/GUI/Layouts/ChildElement.layout", m_Grid) ); //Add child to array and make our grid the parent of this child widget
    		child.LoadImageFile(0, "set:dayz_gui image:DayZLogo");

    		m_CustomChildrenHighIQ.Insert( child ); 
    		break;

    		case m_BtnRemoveChild:
    		//Remove random child from grid
    		if ( m_CustomChildrenHighIQ && m_CustomChildrenHighIQ.Count() > 0 )
    		{
    			int index = Math.RandomIntInclusive( 0, m_CustomChildrenHighIQ.Count() - 1 );
    			ref Widget toRemove = m_CustomChildrenHighIQ[ index ];
    			if ( toRemove )
    			{
    				toRemove.Unlink();
    				m_CustomChildrenHighIQ.Remove( index );
    			}
    		}
    		break;
    	}
        return super.OnClick(w, x, y, button);
    }

    //Called by WidgetEventHandler that is registered at line 70 ( more of these examples can be found in vanilla scripts / menus creates by devs )
    void OnDoubleClicked(Widget w, int x, int y, int button) 
    {
        if (button == MouseState.LEFT)
        {
            //Do something
        }
        else if (button == MouseState.RIGHT)
        {
            //Do something
        }
    }

    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 0.5 );
        else
            PPEffects.SetBlurMenu( 0 );
    }
};