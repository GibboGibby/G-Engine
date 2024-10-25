-- premake5.lua

workspace "Goob"
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
IncludeDir["GLFW"] = "Goob/vendor/GLFW/include"

include "Goob/vendor/GLFW"

project "Goob"
   location "Goob"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   pchheader "gbpch.h"
   pchsource "Goob/src/gbpch.cpp"

   files
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs
   {
      "%{prj.name}/src",
      "Goob/vendor/spdlog/include",
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
         "GB_PLATFORM_WINDOWS",
         "GB_BUILD_DLL"
      }

      postbuildcommands
      {
         ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
      }

   filter "configurations:Debug"
      defines "GB_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "GB_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "GB_DIST"
      optimize "On"


project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"

   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs
   {
      "Goob/src",
      "Goob/vendor/spdlog/include"
   }

   links
   {
      "Goob"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
         "GB_PLATFORM_WINDOWS"
      }

   filter "configurations:Debug"
      defines "GB_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "GB_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "GB_DIST"
      optimize "On"