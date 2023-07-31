#include<iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;
        int data;
        Singleton(){}
    public:
        static Singleton* getInstance(){
            if(instance==nullptr){
                instance=new Singleton();
            }
            return instance;
        }
        void setData(int num){
            this->data=num;
        }
        void getData()const{
            cout<<"El numero en la instancia es : "<<data<<endl;
        }
};

Singleton* Singleton::instance=nullptr;
int main(){
    Singleton *a1=Singleton::getInstance();
    a1->setData(45);
    a1->getData();
    Singleton* another=Singleton::getInstance();
    another->getData();



    return 0;
}