#include <Coffee.h>

class Sandbox : public Coffee::Application
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

Coffee::Application* Coffee::CreateApplication()
{
	return new Sandbox();
}