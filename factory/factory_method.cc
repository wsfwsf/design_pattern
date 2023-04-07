#include <iostream>
using namespace std;

class Product{
	public:
		virtual void show()=0;
};

class ProductA:public Product{
	public:
		void show(){
			cout<<"Product A"<<endl;
		}
};

class ProductB:public Product{
	public:
		void show(){
			cout<<"Product B"<<endl;
		}
};

class Factory{
	public:
		virtual Product* CreateProduct()=0;
};

class FactoryA :public Factory{
	public:
		Product* CreateProduct(){
			return new ProductA();
		}
};

class FactoryB:public Factory{
	public:
		Product* CreateProduct(){
			return new ProductB();
		}
};

int main(){
	Factory* factory;
	Product* product;
	
	factory = new FactoryA();
	product = factory->CreateProduct();
	product->show();

	factory = new FactoryB();
	product = factory->CreateProduct();
	product->show();

	return 0;
}
