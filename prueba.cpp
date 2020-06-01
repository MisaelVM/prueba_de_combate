#include <iostream>
#include <string>
using namespace std;

class personaje;

class enemigo{
    string nombre;
    int hp_max;


public:
    int fuerza;
    int hp;
    enemigo(string x, int h, int f)
    {
        nombre = x;
        hp_max = h;
        hp= h;
        fuerza = f;
    }
    int get_hp()
    {
        return hp;
    }
    void atacar(personaje);

    bool enemigo_muerto()
    {
        if (hp <=0)
            return true;
        else
            return false;

    }
    void restar_vida(int x)
    {
        hp -=x;
    }
    ~enemigo(){}

};

class personaje
{
    string nombre;
    int hp_max;


public:
    int fuerza;
    int hp;
    personaje(string x, int h, int f)
    {
        nombre = x;
        hp_max = h;
        hp= h;
        fuerza = f;
    }
    int get_hp()
    {
        return hp;
    }
    void atacar(enemigo x)
    {
        x.hp = x.hp-fuerza;
    }

     bool personaje_muerto()
    {
        if (hp <=0)
            return true;
        else
            return false;

    }
    void restar_vida(int x)
    {
        hp -=x;
    }
    ~personaje(){}
};

void enemigo::atacar(personaje x)
    {
        x.hp -= fuerza;
    }

int main()
{
    personaje x ("ness", 100, 40);
    enemigo y ("starman", 100, 30);
    int g;
    cin >> g;

    while (x.hp >=0 || y.hp >= 0)
    {
        cout << "elige accion";
        if(x.personaje_muerto()==true)
            break;
        cin >> g;
        if (g == 1)
            y.restar_vida(x.fuerza);
        if (g==0){
            cout << "huiste";
            break;}
        if(y.enemigo_muerto()==true)
            break;
        cout <<"imp";
        cout << "tu vida "<<x.hp<<" vida del enemigo "<<y.hp;
        x.restar_vida(y.fuerza);

    }
}
