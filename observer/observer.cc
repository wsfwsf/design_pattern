#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
	Observer() {}
	~Observer() {}
	virtual void run() = 0;
};

class Subject{
	public:
		Subject(){}
		void add(Observer* pobserver){
			Observer_list.push_back(pobserver);
		}
		void call(){
			for(auto p:Observer_list){
				p->run();
			}
		}
	private:
		vector<Observer*> Observer_list;
};

class Observer1:public Observer{
	public:
		Observer1(){}
		~Observer1(){}
		virtual void run(){
			cout<<"observer1 run()"<<endl;
		}
};


class Observer2:public Observer{
	public:
		Observer2(){}
		~Observer2(){}
		virtual void run(){
			cout<<"observer2 run()"<<endl;
		}
};

int main(){
	Observer1 *observer11 = new Observer1();
	Observer1 *observer12 = new Observer1();
	Observer2 *observer21 = new Observer2();
	Observer2 *observer22 = new Observer2();

	Subject *sub = new Subject();
	sub->add(observer11);
	sub->add(observer12);
	sub->add(observer21);
	sub->add(observer22);

	sub->call();

	return 0;
}
