#include <iostream>
#include<vector>
using namespace std;

class IPeleador{
    protected:
        string nombre;
        int danio;
    public:
        virtual int attack()=0;
        virtual void toString()=0;
        virtual ~IPeleador(){};
};

class Sayayin : public IPeleador{
    public:
        Sayayin(string nom,int da){
            this->nombre=nom;
            this->danio=da;
        }
        int attack(){
            return danio;
        }
        void toString(){
            cout<<"Mi nombre es : "<<nombre<<endl;
        }
};

class Human{
    protected:
        string nombre;
        int fuerza;
    public:
        Human(string nom,int f){
            this->nombre=nom;
            this->fuerza=f;
        }
        int golpear(){
            return fuerza*3;
        }
        string Saludar(){
            string s ="Hola mi nombre es : "+nombre;
            return s;
        }
};

class AdapterHuman : public IPeleador{
    protected:
        Human * humano=nullptr;
    public:
        AdapterHuman(Human * h){
            this->humano=h;
        }
        int attack(){
            return humano->golpear();
        }
        void toString(){
            cout<<humano->Saludar()<<endl;
        }
        ~AdapterHuman(){
            cout<<"eliminando humano dinamico"<<endl;
            delete humano;
        }
};

int main(){
    Sayayin * goku=new Sayayin("Goku",100);
    AdapterHuman * krillin=new AdapterHuman(new Human("Krilin",20));
    vector<IPeleador *> peleadores;
    peleadores.push_back(goku);
    peleadores.push_back(krillin);

    for (auto p : peleadores){
        p->toString();
        cout<<"mi danio es de "<<p->attack()<<endl;
    }
    delete goku;
    delete krillin;

    return 0;
}