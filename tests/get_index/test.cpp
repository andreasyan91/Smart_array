#include "smart_array.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

std::string read_file()
{
        std::ifstream in_file;
        in_file.open("input.txt");
        if ( ! in_file.is_open() ) {
                std::cerr << "couldn't open the file" << std::endl;
        }
        std::string data;
        in_file >> data;
        in_file.close();
        return data;
}

bool testing()
{
        Smart_array smart_object(5,0);
        std::string data =  read_file();
        int index = data[0] - '0';        
        std::ofstream out_file;
        out_file.open("get_index.txt");
        if ( ! out_file.is_open() ) {
                std::cerr << "couldn't open the file" << std::endl;
        }
        if ( smart_object.get_index(index) ) {
                std::cout<<"yes"<<std::endl;
                out_file << "test1 passed" << std::endl;
        } else {
                std::cout<<"no"<<std::endl;
                out_file << "test1 failed" << std::endl;
        }
        out_file.close();
}

int main()
{
        testing();
        return 0;
}
