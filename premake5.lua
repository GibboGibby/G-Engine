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

project "Goob"
   location "Goob"
   kind "SharedLib"
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
      "%{prj.name}/vendor/spdlog/include"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "10.0.22621.0"

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
      "Goob/vendor/spdlog/include",
      "Goob/src"
   }

   links
   {
      "Goob"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "10.0.22621.0"

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