#include<iostream>
#include<vector>
#include<memory>
using namespace std;


class Flyweight{
    private:
        vector<string> texture;
        string tipo;
        string nombre;
    public:
        Flyweight(string t,string nom){
            nombre=nom;
            tipo=t;
            for (int i =0;i<40;i++){
                texture.push_back("DCt5Z4A39VjFiBTCPhZqfZRDYVF7TkzaSfkRmqMe8DtD7rDtJhcNMG4L362W1D0pBK9UyMba4HfahfBFyyyYSCdMnCGUpHSrrxNu");
            }
        }
        string getTipo(){
            return tipo;
        }
        string toString(){
            string s= nombre+ " tam del vector : "+to_string(texture.size());
            return s;
        }
        ~Flyweight(){}

};

class FlyFactory{
    private:
        static FlyFactory * instancia;
        vector<Flyweight *> lista;
        FlyFactory(){}
    public:
        ~FlyFactory(){
            delete instancia;
            for(auto e : lista){
                delete e;
            }}
        static FlyFactory * getInstance(){
            if(instancia==nullptr){
                instancia=new FlyFactory;
            }
            return instancia;
        }

        Flyweight * getFlyweight(string tipo){
            if(tipo=="wood"){
                for(auto e : lista){
                    if(e->getTipo()=="wood"){
                        return e;
                    }}
                
                lista.push_back(new Flyweight("wood","Luciana"));
                return lista.back();
                    
                
            }
            else if(tipo=="stone"){
                for(auto e : lista){
                    if(e->getTipo()=="stone"){
                        return e;
                    }
                }
                    
                lista.push_back(new Flyweight("stone","Valery"));
                return lista.back();
                    
                
            }
            else{return nullptr;}
        }
        void getSize(){
            cout<<"Tamanio de la lista es : "<<lista.size()<<endl;
        }

};

class IUser{
    protected:
        Flyweight * textura=nullptr;
        string tipo;
        int resistencia;
    public:
        virtual string getTipo(){
            return tipo;
        }
        virtual void draw()=0;
};

class UserWood : public IUser{
    public:
        UserWood(Flyweight * ref){
            textura=ref;
            tipo="wood";
            resistencia=300;
        }
        ~UserWood(){}
        void draw(){
            cout<<"Tipo :"<<tipo<<" resistencia :"<<resistencia<<" vector : "<<textura->toString()<<endl;
        }

};
class UserStone : public IUser{
        public:
        UserStone(Flyweight * ref){
            textura=ref;
            tipo="wood";
            resistencia=300;
        }
        ~UserStone(){}
        void draw(){
            cout<<"Tipo :"<<tipo<<" resistencia :"<<resistencia<<" vector : "<<textura->toString()<<endl;
        }

};

FlyFactory* FlyFactory::instancia = nullptr;



int main(){
    FlyFactory * flyFactory=FlyFactory::getInstance();
    vector<UserWood *> listWood;


    for(int i =0;i<1000;i++){
        listWood.push_back(new UserWood(flyFactory->getFlyweight("wood")));
    }
    for (auto e : listWood){
        e->draw();
    }

    for(auto i : listWood){
        delete i;
    }

    return 0;
}