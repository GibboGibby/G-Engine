#pragma once

#ifdef GB_PLATFORM_WINDOWS

extern Goob::Application* Goob::CreateApplication();

int main(int argc, char** argv)
{
	Goob::Log::Init();
	GB_CORE_WARN("Initialized Goob");
	GB_INFO("Hello! Var={0}", 5);

	printf("Goob Engine Starting");
	auto app = Goob::CreateApplication();
	app->Run();
	delete app;
}

#endif