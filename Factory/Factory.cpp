#include<iostream>
using namespace std ;

//clase que utilizara la fabrica
class Pizza{
    private:
        int rebanadas;
        string especialidad;
    public:
        Pizza(int rbnds, string esp){
            this->rebanadas=rbnds;
            this->especialidad=esp;
        }
        ~Pizza(){}
        void toString()const{
            cout<<"Cantidad de rebanadas : "<<rebanadas<<" Especialidad : "<<especialidad<<endl;
        }
};

//interfaz o clase abstracta de la fabrica
class IPizzeria{
    public:
        virtual Pizza* crearPizza(string)=0;
        ~IPizzeria(){};
};

//clase fabrica 
class PizzeriaCF:public IPizzeria{
    public:
        Pizza* crearPizza(string tipo){
            if(tipo=="Peperoni"){
                return new Pizza(8,"Peperoni");
            }
            else if(tipo=="Hawaiana"){
                return new Pizza(8,"Hawaiana");

            }
            else{
                return NULL;
            }
        }
};

int main(){
    PizzeriaCF cf;
    Pizza ** listaPizzas=new Pizza * [2];

    listaPizzas[0]=cf.crearPizza("Peperoni");
    listaPizzas[1]=cf.crearPizza("Hawaiana");

    listaPizzas[0]->toString();
    listaPizzas[1]->toString();

    for(int i=0;i<2;i++){
        delete listaPizzas[i];
    }

    delete [] listaPizzas;




    return 0;
}