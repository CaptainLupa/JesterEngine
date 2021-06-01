workspace "JesterEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "JesterEngine"
	location "JesterEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name} ")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/ThirdPartyLibs/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"JS_DLL_BUILD",
			"JS_PLATFORM_WINDOWS"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/MR.0/")
		}

	filter "configurations:Debug"
		defines "JS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JS_DIST"
		optimize "On"


project "MR.0"
	location "JesterEngine"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name} ")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"JesterEngine/ThirdPartyLibs/spdlog/include",
		"JesterEngine/src"
	}

	links { "JesterEngine" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"JS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "JS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JS_DIST"
		optimize "On"
	