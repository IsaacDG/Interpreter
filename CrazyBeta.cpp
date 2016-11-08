#include <iostream>
#include <string>

	const char INCREMENT = '+';
	const char DECREMENT = '-';
	const char RIGHT = '>';
	const char LEFT = '<';
	const char INTPRINT = ':';
	const char CHARPRINT = '.';
	const char ENTERLOOP = '{';
	const char JUMPBACK = '}';

	static int dpIndex = 0;

void increment(int*& dp){

	(*dp)++;

}

void decrement(int*& dp){

	(*dp)--;

}

void moveRight(int*& dp){

	dp++;

}

void moveLeft(int*& dp){
	dp--;
}

void printInt(int*& dp){

	std::cout << *dp;

}

void printAsChar(int*& dp){

	char c = (char)*dp;
	std::cout << c;

}

int findEndLoop(int start, int inputLength, std::string input){

	char current;
	int count = 0;
	int endIndex = 0;

	for(int i = start + 1; i < inputLength; i++){
		if(input[i] == '{'){
			count++;
		} else if(input[i] == '}'){
			if(count != 0){
				count--;
			} else {
				return (i + 1);
			}
		}
	}
	return endIndex;
}

void runCrazy(int start, int inputLength, int*& dp, std::string input){

	char command;

	int startLoopIndex = 0;

	for(int i = start; i < inputLength; ++i){

		command = input[i];

		switch(command){

			case(INCREMENT):
			std::cout << "Incrementing" << std::endl;
			increment(dp);
			break;

			case(DECREMENT):
			std::cout << "Decrementing" << std::endl;
			decrement(dp);
			break;

			case(RIGHT):
			std::cout << "Right" << std::endl;
			moveRight(dp);
			dpIndex++;
			break;

			case(LEFT):
			std::cout << "Left" << std::endl;
			moveLeft(dp);
			dpIndex--;
			break;

			case(INTPRINT):
			std::cout << "Int Print" << std::endl;
			printInt(dp);
			break;

			case(CHARPRINT):
			std::cout << "Char print" << std::endl;
			printAsChar(dp);
			break;

			case(ENTERLOOP):{
				std::cout << "Enter Loop" << std::endl;
				int endLoopIndex = findEndLoop(i, inputLength, input);
				if(*dp == 0){
					i = endLoopIndex;
				} else {
					startLoopIndex = i + 1;
					runCrazy(startLoopIndex, endLoopIndex, dp, input);
				}
			}
			break;

			case(JUMPBACK):
			// std::cout << "Exit loop" << std::endl;
			i = startLoopIndex - 1;
			break;

			default:
			std::cout << "Error in input." << std::cout << std::endl;
			break;

		}

	}

}

int main(){

	int tape[1000] = {0};
	int* dp = &tape[0];

	// int dpIndex = 0;

	std::string input = "++++++{>++++++++++<-}>+++++.";

	// std::cin >> input;

	int inputLength = input.size();
	
	runCrazy(0, inputLength, dp, input);

	// std::cout << "Address of tape[0]: " << &tape[0] << std::endl;
	// std::cout << "Address that dp is pointing to: " << dp << std::endl;

	return 0;
}