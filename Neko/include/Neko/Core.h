#pragma once

#ifdef NEKO_PLATFORM_WINDOWS
    #ifdef DLL_EXPORT
        #define NEKO_API _declspec(dllexport)
    #else
        #define NEKO_API _declspec(dllimport)
    #endif
#else
    #define NEKO_API 
#endif