class CfgMods
{
	class UISample
	{
		dir="UISample";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DayZ UI Sample";
		credits="DaOne";
		author="DaOne";
		authorID="420420";
		inputs="UISample/inputs.xml";
		version="Version 1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"UISample/GUI/Data/bg-footer-header.imageset",
					"UISample/GUI/Data/dz-bg-black.imageset",
					"UISample/GUI/Data/vpp_logo_main_menu.imageset"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"UISample/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"UISample/5_Mission"
				};
			};
		};
	};
};
class CfgPatches
{
	class DZM_UISample
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"RPC_Scripts"
		};
	};
};