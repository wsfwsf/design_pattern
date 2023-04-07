#include <iostream>
#include <string>

using namespace std;

class Target{
	public:
		virtual void request()=0;
};

class Adaptee{
	public:
		void specificRequest(){
			cout<<"Adaptee::specificRequest"<<endl;
		}
};

class Adapter:public Target{
	public:
		Adapter(Adaptee* adaptee):m_adaptee(adaptee){}
		virtual void request(){
			m_adaptee->specificRequest();
		}
	private:
		Adaptee* m_adaptee;
};

int main(){
	Adaptee* adaptee = new Adaptee();
	Target* target = new Adapter(adaptee);
	target->request();
	delete target;
	delete adaptee;

	return 0;
}
