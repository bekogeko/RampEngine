#include <Ramp.h>


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
			RMP_DEBUG("TAB IS PRESSED");
		
		
	}

	void OnEvent(Ramp::Event& ev) override
	{

	}

};

class Sandbox : public Ramp::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ramp::ImGuiLayer());
	}
	~Sandbox()
	{
		RMP_DEBUG("Sandbox PUBG");
	}

private:

};

Ramp::Application* Ramp::CreateApplication()
{
	return new Sandbox();
}