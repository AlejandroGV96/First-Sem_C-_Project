#include <iostream>

/// <summary>
/// Function that restores a wrong input from the user
/// </summary>
void wrongInput();

/// <summary>
///	Function that selects operation
/// </summary>
/// <returns> Selection from user to pick operation to perform</returns>
char userSelection();

/// <summary>
/// Function that will be used to get the desired amount of vectors to operate with when possible.
/// </summary>
/// <returns>integer that will be used to set the amount of vectors to operate with</returns>
int amountOfVec();

/// <summary>
///	Funtion prompted at the end of each operation for keep running the program or not
/// </summary>
/// <returns>True or False to change the value of the status bool variable</returns>
bool programStatus();

/// <summary>
/// Function for adding vectors, allows any amount of vectors
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <param name="isSum">parameter for switching the behaviour of the function for addition or substraction</param>
void SumOrSubs(double** vecArray, short vecNum, short vecLength,bool isSum);

/// <summary>
/// Function for calculating the scalar product between n vectors, for n = vecNum (amount of vectors)
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
double dotProduct(double** vecArray, short vecNum, short vecLength);

/// <summary>
/// Function for calculating the magnitude of a vector
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <returns>returns a double with the magnitude of the vector as a value</returns>
double magnitude(double** vecArray, short vecNum, short vecLength, int count = 0);

/// <summary>
/// Function for calculating the magnitude of a vector
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
/// <param name="vecNum"> parameter for informing amount of vectors contained in matrix</param>
/// <param name="vecLength">parameter for informing amount of values contained in vectors</param>
/// <param name="count"> will be used to calculate magnitude of multiple vectors in calculating the angle</param>
/// <returns>returns a double with angle between the vectors as a value</returns>
double angleBetweenVec(double** vecArray, short vecNum, short vecLength);

/// <summary>
/// Hard coded cross product of 3D-Vectors,
/// no need of making it dynamic.
/// </summary>
/// <param name="vecArray">parameter for passing array of vectors (matrix) from main function</param>
void crossProduct(double** vecArray);
