#include<iostream>
using namespace std;

//interfaz de la clase Abstract Factory
class IAbstractFactory{
    public:
        virtual void crearComputadora()=0;
        virtual void crearTablet()=0;
};

int main(){
    return 0;
}