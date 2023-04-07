#include <iostream>
using namespace std;

class IDBConnection{};
class IDBCommand{};
class IDBReader{};

class Factory{
	public:
		virtual IDBConnection* createDBConnection()=0;
		virtual IDBCommand* createDBCommand()=0;
		virtual IDBReader* createReader()=0;
};

class sqlConnection:public IDBConnection{};
class sqlCommand:public IDBCommand{};
class sqlReader:public IDBReader{};

class oricleConnection:public IDBConnection{};
class oricleCommand:public IDBCommand{};
class oricleReader:public  IDBReader{};

class sqlFactory:public Factory{
	public:
		virtual IDBConnection* createDBConnection(){
			return new sqlConnection();
		}
		virtual IDBCommand* createDBCommand(){
			return new sqlCommand();
		}
		virtual IDBReader* createReader(){
			return new sqlReader();
		}
};

class oricleFactory:public Factory{
	public:
		virtual IDBConnection* createDBConnection(){
			return new oricleConnection();
		}
		virtual IDBCommand* createDBCommand(){
			return new oricleCommand();
		}
		virtual IDBReader* createReader(){
			return new oricleReader();
		}
};

int main(){
	Factory* factory = new sqlFactory();
	IDBConnection* connection = factory->createDBConnection();
	IDBCommand* command = factory->createDBCommand();
	IDBReader* reader = factory->createReader();
	return 0;
}
