outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "RampEngine"
	architecture "x64"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"


IncludeDir = {}
IncludeDir["GLFW"] = "RampEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "RampEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "RampEngine/vendor/imgui"
IncludeDir["glm"] = "RampEngine/vendor/glm"

include "RampEngine/vendor/GLFW"
include "RampEngine/vendor/Glad"
include "RampEngine/vendor/imgui"


project "RampEngine" 
	location "RampEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rmppch.h"
	pchsource "RampEngine/src/rmppch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp", 
		"%{prj.name}/vendor/glm/glm/**.inl", 
	}

	defines{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	--RampEngine\vendor\GLFW\bin\Debug-windows-x86_64\GLFW\GLFW.lib
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}


	filter "system:windows"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS",
			"RMP_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		runtime "Debug"
		symbols "on"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		runtime "Release"
		optimize "on"
	filter "configurations:Dist"
		defines "RMP_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/"
	}

	includedirs{
		"RampEngine/vendor/spdlog/include",
		"RampEngine/src",
		"RampEngine/vendor",
		"%{IncludeDir.glm}" 
	}

	links{
		"RampEngine" 
	}


	filter "system:windows"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RMP_DEBUG"
		runtime "Debug"
		symbols "on"
	filter "configurations:Release"
		defines "RMP_RELEASE"
		runtime "Release"
		optimize "on"
	filter "configurations:Dist"
		defines "RMP_DIST"
		runtime "Release"
		optimize "on"