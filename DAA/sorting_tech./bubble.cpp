#include <iostream>

void printArray(int *array, int n)
{   
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " ";
        std::cout<<"\n";
}

void bubbleSort(int *array, int n)
{
    bool swapped = true;
    int j = 0;
    int temp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

int main()
{
    int array[] = {95, 45, 48, 98, 485, 65, 54, 478, 1, 2325};
    int n = sizeof(array)/sizeof(array[0]);

    printArray(array, n);

    bubbleSort(array, n);
    
    printArray(array, n);
    return (0);
}