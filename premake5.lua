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
    IncludeDir["glm"] = "FruitNinja/vendor/glm/glm"
    IncludeDir["assimp"] = "FruitNinja/vendor/assimp/include"
    IncludeDir["stb_image"] = "FruitNinja/vendor/stb_image"

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
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/vendor/glm/glm/*.hpp",
            "%{prj.name}/vendor/glm/glm/*.inl"
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
            "%{IncludeDir.Glad}",
            "%{IncludeDir.glm}",
            "%{IncludeDir.assimp}",
            "%{IncludeDir.stb_image}"
        }
        
        libdirs
        {
            "vendor/libs/lib"
        }

        --postbuildcommands
        --{
        --    "{COPY} vendor/libs/lib/assimp-vc143-mtd.dll bin/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}"
        --}

        filter "configurations:Debug"
            defines "FN_DEBUG"
            buildoptions "/MDd"
            symbols "On"
        
        filter "configurations:Release"
            defines "FN_RELEASE"
            buildoptions "/MD"
            optimize "On"