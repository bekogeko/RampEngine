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
		//RMP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ramp::Event& ev) override
	{

		RMP_TRACE("{0}", ev.ToString());
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
	}

private:

};

Ramp::Application* Ramp::CreateApplication()
{
	return new Sandbox();
}