outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "RampEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

include "RampEngine/vendor/GLFW"


IncludeDir = {}
--IncludeDir["GLFW"] = "RampEngine/vendor/GLFW/include"




project "RampEngine"
	location "RampEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "rmppch.h"
	pchsource "RampEngine/src/rmppch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/GLFW/include/"
	}
	--RampEngine\vendor\GLFW\bin\Debug-windows-x86_64\GLFW\GLFW.lib
	links{
		"opengl32.lib",
		"GLFW"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS",
			"RMP_BUILD_DLL",
			"RMP_ENABLE_ASSERTS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "RMP_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"RampEngine/vendor/spdlog/include",
		"RampEngine/src"
	}

	links{
		"RampEngine"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "RMP_DIST"
		optimize "On"