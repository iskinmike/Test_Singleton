// Singleton1.h Синглтон Майерса
class singleton
{
public:
	static singleton* instance() {
		static singleton inst;
		return &inst;
	}
private: // Запрещаем
	singleton() {}; // конструктор
	~singleton() {}; // и деструктор

	// необходимо также запретить копирование
	singleton(singleton const&); 
	singleton& operator= (singleton const&); 
};

extern "C" {
	__declspec(dllexport) singleton* getFunctionModuleObject();
}
