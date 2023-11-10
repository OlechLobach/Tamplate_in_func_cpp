#include <iostream>
#include <ctime>

template <typename T>
void generateRandomArray(T arr[], int size, T minVal, T maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T>
T findMax(const T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


template <typename T>
T findMax(const T arr[][3], int rows, int cols) {
    T maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}


template <typename T>
T findMax(const T arr[][3][3], int dim1, int dim2, int dim3) {
    T maxVal = arr[0][0][0];
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                if (arr[i][j][k] > maxVal) {
                    maxVal = arr[i][j][k];
                }
            }
        }
    }
    return maxVal;
}


template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}


template <typename T>
T findMax(T a, T b, T c) {
    return findMax(findMax(a, b), c);
}

int main() {
    const int size1D = 5;
    int arr1D[size1D];

    srand(static_cast<unsigned>(time(nullptr)));
    generateRandomArray(arr1D, size1D, 1, 20);

    std::cout << "1D Array: ";
    printArray(arr1D, size1D);

    std::cout << "Max in 1D array: " << findMax(arr1D, size1D) << std::endl;

    const int size2D = 2;
    int arr2D[size2D][3];

    generateRandomArray(arr2D[0], 3, 1, 20);
    generateRandomArray(arr2D[1], 3, 1, 20);

    std::cout << "2D Array: " << std::endl;
    for (int i = 0; i < size2D; ++i) {
        printArray(arr2D[i], 3);
    }

    std::cout << "Max in 2D array: " << findMax(arr2D, size2D, 3) << std::endl;

    const int size3D = 2;
    int arr3D[size3D][3][3];

    generateRandomArray(arr3D[0][0], 3, 1, 20);
    generateRandomArray(arr3D[0][1], 3, 1, 20);
    generateRandomArray(arr3D[0][2], 3, 1, 20);
    generateRandomArray(arr3D[1][0], 3, 1, 20);
    generateRandomArray(arr3D[1][1], 3, 1, 20);
    generateRandomArray(arr3D[1][2], 3, 1, 20);

    std::cout << "3D Array: " << std::endl;
    for (int i = 0; i < size3D; ++i) {
        for (int j = 0; j < 3; ++j) {
            printArray(arr3D[i][j], 3);
        }
        std::cout << std::endl;
    }

    std::cout << "Max in 3D array: " << findMax(arr3D, size3D, 3, 3) << std::endl;

    std::cout << "Max of two integers: " << findMax(10, 5) << std::endl;
    std::cout << "Max of three integers: " << findMax(5, 10, 8) << std::endl;

    return 0;
}
