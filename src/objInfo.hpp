#ifndef objInfo_hpp
#define objInfo_hpp

#ifdef _WIN32
#include <windows.h>
#define EXPORT __declspec(dllexport)
#endif

#ifdef __APPLE__
#define EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

float EXPORT GetNumVertices(char* pathFromZBrush,
                   double valueFromZBrush,
                   char* pOptBuffer1,
                   int optBuffer1Size,
                   char* pOptBuffer2,
                   int optBuffer2Size,
                   char** zData);

#ifdef __cplusplus
}
#endif

#endif /* objInfo_hpp */
