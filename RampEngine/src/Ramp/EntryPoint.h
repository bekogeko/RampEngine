#pragma once

#ifdef RMP_PLATFORM_WINDOWS

extern Ramp::Application* Ramp::CreateApplication();

int main(int argc, char** argv)
{
	printf("Ramp Engine");
	auto app = Ramp::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error Ramp Engine only support Windows
#endif