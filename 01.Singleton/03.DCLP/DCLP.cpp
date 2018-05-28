/**
  @file	DCLP.cpp
  @date	2018-05-28
  @author JeongKwonHo(jkh2802@gmail.com)
  @brief	Double-Checking Locking Singleton

*/

#include <mutex>
#include <iostream>

class Singleton
{
	private:
		static Singleton* instance;	//using voltaile 
		static std::mutex _mutex;

		Singleton() {}
		Singleton(const Singleton&){}
		~Singleton(){}

	public:
		static Singleton* getInstance()
		{
			if(instance == nullptr)
			{
				std::lock_guard<std::mutex>lock(_mutex);

				if(instance == nullptr)
					instance = new Singleton();
			}

			return instance;
		}
};
std::mutex Singleton::_mutex;
Singleton* Singleton::instance = nullptr;


int main()
{
	Singleton* s = Singleton::getInstance();
	Singleton* r = Singleton::getInstance();

	std::cout<<s<<std::endl;

	std::cout<<r<<std::endl;

	return 0;
}
