#include <iostream>
#include "smart_array.hpp"

Smart_array::Smart_array (int s, int v) 
        :m_size(s), m_value(v)
{
        std::cout << "value = "<<m_value;

        std::cout << "Constructor called " << std::endl;
        m_array = new float [m_size];
        if ( m_array != NULL) {
                for (int i=0; i < m_size; ++i) {
                        m_array[i] = m_value;
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

Smart_array::Smart_array(const Smart_array &copy_arr)
{
        std::cout << "Copy constructor called " << std::endl;
        m_size = copy_arr.m_size;
        m_value = copy_arr.m_value;
        m_array = new float [m_size];
        for (int i = 0; i < m_size; ++i) {
               m_array[i] = copy_arr.m_array[i];
        }
}

Smart_array& Smart_array::operator = (const Smart_array &copy_arr)
{
        std::cout << "Operator = called " << std::endl;
        m_value = copy_arr.m_value;
        m_size = copy_arr.m_size;
        m_array = new float [m_size];
        for (int i = 0; i < m_size; ++i) {
                m_array[i] = copy_arr.m_array[i];
        }

}

bool Smart_array::set (int index, int value)
{
        int size = get_size();                
        if ( (index >= 0) && (index <= size) ) {
               m_array[index] = value;
               return true;
        } else {
                std::cout << "Invalide index" << std::endl;
                return false;
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
                resized_array[i] = m_value;
        }
        std::cout << "value = "<<m_value;
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
        m_array = resized_array;
}

void Smart_array::print()
{
        for (int i = 0; i < m_size; ++i) {
                std::cout << m_array[i] << "  ";
        }
        std::cout << std::endl;
}

void Smart_array::swap(int o, int n)
{
        int temp = m_array[o];
        m_array[o] = m_array[n];
        m_array[n] = temp;
}
