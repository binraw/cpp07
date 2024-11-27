
#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
            intArray[i] = i * 2;
        }

        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
            std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
        }

        std::cout << "Accessing out of bounds: " << intArray[10] << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
