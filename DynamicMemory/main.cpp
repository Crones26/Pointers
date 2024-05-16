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
	int* b_arr = new int[n + 1];
	for (int i = 0; i < n; i++) 
	{
		b_arr[i] = arr[i];
	}
	delete[] arr;
	arr = b_arr;
	b_arr[n] = value;
	n++;
	Print(arr, n);
	delete[] b_arr;
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