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
	int n = 5;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);
	
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		// ��������� � ��������� ������� ����� ���������� ���������� � �������� �������������
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		// ��������� � ��������� ������� ����� �������� �������������� []
	}
	cout << endl;
}