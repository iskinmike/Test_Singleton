// Singleton1.h
class singleton
{
public:
	static singleton* instance() {
		static singleton inst;
		return &inst;
	};
	//CRITICAL_SECTION c_cs;
	int sinVar;
	int *psv=&sinVar;

	void initSinVar(){
		sinVar = 0;
	};
	void increaseSinVar(){
		sinVar++;
	};

private: // Запрещаем
	singleton() {
		//sinVar = 0;
		//psv = &sinVar;
	}; // конструктор
	~singleton() {}; // и деструктор

	// необходимо также запретить копирование
	singleton(singleton const&); // реализация не нужна
	singleton& operator= (singleton const&);  // и тут

};
/*

extern "C" {
	__declspec(dllexport) singleton* getFunctionModuleObject();
	__declspec(dllexport) void getIntoCS();
	__declspec(dllexport) void getOutCS();
}

*/

extern "C" {
	__declspec(dllexport) singleton* getFunctionModuleObject();
}
extern "C" {

	__declspec(dllexport) void getIntoCS();
}
extern "C" {

	__declspec(dllexport) void getOutCS();
}
extern "C" {

	__declspec(dllexport) void initCS();
}
extern "C" {
	__declspec(dllexport) int *getG_Var();
}
