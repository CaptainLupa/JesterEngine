#pragma once

#include "Core.h"

namespace Jester {
	class JESTER_API Application { 
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in Client
	Application* CreateApplication();
}