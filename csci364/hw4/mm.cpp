//Grant Haataja - Assignment 4
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

//function to check if given string is a number
bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) == false) {
			return false;
		}
	}
	return true;
}
//function to allocate memory for a matrix
int ** matrixalloc(int size)
{
	int **a = new int*[size];
	for (int i = 0; i < size; i++) {
		a[i] = new int[size];
	}
	return a;
}
//function to deallocate memory for a matrix
void matrixFree(int **matrix, int size)
{
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//function to initialize a magtrix
void matrixInit(int **matrix, int size, int num)
{	
	for (int i = 0; i < size; i++ ) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = num;
		}
	}
}
//function to print a matrix
void matrixPrint(int **matrix, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//main function to run the program
int main(int argc, char **argv) 
{
	bool printFlag = false;
	if (argc == 2) {

	}
	else if (argc == 3) {
		string str(argv[2]);
		if ((str == "Y" || str == "y" || str == "1")) {
			printFlag = true;
		}
	}
	else {
		cout << "Usage: ./mm <matrix size> <print flag>" << endl;
		return 0;
	}
	if (!isNumber(argv[1])) {
		cout << "Matrix size must be an integer." << endl;
		return 0;
	}
	
	//convert command line argument to an integer for matrix size	
	int matrixSize = atoi(argv[1]);
	
	//allocate space for three matrices
	int **first = matrixalloc(matrixSize);
	int **second = matrixalloc(matrixSize);
	int ** product = matrixalloc(matrixSize);	
	
	//set up seeded random number generator
	const int seed = 1;
	mt19937 engine(seed);
	uniform_int_distribution<int> dist(0, 100);
	
	//initialize product with 0's in each entry
	matrixInit(product, matrixSize, 0);
	
	//define compiler flag to initialize the two matrices either with 1's or randomly
	#ifdef TEST
		matrixInit(first, matrixSize, 1);
		matrixInit(second, matrixSize, 1);
	#else
		for (int i = 0; i < matrixSize; i++ ) {
			for (int j = 0; j < matrixSize; j++) {
				first[i][j] = dist(engine);
			}
		}
		for (int i = 0; i < matrixSize; i++ ) {
			for (int j = 0; j < matrixSize; j++) {
				second[i][j] = dist(engine);
			}
		}
	#endif
	
	//check time before matrix multiplication
	auto begin = chrono::system_clock::now();

	//perform matrix multiplication
	#pragma omp parallel for schedule(dynamic, 1) num_threads(8)
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			for (int k = 0; k < matrixSize; k++) {
				product[i][j] += first[i][k] * second[k][j];
			}
		}
	}
	//check time and print time difference
	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed_time = end - begin;
	cout << "Matrix Multplication took " << elapsed_time.count() << " seconds." << endl;

	//check to see if the product will be printed
	if (printFlag) {
		matrixPrint(product, matrixSize);
	}
	
	//free memory
	matrixFree(first, matrixSize);
	matrixFree(second, matrixSize);
	matrixFree(product, matrixSize);
	cout << "Program Complete." << endl;	
	
	return 1;
}
