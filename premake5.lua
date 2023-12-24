workspace "AdventOfCode2023"
    architecture "x86_64"
    startproject "Day01"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

    OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    group "Week 1"
        include "Day01"
        include "Day02"
    group ""