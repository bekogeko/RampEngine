#pragma once
#include "rmppch.h"
#include "Application.h"

#include "Ramp/Log.h"
#include "Ramp/Events/ApplicationEvent.h"
#include "Ramp/Events/MouseEvent.h"

#include "input.h"

#include <Glad\glad.h>



namespace Ramp
{
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		RMP_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));


		m_ImGuiLayer = new ImGuiLayer();

		PushLayer(m_ImGuiLayer);
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}


	void Application::OnEvent(Event& e)
	{

		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));



		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}


	}


	void Application::Run()
	{
		//bool as = glfwWindowShouldClose((GLFWwindow)m_Window);
		while (m_Running)
		{

			glClearColor(0.12f, 0.27f, 0.27f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();


			m_Window->OnUpdate();

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}