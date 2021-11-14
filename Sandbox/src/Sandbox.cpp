#include <Ramp.h>

//
//class ExampleLayer : public Ramp::Layer
//{
//public:
//	ExampleLayer()
//		: Layer("Example")
//	{
//	}
//
//	void OnUpdate() override
//	{
//
//		
//		
//	}
//
//	void OnEvent(Ramp::Event& ev) override
//	{
//
//	}
//
//};

class Sandbox : public Ramp::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
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