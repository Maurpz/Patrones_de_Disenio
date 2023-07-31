#include<iostream>
using namespace std;


//interfaz individuo
//es importante usar los metodos get y set para modificar los datos privados 
//ayuda a mantener el encapsulamiento

class I_Individuo{
    protected:
        float vida;
        string nombre;
        float armadura=0;
    public:
        virtual void takeDamage(int)=0;
        virtual void toString()const=0;
        virtual ~I_Individuo(){}
        //gets and sets

        virtual float getVida()const=0;
        virtual void setVida(float n_vida)=0;

        //experimental obtener armadura acumulada
        virtual float getArmor()=0;
};

//Campeones o jugadores

class Jugador : public I_Individuo{
    public:
        Jugador(int _vida, string _nombre){
            this->vida=_vida;
            this->nombre=_nombre;
        }
        void takeDamage(int danio) override {
            this->vida=this->vida-danio;
        }
        void toString()const override {
            cout<<"Mi nombre es : "<<nombre<<".  Vida : "<<vida<<endl;
        }
        float getArmor(){
            return 0;
        }
        float getVida()const{
            return this->vida;
        }
        void setVida(float n_vida){
            this->vida=n_vida;
        }
};


//implementamos la intefaz del decorador

class DecoradorJugador:public I_Individuo{
    protected:
        I_Individuo * jugador;
    public:
        DecoradorJugador(I_Individuo * _jugador){
            this->jugador=_jugador;
        }
        virtual ~DecoradorJugador(){}

        //metodos
        void takeDamage(int danio) override {
            jugador->takeDamage(danio);
        }
        void toString() const override {
            jugador->toString();
        }
        float getArmor(){
            float armor=jugador->getArmor();
            if(armor==0){
                return armor+this->armadura;
            }
            return this->armadura+jugador->getArmor();
        }
        float getVida()const{
            return jugador->getVida();
        }
        void setVida(float n_vida){
            jugador->setVida(n_vida);
        }

       
};


//implementacion decorator concreto

class Casco : public DecoradorJugador{
    public:
        Casco(I_Individuo * jugador):DecoradorJugador(jugador){
            this->armadura=0.15;
        }
        ~Casco(){}
        //metodos
        void takeDamage(int danio)override{
            float armor=getArmor();
            cout<<"La armadura aqui es de "<<armor<<endl;
            float danio_recibido=1-armor;
            jugador->setVida(jugador->getVida()-(danio_recibido*danio));

        }

};

class Chaleco : public DecoradorJugador{
    public:
        Chaleco(I_Individuo * jugador):DecoradorJugador(jugador){
            this->armadura=0.20;
        }
        ~Chaleco(){}
        void takeDamage(int danio)override{
            float armor=getArmor();
            cout<<"La armadura aqui es de "<<armor<<endl;
            float danio_recibido=1-armor;
            jugador->setVida(jugador->getVida()-(danio_recibido*danio));
        }
};
int main(){
    I_Individuo * p1=new Jugador(1000,"Jose");
    I_Individuo * d1=new Casco(p1);
    I_Individuo * d2=new Chaleco(d1);
    I_Individuo * d3=new Chaleco(d2);


    d3->toString();
    d3->takeDamage(400);
    d3->toString();
    delete d3;
    delete d2;
    delete d1;
    delete p1;

    return 0;
};

//como es un funcion polimorfica cuando una clase es abstracta todo los elementos de preferencia deberian ser virtuales puros 
// el problema con el set vida y no el sett vida esque estaba llamdnoa al funcion de quien estaba en ese caso 
//cuando deberia de llamar a alfuncion  de quien en verdad tiene los valores en la instancia 
// en este casio el principal problema que tubimos fue que onteniamos el valor de vidfa perod e los decoradores recordem,os
//que el decorador tm hereda de individuo por lo que el individuo tmb tiene vida y sus otro sparametros per
//estos noe stan inicializados entonces debemos de pedir la vida o setiar la vida a quein enverdad tiene localeinfo_structparametros inicializados
//en este caso la primera instacnia de este 
//por ello debemos de preguntar el getvida pero del objetoq ue anidamos en la clase contenedor de esta amnera
//sera una llamada enc adena
//hasta el que tiene los datos , de no ser asi no trabajaemos con los datos del la instancia principal