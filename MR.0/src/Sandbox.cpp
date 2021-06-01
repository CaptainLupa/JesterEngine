#include <Jester.h>

class Sandbox: public Jester::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


Jester::Application* Jester::CreateApplication() {
	return new Sandbox();
}