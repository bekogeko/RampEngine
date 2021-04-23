#pragma once
#include "Application.h"

#include "Ramp/Log.h"
#include "Ramp/Events/ApplicationEvent.h"


namespace Ramp
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280,720);// evet biliyom yil 2021 ama hala 720 p ekran acanlar var evet olabilir cokda yargilamamak lazim

		RMP_CORE_TRACE(e.ToString());//hipito hopito bu olayi benim saheser fonksiyonum birazdan ekrana yazdiriyo
		//RMP_CORE_TRACE("SLM CNM");//hipito hopito bu olayi benim saheser fonksiyonum birazdan ekrana yazdiriyo

		while (true);
	}
}