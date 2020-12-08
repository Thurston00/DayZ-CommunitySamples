//config.cpp for your custom sounds

class CfgPatches
{
	class Source_Car_Sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Sounds_Effects"};
	};
};
class CfgSoundShaders
{
	class base_Source_Car_horn_SoundShader
	{
		range=150;
	};
	class Source_Car_horn_EXT_SoundShader: base_Source_Car_horn_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\horn_EXT",
				1
			}
		};
		volume=1;
	};
	class Source_Car_horn_INT_SoundShader: base_Source_Car_horn_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\horn_INT",
				1
			}
		};
		volume=1;
	};
	class baseEngineSource_Car_SoundShader
	{
		range=80;
	};
	class Source_Car_Engine_Ext_Rpm0_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm0",
				1
			}
		};
		frequency="0.95 * ((850 + ((rpm - 850)/(8000/5600))) max 850) / 850";
		volume="0.75 * 1 * engineOn * 0.4 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) + 2.5*50),(((850+1200)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Rpm1_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm1",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume="0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Offload_Rpm1",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume="0.75 * 1 * (thrust factor[0.6,0.2]) * 0.8 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Rpm2_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm2",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume="0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Offload_Rpm2",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume="0.75 * 1 * (thrust factor[0.6,0.2]) * 0.8 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Rpm3_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm3",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume="0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3250)/2) + 2.5*200),(((2300+3250)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Offload_Rpm3",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume="0.75 * 1 * (thrust factor[0.6,0.2]) * 0.8 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3250)/2) + 2.5*200),(((2300+3250)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Rpm4_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm4",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 3250";
		volume="0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3250)/2) - 2.5*200),(((2300+3250)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) + 2.5*200),(((3250+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Offload_Rpm4",
				1
			}
		};
		frequency="0.95 * (850 + ((rpm - 850)/(8000/5600))) / 3250";
		volume="0.75 * 1 * (thrust factor[0.6,0.2]) * 0.8 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3250)/2) - 2.5*200),(((2300+3250)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) + 2.5*200),(((3250+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Rpm5_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Rpm5",
				1
			}
		};
		frequency="(0.95 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume="0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Offload_Rpm5",
				1
			}
		};
		frequency="(0.95 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume="0.75 * 1 * (thrust factor[0.6,0.2]) * 0.8 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class Source_Car_Engine_Ext_Broken_SoundShader: baseEngineSource_Car_SoundShader
	{
		samples[]=
		{
			
			{
				"\Source_Car\sounds\sc_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.99999998;
		volume="0.75 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[4800,6200])";
	};
	
};
class CfgSoundSets
{
	class base_Source_Car_horn_SoundSet
	{
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class Source_Car_horn_EXT_SoundSet: base_Source_Car_horn_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_horn_EXT_SoundShader"
		};
		frequencyRandomizer=0;
		volumeRandomizer=0;
	};
	class Source_Car_horn_INT_SoundSet: base_Source_Car_horn_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_horn_INT_SoundShader"
		};
		frequencyRandomizer=0;
		volumeRandomizer=0;
	};
	class baseEngine_EXT_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		occlusionFactor=0;
		obstructionFactor=0;
		spatial=1;
		loop=1;
		positionOffset[]={0,0,0.30000001};
	};
	class Source_Car_Engine_Ext_Rpm0_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm0_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm1_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Offload_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Offload_Ext_Rpm1_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm2_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Offload_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Offload_Ext_Rpm2_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm3_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Offload_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Offload_Ext_Rpm3_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm4_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Offload_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Offload_Ext_Rpm4_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Rpm5_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Offload_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Offload_Ext_Rpm5_SoundShader"
		};
		volumeFactor=1.2;
	};
	class Source_Car_Engine_Ext_Broken_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Source_Car_Engine_Ext_Broken_SoundShader"
		};
		volumeFactor=1.6;
	};
};