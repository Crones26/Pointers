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
void FillRand(char arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols);

template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* push_back(T* arr, int& n, T value);
template<typename T> T* push_front(T* arr, int& n, T value);
template<typename T> T* insert(T* arr, int& n, T value, int index);

template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index);

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

#ifdef DYNAMIC_MEMORY_1
    int n = 5;
    cout << "Введите размер массива: "; cin >> n;
    //int* arr = new int[n];
    double* arr = new double[n];

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
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строки: "; cin >> cols;

    //int** arr = Allocate <int>(rows, cols);
    double** arr = Allocate <double>(rows, cols);
    //char** arr = Allocate <char>(rows, cols);

    FillRand(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление последней строки в массив: " << endl;
    arr = push_row_back(arr, rows, cols);
    //FillRand(arr[rows - 1], cols);
    FillRand(arr[rows - 1], cols, 100, 1000);
    Print(arr, rows, cols);
    cout << "Добавление нулевой строки в массив: " << endl;
    arr = push_row_front(arr, rows, cols);
    //FillRand(arr[0], cols);
    FillRand(arr[0], cols, 100, 1000);
    Print(arr, rows, cols);
    int row_index;
    cout << "Введите индекс для вставки строки: "; cin >> row_index;
    arr = insert_row(arr, rows, cols, row_index);
    //if (row_index < rows) FillRand(arr[row_index], cols);
    if (row_index < rows)FillRand(arr[row_index], cols, 100, 1000);
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
    push_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Добавление нулевого столбца в массив: " << endl;
    push_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    int col_index;
    cout << "Введите индекс для вставки столбца: "; cin >> col_index;
    insert_col(arr, rows, cols, col_index);
    Print(arr, rows, cols);

    cout << "Удаление последнего столбца: " << endl;
    pop_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Удаление нулевого столбца: " << endl;
    pop_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "Введите индекс для удаления столбца: "; cin >> col_index;
    erase_col(arr, rows, cols, col_index);
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
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % (maxRand - minRand) + minRand;
        *(arr + i) /= 100;
    }
}
void FillRand(char arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand();
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
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = minRand + rand() % (maxRand - minRand);
            arr[i][j] /= 100;
        }
    }
}
void FillRand(char** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand();
        }
    }
}

template<typename T> void Print(T arr[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << tab;
    cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << +arr[i][j] << tab;
        cout << endl;
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
    buffer[index] = value;
    for (int i = index; i < n; i++)
    {
        buffer[i + 1] = arr[i];
    }
    delete[] arr;
    n++;
    return buffer;
}
template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
    T** buffer = new T * [rows + 1];
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[rows] = new T[cols]{};
    delete[] arr;
    rows++;
    return buffer;
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
    T** buffer = new T * [rows + 1];
    for (int i = 0; i < rows; i++)
    {
        buffer[i + 1] = arr[i];
    }
    buffer[0] = new T[cols]{};
    delete[] arr;
    rows++;
    return buffer;
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index)
{
    T** buffer = new T * [rows + 1];
    for (int i = 0; i < index; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[index] = new T[cols]{};
    for (int i = index; i < rows; i++)
    {
        buffer[i + 1] = arr[i];
    }
    delete[] arr;
    rows++;
    return buffer;
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols + 1]{};
        for (int j = 0; j < cols; j++)
        {
            buffer[j] = arr[i][j];
        }
        //buffer[cols] = rand() % 100;
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols + 1]{};
        for (int j = 0; j < cols; j++)
        {
            buffer[j + 1] = arr[i][j];
        }
        //buffer[0] = rand() % 100;
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols + 1]{};
        for (int j = 0; j < index; j++)
        {
            buffer[j] = arr[i][j];
        }
        for (int j = index; j < cols; j++)
        {
            buffer[j + 1] = arr[i][j];
        }
        //buffer[index] = rand() % 100;
        delete[] arr[i];
        arr[i] = buffer;
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
    T** buffer = new T * [--rows];
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }
    delete[] arr[rows];
    delete[] arr;
    return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
    T** buffer = new T * [--rows];
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i + 1];
    }
    delete[] arr[0];
    delete[] arr;
    return buffer;
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
    T** buffer = new T * [--rows];
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

template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols - 1];
        for (int j = 0; j < cols - 1; j++)
        {
            buffer[j] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols--;
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols - 1];
        for (int j = 0; j < cols - 1; j++)
        {
            buffer[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols--;
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; i++)
    {
        T* buffer = new T[cols - 1];
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
}