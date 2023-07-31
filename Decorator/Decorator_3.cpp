#include<iostream>
using namespace std;

//Primero definimos la interfaz principal interfaz=Clase abstracta
class I_Enemy{
    public:
        virtual int takeDamage()const=0;
        virtual ~I_Enemy(){}
};

//creamos la primera implementacion de enemigo concreto

class BaseEnemy:public I_Enemy{
    public:
        BaseEnemy(){}
        int takeDamage()const{
            return 100;
        }
};


//----------------------DECORADORES-----------------------  
//primero definimos una abstraccion de que es un decorador

class I_Decorator : public I_Enemy{
    protected:
        I_Enemy * enemigo;
    public:
        I_Decorator(I_Enemy * _enemigo){
            this->enemigo=_enemigo;
        }
        virtual ~I_Decorator(){}
        int takeDamage()const{
            return enemigo->takeDamage();
        }
};

//creamos el primer decorador concreto

class Casco :public I_Decorator{
    public:
        Casco(I_Enemy * enemigo):I_Decorator(enemigo){}
        int takeDamage()const{
            return 80;
        }

};





int main(){
    I_Enemy * e1=new BaseEnemy();
    I_Enemy * e_d=new Casco(e1);
    cout<<e1->takeDamage()<<endl;
    cout<<e_d->takeDamage()<<endl;
    delete e_d;
    delete e1;
    return 0;
};