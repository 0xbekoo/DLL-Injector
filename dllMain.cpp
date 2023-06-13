#include <windows.h>

BOOL WINAPI DllMain(
    HINSTANCE hModule,
    DWORD fdwReason,
    LPVOID lpvReserved
) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        MessageBoxW(NULL, L"DLL Injected!", L"BUFFFFFF!", 0X040L | 0x00L);
        break;
    }
    return TRUE;
}