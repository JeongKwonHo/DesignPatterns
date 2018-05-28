/**
	@file	DynamicSingleton.cpp
	@date	2018-5-24
	@author	JeongKwonHo(jkh2802@gmail.com)
	@brief	Dynamic Singleton using atexit
	
*/

#include <iostream>

class Singleton
{
private:
	static Singleton* instance;

private:
	Singleton() {};
	Singleton(const Singleton& other);
	~Singleton() {};
	
public:
	static Singleton* getInstance()
	{
		if (!instance) {
			instance = new Singleton;
			atexit(release_instance);
		}
		return instance;
	}
	static void release_instance() {
		if (instance) {
			delete instance;
			instance = nullptr;
			
		}
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton* s = Singleton::getInstance();
	Singleton* r = Singleton::getInstance();

	std::cout << s << std::endl;
	std::cout << r << std::endl;


	return 0;
}
