#include <string>
#include <iostream>
using namespace std;

template <typename T1, typename T2>   //Где T1,T2 - имя шаблона. Она подстраивается под любой тип данных.
T1 sum(T1 a, T2 b) {
    return a + b;
}


class human 
{          // Класс

public:       //Модификатор доступа

    int age;            // Поля класса
    string name;

    void Print() {
        cout << "Name: " << name << ". Age: " << age;
    };
};

class point {

private:
    int x;
    int y;

public:
    point() {
        x = 0;
        y = 0;
    }
    point(int valueX, int valueY) {    
        x = valueX;
        y = valueY;
    }

    void setX(int valueX) {
        x = valueX;
    }
    int getX() {
        return(x);
    }
    void setY(int valueY) {
        y = valueY;
    }
    int getY() {
        return(y);
    }
    void Print() {
        cout << "x = " << x << "\ty = " << y << endl << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");
 
    point a(5,2);
    point b; //Он будет (0;0)
    a.Print();
    b.Print();
    
    
    
    human firstHuman; //Объект класса
    firstHuman.name = "SirGay";
    firstHuman.age = 228;
    firstHuman.Print();
   
}
