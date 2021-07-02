/*Реализовать класс "гиперплоскость в n-мерном пространстве", с
возможностями проверки совпадения двух гиперплоскостей, а также
проверки для заданной точки нахождения на гиперплоскости, или в
положительном(отрицательном) полупространстве относительно нее*/
/*Реализовать класс "гиперплоскость в n-мерном пространстве", с
возможностями проверки совпадения двух гиперплоскостей, а также
проверки для заданной точки нахождения на гиперплоскости, или в
положительном (отрицательном) полупространстве относительно нее.*/

#include <iostream>
using namespace std;
class Point
{
public:
	Point(size_t dimension, double* koor)
	{
		this->koor = new double[dimension];
		this->koor = koor;
	}
	double* koor;
};

class Hyperplane {
public:
	Hyperplane(size_t dimension, double* koef, double free)
	{
		this->dimension = dimension;
		this->koef = koef; // коэфы перед иксами
		this->free = free; // свободный член
	}
	Hyperplane(const Hyperplane& other)
	{
		dimension = other.dimension;
		for (size_t i = 0; i < dimension + 1; i++)
		{
			koef[i] = other.koef[i];
		}
		free = other.free;
	}
	Hyperplane(size_t dimension, double* koef, double free)
		~Hyperplane()
	{
		delete[] koef;
	}
	bool isEqual(Hyperplane other) // Проверка эквивалентности гиперплоскостей - для этого нужно, чтобы коэффициенты были пропорциональны
	{
		double prop;
		int i = 0;
		while (koef[i] == 0 && other.koef[i] == 0)
		{
			i++;
		}
		if (other.koef[i] != 0 && koef[i] != 0)
		{
			prop = koef[i] / other.koef[i];
		}
		else if (other.koef[i] != 0 && koef[i] == 0 || other.koef[i] == 0 && koef[i] != 0)
		{
			return false;
		}
		for (i = i + 1; i < dimension + 1; i++)
		{
			if (other.koef[i] == 0 && koef[i] != 0)
				return false;
			if (other.koef[i] != 0 && koef[i] == 0)
				return false;
			if (other.koef[i] == 0 && koef[i] == 0)
				continue;
			if (koef[i] / other.koef[i] != prop)
			{
				return false;
			}
		}
		if (free / other.free != prop)
		{
			return false;
		}
		return true;
	}
	int HowPoly(Point point) //Проверка - в каком полупространстве находится заданная точка. Подставляем коэффициенты в уравнение гиперплоскости
	{
		double result = 0;
		for (size_t i = 0; i < dimension + 1; i++)
		{
			result += point.koor[i] * koef[i];
		}
		if (result < 0)
			return -1;
		else if (result == 0)
			return 0;
		else
			return 1;

	}
private:
	size_t dimension;
	double* koef = new double[dimension + 1];
	double free;
};
int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите размерность пространства > 1";
	size_t dimention;
	cin >> dimention;
	if (dimention < 2) {
		cout << "Введите разменость пространства БОЛЬШЕ ЕДИНИЦЫ";
		return(0);

	}
	double* koef_1 = new double[dimention - 1];
	cout << "Введите коэффициенты первой гиперплоскости - ";
	for (size_t i = 0; i < dimention - 1; i++)
	{
		cin >> koef_1[i];
	}
	cout << "Введите свободный член первой гиперплоскости - ";
	double free_1;
	cin >> free_1;
	double* koef_2 = new double[dimention - 1];
	cout << "Введите коэффициенты первой гиперплоскости - ";
	for (size_t i = 0; i < dimention - 1; i++)
	{
		cin >> koef_2[i];
	}
	cout << "Введите свободный член первой гиперплоскости - ";
	double free_2;
	cin >> free_2;


	cout << "Введите координаты точки, через которую проходит первая гиперплоскость через пробел";
	double* koor_a = new double[dimention];
	for (size_t i = 0; i < dimention; i++)
	{
		cin >> koor_a[i];
	}
	bool equal;

	Point a(dimenton, *koor_a);
	Hyperplane Hyperpl_1(dimention, koef_1, free_1);
	Hyperplane Hyperpl_2(dimention, koef_2.free_2);
	int to4ka;
	equal = Hyperpl_1.isEqual(Hyperpl_2);
	to4ka = Hyperpl_1.HowPoly(a);
	cout << "Эквивалентность гиперплоскостей - " << equal << endl;
	if (to4ka == 1) { cout << "точка лежит в положительном полупространстве" }
	else if (to4ka == 0) { cout << "точка лежит на полупространстве" }
	else cout << "точка лежит в отрицательном полупространстве";

}

}
