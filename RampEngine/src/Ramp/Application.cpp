#pragma once
#include "rmppch.h"
#include "Application.h"

#include "Ramp/Log.h"
#include "Ramp/Events/ApplicationEvent.h"
#include "Ramp/Events/MouseEvent.h"

#include<GLFW\glfw3.h>

namespace Ramp
{
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)


	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
	}

	
	
	void Application::OnEvent(Event& e)
	{
		RMP_CORE_INFO(" {0} ", e.ToString());
	}
	
	
	
	Application::~Application()
	{

	}

	void Application::Run()
	{
		//WindowResizeEvent e(1280,720);// evet biliyom yil 2021 ama hala 720 p ekran acanlar var evet olabilir cokda yargilamamak lazim
		//MouseMovedEvent ms_e(10,30
		//RMP_CORE_FATAL(e.ToString());//hipito hopito bu olayi benim saheser fonksiyonum birazdan ekrana yazdiriyo
		//RMP_CORE_FATAL(ms_e.ToString());//hipito hopito bu olayi benim saheser fonksiyonum birazdan ekrana yazdiriyo
		////RMP_CORE_TRACE("SLM CNM");//hipito hopito bu olayi benim saheser fonksiyonum birazdan ekrana yazdiriyo

		//bool as = glfwWindowShouldClose((GLFWwindow)m_Window);
		while (m_Running)
		{

			glClearColor(0,1,1,1);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window->OnUpdate();

		}
	}
}