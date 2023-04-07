#include <iostream>
using namespace std;

class Stream{
	public:
		Stream(){}
		virtual char read(int number)=0;
		virtual void seek(int pos)=0;
		virtual void write(char ch)=0;
		virtual ~Stream(){}
};

class FileStream:public Stream{
	public:
		FileStream(){}
		virtual char read(int number){
			cout<<"FileStream read"<<endl;
			return (char)0;
		}
		virtual void seek(int pos){
			cout<<"FileStream seek"<<endl;
		}
		virtual void write(char ch){
			cout<<"FileStream write"<<endl;
		}
};

class NetworkStream:public Stream{
	public:
		NetworkStream(){}
		virtual char read(int pos){
			cout<<"NetworkStream read"<<endl;
			return (char)0;
		}
		virtual void seek(int pos){
			cout<<"NetworkStream seek"<<endl;
		}
		virtual void write(char ch){
			cout<<"NetworkStream write"<<endl;
		}
};

class Decorator:public Stream{
public:
	Decorator(Stream* pstream):stream(pstream){}
	virtual char read(int pos){
		cout<<"before read"<<endl;
		stream->read(0);
		cout<<"behind read"<<endl;
		return (char)0;
	}
	virtual void seek(int pos){
		cout<<"before seek"<<endl;
		stream->seek(0);
		cout<<"behind seek"<<endl;
	}
	virtual void write(char ch){
		cout<<"before write"<<endl;
		stream->write('\0');
		cout<<"behind write"<<endl;
	}
private:
	Stream* stream;
};


int main(){
	FileStream* fstream = new FileStream();
	NetworkStream* nstream = new NetworkStream();

	Decorator* fdecorator = new Decorator(fstream);
	fdecorator->read(0);
	cout<<endl;
	fdecorator->seek(0);
	cout<<endl;
	fdecorator->write('\0');
	cout<<endl;
	cout<<endl;

	Decorator* ndecorator = new Decorator(nstream);
	ndecorator->read(0);
	cout<<endl;
	ndecorator->seek(0);
	cout<<endl;
	ndecorator->write('\0');

	return 0;
}
