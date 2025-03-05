#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>
class Array
{
private:
    size_t size;
    size_t capacity;
    T *array;

public:
    Array()
    {
        size = 0;
        capacity = 5;
        array = new T[capacity];
    }
    Array(const Array &copy)
    {
        size = copy.size;
        capacity = copy.capacity;
        array = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            array[i] = copy.array[i];
        }
    }

    Array &operator=(const Array &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] array;
        size = other.size;
        capacity = other.capacity;
        array = new T[capacity];
        for (int i = 0; i < size; i++)
            array[i] = other.array[i];
        return *this;
    }

    // SwitchElements :- Reverse 2 elements locations.
    void SwitchElements(int x, int y)
    {
        if (x >= 0 && x < size && y >= 0 && y < size)
        {
            T temp = array[x];
            array[x] = array[y];
            array[y] = temp;
        }
    }

    // Resize :- Control the size of the array.
    void Resize(size_t newCapacity)
    {
        if (newCapacity <= capacity)
        {
            cout << "Error: The new capacity must be greater than the current capacity (" << capacity << "). Please enter a larger value." << endl;
            return;
        }
        T *newArray = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    // Append :- Add element at the end of the array.
    void Append(T element)
    {
        if (size >= capacity)
        {
            Resize(capacity * 2);
        }
        array[size] = element;
        size++;
    }

    // Insert :- Insert an element at a specific location.
    void Insert(T element, int index)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Index out of range!");
        }
        if (size >= capacity)
        {
            Resize(capacity * 2);
        }
        for (size_t i = size; i > index; i--)
        {
            array[i] = array[i - 1];
        }

        array[index] = element;
        size++;
    }

    // Delete :-Delete an element from a specific location.
    void Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range!");
        }

        for (size_t i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }

    // Get_Element :- Return a specific element.
    T &Get_Element(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range!");
        }
        return array[index];
    }

    // Get_Size :- Return the current size of the array.
    int Get_Size() const
    {
        return size;
    }

    // Reverse :- Reverse array elements.
    void Reverse()
    {
        int i = 0;
        int j = size - 1;
        T temp;
        while (i < j)
        {
            SwitchElements(i, j);
            i++;
            j--;
        }
    }

    // Search :- look up for an element and return its index.
    int Search(T element)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (array[i] == element)
            {
                return i;
            }
        }
        throw out_of_range("Element not found!");
    }


    // Sort :- Sorts array elements in ascending order using merge sort algorithm.
    void MergeSort(int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            MergeSort(low, mid);
            MergeSort(mid + 1, high);
            Merge(low, mid, high);
        }
    }
    void Merge(int low, int mid, int high)
    {
        int leftsize = mid - low + 1;
        int rightsize = high - mid;

        // Temp arrays(I created them as dynamic arrays so i can delete them later)
        T *leftarray = new T[leftsize];
        T *rightarray = new T[rightsize];

        // Copy array elements in the temp arrays.
        for (size_t i = 0; i < leftsize; i++)
        {
            leftarray[i] = array[i + low]; //???
        }
        for (size_t i = 0; i < rightsize; i++)
        {
            rightarray[i] = array[mid + i + 1];
        }

        size_t r = 0, l = 0, k = low; //???

        while (r < rightsize && l < leftsize)
        {
            if (leftarray[l] <= rightarray[r])
            {
                array[k] = leftarray[l];
                l++;
            }
            else
            {
                array[k] = rightarray[r];
                r++;
            }
            k++;
        }
        while (l < leftsize)
        {
            array[k] = leftarray[l];
            l++;
            k++;
        }
        while (r < rightsize)
        {
            array[k] = rightarray[r];
            r++;
            k++;
        }
        delete[] leftarray;
        delete[] rightarray;
    }
};

#endif
