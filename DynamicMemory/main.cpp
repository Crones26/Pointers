﻿#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int index, const int value);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);
int** push_col_back(int** arr, const int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, const int rows, int& cols, const int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);
int** pop_col_back(int** arr, const int rows, int& cols);
int** pop_col_front(int** arr, const int rows, int& cols);
int** erase_col(int** arr, const int rows, int& cols, const int index);

#define DYNAMIC_MEMORY_2

void main()
{
    setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
    int n = 5;
    cout << "Введите размер массива: "; cin >> n;
    int* arr = new int[n];

    FillRand(arr, n);
    Print(arr, n);

    int value;
    cout << "Введите добавляемое значение: "; cin >> value;
    arr = push_back(arr, n, value);
    Print(arr, n);

    cout << "Введите добавляемое значение: "; cin >> value;
    arr = push_front(arr, n, value);
    Print(arr, n);
    int index;
    cout << "Введите добавляемое значение на место индекса: "; cin >> value;
    cout << "Введите индекс: "; cin >> index;
    arr = insert(arr, n, index, value);
    Print(arr, n);

    cout << "Удаление последнего элемента: " << endl;
    arr = pop_back(arr, n);
    Print(arr, n);

    cout << "Удаление нулевого элемента: " << endl;
    arr = pop_front(arr, n);
    Print(arr, n);

    cout << "Введите индекс элемента, которые хотите удалить: "; cin >> index;
    arr = erase(arr, n, index);
    Print(arr, n);

    delete[] arr;

#endif // DYNAMIC_MEMORY_1

    int rows = 3;
    int cols = 4;
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строки: "; cin >> cols;
    int** arr = Allocate(rows, cols);
    FillRand(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление последней стороки в массив: " << endl;
    arr = push_row_back(arr, rows, cols);
    FillRand(arr[rows - 1], cols);
    Print(arr, rows, cols);
    cout << "Добавление нулевой стороки в массив: " << endl;
    arr = push_row_front(arr, rows, cols);
    FillRand(arr[0], cols);
    Print(arr, rows, cols);
    int row_index;
    cout << "Введите индекс для вставки строки: "; cin >> row_index;
    arr = insert_row(arr, rows, cols, row_index);
    FillRand(arr[row_index], cols);
    Print(arr, rows, cols);

    cout << "Удаление последней строки: " << endl;
    arr = pop_row_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Удаление нулевой строки: " << endl;
    arr = pop_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для удаления строки: "; cin >> row_index;
    arr = erase_row(arr, rows, cols, row_index);
    Print(arr, rows, cols);

    cout << "Добавление последнего столбца в массив: " << endl;
    arr = push_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление нулевого столбца в массив: " << endl;
    arr = push_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    int col_index;
    cout << "Введите индекс для вставки столбца: "; cin >> col_index;
    arr = insert_col(arr, rows, cols, col_index);
    Print(arr, rows, cols);

    cout << "Удаление последнего столбца: " << endl;
    arr = pop_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Удаление нулевого столбца: " << endl;
    arr = pop_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для удаления столбца: "; cin >> col_index;
    arr = erase_col(arr, rows, cols, col_index);
    Print(arr, rows, cols);

    Clear(arr, rows);
}

int** Allocate(const int rows, const int cols)
{
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols] {};
    }
    return arr;
}
void Clear(int** arr, const int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void FillRand(int arr[], const int n) 
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}
void FillRand(int** arr, const int rows, const int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = rand() % 100;
        }
    }
    cout << endl;
}
void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;
}
void Print(int** arr, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << tab;
        }
        cout << endl;
    }
    cout << endl;
}
//void Print(int** arr, const int rows, const int cols)
//  {
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            cout << *(*(arr + i) + j) << tab;
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

int* push_back(int arr[], int& n, const int value) 
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[n] = value;
    delete[] arr;
    n++;
    return buffer;
}
int* push_front(int arr[], int& n, const int value) 
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i + 1] = arr[i];
    }
    buffer[0] = value;
    delete[] arr;
    n++;
    return buffer;
}
int* insert(int arr[], int& n, const int index, const int value) 
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < index; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[index] = value;
    for (int i = index; i < n; i++) 
    {
        buffer[i + 1] = arr[i];
    }
    delete[] arr;
    n++;
    return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols) 
{
    int** buffer = new int* [rows + 1];
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[rows] = new int[cols] {};
    delete[] arr;
    rows++;
    return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
    int** buffer = new int* [rows + 1];
    for (int i = 0; i < rows; i++)
    {
        buffer[i + 1] = arr[i];
    }
    buffer[0] = new int[cols] {};
    delete[] arr;
    rows++;
    return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, const int index) 
{
    int** buffer = new int* [rows + 1];
    for (int i = 0; i < index; i++) 
    {
        buffer[i] = arr[i];
    }
    buffer[index] = new int[cols] {};
    for (int i = index; i < rows; i++)
    {
        buffer[i + 1] = arr[i];
    }
    delete[] arr;
    rows++;
    return buffer;
}
int** push_col_back(int** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1];
        for (int j = 0; j < cols; j++) 
        {
            buffer[j] = arr[i][j];
        }
        buffer[cols] = rand() % 100;
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
    return arr;
}
int** push_col_front(int** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1];
        for (int j = 0; j < cols; j++)
        {
            buffer[j + 1] = arr[i][j];
        }
        buffer[0] = rand() % 100;
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
    return arr;
}
int** insert_col(int** arr, const int rows, int& cols, const int index)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1];
        for (int j = 0; j < index; j++)
        {
            buffer[j] = arr[i][j];
        }
        buffer[index] = rand() % 100;
        for (int j = index; j < cols; j++)
        {
            buffer[j + 1] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
    return arr;
}

int* pop_back(int arr[], int& n) 
{
    int* buffer = new int[--n];
    for (int i = 0; i < n; i++) 
    {
        buffer[i] = arr[i];
    }
    delete[] arr;
    return buffer;
}
int* pop_front(int arr[], int& n)
{
    int* buffer = new int[--n];
    for (int i = 0; i < n; i++) 
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr;
    return buffer;
}
int* erase(int arr[], int& n, const int index) 
{
    int* buffer = new int[--n];
    for (int i = 0; i < index; i++)
    {
        buffer[i] = arr[i];
    }
    for (int i = index; i < n; i++) 
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr;
    return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols) 
{
    
    int** buffer = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }
    delete[] arr[--rows];
    delete[] arr;
    return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols) 
{
    
    int** buffer = new int* [--rows];
    for (int i = 0; i < rows; i++) 
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr[0];
    delete[] arr;
    return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int index) {
    
    int** buffer = new int* [--rows];
    for (int i = 0; i < index; i++) 
    {
        buffer[i] = arr[i];
    }
    for (int i = index; i < rows; i++) 
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr[index];
    delete[] arr;
    return buffer;
}
int** pop_col_back(int** arr, const int rows, int& cols) {
    for (int i = 0; i < rows; i++) 
    {
        int* buffer = new int[cols - 1];
        for (int j = 0; j < cols - 1; j++) 
        {
            buffer[j] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols--;
    return arr;
}
int** pop_col_front(int** arr, const int rows, int& cols) {
    for (int i = 0; i < rows; i++) 
    {
        int* buffer = new int[cols - 1];
        for (int j = 0; j < cols - 1; j++) 
        {
            buffer[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols--;
    return arr;
}
int** erase_col(int** arr, const int rows, int& cols, const int index) {
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols - 1];
        for (int j = 0; j < index; j++)
        {
            buffer[j] = arr[i][j];
        }
        for (int j = index; j < cols - 1; j++) 
        {
            buffer[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols--;
    return arr;
}