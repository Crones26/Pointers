#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template <typename T> T** Allocate(const int rows, const int cols);
template <typename T> void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* push_back(T* arr, int& n, T value);
template<typename T> T* push_front(T* arr, int& n, T value);
template<typename T> T* insert(T* arr, int& n, T value, int index);

template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, int index);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index);

template<typename T> T* pop_back(T* arr, int& n);
template<typename T> T* pop_front(T* arr, int& n);
template<typename T> T* erase(T* arr, int& n, int index);

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);

template<typename T> void pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
    setlocale(LC_ALL, "");

    typedef char DataType; // Директива typedef создает псевдоним для существующего типа данных
#ifdef DYNAMIC_MEMORY_1
    int n = 5;
    cout << "Введите размер массива: "; cin >> n;

    DataType* arr = new DataType[n];

    FillRand(arr, n);
    Print(arr, n);

    DataType value;
    cout << "Введите добавляемое значение: "; cin >> value;
    arr = push_back(arr, n, value);
    Print(arr, n);

    cout << "Введите добавляемое значение: "; cin >> value;
    arr = push_front(arr, n, value);
    Print(arr, n);
    int index;
    cout << "Введите индекс: "; cin >> index;
    cout << "Введите добавляемое значение на место индекса: "; cin >> value;
    arr = insert(arr, n, value, index);
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

#ifdef DYNAMIC_MEMORY_2

    int rows;
    int cols;
    int index;
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строки: "; cin >> cols;

    DataType** arr = Allocate <DataType>(rows, cols);

    FillRand(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление последней строки в массив: " << endl;
    arr = push_row_back(arr, rows, cols);
    FillRand(arr[rows - 1], cols, 100, 1000);
    Print(arr, rows, cols);
    cout << "Добавление нулевой строки в массив: " << endl;
    arr = push_row_front(arr, rows, cols);;
    FillRand(arr[0], cols, 100, 1000);
    Print(arr, rows, cols);
    cout << "Введите индекс для вставки строки: "; cin >> index;
    arr = insert_row(arr, rows, cols, index);
    if (index < rows)FillRand(arr[index], cols);
    Print(arr, rows, cols);

    cout << "Удаление последней строки: " << endl;
    arr = pop_row_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Удаление нулевой строки: " << endl;
    arr = pop_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для удаления строки: "; cin >> index;
    arr = erase_row(arr, rows, cols, index);
    Print(arr, rows, cols);

    cout << "Добавление последнего столбца в массив: " << endl;
    push_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление нулевого столбца в массив: " << endl;
    push_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для вставки столбца: "; cin >> index;
    insert_col(arr, rows, cols, index);
    Print(arr, rows, cols);

    cout << "Удаление последнего столбца: " << endl;
    pop_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Удаление нулевого столбца: " << endl;
    pop_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для удаления столбца: "; cin >> index;
    erase_col(arr, rows, cols, index);
    Print(arr, rows, cols);

    Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}

template <typename T> T** Allocate(const int rows, const int cols)
{
    T** arr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new T[cols]{};
    }
    return arr;
}
template <typename T> void Clear(T** arr, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % (maxRand - minRand) + minRand;
    }
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
    minRand *= 100;
    maxRand *= 100;
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % (maxRand - minRand) + minRand;
        *(arr + i) /= 100;
    }
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand();
        if (arr[i] == '\f')i--;
    }
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
    for (int i = 0; i < rows; i++)
    {
        FillRand(arr[i], cols);
    }
    cout << endl;
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
    for (int i = 0; i < rows; i++)
    {
        FillRand(arr[i], cols);
    }
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
    for (int i = 0; i < rows; i++)
    {
        FillRand(arr[i], cols);
    }
}

template<typename T> void Print(T arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        Print(arr[i], cols);
    }
    cout << endl;
}

template<typename T> T* push_back(T* arr, int& n, T value)
{
    T* buffer = new T[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[n] = value;
    delete[] arr;
    n++;
    return buffer;
}
template<typename T> T* push_front(T* arr, int& n, T value)
{
    T* buffer = new T[n + 1];
    for (int i = 0; i < n; i++)
        buffer[i + 1] = arr[i];
    delete[] arr;
    arr = buffer;
    arr[0] = value;
    n++;
    return arr;
}
template<typename T> T* insert(T* arr, int& n, T value, int index)
{
    T* buffer = new T[n + 1];
    for (int i = 0; i < index; i++)
    {
        buffer[i] = arr[i];
    }
    
    for (int i = index; i < n; i++)
    {
        buffer[i + 1] = arr[i];
    }
    buffer[index] = value;
    delete[] arr;
    n++;
    return buffer;
}
template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
    return push_back(arr, rows, new T[cols]{});
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
    return push_front(arr, rows, new T[cols]{});
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, int index)
{
	return insert(arr, rows, new T[cols]{}, index);
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = push_back(arr[i], cols, T());
        cols--;
    }
    cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = push_front(arr[i], cols, T());
        cols--;
    }
    cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = insert(arr[i], cols, T(), index);
        cols--;
    }
    cols++;
}   

template<typename T> T* pop_back(T* arr, int& n)
{
    T* buffer = new T[--n];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i];
    }
    delete[] arr;
    return buffer;
}
template<typename T> T* pop_front(T* arr, int& n)
{
    T* buffer = new T[--n];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr;
    return buffer;
}
template<typename T> T* erase(T* arr, int& n, int index)
{
    T* buffer = new T[--n];
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
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
    delete[] arr[rows - 1];return pop_back(arr, rows);
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
    delete[] arr[0];return pop_front(arr, rows);
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
    delete[] arr[index];return erase(arr, rows, index);
}

template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = pop_back(arr[i], cols);
        cols++;
    }
    cols--;
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = pop_front(arr[i], cols);
        cols++;
    }
    cols--;
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = erase(arr[i], cols, index);
        cols++;
    }
    cols--;
}