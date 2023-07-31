#include<iostream>
using namespace std;


//abstraccion de enemigo
class Enemy{
    public:
        virtual int takeDamage()const =0;
        virtual ~Enemy(){};
};


//implementacion de enemigo
class BaseEnemy : public Enemy{
    public:
        int takeDamage()const{
            return 10;
        }
};




//abstraccion del decorador
//heredamos de enemi para que el decorador puede ser tratado com un enemigo
class EnemyDecorator : public Enemy{
    protected:
        Enemy* enemigo;
    public:
        EnemyDecorator(Enemy * _enemigo){
            this->enemigo=_enemigo;
        }
        int takeDamage()const{
            return enemigo->takeDamage();
        }
        ~EnemyDecorator(){}
};



class CascoDecorator : public EnemyDecorator{
    public:
        CascoDecorator(Enemy * _enemigo):EnemyDecorator(_enemigo){};
        int takeDamage()const{
            return 5;
        }
};

class ArmorDecorator : public EnemyDecorator{
    public:
        ArmorDecorator(Enemy * _enemigo):EnemyDecorator(_enemigo){};
        int takeDamage()const {
            return 2;
        }
};



int main(){
    Enemy * e1=new BaseEnemy;
    Enemy *e_d = new CascoDecorator(e1);
    Enemy * e_d_CA=new ArmorDecorator(e_d);

    cout<<e_d_CA->takeDamage();

    delete e1;
    delete e_d;
    delete e_d_CA;
    return 0;
}