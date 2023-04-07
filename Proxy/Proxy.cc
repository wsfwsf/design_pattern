#include <iostream>
#include <string>
using namespace std;

class Person{
	public:
		Person(){}
		virtual void rentHouse()=0;
		virtual ~Person(){}
};

class PersonA:public Person{
	public:
		virtual void rentHouse(){
			cout<<"PersonA rent one house!"<<endl;
		}
		
};

class Proxy:public Person{
	public:
		Proxy(Person* m_person):person(m_person){}
		void rentHouse(){
			person->rentHouse();
			cout<<"This is Proxy"<<endl;
		}
	private:
		Person* person;
};

int main(){
	Person* p = new PersonA();
	Person* proxy = new Proxy(p);
	proxy->rentHouse();

	return 0;
}
