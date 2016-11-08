// Isaac Gonzalez
// Homework 3
// Completed 2/9/16

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

const char INCREMENT = '+';
const char DECREMENT = '-';
const char RIGHT = '>';
const char LEFT = '<';
const char INT_PRINT = ':';
const char CHAR_PRINT = '.';
const char ENTER_LOOP = '{';
const char JUMP_BACK = '}';

static int dpIndex = 0;

static int* dp;

static int tape[1000] = {0};

static int width = 4;

int findEndLoop(int start, int inputLength, std::string input);

void printWidth(std::string line){

	int size = width + line.size();
	std::cout << std::setw(size) << line << std::endl;

}

void increment(){

	(*dp)++;
}

void decrement(){

	(*dp)--;

}

void moveRight(){

	dp = &*(tape + dpIndex);
	//dp++;

}

void moveLeft(){
	dp = &*(tape + dpIndex);

}

void printInt(){

	std::cout << *dp;

}

void printAsChar(){

	char c = *dp;
	std::cout << c;

}

void toCPP(int start, int inputLength, std::string input){

	char command;

	int index = start;

	while(index < inputLength){
		command = input[index];

		switch(command){

			case(INCREMENT):{
				std::string inc = "(*dp)++;";
				printWidth(inc);
				index++;
			}
			break;

			case(DECREMENT):{
				std::string dec = "(*dp)--;";
				printWidth(dec);
				index++;
			}
			break;

			case(RIGHT):{
				std::string goRight = "dp++;";
				printWidth(goRight);
				index++;
			}
			break;

			case(LEFT):{
				std::string goLeft = "dp--;";
				printWidth(goLeft);
				index++;
			}
			break;

			case(INT_PRINT):{
				std::string intCommand = "std::cout << *dp;";
				printWidth(intCommand);
				index++;
			}
			break;

			case(CHAR_PRINT):{
				std::string chInit = "c = *dp;";
				std::string chPrint = "std::cout << c;";
				printWidth(chInit);
				printWidth(chPrint);
				index++;
			}
			break;

			case(ENTER_LOOP):{

				int endLoopIndex = findEndLoop(index, inputLength, input);
				printWidth("while(*dp){");
				width += 2;
				int startLoopIndex = index + 1;
				toCPP(startLoopIndex, endLoopIndex - 1, input);
				width -= 2;
				printWidth("}");
				index = endLoopIndex;
			}
			break;

			case(' '):
			index++;
			break;

			default:
			index++;
			break;

		}
	}


}

int findEndLoop(int start, int inputLength, std::string input){

	char current;
	int count = 0;
	int endIndex = 0;

	for(int i = start + 1; i < inputLength; ++i){
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

void runCrazy(int start, int inputLength, std::string input){

	char command;

	int startLoopIndex = 0;

	int index = start;
	while(index < inputLength){
		command = input[index];

		switch(command){

			case(INCREMENT):
			increment();
			index++;
			break;

			case(DECREMENT):
			decrement();
			index++;
			break;

			case(RIGHT):
			index++;
			dpIndex++;
			if(dpIndex > 999){ //wraparound

				dpIndex -= 1000;

			}
			moveRight();
			break;

			case(LEFT):
			index++;
			dpIndex--;
			if(dpIndex < 0){ //wraparound
				dpIndex = 1000 + dpIndex;
			}
			moveLeft();
			break;

			case(INT_PRINT):
			printInt();
			index++;
			break;

			case(CHAR_PRINT):
			printAsChar();
			index++;
			break;

			case(ENTER_LOOP):{

				int endLoopIndex = findEndLoop(index, inputLength, input);

				if(*dp == 0){
					index = endLoopIndex;
				} else {
					startLoopIndex = index + 1;
					runCrazy(startLoopIndex, endLoopIndex - 1, input);
					index = index;
				}
			}
			break;

			case(' '):
			index++;
			break;

			default:
			index++;
			break;

		}
	}
	

}

void printOut(){

	int start = dpIndex - 4;

	int index = start;

	if(start < 0){

		start = 1000 + start;

		index = start;

	}

	std::cout << std::setw(14) << "Tape Index: ";
	for(int i = 0; i < 9; i++){

		if(index == 1000){
			index = 0;
		}
		std::cout << std::setw(5) << index;
		index++;

	}
	std::cout << std::endl;

	std::cout << std::setw(14)<< "Tape Content: ";
	for(int i = 0; i < 9; i++){

		if(start == 1000){
			start = 0;
		}
		std::cout << std::setw(5) << tape[start];
		start++;

	}
	std::cout << std::endl;

	std::cout << std::setw(39) << "^" << std::endl;

}

void interactiveMode(){

	std::string input;

	std::cout << "Enter Crazy Command(s): " << std::endl;
	printOut();
	std::getline(std::cin, input);
	while(input != "exit"){

		std::cout << std::endl;
		runCrazy(0, input.size(), input);
		std::cout << std::endl;
		printOut();
		std::cout << ": ";
		std::getline(std::cin, input);

	}

}

int main(int argc, char** argv)
{

	dp = tape;

	if(argc > 2){
		char mode = argv[1][1];
		std::ifstream inFile(argv[2]);
		std::string input;
		std::getline(inFile, input);

		if(mode == 'c'){
			std::cout << "#include <iostream>" << std::endl;
			std::cout << "int main() {" << std::endl;
			printWidth("int tape[1000] = {0};");
			printWidth("int* dp = &tape[0];");
			printWidth("char c;");
			toCPP(0, input.size(), input);
			printWidth("return 0;");
			std::cout << "}" << std::endl;
		} else if(mode == 'e'){
			runCrazy(0, input.size(), input);
		}
	} else {
		std::cout << "Going to interactive mode: " << std::endl;
		interactiveMode();
	}
	return 0;
}