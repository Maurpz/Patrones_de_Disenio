#include <iostream>
#include <vector>
using namespace std;

class Juego{
    private:
        string nombre;
        string jugador;
        int checkpoint;
    public:
        Juego(){
            this->nombre="juego";
            this->checkpoint=0;
            this->jugador="NN";

        }
        Juego(string nom){
            this->nombre=nom;
            this->checkpoint=0;
            this->jugador="NN";
        }
        int getCheckpoint(){
            return this->checkpoint;
        }
        void setCheckpoint(int point){
            this->checkpoint=point;
        }
        void setJugador(string jugador){
            this->jugador=jugador;
        }
        friend ostream& operator << (ostream &os, const Juego &game){
            os<<" [ Jugador: "<<game.jugador<<" llego hasta el Checkpoint  ("<<game.checkpoint<<") ]";
            return os;
        }
        
        Juego& operator=(const Juego &game){
            this->checkpoint=game.checkpoint;
            this-> jugador=game.jugador;
            this->nombre=game.nombre;
            return *this;
        }
        
        ~Juego(){}
};

class Memento{
    private:
        Juego estado;
    public:
        Memento(Juego estado){
            this->estado=estado;
        }
        Juego getState(){
            return this->estado;
        }
        ~Memento(){}
};


class Originador{
    private:
        Juego estado;
    public:
        Originador() = default;
        void setEstado(Juego estado){
            this->estado=estado;
        }
        Juego getEstado(){
            return this->estado;
        }
        Memento* guardar(){
            return new Memento(estado);
        }
        void restaurar(Memento* anterior){
            this->estado=anterior->getState();
        }
        ~Originador(){}


};


class Cuidador{
    private:
        Memento** listaMementos=new Memento*[5];
        int size=0;
    public:
        Cuidador() = default;
        void addMemento(Memento* m){
            if(size==5){
                cout<<"Ya no se pueden guardar mas mementos"<<endl;
            }
            else{
                listaMementos[size]=m;
                this->size++;
            }
            
        }
        Memento* getMemento(int index){
            return listaMementos[index];
        }
        ~Cuidador(){
            for(int i=0;i<5;i++){
                delete listaMementos[i];
            }
            delete [] listaMementos;
            }

};

int main(){
    
    string nombreJuego="Salto en el Tiempo";
    Juego game1(nombreJuego);
    Cuidador cuidador;
    Originador originador;


    game1.setJugador("Jose");
    cout<<"---------------------checkpoint 1---------------------------"<<endl;
    game1.setCheckpoint(1);
    originador.setEstado(game1);//guardamos el estado en el originador
    cuidador.addMemento(originador.guardar());//memento guardado en la pos 0
    std::cout<<game1<<std::endl;


    cout<<"---------------------checkpoint 2---------------------------"<<endl;
    game1.setCheckpoint(2);
    originador.setEstado(game1);//guardamos el estado en el originador
    cuidador.addMemento(originador.guardar());//memento guardado en la pos 1
    cout<<game1<<endl;


    cout<<"---------------------checkpoint 3---------------------------"<<endl;
    game1.setCheckpoint(3);
    originador.setEstado(game1);//guardamos el estado en el originador
    cuidador.addMemento(originador.guardar());//memento guardado en la pos 2
    cout<<game1<<endl;
    

    cout<<"---------------------checkpoint 4---------------------------"<<endl;
    game1.setCheckpoint(4);
    originador.setEstado(game1);//guardamos el estado en el originador
    cuidador.addMemento(originador.guardar());//memento guardado en la posicion 3
    cout<<game1<<endl;


    cout<<"---------------------checkpoint 5---------------------------"<<endl;
    game1.setCheckpoint(5);
    originador.setEstado(game1);//guardamos el estado en el originador
    cuidador.addMemento(originador.guardar());//memento guardado en la pos 4
    cout<<game1<<endl;
    cout<<"Cae el jugador....."<<endl;


    cout<<"----------Esto es una restauracio del memento guardado-------------"<<endl;
    originador.restaurar(cuidador.getMemento(4));//recuperamos un estado del cuidador al originador

    Juego game2;
    game2=game1=originador.getEstado();
    cout<<game2<<endl;
    

    return 0;
};