#pragma once

#ifdef GB_PLATFORM_WINDOWS

extern Goob::Application* Goob::CreateApplication();

int main(int argc, char** argv)
{
	Goob::Log::Init();

	auto app = Goob::CreateApplication();
	app->Run();
	delete app;
}

#endif