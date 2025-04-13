#include <Windows.h>
#include <stdio.h>
#include <string>

#include "objInfo.hpp"

float EXPORT GetNumVertices(char* pathFromZBrush,
    [[maybe_unused]] double valueFromZBrush,
    [[maybe_unused]] char* pOptBuffer1,
    [[maybe_unused]] int optBuffer1Size,
    [[maybe_unused]] char* pOptBuffer2,
    [[maybe_unused]] int optBuffer2Size,
    [[maybe_unused]] char** zData)
{
    static const char* prefix_v = "v ";
    errno_t err;

    FILE* fp;
    err = fopen_s(&fp, pathFromZBrush, "r");

    const int column = 256;
    char str[column];
    int numVerts = 0;

    if (err != 0) {
        OutputDebugString("cannot open the file");
    } else {
        while (fgets(str, column, fp) != NULL) {
            if (strncmp(str, prefix_v, 2) == 0) {
                numVerts++;
            }
        }
        fclose(fp);
    }
    std::string numVertsStr = std::to_string(numVerts);
    OutputDebugString(numVertsStr.c_str());

    return static_cast<float>(numVerts);
}

#ifdef _WIN32
BOOL WINAPI DllMain(
    [[maybe_unused]] HINSTANCE hinstDLL,
    DWORD fdwReason,
    [[maybe_unused]] LPVOID lpvReserved)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}
#endif
