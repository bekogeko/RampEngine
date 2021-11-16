#pragma once
#include "Core.h"
#include "Window.h"
#include "Ramp/LayerStack.h"
#include "Ramp/Events/Event.h"
#include "Ramp/Events/ApplicationEvent.h"

#include "ImGui/ImGuiLayer.h"

namespace Ramp
{
	class RAMP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline	Window& GetWindow() { return *m_Window; }
		inline static	Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	//To be Defined in client
	Application* CreateApplication();



}
