#include <iostream>
#include "smart_array.hpp"

Smart_array::Smart_array (int s) 
        :m_size(s)
{
        m_array = new float [m_size];
        if ( m_array != NULL) {
                for (int i=0; i < m_size; ++i) {
                        m_array[i] = 1.5;
                }
        } else {
                std::cout << "Not enough memory" << std::endl;
        }
}
Smart_array::~Smart_array ()
{
        std::cout << "Object is being deleted" << std::endl;
        delete[] m_array;
}

void Smart_array::set (int index, int value)
{
        int size = get_size();                
        if ( (index >= 0) && (index <= size) ) {
               m_array[index] = value;
        } else {
                std::cout << "Invalide index" << std::endl;
        }
}

int Smart_array::get_size ()
{
        return m_size;
}

int Smart_array::get_index (int index)
{
        int size = get_size(); 
        if ( (index >= 0) && (index <= size) ) {
                std::cout << m_array[index] << std::endl;
        } else {
                std::cout << "Out of range" << std::endl;
        }
}
void Smart_array::resize (int size)
{
        float* resized_array = new float [size];

        for (int i=0; i < size; ++i) {
                resized_array[i] = 1.5;
        }
        if ( size < m_size) {
                for (int i = 0; i < size; ++i) {
                        resized_array[i] = m_array[i];
                }
        } else {
                for (int i = 0; i < m_size; ++i) {
                        resized_array[i] = m_array[i];
                }
        }
        m_size = size;
}

void Smart_array::print()
{
        for (int i = 0; i < m_size; ++i) {
                std::cout << m_array[i] << "  ";
        }
        std::cout << std::endl;
}

