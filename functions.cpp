#include<iostream>
#include <cmath>

/// <summary>
/// Function that restores a wrong input from the user
/// </summary>
void wrongInput() {
	std::cout << "Please enter a valid input!\n   ";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

/// <summary>
///	Function that selects operation
/// </summary>
/// <returns> Selection from user to pick operation to perform</returns>
char userSelection() {
	char userSelect;
	std::cout << "   ->";
	std::cin >> userSelect;
	std::cout << "\n";
	return userSelect;
}

/// <summary>
/// Function that will be used to get the desired amount of vectors to operate with when possible.
/// </summary>
/// <returns>integer that will be used to set the amount of vectors to operate with</returns>
int amountOfVec() {
	int x;
	std::cout << "Enter number of vectors to operate with:\n   ";
	restartInputVecAmount:
	std::cin >> x;
	if (std::cin.fail()) {
		wrongInput();
		goto restartInputVecAmount;
	}
	return x;
}

/// <summary>
///	Funtion prompted at the end of each operation for keep running the program or not
/// </summary>
/// <returns>True or False to change the value of the status bool variable</returns>
bool programStatus() {
	std::cout << "Do you want to perform another operation?\n   Y - Yes\n   N - No\n   ->";
	char x;
restartInputStatus:

	// if y or n, will continue or not the program loop ( NO CASE SENSITIVE). If any other input, waits for new possible answer.
	std::cin >> x;
	if (x == 'Y' || x == 'N' || x == 'y' || x == 'n') {
		return((x == 'Y' || x == 'y') ? true : false);
	}
	else {
		wrongInput();
		goto restartInputStatus;
	}

}

/// <summary>
/// Function for adding or substracting vectors, allows any amount of vectors
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <param name="isSum">parameter for switching the behaviour of the function for addition or substraction</param>
void SumOrSubs(double** vecArray, short vecNum, short vecLength, bool isSum) {

	double* resultVector = new double[vecLength] {}; // new array for result initialized with zero-values
	
	//IF isSum = TRUE: Will add to the 'i' element of result vector, each 'i' element for every 'j' vector
	//IF isSum = FALSE: will perform -> v1 + (v2* -1) + (v2* -1) + . . . + (vn * -1) , for n = vecNum (amount of vectors)
	for (int i = 0; i < vecLength; i++) {

		for (int j = 0; j < vecNum; j++) {
			if(j==0&& !isSum){
				resultVector[i] = vecArray[j][i];
				continue;
			}
			else {

				isSum?resultVector[i] += vecArray[j][i]: resultVector[i] += (vecArray[j][i] * (-1));
			}
		}
	}

	// For formating and displaying the result
	std::cout << "Result vector is:\n   x = { ";
	for (int j = 0; j < vecLength; j++) {
		std::cout << resultVector[j];
		if (j != vecLength - 1) std::cout << ", ";
	}
	std::cout << "}\n\n";
}

/// <summary>
/// Function for calculating the scalar product between n vectors, for n = vecNum (amount of vectors)
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <returns>returns a double with the dot product of the vectora as a value</returns>
double dotProduct(double** vecArray, short vecNum, short vecLength) {
	
	double result{}, x{};
	
	// adding the multiplication between the i value of every j vector to find the scalar product
	for (int i = 0; i < vecLength; i++){ 
		x = 1;
		for (int j = 0; j < vecNum; j++) {
			x *= vecArray[j][i];
		}
		result += x;
	}
	return result;
}

/// <summary>
/// Function for calculating the magnitude of a vector
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <param name="count"> will be used to calculate magnitude of multiple vectors in calculating the angle</param>
/// <returns>returns a double with the magnitude of the vector as a value</returns>
double magnitude(double** vecArray, short vecNum, short vecLength, int count = 0) {
	
	double result{}, x{};
	
	// Adding the values to the power of 2 together 
	for (int i = 0; i < vecLength; i++) {
		x += pow(vecArray[count][i],2);
	}

	// using previously calculated value to the sqare root for finding the magnitude
	result = sqrt(x);
	return result;
}

/// <summary>
/// Function for calculating the magnitude of a vector
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <param name="count"> will be used to calculate magnitude of multiple vectors in calculating the angle</param>
/// <returns>returns a double with angle between the vectors as a value</returns>
double angleBetweenVec(double** vecArray, short vecNum, short vecLength) {

	double productOfMagnitudes{ 1 }; // variable that will store the product of the magnitude of all vectors
	double dotProd{ dotProduct(vecArray, vecNum, vecLength) }; // variable storing the dot product of the vectors
	double alfa{}; // variable that will store the angle between vectors
	double PI{ 3.141592653589793238463 }; // Pi number for converting radians to degrees
	
	// calculating product of all magnitudes
	for (int i = 0; i < vecNum; i++) {
		productOfMagnitudes *= magnitude(vecArray, vecNum, vecLength,i);
	}

	// applying formula for getting the angle and converting to degrees
	alfa = (acos(dotProd / productOfMagnitudes) * (180/PI));

	return alfa;
}

/// <summary>
/// Hard coded function that calculates the cross product of 3D-Vectors,
/// no need of making it dynamic.
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
void crossProduct(double** vecArray) {

	// storing the two vectors individually
	double v1[3]{ vecArray[0][0],vecArray[0][1],vecArray[0][2] }, v2[3]{ vecArray[1][0],vecArray[1][1],vecArray[1][2] };

	// using the cross product formula with the two 3D vectors
	double vR[3]{ ((v1[1] * v2[2]) - (v1[2] * v2[1])),((v1[2] * v2[0]) - (v1[0] * v2[2])),((v1[0] * v2[1]) - (v1[1] * v2[0])) };

	// displaying the result
	std::cout << "The cross product of your vectors is:\n   x = { ";
	for (int j = 0; j < 3; j++) {
		std::cout << vR[j];
		if (j != 3 - 1) std::cout << ", ";
	}
	std::cout << "}\n\n";
}
;