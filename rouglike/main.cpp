#include <iostream>
#include <thread>
#include <windows.h>
#include "headers/globals.h"
#include "headers/inputHandler.h"

using namespace std;


int main()
{
    thread inputThread(Input);
    while (ProgramOpenState) {
        Sleep(500);
    }
    inputThread.detach();
    return 0;
}
