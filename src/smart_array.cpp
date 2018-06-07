#include <iostream>

#include "smart_array.hpp"

Smart_array::Smart_array (int s, int v) 
        :m_size(s), m_value(v)
{
        std::cout << "value = " << m_value;
        std::cout << "Constructor called " << std::endl;
        try {
                m_array = new int [m_size];
        } catch (std::bad_alloc& e) {
                std::cout << e.what() << std::endl;
        }
        for (int i=0; i < m_size; ++i) {
                m_array[i] = m_value;
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
        try {
                m_array = new int [m_size];
        } catch (std::bad_alloc& e) {
                std::cout << e.what() << std::endl;
        }
        for (int i = 0; i < m_size; ++i) {
                m_array[i] = copy_arr.m_array[i];
        }
}

Smart_array& Smart_array::operator = (const Smart_array &copy_arr)
{
        std::cout << "Operator = called " << std::endl;
        m_value = copy_arr.m_value;
        m_size = copy_arr.m_size;
        try {
                m_array = new int [m_size];
        } catch (std::bad_alloc& e) {
                std::cout << e.what() << std::endl;
        }
        for (int i = 0; i < m_size; ++i) {
                m_array[i] = copy_arr.m_array[i];
        }
        return *this;
}

std::ostream& operator << ( std::ostream &output, const Smart_array &obj)
{
        output << "Size : " << obj.m_size << "\n";
        output << "Value : " << obj.m_value << "\n";
        for (int i = 0; i < obj.m_size; i++){
                output << obj.m_array[i] << " ";
        }
        output << std::endl;
        return output;
}

bool Smart_array::get_index (int index)
{
        int size = get_size();
        if ( (index >= 0) && (index <= size) ) {
                return true;
        } else {
                return false;
        }
}

int& Smart_array::operator [] ( int index) 
{
        if(get_index(index)) {
                std::cout << m_array[index] << std::endl;
                return m_array[index];
        } else {
                std::cout << "Out of range" << std::endl;
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

void Smart_array::resize (int size)
{
        int* resized_array = new int [size];

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

bool Smart_array:: swap(int o, int n)
{
        int temp;
        int size = get_size();
        if (( (n >= 0) && (n <= size) ) && ( (o >= 0) && (o <= size))) {
                temp = m_array[o];
                m_array[o] = m_array[n]; 
                m_array[n] = temp;
                return true;
        } else {
                std::cout << " Out of range "<< std::endl;
                return false;
        } 
}
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

