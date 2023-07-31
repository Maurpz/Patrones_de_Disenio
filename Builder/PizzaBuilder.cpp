#include<iostream>
using namespace std;

//producto
class Pizza{
    private:
        bool peperoni=false;
        bool salchicha=false;
        bool pinia=false;
        bool queso_chedar=false;
        bool queso_motzarela=false;
        bool queso_parmesano=false;
        bool papas_fritas=false;
        int huevo_frito=0;
        string tamanio;
    public:
        Pizza(){}
        ~Pizza(){}
        //sets
        void setPeperoni(){peperoni=true;}
        void setSalchicha(){salchicha=true;}
        void setPinia(){pinia=true;}
        void setChedar(){queso_chedar=true;}
        void setMotzarela(){queso_motzarela=true;}
        void setParmesano(){queso_parmesano=true;}
        void setPapas(){papas_fritas=true;}
        void setHuevo(int cant){huevo_frito=cant;}
        void setTamanio(string tam){tamanio=tam;}

        //gets
        bool getPeperoni(){return peperoni;}
        bool getSalchicha(){return salchicha;}
        bool getPinia(){return pinia;}
        bool getChedar(){return queso_chedar;}
        bool getMotzarela(){return queso_motzarela;}
        bool getParmesano(){return queso_parmesano;}
        bool getPapas(){return papas_fritas;}
        int getHuevo(){return huevo_frito;}
        string getTamanio(){return tamanio;}
        void toString()const{
            cout<<"Peperoni : "<<int(peperoni)<<endl;
            cout<<"Salchicha : "<<int(salchicha)<<endl;
            cout<<"pinia : "<<int(pinia)<<endl;
            cout<<"chedar : "<<int(queso_chedar)<<endl;
            cout<<"motzarela : "<<int(queso_motzarela)<<endl;
            cout<<"parmesano : "<<int(queso_parmesano)<<endl;
            cout<<"paspas : "<<int(papas_fritas)<<endl;
            cout<<"huevo : "<<int(huevo_frito)<<endl;
            cout<<"tamanio : "<<tamanio<<endl;



        }
        

};

class IBuilder{
    protected:
        Pizza * pizza=nullptr;
    public:
        virtual ~IBuilder(){}
        virtual void cosinarPizza(string)=0;
        virtual Pizza* getPizza()=0;
};

class PeperoniBuilder : public IBuilder{
    public:
        PeperoniBuilder(){
            pizza=new Pizza();
        }
        void cosinarPizza(string tam)override{
            pizza->setTamanio(tam);
            pizza->setPeperoni();
            pizza->setParmesano();
        }
        Pizza * getPizza(){return pizza;}
};

class SalchipaperaBuilder : public IBuilder{
    public:
        SalchipaperaBuilder(){
            pizza=new Pizza();
        }
        void cosinarPizza(string tam)override{
            pizza->setTamanio(tam);
            pizza->setSalchicha();
            pizza->setHuevo(2);
            pizza->setPapas();
            pizza->setMotzarela();
        }
        Pizza * getPizza()override{
            return pizza;
        }
};

class Cosina{
    private:
        IBuilder * builder=nullptr;
    public:
        Cosina(){}
        void setBuilder(IBuilder * build){builder=build;}
        Pizza * pedirPizza(string tam){
            builder->cosinarPizza(tam);
            return builder->getPizza();
        }
};


int main(){
    Cosina cosina;
    PeperoniBuilder peperoni;
    SalchipaperaBuilder salchi;
    cosina.setBuilder(&peperoni);
    Pizza * p1=cosina.pedirPizza("Grande");
    p1->toString();
    delete p1;
    cosina.setBuilder(&salchi);
    p1=cosina.pedirPizza("Mediana");
    p1->toString();
    delete p1;

    return 0;
}