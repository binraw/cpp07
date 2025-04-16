#include "iter.hpp"

void printElement(int value)
{
	std::cout << value << std::endl;
}

template <typename T>
	void incrementElement(T& value)

	{
		int copy_value = value;
		copy_value++;
		std::cout << "value tab +1 : " << copy_value << std::endl;
	};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, len, printElement);

	iter(arr, len, incrementElement<int>);

    iter(arr, len, incrementElement<const int>);

    return 0;
}
