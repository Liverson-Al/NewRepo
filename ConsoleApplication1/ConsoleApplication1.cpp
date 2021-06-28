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
    point(int x, int y) {    
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }
    int getX() {
        return(x);
    }
    void setY(int y) {
        this->y = y;
    }
    int getY() {
        return(y);
    }
    void Print() {
        cout << "x = " << x << "\ty = " << y << endl << endl;
    }
};

class testClass {
    int* data;

public:
    testClass(int size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = i;
        }
        
        cout << data << " Конструктор создан\n";
        for (size_t i = 0; i < size; i++)
        {
            cout << data[i] << endl;
        }
    }
    ~testClass() {
        delete[] data;
        cout << data << " Деструктор создан\n";
    }
};

int main()
{
    setlocale(LC_ALL, "");
     testClass test1(1);
     testClass test2(2);




    //point a(5,2);
    //point b; //Он будет (0;0)
    //a.Print();
    //b.Print();            
    //human firstHuman; //Объект класса
    //firstHuman.name = "SirGay";
    //firstHuman.age = 228;
    //firstHuman.Print();
   
}
