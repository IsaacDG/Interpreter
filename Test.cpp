#include <iostream>
#include <iomanip>

int main(int arc, char** argv){

	int size = 0;
	// std::cout << "Enter a size for the array: ";
	// std::cin >> size;
	int array[4] = {0};
	std::cout << "&array = " << &array << std::endl;
	int* ptr = array;
	std::cout << "&array++ = " << ++ptr << std::endl;
	// for(int i = 0; i < size; i++){

	// 	array[i] = i;

	// }

	// for(int i = 0; i < size; i++){
	// 	std::cout << array[i] << std::endl;
	// }
	// delete [] array;
	return 0;
}