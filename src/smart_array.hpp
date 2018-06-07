#include <iostream>

class Smart_array
{
        public :              

                ///Creates array with the length of given number
                /**
                 *@param int is an integer for array length
                 *@return Returns dynamic array
                 **/
                Smart_array(int, int);

                /// Initiolizes object with other object 
                Smart_array(const Smart_array&);

                /// Is called when the object is deleted to free allocated memory                
                ~Smart_array();

                ///Assings one object to the other object
                // Smart_array& is the object from which will be coped
                Smart_array& operator = (const Smart_array&);

                ///
                int& operator [] (int);

                ////
                friend std::ostream &operator << (std::ostream&, const Smart_array&);

                ///Changes the value of the given index
                /**
                 * @param int first int is index which will be changed and 
                 * @param int is index of the new value
                 * @return Returns array with changed value at the given index
                 **/
                bool set(int, int);

                /// Returns the size of the array                
                int get_size();

                /**
                 * @param int Intenger for the index
                 * @return Returns the value of the given index
                 **/
                bool get_index(int);

                /**
                 * @param int Is an integer for the new array length
                 * @return Returns dynamic array with new length
                 **/
                void resize(int);

                /// Swaps the array values by the inputed indexes
                bool swap(int, int);

                /// Prints all array values                
                void print();

                ///
                int sort( int*, int, int);

                ///
                int* quick_sort(int*, int, int);
        private:
                int m_size;
                int* m_array;
                int m_value;
};

