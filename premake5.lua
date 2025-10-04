project "tracy"
	kind "StaticLib"
	language "C++"
	cppdialect "C++11"
	staticruntime "on" 

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		-- Tracy public headers
      "public/tracy/TracyC.h",
      "public/tracy/Tracy.hpp",
      "public/tracy/TracyCUDA.hpp",
      "public/tracy/TracyD3D11.hpp",
      "public/tracy/TracyD3D12.hpp",
      "public/tracy/TracyLua.hpp",
      "public/tracy/TracyMetal.hmm",
      "public/tracy/TracyOpenCL.hpp",
      "public/tracy/TracyOpenGL.hpp",
      "public/tracy/TracyVulkan.hpp",

      -- Tracy client headers
      "public/client/**.h",
      "public/client/**.hpp",

      -- Tracy common headers
      "public/common/**.h",
      "public/common/**.hpp",

      -- Tracy client source
      "public/TracyClient.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		links { "ws2_32", "dbghelp" }
	filter "configurations:Debug"
		runtime "Debug"
		defines { "TRACY_ENABLE" }
		symbols "on"
	filter "configurations:Release"
		runtime "Release"
		optimize "on"