#include <Ramp.h>

//#include "imgui/imgui.h"

class ExampleLayer : public Ramp::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Ramp::Input::isKeyPressed(RMP_KEY_TAB))
			RMP_LOG("TAB IS PRESSED");
		
		
	}

	/*virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}*/


};

class Sandbox : public Ramp::Application
{
public:
	Sandbox()
	{

		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}

private:

};

Ramp::Application* Ramp::CreateApplication()
{
	return new Sandbox();
}