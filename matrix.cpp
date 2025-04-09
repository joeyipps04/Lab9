//EECS 348 Lab 9
//Perform matrix operations on an NxN matrix
//Inputs: 
//Outputs: 
//Myself, ChatGPT
//Joey Ippolito, 3114450
// 04/09/2025

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
    int size;
    vector<vector<T>> data;

public:
matrix(int N) : size(N), data(N, vector<T>(N)) {}

    void set(int i, int j, T value) {
        data[i][j] = value;
    }
    
    T get(int i, int j) const {
        return data[i][j];
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << setw(8) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix& other) const { //function to add two matrices
        Matrix added(size);    //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                added.T[i][j] = T[i][j] + other.T[i][j];   //adds values of two matrices
            }
        }
        return added;   //returns added matrix
    }

    Matrix multiply(const Matrix &other) const {    //function to multiply two matrices
        Matrix multiplied(N);   //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                for (int k = 0; k < N; ++k) {   //iterates through columns of first matrix and rows of second matrix
                    multiplied.T[i][j] += T[i][k] * other.T[k][j]; //multiplies values of two matrices
                }
            }
        }
        return multiplied;  //returns multiplied matrix
    }

    int diagonalsum() const {   //function add values of diagonal of matrix
        int sum = 0;    //initializes sum to 0
        for (int i = 0; i < N; ++i) {   //iterates through rows
            sum += T[i][i];  //adds values of diagonal from top left to bottom right
            sum += T[i][N-1-i];  //adds values of diagonal from top right to bottom left
        }
        return sum;  //returns sum of diagonals
    }

    void swaprows(int row1, int row2) { //function to swap two rows of matrix
        swap(T[row1], T[row2]);   //swaps rows using std swap function
    }
    //used chatgpt to help find swap function 
    void swapcolumns(int col1, int col2) {  //function to swap two columns of matrix
        for (int i = 0; i < N; ++i) {   //iterates through rows
            swap(T[i][col1], T[i][col2]); //swaps columns using std swap function
        }   //have to iterate through rows to swap columns, by swapping each value individually
    }

    void chngevalue(int row, int col, int value) {  //function to change value of matrix at given row and column
        T[row][col] = value; //sets value at given row and column to new value
    }
};