#include "smart_array.hpp"
#include <iostream>

int main()

{
        Smart_array arr1(5);
        arr1.set(3, 88);
        arr1.print();
        arr1.set(88,3);
        std::cout << "size = " << arr1.get_size() << std::endl;
        arr1.get_index(3);
        arr1.get_index(10);
        arr1.resize(10);
        std::cout << "size = " << arr1.get_size() << std::endl;
        arr1.resize(4);
        std::cout << "size = " << arr1.get_size() << std::endl;

        return 0;
}
