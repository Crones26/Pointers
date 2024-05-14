#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define DELIMITER "\n------------------------------------------------------------------------\n"
#define SPLIT_1
#define SPLIT_2

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];

#ifdef SPLIT_1
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < 10; i++)
	{
		arr[i] % 2 == 0 ? even_count++ : odd_count++;
	}
	cout << "Четных чисел массива:   " << even_count << endl;
	cout << "Нечетные чисел массива: " << odd_count << endl;

	int* even = new int[even_count];
	int* odd = new int[odd_count];
	int* even_pointer = even;
	int* odd_pointer = odd;

	for (int i = 0; i < 10; i++)
	{
			/*if (arr[i] % 2 == 0)
			{
				*even_pointer = arr[i];even_pointer++;
			}
			else
			{
				*odd_pointer = arr[i];odd_pointer++;
			}*/
		arr[i] % 2 == 0 ? *even_pointer++ = arr[i] : *odd_pointer++ = arr[i];
	}
	cout << "Четные числа массива:   ";
	for (int i = 0; i < even_count; i++)
	{
		cout << even[i] << tab;
	}
	cout << endl;
	cout << "Нечетные числа массива: ";
	for (int i = 0; i < odd_count; i++)
	{
		cout << odd[i] << tab;
	}
	cout << endl;
	delete[] even;
	delete[] odd;
	cout << DELIMITER;
#endif // SPLIT_1

#ifdef SPLIT_2
	FillRand(arr, n);
	cout << "Исходный массив: " << endl;
	Print(arr, n);
	int even_counts = 0;
	int odd_counts = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 ? even_counts++ : odd_counts++;
	}
	cout << "Четных чисел массива:   " << even_counts << endl;
	cout << "Нечетных чисел массива: " << odd_counts << endl;
	int* even_arr = new int[even_counts];
	int* odd_arr = new int[odd_counts];
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}
	cout << "Четные числа массива:   ";
	Print(even_arr, even_counts);
	cout << "Нечетные числа массива: ";
	Print(odd_arr, odd_counts);
	delete[] even_arr;
	delete[] odd_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // SPLIT_2

}


