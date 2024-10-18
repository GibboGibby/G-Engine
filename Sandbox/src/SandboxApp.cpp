#include <Goob.h>

class Sandbox : public Goob::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};


Goob::Application* Goob::CreateApplication()
{
	return new Sandbox();
}