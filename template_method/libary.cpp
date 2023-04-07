#include <iostream>
#include <vector>
using namespace std;

class Libary{
	public:
		void run(){
			step1();
			step2();
			step3();
		}
		Libary(){}
	protected:
		void step1(){
			cout<<"step1()"<<endl;
		}
		void step2(){
			cout<<"step2()"<<endl;
		}
		virtual void step3()=0;
	public:
		virtual ~Libary(){}
};

class App:public Libary{
	public:
		App(){}
	protected:
		virtual void step3(){
			cout<<"App step3()"<<endl;
		}
	public:
		virtual ~App(){}
};

int main(){
	App app;
	app.run();
	return 0;
}
