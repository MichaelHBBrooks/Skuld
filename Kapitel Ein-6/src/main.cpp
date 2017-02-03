/**
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a
 * method to rotate the image by 90 degrees. Can you do this in place?
 *
 * Programmer response:
 * Do I know the size of N? I'm guessing not.
 * Can I choose how to represent this matrix? A vector? As one-dimensional array? As an object?
 * I feel like I'm getting hung up on the structure of the matrix rather than solving it.
 *
 *
 * This took me way, WAY longer than it should have. I knew what I wanted, but I kept interchanging
 * the variables. If I were doing this with pseudocode, I would need to focus on the larger picture
 * rather than the smaller picture. I had the small scale right, but I kept mixing up the x and y
 * coordinates.
 * I should have written out something like, "the top row is conceptualized with x remaining the
 * same, while y changes". That part I got just fine, but it was when I transitioned to thinking
 * about the right-hand column's manipulation, it fell apart.
 * Conceptualize better!
 *
 * I also spent a chunk of time in the beginning trying to figure out the best way to represent the
 * 2 dimensional array. Arrays such as int x[][] in C++ don't like being passed around. The array's
 * size must be known, which goes against what the question asked. I should have used vectors
 * earlier. Conceptually though, I knew how it should've been represented. This step in pseudocode
 * is trivial however.
 */

#include<iostream>
#include<vector>

using namespace std;

void printImage(vector<vector<int>> img_array);
void rotateImage(vector<vector<int>> img_array);

int main(int argc, char* argv[]){
	vector<vector<int>> some_array = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
			{3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
			{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
			{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
			{6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
			{7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
			{8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
			{9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

	vector<vector<int>> some_array2 = {
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8}};

	printImage(some_array);
	rotateImage(some_array);

	printImage(some_array2);
	rotateImage(some_array2);

	return 0;
}

void printImage(vector<vector<int>> img_array){
	for(unsigned int x = 0; x < img_array.size(); x++){
		for(unsigned int y = 0; y < img_array[x].size(); y++){
			cout << img_array[x][y];
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * t = 0,0
 * n = array size
 * t = 0,0
 * 0,0 = 0,9
 * 0,9 = 9,9
 * 9,9 = 9,0
 * 9,0 = t
 * ...
 * x=0,y=1
 * x,y = y,n-x
 * y,n-x = n,n-y
 * n,n-y = n-y,x
 * n-y,x = temp
 *
 * @param img_array
 */

//0123456
//0123456
//0123456
//0123456
//0123456
//0123456

void rotateImage(vector<vector<int>> img_array){
	unsigned int n = img_array.size()-1;
	cout << "size: " << n << ", half size: " << n/2 << endl;
	for(unsigned int x = 0; x <= n/2; x++){
		for(unsigned int y = x; y < n-x; y++){
			int temp = img_array[x][y];
			//  right -> top
			img_array[x  ][y  ] = img_array[y  ][n-x];
			//  bottom -> right
			img_array[y  ][n-x] = img_array[n-x][n-y];
			//  left -> bottom
			img_array[n-x][n-y] = img_array[n-y][x  ];
			//  top -> left
			img_array[n-y][x  ] = temp;
		}
	}
	printImage(img_array);
}
