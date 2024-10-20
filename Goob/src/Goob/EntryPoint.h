#pragma once

#ifdef GB_PLATFORM_WINDOWS

extern Goob::Application* Goob::CreateApplication();

int main(int argc, char** argv)
{
	Goob::Log::Init();
	GOOB_CORE_WARN("Initialized Goob");
	GOOB_INFO("Hello! Var={0}", 5);
	GOOB_FATAL("I AM A FATAL ERROR");
	GOOB_ERROR("I am an error");

	printf("Goob Engine Starting");
	auto app = Goob::CreateApplication();
	app->Run();
	delete app;
}

#endif