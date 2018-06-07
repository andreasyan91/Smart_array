#include "smart_array.hpp"
#include <iostream>

int main()

{
        Smart_array arr1(5, 0);
     /*   arr1.set(3, 88);
        arr1.print();
        arr1.set(88,3);
        std::cout << "size = " << arr1.get_size() << std::endl;
        arr1.get_index(3);
        arr1.get_index(10);
        arr1.resize(10);
        std::cout << "size = " << arr1.get_size() << std::endl;
        arr1.resize(4);
        std::cout << "size = " << arr1.get_size() << std::endl;
        arr1.print();*/
        std::cout << std::endl; 
        Smart_array arr2(arr1);
        arr2.print();
        arr2.set(1, 90);
        arr2.print();
        arr2.swap(0, 1);
        arr2.swap(0, 9);
        arr2.swap(0, 99);
        arr2.swap(99, 0);        
       /* arr2.print();
        arr2.set(90,1);
        std::cout << "size = " << arr2.get_size() << std::endl;
        arr2.get_index(3);
        arr2.get_index(10);
        arr2.resize(29);
        std::cout << "size = " << arr2.get_size() << std::endl;
        arr2.print();
        arr2.resize(4);
        std::cout << "size = " << arr2.get_size() << std::endl;*/
        arr2.print();
        std::cout << arr2 << std::endl;
        
       /* Smart_array arr3 = arr2;
        arr3.print();
        std::cout << arr3[188] << std::endl;*/
        return 0;
}
