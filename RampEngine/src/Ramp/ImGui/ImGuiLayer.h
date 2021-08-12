#pragma once

#include "Ramp\Layer.h"

namespace Ramp
{
	class RAMP_API ImGuiLayer : public Layer 
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time =0.0f;

	};
}

