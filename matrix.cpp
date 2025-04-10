//EECS 348 Lab 9
//Perform matrix operations on an NxN matrix
//Inputs: 
//Outputs: 
//Myself, ChatGPT, copilot
//Joey Ippolito, 3114450
// 04/09/2025

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//imports libraries
using namespace std;

template <typename T>   //template class, lets the file use ints and doubles
class Matrix {  //intializes matrix class
private:    //private variables
    int N;      //size of matrix
    vector<vector<T>> mtrx;  //vector of vectors to represent the matrix
public:   //public functions
    Matrix(int size): N(size), mtrx(size, vector<T>(N)) {} //initializes matrix of size NxN and all 0's


    void readfile(ifstream &inputfile) {    //reads matrix from file
        for (int i = 0; i < N; ++i) {       //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                inputfile >> mtrx[i][j];    //reads values for iterations
            }
        }
    }

    void print() const {    //prints matrix
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                cout << setw(8) << mtrx[i][j];  //sets width of output to 8 spaces
            }   
            cout << endl;   
        }
    }

    Matrix operator+(const Matrix &other) const {   //overloads addition operator to add two matrices
        Matrix result(N);   //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                result.mtrx[i][j] = mtrx[i][j] + other.mtrx[i][j];  //adds values of two matrices
            }
        }
        return result;  //returns added matrix
    }

    Matrix operator*(const Matrix &other) const {   //overloads multiplication operator to multiply two matrices
        Matrix result(N);   //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                for (int k = 0; k < N; ++k) {   //iterates through columns of first matrix and rows of second matrix
                    result.mtrx[i][j] += mtrx[i][k] * other.mtrx[k][j]; //multiplies values of two matrices
                }
            }
        }
        return result;  //returns multiplied matrix
    }

    T diagonalSum() const { //function to calculate diagonal sum of matrix
        T sum = 0;  //initializes sum to 0
        for (int i = 0; i < N; ++i) {   //iterates through rows
            sum+= mtrx[i][i];   //adds values of diagonal from top left to bottom right
            sum += mtrx[i][N - 1 - i];  //adds values of diagonal from top right to bottom left
        }
        return sum;     //returns sum of diagonals
    }

    void swaprows(int rowa, int rowb) { //function to swap two rows of matrix
        if(rowa >= 0 && rowa < N && rowb >= 0 && rowb < N) {    //checks if rows are in bounds
            swap(mtrx[rowa], mtrx[rowb]); //swaps rows in matrix
        }
    }

    void swapcols(int col1, int col2) { //function to swap two columns of matrix
        if(col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {    //checks if columns are in bounds
            for (int i = 0; i < N; ++i) {   //iterates through rows
                swap(mtrx[i][col1], mtrx[i][col2]); //swaps values in each row at the specified columns
            }
        }
    }
         
    void chngevalue(int row, int col, T value) {        //function to change value of matrix at given row and column
        if (row >= 0 && row < N && col >= 0 && col < N) {   //checks if row and column are in bounds
            mtrx[row][col] = value;     //sets value at given row and column to new value
        }
    }
};

int main() {    //main function
    string filename;    //initializes filename
    cout << "Enter the filename: "; //asks user for file
    cin >> filename;    //receives file from user

    ifstream userfile(filename);    //opens file to be read
    if (!userfile) {    //checks if file opened successfully
        cerr << "Error opening file." << endl;  //prints error message if not
        return 1;
    }
    int N, type;    //initializes N and type
    userfile >> N >> type;  //reads N and type from file

    if (type== 0) { //checks if matrix is int
        Matrix<int> A(N), B(N); //creates two matrices of size N
        A.readfile(userfile);   //reads first matrix
        B.readfile(userfile);   //reads second matrix
        
        //goes through each operation and prints for the given matrix. Used copilot to write these more efficiently
        cout << "Matrix A:\n"; A.print();
        cout << "Matrix B:\n"; B.print();
        cout << "A + B:\n"; (A + B).print();
        cout << "A * B:\n"; (A * B).print();
        cout << "Diagonal sum of A: " << A.diagonalSum() << endl;
        cout << "Diagonal sum of B: " << B.diagonalSum() << endl;
        cout << "Swapping rows 0 and 1 in A:\n"; A.swaprows(0, 1); A.print();
        cout << "Swapping columns 0 and 1 in A:\n"; A.swapcols(0, 1); A.print();
        cout << "Changing value at (0, 0) in A to 348:\n"; A.chngevalue(0, 0, 348); A.print();
        }   else if (type == 1) {   //if type is double
            Matrix<double> A(N), B(N);  //creates two matrices of size N
            A.readfile(userfile);   //reads first matrix
            B.readfile(userfile);   //reads second matrix
            //goes through each operation and prints for the given matrix. Used copilot to write these more efficiently
            cout << "Matrix A:\n"; A.print();
            cout << "Matrix B:\n"; B.print();
            cout << "A + B:\n"; (A + B).print();
            cout << "A * B:\n"; (A * B).print();
            cout << "Diagonal sum of A: " << A.diagonalSum() << endl;
            cout << "Diagonal sum of B: " << B.diagonalSum() << endl;
            cout << "Swapping rows 0 and 1 in A:\n"; A.swaprows(0, 1); A.print();
            cout << "Swapping columns 0 and 1 in A:\n"; A.swapcols(0, 1); A.print();
            cout << "Changing value at (0, 0) in A to 348.843:\n"; A.chngevalue(0, 0, 348.843); A.print();

        }
        userfile.close(); //closes file
        return 0;       //exits program
    }