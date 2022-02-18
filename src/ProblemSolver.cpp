#include "ProblemSolver.h"
#include <algorithm>
#include <iostream>	

using namespace std;

void ProblemSolver::printArray(int listOfNum[], int& size)
{
	for (int i = 0; i < size; i++) {
		cout << listOfNum[i] << " ";
	}
	cout << endl;
}

void ProblemSolver::debugInfo(debugClasses infoShown)
{
	switch (infoShown)
	{
	case ProblemSolver::STRING:
		debugString();
		break;
	case ProblemSolver::MISC:
		debugMisc();
		break;
	case ProblemSolver::SORTS:
		debugSorts();
		break;
	case ProblemSolver::ALL:
		debugString();
		debugMisc();
		debugSorts();
		break;
	default:
		cout << "Incorrect Debug Flag: " << infoShown;
		break;
	}
}


const std::string ProblemSolver::reverseOrderBasic(std::string& reverseMe)
{
	std::string reverse;

	int length = reverseMe.length();

	for (int i = 0; i < length; i++) {
		reverse = reverseMe.at(i) + reverse;
	}
	
	return reverse;
}

const bool ProblemSolver::isPalindrome(std::string& test)
{
	if (!test.empty()) {
		if (test == reverseOrderBasic(test))
		{
			return true;
		}
	}

	return false;
}

const unsigned int ProblemSolver::numberOfOccurences(std::string& string, char& character)
{
	int length = string.length();
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (string.at(i) == character)
			count++;
	}
	return count;
}

const bool ProblemSolver::isAnagram(std::string& test1, std::string& test2)
{
	vector<string> strings = {test1, test2};


	if (test1.length() != test2.length())
		return false;

	for (auto& item : strings) {
		sort(item.begin(), item.end());
	}
	
	if (strings.at(0) == strings.at(1))
		return true;

	return false;
}

void ProblemSolver::swapArrayElements(int intArray[], const int& index1, const int& index2)
{
	int tmp = intArray[index1];
	intArray[index1] = intArray[index2];
	intArray[index2] = tmp;
}

int ProblemSolver::fibonacci(const int& n)
{
	if (n <= 1)

		return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

void ProblemSolver::swapNumbersNoThirdVariable(int intArray[], int index1, int index2)
{
	intArray[index2] = intArray[index1] + intArray[index2];
	intArray[index1] = intArray[index2] - intArray[index1];
	intArray[index2] = intArray[index2] - intArray[index1];
}

void ProblemSolver::swapNumbersNoThirdVariable(int num1, int num2)
{
	std::cout << num1 << " " << num2 << endl;
	num2 = num1 + num2;
	num1 = num2 - num1;
	num2 = num2 - num1;
	std::cout << num1 << " " << num2 << endl;

}

void ProblemSolver::printFibonacci(const int& n)
{
	for (int i = 0; i < n; i++) {
		cout << fibonacci(i) << ", ";
	}
}

void ProblemSolver::bubbleSort(int arrayP[], const int size, const bool leftToRight)
{
	bool isSolved = false;
	
	int unsolvedSort = size - 1;

	while (!isSolved) 
	{
		isSolved = true;
		for (int i = 0; i < unsolvedSort; i++)
		{
			if (!leftToRight) {
				if (arrayP[i] < arrayP[i + 1]) {
					swapArrayElements(arrayP, i, i + 1);
					isSolved = false;
				}
			}
			else {
				if (arrayP[i] > arrayP[i + 1]) {
					swapArrayElements(arrayP, i, i + 1);
					isSolved = false;
				}
			}
		}
		unsolvedSort--;

	}


}

void ProblemSolver::insertionSort(int arrayP[], const int size)
{
	for(int i = 1; i < size; i++)
	{
		int current = arrayP[i];
		int j = i - 1;
		while(j >= 0 && arrayP[j] > current)
		{
			arrayP[j + 1] = arrayP[j];
			j--;
		}
		arrayP[j + 1] = current;
	}

}

void ProblemSolver::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partitionss
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int ProblemSolver::partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j < high; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swapArrayElements(arr, i, j);
		}
	}
	swapArrayElements(arr, i+1, high);
	return (i + 1);
}

void ProblemSolver::debugString()
{

	cout << "---------------------------" << endl << "String Debug Information" << endl << "---------------------------" << endl;

	string test = "Hello";

	cout << "Test String is: " << test << endl;  
	
	cout << "--Reverse Testing--" << endl;

	string test2 = reverseOrderBasic(test);

	cout << "The reverse of test1 is: " << test2 << endl;

	cout << "--Palindrome Testing--" << endl;

	test = "babab";
	cout << "Test is changed to " << test << endl;
	if (isPalindrome(test))
	{
		cout << "Palindrome can detect true" << endl;
	}
	else
	{
		cout << "Palindrome can not detect true" << endl;
	}
	test = "Hello";
	cout << "Test is changed to " << test << " Again" << endl;
	if(!isPalindrome(test))
	{
		cout << "Palindrome can detect false" << endl;
	}else
	{
		cout << "Palindrome can not detect false" << endl;
	}

	cout << "--Character Occurence Testing--" << endl;
	
	char testChar = 'b';

	cout << "The test char is: " << testChar << endl;
	cout << "The number of occurences in " << test << " is " << numberOfOccurences(test, testChar) << endl;
	testChar = 'l';
	cout << "The test char is: " << testChar << endl;
	cout << "The number of occurences in " << test << " is " << numberOfOccurences(test, testChar) << endl;
	
	cout << "--Angram Testing--" << endl;

	cout << "Test2 is " << test2 << endl;

	if (isAnagram(test, test2))
	{
		cout << "IsAnagram can detect true" << endl;
	}else
	{
		cout << "IsAnagram can not detect true" << endl;
	}

	test2 = "Nuthn";
	cout << "Test2 is changed to " << test2 << endl;

	if(!isAnagram(test,test2))
	{
		cout << "IsAnagram can detect false" << endl;
	}
	else
	{
		cout << "IsAnagram can not detect false" << endl;
	}

}

void ProblemSolver::debugMisc()
{
	cout << "---------------------------" << endl << "Misc Debug Information" << endl << "---------------------------" << endl;
	cout << "Fibonaccii to 20 elements" << endl;
	int fib = 20;
	printFibonacci(fib);

	cout << endl;

	int listOfNum[] = { 2, 24, 3, 4, 10, 9, 4, 1 };
	int arrLength = std::size(listOfNum);
	
	printArray(listOfNum, arrLength);
	

	cout << "Given an array " << endl;
	reverseArray(listOfNum, arrLength);
	
	cout << "Reverse that arry" << endl;
	printArray(listOfNum, arrLength);

	cout << "Swapping without variables" << endl;
	swapNumbersNoThirdVariable(1, 4);

}

void ProblemSolver::debugSorts()
{
	cout << "---------------------------" << endl << "Sorter Debug Information" << endl << "---------------------------" << endl;
	int listOfNum[] = { 2, 24, 3, 4, 10, 2, 9, 4, 1 };
	int listOfNum2[] = { 1, 2,3, 4,5,6,7,8,9,10,11 };
	
	int arrLength = std::size(listOfNum);

	cout << "Starting Array" << endl;
	memcpy(listOfNum2, listOfNum, sizeof(listOfNum));
	printArray(listOfNum2, arrLength);

	insertionSort(listOfNum2, arrLength);

	cout << "After Insertion sort" << endl;
	printArray(listOfNum2, arrLength);

	memcpy(listOfNum2, listOfNum, sizeof(listOfNum));
	
	bubbleSort(listOfNum2, arrLength);

	cout << "After Bubble sort" << endl;
	printArray(listOfNum2, arrLength);

	memcpy(listOfNum2, listOfNum, sizeof(listOfNum));

	cout << "After Quick Sort " << endl;

	quickSort(listOfNum2, 0, arrLength);

	printArray(listOfNum2, arrLength);

	memcpy(listOfNum2, listOfNum, sizeof(listOfNum));
	
	cout << "After HeapSort " << endl;

	heapSort(listOfNum2, arrLength);

	printArray(listOfNum2, arrLength);



}

void ProblemSolver::heapify(int arr[], int& size, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	//cout << largest << " " << l << " " << r << endl;
	//printArray(arr, size);
	// If left child is larger than root
	if (l < size && arr[l] > arr[largest]) {
		largest = l;
		//cout << "left " << arr[l] << endl;
	}

	// If right child is larger than largest so far
	if (r < size && arr[r] > arr[largest]) {
		largest = r;
		//cout << "right " << arr[r] << endl;
	}

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, size, largest);
	}
}

// main function to do heap sort
void  ProblemSolver::heapSort(int arr[], int& size)
{
	//printArray(arr, size);
	// Build heap (rearrange array)
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// One by one extract an element from heap
	for (int i = size - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}

}

void ProblemSolver::reverseArray(int arrayP[], const int size)
{
	for (int i = 0; i < size/2; i++)
	{
		swapNumbersNoThirdVariable(arrayP, i, size - 1 - i);
	}

}


template<typename T>
inline void ProblemSolver::printVector(std::vector<T>& vec)
{

	for (const auto& item : vec) {
		cout << item << endl;
	}
	cout << endl;
}
