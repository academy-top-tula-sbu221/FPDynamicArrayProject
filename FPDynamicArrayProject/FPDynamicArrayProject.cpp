#include <iostream>

using namespace std;

void ArrayCreate(int*& array, int size)
{
    if (array != nullptr)
        delete[] array;
    array = new int[size];
}

void ArrayInit(int* array, int size)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void ArrayPushBack(int*& array, int& size, int value)
{
    int* arrayNew = new int[size + 1];
    for (int i = 0; i < size; i++)
        arrayNew[i] = array[i];
    arrayNew[size] = value;

    delete[] array;
    array = arrayNew;

    size++;
}

void ArrayInsert(int*& array, int& size, int index, int value)
{
    if (index >= size)
    {
        ArrayPushBack(array, size, value);
        return;
    }

    if (index < 0)
        index = 0;

    int* arrayNew = new int[size + 1];
    for (int i = 0; i < index; i++)
        arrayNew[i] = array[i];
    arrayNew[index] = value;
    for (int i = index; i < size; i++)
        arrayNew[i + 1] = array[i];

    delete[] array;
    array = arrayNew;
    size++;
}

int ArrayPopBack(int*& array, int& size)
{

}

int ArrayRemove(int*& array, int& size, int index)
{

}

int main()
{
    int* array{ nullptr };
    int size{ 10 };

    ArrayCreate(array, size);
    ArrayInit(array, size);
    ArrayPrint(array, size);

    ArrayPushBack(array, size, 123);

    ArrayPrint(array, size);

    ArrayInsert(array, size, 5, 999);

    ArrayPrint(array, size);
}
