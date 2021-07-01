#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include<functional>
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
class student :public human {
public:
    int group;
    void Study() {
        cout << "Да учусь я, отстань";
    }
};
class prepod :public human {
public:
    string subject;
};
class zao4niyStident :public student {
    void Study() {
        cout << "Да учусь я, просто у меня инет вырубили, вот и ебланю";
    }
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
    int Size;
public:
    testClass(int size) {
        this->Size = size;
        this->data = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = i;
        }
        
        cout << data << " Конструктор создан\n";
        
    }

    testClass(const testClass& other) {
        this->Size = other.Size;
        this->data = new int[other.Size];
        for (size_t i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }
        cout << "Вызвался конструктор копирования " << this << endl;
    }

    testClass & operator = (const testClass& other) {
        cout << "Вызвался конструктор = " << this << endl;
        this->Size = other.Size;
        if (this->data != nullptr) {
            delete[] this->data;
        }
        
        this->data = new int[other.Size];
        for (size_t i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    ~testClass() {
        delete[] data;
        cout << data << " Деструктор создан\n";
    }
};

class Apple {
    int weight;
    string color;
public:
    static int count;
    static int sumWeight;

        Apple(int weight, string color) {
        this->weight = weight;
        this->color = color;
        count++;
        sumWeight += weight;
    }
};
int Apple::count = 0; 
int Apple::sumWeight = 0;

/*class Singleton {
protected:
    //Конструктор Одиночки всегда должен быть скрытым, чтобы предотвратить создание объекта через оператор new.
    Singleton(const string value) :value_(value)
    {
    }
    static Singleton* singleton_;
    string value_;
public:
    //Он не должен быть клонируемым
    Singleton(Singleton& other) = delete;
    //Он не должен быть назначаемым
    void operator=(const Singleton&) = delete;
    /**
     * Это статический метод, управляющий доступом к экземпляру одиночки. При
     * первом запуске, он создаёт экземпляр одиночки и помещает его в
     * статическое поле. При последующих запусках, он возвращает клиенту объект,
     * хранящийся в статическом поле.
     
    static Singleton* GetInstance(const string& value);
    string value() const {
        return value_;
    }

};
Singleton* Singleton::singleton_ = nullptr;
Singleton* Singleton::GetInstance(const string& value) {
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(value);
    }
    return(singleton_);
}
void ThreadFoo() {
    // Этот код эмулирует медленную инициализацию.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar() {
    // Этот код эмулирует медленную инициализацию.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}*/

template <typename T1, typename T2>
class MyClass {
public:
    MyClass(T1 value, T2 value2) {
        this->value = value;
        this->value2 = value2;
    }
    void DataTypeSize() {
        cout << "value " << sizeof(value) << endl;
        cout << "value2 " << sizeof(value2) << endl;
    }

private:
    T1 value;
    T2 value2;

}; 

template <typename T>
class printer {
public:
    void Print(T value) {
        cout << value << endl; 
    }
};
template<> //Специализация класса
class printer<string> {
public:
    void Print(string value) {
        cout << "_____" << value << "______" << endl;
    }
};


void Foo(int a) {
    if (a > 10 && a < 40) {
        cout << a << endl;
    }
}
void Bar(int a) {
    if (a % 2==0) {
        cout << a << endl;
    }
}
void DoWork(vector<int> &vc, function<void(int)> f) {
    for (auto el : vc) {
        f(el);
    }
}

class Gun {
public:
    virtual void shoot() {
        cout << "Bang\n";
    }
};
class Rifle :public Gun {
public:
    void shoot() override{    //override проверяет соответствует ли shoot предыдущему классу, если нет, то пэздос
        cout << "Bang Bang Bang\n";
    }
};
class Player {
public:
    void shoot(Gun *gun) {
        gun->shoot();
    }
};

//int calculate(string str_in) {
//    stack<int> val_stack;              
//    int n1, n2, res;
//
//    for (int i = 0; i < str_in.length(); ++i) {
//        if (isNumber(str_out[i])) {
//            val_stack.push(str_out[i]);
//        }
//        else {
//            n2 = val_stack.pop();
//            n1 = val_stack.pop();
//            switch (str_out[i]) {
//            case '+': res = n1 + n2; break;
//            case '-': res = n1 - n2; break;
//            case '*': res = n1 * n2; break;
//            case '/': res = n1 / n2; break;
//            default: cout << "Ошибка !\n";
//            }
//            val_stack.push(res);
//        }
//    }
//    return val_stack.pop();
//} // Тут обратная польская реализация
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int SIZE = 256;

class stack {
    int p;
    int data[SIZE];
public:
    stack() {
        for (int i = 0; i < SIZE; i++)
            this->data[i] = 0;
        this->p = 0;
    }
    int pop() {
        this->p--;
        return this->data[p];
    }
    void push(int num) {
        this->data[p] = num;
        p++;
    }
};

int power(int n, int k) {
    int c = 1;
    while (k != 1) {
        if (k % 2 == 0) {
            k /= 2;
            n *= n;
        }
        else {
            k--;
            c *= n;
        }
    }
    return n * c;
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    string token;
    stack data;
    int iAop = 0;
    int iBop = 0;
    while (input >> token) {
        if (token == "+") {
            iBop = data.pop();
            iAop = data.pop();
            data.push(iAop + iBop);
            continue;
        }
        if (token == "-") {
            iBop = data.pop();
            iAop = data.pop();
            data.push(iAop - iBop);
            continue;
        }
        if (token == "*") {
            iBop = data.pop();
            iAop = data.pop();
            data.push(iAop * iBop);
            continue;
        }
        if (token == "/") {
            iBop = data.pop();
            iAop = data.pop();
            data.push(iAop / iBop);
            continue;
        }
        if (token == "^") {
            iBop = data.pop();
            iAop = data.pop();
            data.push(power(iAop, iBop));
            continue;
        }
        data.push(atoi(token.c_str()));
    }
    output << data.pop();
    input.close();
    output.close();
    return 0;
}
int main()
{
    setlocale(LC_ALL, "");
    
    Gun gun;
    Rifle rifle;

    Player player;
    player.shoot(&rifle);
    
    
    
   /* vector<int> vc = {1,51,44,17,98,22,18,222};
    DoWork(vc, Bar);*/ //DoWork(vc, Foo);



   /* printer<string> p;
    p.Print("545asdj");*/


    /*point a(2,8);
    int b = 5;
    MyClass<int,point> c(b,a);
    c.DataTypeSize();*/


    /*cout << "Если есть равное значение, значит синглтон был переюзан (ура) \n Если есть 2 различных значения, то создалось 2 синглтона (бля) \n Результат: ";
    thread t1(ThreadBar);
    thread t2(ThreadFoo);
    t1.join();
    t2.join();*/



   /* Apple apple(150, "Red");
    Apple apple2(200, "Blue");
    cout << Apple::count << endl << Apple::sumWeight;*/



    /* testClass a(10);
     testClass b(2);
     testClass c(5);
     c = a = b;*/



    /*point a(5,2);
    point b; //Он будет (0;0)
    a.Print();
    b.Print();            
    human firstHuman; //Объект класса
    firstHuman.name = "SirGay";
    firstHuman.age = 228;
    firstHuman.Print();*/
   
}
