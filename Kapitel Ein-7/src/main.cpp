/**
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are
 * 0.
 *
 * Programmer response:
 * This doesn't make much sense to me. If there's a single zero in the matrix, would that infect
 * the entire matrix and make it entirely filled with zeroes? As in...
 * 1 2 3      1 2 0      0 0 0
 * 4 5 6  --> 4 5 0  --> 0 0 0
 * 7 8 0      0 0 0      0 0 0
 *
 * Or would it stop at that second step?
 * And if it did stop at that second step, then it would mean something like this would happen.
 * 0 2 3      0 0 0
 * 4 5 6  --> 0 5 0
 * 7 8 0      0 0 0
 *
 * Right?
 * Three passes will be needed. One to record the location of zeroes, another to set the rows, and
 * one last one to set columns appropriately. Since the entire row and column associated with the 0
 * are obliterated, then it's not necessary to record both the row AND column for a single zero.
 * Overlaps are unnecessary.
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix);
void zeroMatrix(vector<vector<int>> matrix);

int main(int argc, char* argv[]){
	vector<vector<int>> a = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};
	vector<vector<int>> b = {
			{1, 2, 3, 9},
			{4, 5, 6, 9},
			{7, 8, 0, 9}
	};
	vector<vector<int>> c = {
			{0, 2, 3},
			{4, 5, 6},
			{7, 8, 0}
	};

	zeroMatrix(a);
	zeroMatrix(b);
	zeroMatrix(c);

	return 0;
}

void zeroMatrix(vector<vector<int>> matrix){
	bool rows[matrix.size()] = {};
	bool columns[matrix.front().size()] = {};
	printMatrix(matrix);
	for(unsigned int x = 0; x<matrix.size(); x++){
		for(unsigned int y = 0; y<matrix[x].size(); y++){
			if(matrix[x][y] == 0){
				rows[x] = true;
				columns[y] = true;
			}
		}
	}

	for(unsigned int x = 0; x<sizeof(rows); x++){
		if(rows[x]){
			for(unsigned int y = 0; y<matrix[x].size(); y++){
				matrix[x][y] = 0;
			}
		}
	}

	for(unsigned int y = 0; y<sizeof(columns); y++){
		if(columns[y]){
			for(unsigned int x = 0; x<matrix.size(); x++){
				matrix[x][y] = 0;
			}
		}
	}

	printMatrix(matrix);
}

void printMatrix(vector<vector<int>> matrix){
	for(unsigned int x = 0; x<matrix.size(); x++){
		for(unsigned int y = 0; y<matrix[x].size(); y++){
			cout << matrix[x][y] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
