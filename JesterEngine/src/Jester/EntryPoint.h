#pragma once

#ifdef JS_PLATFORM_WINDOWS

extern Jester::Application* Jester::CreateApplication();

int main(int argc, char** argv) {
	Jester::Log::init();
	JS_CORE_WARN("Initialized Log!");
	int a = 5;
	JS_INFO("Hello! Var={0}", a);
	auto app = Jester::CreateApplication();
	app->Run();
	delete app;
}

#endif