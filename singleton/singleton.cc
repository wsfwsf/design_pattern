#include <iostream>
using namespace std;


//not thread safe
class singletom{
	private:
		singleton(){}
		singleton(const singleton& other){}
		static singleton* m_instance;
	public:
		static singleton* getinstance(){
			if(m_instance==nullptr){
				m_instance = new singleton();
			}
			return m_instance;
		}
};

singleton* singleton::m_instance=nullptr;


