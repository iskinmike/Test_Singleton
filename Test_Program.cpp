#include "Singleton1.h"

#include <iostream>
#include <windows.h> 
#include <fstream>

//#include <stdlib.h>

Singleton* Singleton::p_instance = 0;

using namespace std;

int main(){

	std::cout << "Works!!!" << std::endl;

	Singleton *FirstObject;

	FirstObject = getFunctionModuleObject();


	std::cout << "Address: " << FirstObject << std::endl;

	ofstream out("test.txt");

	if (!out){
		cout << "don't work" << endl;
		return 1;
	};

	out << FirstObject << " 1 " << endl;

	Sleep(1000);
	//File << "Singleton: " << FirstObject;
	for (int i = 0; i < 10; i++){
		Sleep(2000);
		FirstObject = getFunctionModuleObject();
		out << "Address: " << FirstObject << "  ---- "<< endl;
		std::cout << "Address: " << FirstObject << std::endl;
	};

	out.close();
	return 0;
}
