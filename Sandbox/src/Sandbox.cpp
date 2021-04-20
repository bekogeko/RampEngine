#include <Ramp.h>


class Sandbox : public Ramp::Application
{
public:
	Sandbox()
	{
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