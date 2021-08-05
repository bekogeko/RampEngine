#pragma once

#include "Ramp\Core.h"
#include "Ramp\Log.h"
#include "Ramp\Window.h"
#include <GLFW\glfw3.h>


namespace Ramp
{
	class WindowsWindow: public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		
		inline unsigned int GetWidth()const override { return m_Data.Width; }
		inline unsigned int GetHeight()const override { return m_Data.Height; }
		
		inline void SetEventCallBack(const EventCallBackFn& callback) override { m_Data.EventCallBack = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBackFn EventCallBack;

		};

		WindowData m_Data;

	};

}