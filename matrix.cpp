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
    int N;  
    vector<vector<T>> mtrx;  
public:
    Matrix(int size): N(size), mtrx(size, vector<T>(N)) {} 


    void readfile(ifstream &inputfile) {    //reads matrix from file
        for (int i = 0; i < N; ++i) {       //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                inputfile >> mtrx[i][j];    //reads values for iterations
            }
        }
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << setw(8) << mtrx[i][j];
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result.mtrx[i][j] = mtrx[i][j] + other.mtrx[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    result.mtrx[i][j] += mtrx[i][k] * other.mtrx[k][j];
                }
            }
        }
        return result;
    }

    T diagonalSum() const {
        T sum = 0;
        for (int i = 0; i < N; ++i) {
            sum+= mtrx[i][i];  
            sum += mtrx[i][N - 1 - i]; 
        }
        return sum; 
    }

    void swaprows(int rowa, int rowb) {
        if(rowa >= 0 && rowa < N && rowb >= 0 && rowb < N) {
            swap(mtrx[rowa], mtrx[rowb]); //swaps rows in matrix
        }
    }

    void swapcols(int col1, int col2) {
        if(col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
            for (int i = 0; i < N; ++i) {
                swap(mtrx[i][col1], mtrx[i][col2]);
            }
        }
    }
         
    void chngevalue(int row, int col, T value) {
        if (row >= 0 && row < N && col >= 0 && col < N) {
            mtrx[row][col] = value;
        }
    }
};

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream userfile(filename);
    if (!userfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    int N, type;
    userfile >> N >> type;

    if (type== 0) {
        Matrix<int> A(N), B(N);
        A.readfile(userfile);
        B.readfile(userfile);
    
        cout << "Matrix A:\n"; A.print();
        cout << "Matrix B:\n"; B.print();
        cout << "A + B:\n"; (A + B).print();
        cout << "A * B:\n"; (A * B).print();
        cout << "Diagonal sum of A: " << A.diagonalSum() << endl;
        cout << "Diagonal sum of B: " << B.diagonalSum() << endl;
        cout << "Swapping rows 0 and 1 in A:\n"; A.swaprows(0, 1); A.print();
        cout << "Swapping columns 0 and 1 in A:\n"; A.swapcols(0, 1); A.print();
        cout << "Changing value at (0, 0) in A to 348:\n"; A.chngevalue(0, 0, 348); A.print();
        }   else if (type == 1) {
            Matrix<double> A(N), B(N);
            A.readfile(userfile);
            B.readfile(userfile);

            cout << "Matrix A:\n"; A.print();
            cout << "Matrix B:\n"; B.print();
            cout << "A + B:\n"; (A + B).print();
            cout << "A * B:\n"; (A * B).print();
            cout << "Diagonal sum of A: " << A.diagonalSum() << endl;
            cout << "Diagonal sum of B: " << B.diagonalSum() << endl;
            cout << "Swapping rows 0 and 1 in A:\n"; A.swaprows(0, 1); A.print();
            cout << "Swapping columns 0 and 1 in A:\n"; A.swapcols(0, 1); A.print();
            cout << "Changing value at (0, 0) in A to 348.843:\n"; A.chngevalue(0, 0, 349.843); A.print();

        }
        userfile.close(); 
        return 0;
    }