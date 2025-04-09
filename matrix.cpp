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
matrix(int n) : size(n), data(n, vector<T>(n)) {}

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
                cout << setw(5) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    