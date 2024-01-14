workspace "FruitNinja"
    architecture "x64"

    configurations 
    {
        "Debug", 
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["GLFW"] = "FruitNinja/vendor/GLFW/include"
    IncludeDir["Glad"] = "FruitNinja/vendor/Glad/include"

    include "FruitNinja/vendor/Glad"
    include "FruitNinja/vendor/GLFW"

    project "FruitNinja"
        location "FruitNinja"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"

        targetdir("bin/" ..outputdir.. "/%{prj.name}")
        objdir("bin-int/" ..outputdir.. "/%{prj.name}")

        pchheader "pch.h"
        pchsource "FruitNinja/src/Game/pch.cpp"

        links
        {
            "GLFW",
		    "Glad"
        }

        files 
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        defines
        {
            "GLFW_INCLUDE_NONE",
            "_CRT_SECURE_NO_WARNINGS",
            "ENGINE_ENABLE_ASSERTS"
        }

        includedirs
        {
            "%{prj.name}/src",
            "%{prj.name}/src/Game",
            "%{prj.name}/vendor/spdlog/include",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}"
        }

        filter "configurations:Debug"
            defines "FN_DEBUG"
            buildoptions "/MDd"
            symbols "On"
        
        filter "configurations:Release"
            defines "FN_RELEASE"
            buildoptions "/MD"
            optimize "On"