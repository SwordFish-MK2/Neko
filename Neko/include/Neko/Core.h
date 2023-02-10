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

#ifdef NK_ENABLE_ASSERTS
    #define NK_ASSERT(x,...){if(!(x)){NK_ERROR("Assertion Failed: {0}",__VA_ARGS__);EMBED_BREAKPOINT;}}
    #define NK_CORE_ASSERT(x,...){if(!(x)){NK_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);EMBED_BREAKPOINT;}}
#else
    #define NK_ASSERT(x,...) 
    #define NK_CORE_ASSERT(x,...)  
#endif

#define BIT(x) 1<<x