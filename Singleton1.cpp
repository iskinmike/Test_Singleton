#include "Singleton1.h"

#include <iostream>

Singleton* Singleton::p_instance = 0;

//using namespace std;

__declspec(dllexport) Singleton *getFunctionModuleObject() {
	Singleton *TempObj;
	TempObj = Singleton::getInstance();
	return TempObj;
};
