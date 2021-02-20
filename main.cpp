#include "Header.h"

int main() {
	
	// boolean for keeping the program running
	bool status = true;

	// will be used later for declaring constant variables
	short vecSize; // variable for storing desired vector size
	short vecAmount; // variable for storing desired vector amount

	std::cout << "---------------------------------------\n"
		<< "          Vector Calculator\n"
		<< "---------------------------------------\n\n\n";

	// program loop
	while (status) {
		/// selection menu
		std::cout << "\nPlease choose the operation to perform: \n";
		std::cout
			<< "	a - Vector Addition (n nD-vectors).\n"
			<< "	b - Vector Substraction (n nD-vectors).\n"
			<< "	c - Scalar (dot) Product (n nD-vectors).\n"
			<< "	d - Magnitude of a Vector (1 nD-vector).\n"
			<< "	e - Angle between Vectors (2 nD-vectors).\n"
			<< "	f - Cross Product (2 3D-vectors).\n"
			<< "	x - Exit Program\n\n   ";

		// getting user's answer
	restartInputOpSelect:
		char userSelect = userSelection();

		// switch dermining behaviour of the main code depending on user's answer
		switch (userSelect) {
		case 'a': // addition 
			vecAmount = amountOfVec();
			break;
		case 'b': //substraction
			vecAmount = amountOfVec();
			break;
		case 'c': //Scalar product
			vecAmount = amountOfVec();
			break;
		case 'd': //magnitude of a vector
			vecAmount = 1;
			break;
		case 'e': //angle between vectors
			vecAmount = 2;
			break;
		case 'f': //cross product of two 3D-vectors
			vecAmount = 2;
			vecSize = 3;
			goto crossTag;
		case 'x': //exit program
			goto exit;
		default:
			wrongInput();
			goto restartInputOpSelect;
		}

		// size of the vectors
	restartInputVecSize:
		std::cout << "Enter size of vector(s):\n   ";
		std::cin >> vecSize;
		if (std::cin.fail()) {
			wrongInput();
			goto restartInputVecSize;
		}
	crossTag: // Code continue here after selecting cross product;
		std::cout << "\n";
		const short vecNum = vecAmount; // constant that is defined depending on user's answer
		const short vecLength = vecSize; // constant that is defined depending on user's answer

		// initialize buffer with enough memory for all the elements for then initialize a matrix
		double* matrix_data = new double[vecNum * vecLength];
		double** vecArray = new double* [vecNum];

		// create an array filled with arrays (matrix) that represent the vectors
		for (int i = 0; i < vecNum; i++) {
			vecArray[i] = matrix_data + vecLength * i;
		}

		// Entering values for the vectors
		for (int i = 0; i < vecNum; i++) {
			std::cout << "Please enter " << vecLength << " value(s) for vector #" << i + 1 << ":\n   ";
			restartInputVecValues:
			for (int j = 0; j < vecLength; j++) {
				std::cin >> vecArray[i][j];
				if (std::cin.fail()) {
					wrongInput();
					goto restartInputVecValues;
				}
				std::cout << "   ";
			}
			std::cout << "\n";
		}

		// to format the vector(s) and display it/them
		std::cout << "Vector(s):\n   ";
		for (int i = 0; i < vecNum; i++) {
			std::cout << "	v" << i + 1 << " = { ";
			for (int j = 0; j < vecLength; j++) {
				std::cout << vecArray[i][j];
				if (j != vecLength - 1) std::cout << ", ";
			}
			std::cout << "}";
			std::cout << "\n";
		}
		std::cout << "\n";

		// switch statement for executing the function with the user specified vectorsc
		switch ((int)userSelect) {
		case('a'): // addition 
			SumOrSubs(vecArray, vecNum, vecLength,true);
			break;
		case ('b'): //substraction
			SumOrSubs(vecArray, vecNum, vecLength, false);
			break;
		case 'c': //Scalar product
			std::cout << "The Scalar (dot) product of your vectors is: " << dotProduct(vecArray, vecNum, vecLength) << ".\n\n";
			break;
		case 'd': //magnitude of a vector
			std::cout << "The Magnitude of your vector is: " << magnitude(vecArray, vecNum, vecLength) << ".\n\n";
			break;
		case 'e': //angle between vectors
			std::cout << "The angle between your two vectors is: " << angleBetweenVec(vecArray, vecNum, vecLength) << " degrees.\n\n";
			break;
		case ('f'): //substraction
			crossProduct(vecArray);
			break;
		}

		// Continue or break the program loop
		status = programStatus();

	}
exit:
	std::cout << "\n\n\n---------------------------------------\n"
		<< "          PROGRAM FINISHED\n"
		<< "---------------------------------------\n\n\n";
	return 0;
}