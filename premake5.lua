outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "RampEngine"
	architecture "x64"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"

include "RampEngine/vendor/GLFW"
include "RampEngine/vendor/Glad"
include "RampEngine/vendor/imgui"


IncludeDir = {}
IncludeDir["GLFW"] = "RampEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "RampEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "RampEngine/vendor/imgui"



project "RampEngine" 
	location "RampEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rmppch.h"
	pchsource "RampEngine/src/rmppch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	--RampEngine\vendor\GLFW\bin\Debug-windows-x86_64\GLFW\GLFW.lib
	links{
		
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS",
			"RMP_BUILD_DLL",
			"RMP_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "RMP_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

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
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "RMP_DIST"
		runtime "Release"
		optimize "On"