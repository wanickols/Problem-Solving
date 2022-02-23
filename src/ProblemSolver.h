#pragma once

#include <vector>
#include <string>
#include <array>
#include <memory>



class ProblemSolver 
{
public:
	ProblemSolver() {};

	enum debugClasses { STRING = 1, MISC = 2, SORTS = 4, ALL = 8};

	//Utility
	void printArray(int listOfNum[], int& size);
	void debugInfo(debugClasses infoShown);

	//String Manipulation
	const std::string reverseOrderBasic(std::string &reverseMe);
	const bool isPalindrome(std::string& test);
	const unsigned int numberOfOccurences(std::string& string, char& character);
	const bool isAnagram(std::string& test1, std::string& test2);


	//Array Manipulation
	//Sorters
	void bubbleSort(int arrayP[], const int size, const bool LeftToRight = true);
	void insertionSort(int arrayP[], const int size);
	void quickSort(int arrayP[], int low, int high);
	void heapSort(int arrayP[], int& size);

	void reverseArray(int arrayP[], const int size);
	void swapNumbersNoThirdVariable(int intArray[], int index1, int index2);
	void swapNumbersNoThirdVariable(int num1, int num2);
	
	
	std::vector<std::vector<int>> sortByFrequency(std::vector<int> arr, bool inOrderOfInsertion = true);

	void printFibonacci(const int &n);


private:
	template<typename T>
	void printVector(std::vector<T>& vec);

	void swapArrayElements(int intArray[], const int& index1, const int& index2);

	void heapify(int arrayP[], int& size, int i);

	static int fibonacci(const int& n);

	int partition(int arr[], int low, int high);
	
	std::unique_ptr<std::vector<std::vector<int>>> store(std::vector<int>& arr, bool inOrderOfInsertion);

	//Debug
	void debugString();
	void debugMisc();
	void debugSorts();

};

