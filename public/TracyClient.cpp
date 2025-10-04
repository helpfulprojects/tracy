//
//          Tracy profiler
//         ----------------
//
// For fast integration, compile and
// link with this source file (and none
// other) in your executable (or in the
// main DLL / shared object on multi-DLL
// projects).
//

// Define TRACY_ENABLE to enable profiler.
#include "common/TracySystem.cpp"
#include "pch.h"

#ifdef TRACY_ENABLE

#  ifdef _MSC_VER
#    pragma warning( push, 0 )
#  endif

#  include "client/TracyAlloc.cpp"
#  include "client/TracyCallstack.cpp"
#  include "client/TracyDxt1.cpp"
#  include "client/TracyKCore.cpp"
#  include "client/TracyOverride.cpp"
#  include "client/TracyProfiler.cpp"
#  include "client/TracySysPower.cpp"
#  include "client/TracySysTime.cpp"
#  include "client/TracySysTrace.cpp"
#  include "client/tracy_rpmalloc.cpp"
#  include "common/TracySocket.cpp"
#  include "common/tracy_lz4.cpp"

#  ifdef TRACY_ROCPROF
#    include "client/TracyRocprof.cpp"
#  endif
#  ifdef _MSC_VER
#    pragma comment( lib, "ws2_32.lib" )
#    pragma comment( lib, "advapi32.lib" )
#    pragma comment( lib, "user32.lib" )
#    pragma warning( pop )
#  endif

#endif
