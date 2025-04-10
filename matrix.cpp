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
    }