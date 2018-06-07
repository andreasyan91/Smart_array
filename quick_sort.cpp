#include <iostream>
#include <string.h>

int sort( int* array, int start, int end)
{
        std::cout<<"in sort function"<<std::endl;
        int pivot = array[end];
        int index = start;
        int temp;
        for (int i = start; i <= end; ++i) {
                if ( pivot > array[i] ) {
                        temp = array[i];
                        array[i] = array[index];
                        array[index] = temp;
                        ++index;
                }
        }
        temp = array[index];
        array[index] = array[end];
        array[end] = temp;
        for (int i = start; i <= end; ++i) {
                std::cout << array[i] << " ";
        }
        std::cout<<std::endl;
        return index;
}
int* quick_sort(int* array, int start, int end)
{
        if ( start < end) {
        int index = sort(array, start, end);
        quick_sort(array, start, index - 1);
        quick_sort(array, index + 1, end);
        }
        return array;
}

int main()
{
        int array[13] = {10, 99, 1, 9, 2, 8, 3, 7, 0, 4, -4, 6, 5};
        std::cout<<std::endl;
        for (int i = 0; i <= 9; ++i) {
                std::cout << array[i] << " ";
        }
        std::cout<<std::endl;
        int end = 12;
        int start = 0;
        quick_sort(array, start, end);
        for (int i = start; i <= end; ++i) {
                std::cout << array[i] << " ";
        }
        std::cout<<std::endl;
        return 0;
}
