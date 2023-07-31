#include<iostream>
using namespace std;


class ICampeon{
    protected:
        float vida;
    public:
        virtual void takeDamage(int)=0;
        virtual void VidaActual()const=0;
        float getVida()const{return vida;}
        void setVida(float n_vida){this->vida=n_vida;}
        virtual ~ICampeon(){};
};


class CampeonConcreto : public ICampeon{
    public:
        CampeonConcreto(float _vida){
            this->vida=_vida;
        }
        void takeDamage(int danio)override{
            this->vida=vida-danio;
            cout<<"Danio recibido :"<<danio<<endl;  
        }
        void VidaActual()const{cout<<"Vida : "<<vida<<endl;}
        
};

class Decorator : public ICampeon{
    protected:
        ICampeon * campeon;
    public:
        Decorator(ICampeon * _campeon){
            this->campeon=_campeon;
        }
        void takeDamage(int danio)override{
            campeon->takeDamage(danio);
        }
        void VidaActual()const{cout<<"Vida : "<<campeon->getVida()<<endl;}

};

class ArmorDecorator : public Decorator{
    public:
    ArmorDecorator(ICampeon * _campeon):Decorator(_campeon){};

    void takeDamage(int danio)override{
        float n_vida=campeon->getVida()-danio*0.8;
        campeon->setVida(n_vida);
        cout<<"Danio recibido :"<<danio*0.8<<endl; 
        cout<<"Danio automitigado :"<<danio*0.2<<endl; 
    }

};

int main(){
    ICampeon * c1= new CampeonConcreto(1400.3);
    c1->VidaActual();
    c1->takeDamage(475);
    c1->VidaActual();
    cout<<"Campon con armadura"<<endl;
    ICampeon * cArmor=new ArmorDecorator(c1);
    cArmor->VidaActual();
    cArmor->takeDamage(500);
    cArmor->VidaActual();

    delete c1;
    delete cArmor;

    return 0;
};
