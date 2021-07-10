workspace "Coffee"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Coffee/vendor/GLFW/include"
IncludeDir["Glad"] = "Coffee/vendor/Glad/include"
IncludeDir["ImGui"] = "Coffee/vendor/ImGui"
IncludeDir["glm"] = "Coffee/vendor/glm"

include "Coffee/vendor/GLFW"
include "Coffee/vendor/Glad"
include "Coffee/vendor/ImGui"

project "Coffee"
	location "Coffee"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "cfpch.h"
	pchsource "Coffee/src/cfpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CF_PLATFORM_WINDOWS",
			"CF_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "CF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CF_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Coffee/vendor/spdlog/include",
		"Coffee/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Coffee"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CF_DIST"
		runtime "Release"
		optimize "On"
