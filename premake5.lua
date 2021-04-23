workspace "RampEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.arcgitecture}"

project "RampEngine"
	location "RampEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RMP_PLATFORM_WINDOWS",
			"RMP_BUILD_DLL"
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