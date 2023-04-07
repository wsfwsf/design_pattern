#include <iostream>
using namespace std;

class Software{
	public:
		virtual void run()=0;
};

class SoftwareGame:public Software{
	public:
		void run(){
			cout<<"Game software"<<endl;
		}
};

class SoftwareNote:public Software{
	public:
		void run(){
			cout<<"Note software"<<endl;
		}
};

class Computer{
	public:
		Computer():m_software(nullptr){}
		virtual ~Computer(){
			if(nullptr==m_software) delete m_software;
		}
		virtual void run()=0;
		void setSoftware(Software* p){
			m_software=p;
		}
	protected:
		Software* m_software;
};

class ComputerLenovo:public Computer{
	public:
		void run(){
			cout<<"Lenovo computer running...."<<endl;
			m_software->run();
		}
};

class ComputerMicro:public Computer{
	public:
		void run(){
			cout<<"micro computer running...."<<endl;
			m_software->run();
		}
};

int main(){
	Computer* p = new ComputerLenovo();
	p->setSoftware(new SoftwareGame());
	p->run();
	delete p;

	p=new ComputerMicro();
	p->setSoftware(new SoftwareNote());
	p->run();
	delete p;

	return 0;
}
