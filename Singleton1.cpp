#include "Singleton1.h"
#include <iostream>

__declspec(dllexport) singleton *getFunctionModuleObject() {
	singleton *TempObj;
	TempObj = singleton::instance();
	return TempObj;
};

