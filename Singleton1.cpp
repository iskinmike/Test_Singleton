
#include "Singleton1.h"

#include <iostream>
#include <Windows.h>

CRITICAL_SECTION g_cs;
//using namespace std;
PCRITICAL_SECTION pcs;
//pcs = &g_cs;

//int InitializeCriticalSection(pcs);
int g_var;

__declspec(dllexport) singleton *getFunctionModuleObject() {
	//InitializeCriticalSection(&g_cs);
	singleton *TempObj;
	TempObj = singleton::instance();
	return TempObj;	
};

__declspec(dllexport) void getIntoCS() {
	std::cout << "Enter Critical Section "  << std::endl;
	EnterCriticalSection(&g_cs);
	std::cout << "Enter Critical Section" << std::endl ;
};

__declspec(dllexport) void getOutCS() {
	std::cout << "Leave Critical Section" << std::endl;
	LeaveCriticalSection(&g_cs);
	std::cout << "Leave Critical Section" << std::endl;
};

__declspec(dllexport) void initCS() {
	std::cout << "Init Critical Section " << &g_cs << std::endl;
	InitializeCriticalSection(&g_cs);
	std::cout << "Init Critical Section" << std::endl;
};

__declspec(dllexport) int *getG_Var() {
	return &g_var;
};
