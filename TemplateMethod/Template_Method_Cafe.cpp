#include<iostream>
using namespace std;

class ICafe{
    public:
        void paso1(){
            cout<<"Calentar el agua "<<endl;
        }
        void paso2(){
            cout<<"Agregar cafe al gusto"<<endl;
        }
        void paso3(){
            cout<<"Agregar azucar al gusto"<<endl;
        }
        virtual void pasoExtra()=0;
        void paso5(){
            cout<<"Disfrutar.."<<endl;
        }
        void prepararCafe(){
            paso1();
            paso2();
            paso3();
            pasoExtra();
            paso5();
        }
};


class Cafe_Leche : public ICafe{
    public:
        Cafe_Leche(){}
        void pasoExtra(){
            cout<<"Agregar leche y mover"<<endl;
        }
};

class Cafe_Vegano : public ICafe{
    public:
        Cafe_Vegano(){}
        void pasoExtra(){
            cout<<"Agregar leche de almendras"<<endl;
        }
};

int main(){
    Cafe_Leche c1;
    Cafe_Vegano c2;
    c1.prepararCafe();
    c2.prepararCafe();

    return 0;
}