#pragma once

#include "Ramp\Layer.h"

// its looks like there is no need to include these

#include "Ramp\Events\ApplicationEvent.h"
#include "Ramp\Events\KeyEvent.h"
#include "Ramp\Events\MouseEvent.h"


namespace Ramp
{
	class RAMP_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;


		void Begin();
		void End();

	private:

		float m_Time = 0.0f;

	};
}

