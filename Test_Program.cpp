#define _CRT_SECURE_NO_WARNINGS

#include "Singleton1.h"

#include <iostream>
#include <windows.h> 
#include <fstream>
#include <stdio.h>

//#include <stdlib.h>

//Singleton* Singleton::p_instance = 0;

using namespace std;
//CRITICAL_SECTION g_cs;

int main(){

	std::cout << "Works!!!" << std::endl;

	singleton *FirstObject;

	FirstObject = getFunctionModuleObject();

	FILE *fil;

	/*
	fil = fopen("D:\SingTest1.txt","a");
	fprintf(fil,"%d",1);
	fclose(fil);
	*/

	std::cout << "Address: " << FirstObject << std::endl;

	ofstream out("test.txt");

	if (!out){
		cout << "don't work" << endl;
		return 1;
	};

	out << FirstObject << " 1 " << endl;
	Sleep(1000);
	//ofstream f("test");
	//fstream File;
	//File.open("D:\ProcINf.txt", ios::app);

	//Sleep(1000);
	//File << "Singleton: " << FirstObject;
	
	//initCS();

	FirstObject->initSinVar();
	
	int *temp=NULL;
	//getIntoCS();
	for (int i = 0; i < 10; i++){
		//Sleep(1000);
		//getIntoCS();
		//Sleep(2000);
		//Sleep(2000);
		FirstObject = getFunctionModuleObject();
		FirstObject->increaseSinVar();
		temp = FirstObject->psv;
		(*temp)++;
		out << "Address: " << FirstObject->sinVar << "  ---- " << FirstObject->psv << " " << *temp << endl;
		std::cout << "Address: " << FirstObject->sinVar << " " << FirstObject->psv << " " << *temp << std::endl;
		// << FirstObject->psv 
		//////////////////////////////////////////////////////
		fil = fopen("D:\SingTest1.txt", "a");
		Sleep(1000);
		fprintf(fil, "%d", FirstObject->sinVar);
		fprintf(fil, "%c", ' ');
		fclose(fil);
		/////////////////////////////////////////////////////
		//getOutCS();
	};
	//getOutCS();
	out.close();
	return 0;
}
