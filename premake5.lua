workspace "FruitNinja"
    architecture "x64"

    configurations 
    {
        "Debug", 
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

    project "FruitNinja"
        location "FruitNinja"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"

        targetdir("bin/" ..outputdir.. "/%{prj.name}")
        objdir("bin-int/" ..outputdir.. "/%{prj.name}")

        pchheader "pch.h"
        pchsource "FruitNinja/src/Game/pch.cpp"

        files 
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        defines
        {
            "_CRT_SECURE_NO_WARNINGS"
        }

        includedirs
        {
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "configurations:Debug"
            defines "FN_DEBUG"
            buildoptions "/MDd"
            symbols "On"
        
        filter "configurations:Release"
            defines "FN_RELEASE"
            buildoptions "/MD"
            optimize "On"