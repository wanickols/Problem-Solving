#include <iostream>

#include "ProblemSolver.h"
#include "BinarySearchTree.h"


using namespace::std;

int main()
{
	ProblemSolver ps;

	

	//ps.debugInfo(ProblemSolver::debugClasses::ALL);
	//BinarySearchTree bst;

	//TODO add this to debug options to get out of main. 
	vector<int> arr = { 2, 11, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12, 6, 5, 7, 8, 9, 10, 2, 2};
	vector<vector<int>> solution = ps.sortByFrequency(arr);
	
	for(int i = 0; i < solution.size(); i++)
	{
		cout << solution.at(i).front() << " " << solution.at(i).back() << endl;
	}

	return 0;
}

