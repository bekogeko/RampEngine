#pragma once
#include "Core.h"

namespace Ramp
{
	class RAMP_API Application
	{ 
	public:
		Application(); 
		virtual ~Application();
		void Run();
	};

	//To be Defined in client
	Application* CreateApplication();



}
