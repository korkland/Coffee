workspace "Coffee"
    architecture "x64"
    
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

include "Coffee/vendor/GLFW"

project "Coffee"
    location "Coffee"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir  .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir  .. "/%{prj.name}")
    
    pchheader "cfpch.h"
    pchsource "Coffee/src/cfpch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }
    
    links
    {
        "GLFW",
        "opengl32.lib"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "CF_PLATFORM_WINDOWS",
            "CF_BUILD_DLL"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "CF_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CF_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CF_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir  .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir  .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Coffee/vendor/spdlog/include",
        "Coffee/src"
    }
    
    links
    {
        "Coffee"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "CF_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "CF_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CF_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CF_DIST"
        optimize "On"
    