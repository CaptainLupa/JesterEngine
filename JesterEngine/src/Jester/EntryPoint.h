#pragma once

#ifdef JS_PLATFORM_WINDOWS

extern Jester::Application* Jester::CreateApplication();

int main(int argc, char** argv) {
	printf("Jester Engine!");
	auto app = Jester::CreateApplication();
	app->Run();
	delete app;
}

#endif