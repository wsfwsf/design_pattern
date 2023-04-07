#include <iostream>
#include <vector>

using namespace std;

class Strategy{
	public:
		Strategy(){}
		virtual ~Strategy(){}
		virtual void algorithm()=0;
};

class ConcreteStrategyA:public  Strategy{
	public:
		ConcreteStrategyA(){}
		virtual ~ConcreteStrategyA(){}
		virtual void algorithm(){
			cout<<"Use algorithm A"<<endl;
		}
};

class ConcreteStrategyB:public Strategy{
	public:
		ConcreteStrategyB(){}
		virtual ~ConcreteStrategyB(){}
		virtual void algorithm(){
			cout<<"Use algorithm B"<<endl;
		}
};

class Context{
	public:
		Context(){}
		virtual ~Context(){}
		void algorithm(){
			strategy->algorithm();
		}
		void setStrategy(Strategy* st){
			strategy=st;
		}
	private:
		Strategy* strategy;
};

int main(){
	ConcreteStrategyA* s1 = new ConcreteStrategyA();
	Context* ctx = new Context();
	ctx->setStrategy(s1);
	ctx->algorithm();

	
	Strategy* s2 = new ConcreteStrategyB();
	ctx->setStrategy(s2);
	ctx->algorithm();

	delete s1;
	delete s2;
	delete ctx;
	
	return 0;
}
