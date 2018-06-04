class Smart_array
{
        public :              

		///Creates array with the length of given number
		/**
		 *@param int is an integer for array length
		 *@return Returns dynamic array
		 **/
                Smart_array(int);

                /// Is called when the object is deleted to free allocated memory                
                ~Smart_array();

		///Changes the value of the given index
		/**
		 * @param int first int is index which will be changed and 
		 * @param int is index of the new value
		 * @return Returns array with changed value at the given index
		 **/
                void set(int, int);

                /// Returns the size of the array                
                int get_size();

		/**
		 * @param int Intenger for the index
		 * @return Returns the value of the given index
		 **/
                int get_index(int);

		/**
		 * @param int Is an integer for the new array length
		 * @return Returns dynamic array with new length
		 **/
                void resize(int);

		/// Prints all array values                
                void print();
        private:
                int m_size;
                float* m_array;
};

