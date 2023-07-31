#include <iostream>
#include <memory_resource>
#include <unistd.h> // Incluimos esta cabecera para obtener _SC_PAGE_SIZE
#include<vector>
#include<memory>
using namespace std;

// Función para obtener la cantidad de memoria RAM utilizada en bytes
size_t getCurrentRSS() {
    FILE* file = fopen("/proc/self/statm", "r");
    if (!file) {
        return 0;
    }
    size_t rss;
    if (fscanf(file, "%*s%zu", &rss) != 1) {
        fclose(file);
        return 0;
    }
    fclose(file);
    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // Obtener el tamaño de la página en KB
    return rss * page_size_kb;
}


class Block{
    private:
        vector<string> lista;
        string nombre;
        int id;
    public:
        Block(string nom, int d){
            nombre = nom;
            id=d;
            for (int i =0;i<40;i++){
                lista.push_back("DCt5Z4A39VjFiBTCPhZqfZRDYVF7TkzaSfkRmqMe8DtD7rDtJhcNMG4L362W1D0pBK9UyMba4HfahfBFyyyYSCdMnCGUpHSrrxNu");
            }
        }
        void toString(){
            cout<<"Nombre : "<<nombre<<" id : "<<id<<" tam del vector : "<<lista.size()<<endl;
        }
        ~Block(){}

};



int main() {
    // Código de tu programa aquí
    vector<unique_ptr<Block>> list;
    for (int i=0;i<100;i++){
        list.push_back(make_unique<Block>(to_string(i*100),(i+1000)));
    }
    for (int i =0;i<100;i++){
        list[i]->toString();
    }
    //vector<int> rr(100);


    // Calcula la cantidad de memoria RAM utilizada después de la ejecución
    size_t memoryUsed = getCurrentRSS();
    cout << "Memoria RAM utilizada: " << memoryUsed << " KB" << endl;

    return 0;
}