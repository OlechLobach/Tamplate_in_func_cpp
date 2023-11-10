#include <iostream>
#include <ctime>

using namespace :: std;


void initializeMatrixAuto(int** data, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            
            data[i][j] = i * cols + j + 1;
        }
    }
}


void displayMatrix(int** data, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

void findDiagonalMinMax(int** data, int rows, int cols, int& maxDiagonal, int& minDiagonal) {
    maxDiagonal = data[0][0];
    minDiagonal = data[0][0];

    for (int i = 1; i < rows && i < cols; ++i) {
        if (data[i][i] > maxDiagonal) {
            maxDiagonal = data[i][i];
        }
        if (data[i][i] < minDiagonal) {
            minDiagonal = data[i][i];
        }
    }
}

void sortRows(int** data, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = 0; k < cols - j - 1; ++k) {
                if (data[i][k] > data[i][k + 1]) {
                  
                    int temp = data[i][k];
                    data[i][k] = data[i][k + 1];
                    data[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

  
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    initializeMatrixAuto(matrix, rows, cols);

    cout << "Original Matrix:\n";
    displayMatrix(matrix, rows, cols);

    int maxDiagonal, minDiagonal;
    findDiagonalMinMax(matrix, rows, cols, maxDiagonal, minDiagonal);
    cout << "Max diagonal element: " << maxDiagonal << endl;
    cout << "Min diagonal element: " << minDiagonal << endl;

    sortRows(matrix, rows, cols);

    cout << "Matrix after sorting rows:\n";
    displayMatrix(matrix, rows, cols);

 
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

