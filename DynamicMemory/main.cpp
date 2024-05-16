#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	int n=5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	int* add_arr = new int[n + 1];
	for (int i = 0; i < n; i++) 
	{
		add_arr[i] = arr[i];
	}
	add_arr[n] = value;
	n++;
	arr = add_arr;
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		// Обращение к элементам массива через арифметику указателей т оперетор разыменования
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		// Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
}