#include <iostream>

class Singleton
{
private:
	static Singleton* instance;

private:
	Singleton() {};
	Singleton(const Singleton& other);

public:
	static Singleton* getInstance()
	{
		if (!instance)
			instance = new Singleton;
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton* s = Singleton::getInstance();
	Singleton* r = Singleton::getInstance();

	std::cout << s << std::endl;
	std::cout << r << std::endl;

}