
#include <iostream>
#include "Array.hpp"

int main() {
    try {
        /* Array empty :*/
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        /* Array size 5 :*/
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        /* modify values int array: */
        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
            intArray[i] = i * 2;
        }
        
        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
            std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
        }
        /* unsigned int Array: */
        Array<unsigned int> unsignedArray(50);
        std::cout << "Unsigned int array size: " << unsignedArray.size() << std::endl;
        /* Copy unsigned int: */
        Array<unsigned int> copyunsigned(unsignedArray);
        std::cout << "Copy Unsigned int array size: " << copyunsigned.size() << std::endl;
        /* Assign Array unsigned int: */
		Array<unsigned int> assignTab = copyunsigned;
        std::cout << "Element index of assignTab (unsigned int): " << assignTab[45] << std::endl;


        /*Error :*/
        std::cout << "Accessing out of bounds: " << intArray[10] << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
