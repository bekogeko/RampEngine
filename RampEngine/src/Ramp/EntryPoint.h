#pragma once

#ifdef RMP_PLATFORM_WINDOWS

extern Ramp::Application* Ramp::CreateApplication();

int main(int argc, char** argv)
{
	Ramp::Log::Init();

	RMP_CORE_WARN("Initialized Log!");
	RMP_INFO("HUGULU MUGULU");


	auto app = Ramp::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error Ramp Engine only support Windows
#endif