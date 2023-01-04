workspace "MarkdownParser"
    configurations { "Debug", "Release"}

    project "MarkdownParser__Header"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
        files { "MarkdownParser.hpp", "main.cpp" }
        -- includedirs { "include" }
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
        filter "configurations:Release"
            defines { "RELEASE" }
            optimize "On"
        filter {}
        targetdir "bin/%{cfg.buildcfg}/"
