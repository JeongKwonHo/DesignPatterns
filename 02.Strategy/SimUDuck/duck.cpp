/*
 	@file	Duck.cpp
	@date	2018-06-02
	@author	JeongKwonHo(jkh2802@gmail.com)
	@brief	SimUDuck simulation using Strategy Pattern
*/
#include <iostream>

class FlyBehavior
{
	public:
		virtual void Fly() =0;
};

class FlyWithWings : public FlyBehavior
{
	public:
		void Fly(){
			std::cout<<"Fly~"<<std::endl;
		}
};

class FlyNoWay : public FlyBehavior
{
	public:
		void Fly(){
			std::cout<<"I can't Fly...."<<std::endl;
		}
};

class QuackBehavior{
	public:
		virtual void Quack() = 0;
};

class QuackQuack : public QuackBehavior{
	public:
		void Quack(){
			std::cout<<"Quack Quack!!"<<std::endl;
		}
};


class MuteQuack : public QuackBehavior{
	public:
		void Quack(){
			std::cout<<"..."<<std::endl;
		}
};




class Duck {

	public:
		Duck() : flyBehavior(nullptr), quackBehavior(nullptr){}
		~Duck()
		{
			if(flyBehavior !=nullptr)
			{
				delete flyBehavior;
			}

			if(quackBehavior !=nullptr)
			{
				delete quackBehavior;
			}
		}

	private:
		FlyBehavior* flyBehavior;
		QuackBehavior* quackBehavior;
	
	public:
		void Swim() {
			std::cout<<"Swiming~~"<<std::endl;
		}

		void Display(){
			std::cout<<"This is Basic Duck"<<std::endl;
		}
		void PerformFly() {
			flyBehavior->Fly();	
		}
		void PerformQuack() {
			quackBehavior->Quack();	
		}
			
		void SetFlyBehavior(FlyBehavior* temp) {
			if(flyBehavior !=nullptr)
				delete flyBehavior;
			flyBehavior = temp;
		}
		void SetQuackBehavior(QuackBehavior* temp) {
			if(quackBehavior != nullptr)
				delete quackBehavior;
			quackBehavior = temp;
		}
		
};
class MallardDuck : public Duck{
	public:
		MallardDuck(){
			SetFlyBehavior(new FlyWithWings);
			SetQuackBehavior(new QuackQuack);
		}
		~MallardDuck(){}
	public:
		void Display()
		{
			std::cout<<"I am MallardDuck!!!!!"<<std::endl;
		}
};

class RedheadDuck : public Duck{
	public:
		RedheadDuck() {
			SetFlyBehavior(new FlyNoWay);
			SetQuackBehavior(new MuteQuack);
		}
		~RedheadDuck(){}

	public:
		void Display()
		{
			std::cout<<"I am RedheadDuck...."<<std::endl;
		}
};

int main()
{
	MallardDuck MD;
	RedheadDuck RD;
	
	MD.Display();
	MD.PerformFly();
	MD.PerformQuack();
	
	std::cout<<std::endl;
	RD.Display();
	RD.PerformFly();
	RD.PerformQuack();

	return 0;

}
