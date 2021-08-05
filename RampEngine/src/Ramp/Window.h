#pragma once

#include "rmppch.h"

#include "Ramp\Core.h"
#include "Ramp\Events\Event.h"

namespace Ramp
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		

		WindowProps(const std::string& title = "Ramp Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}

	};


	class RAMP_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;
		
		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
	

		//Window Attributes
		virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync()const = 0;

		static Window* Create(const WindowProps& props = WindowProps());





	};



}
