#include <iostream>

#include <ctime>   

using namespace :: std;


template <typename T>
void findMinMax(const T arr[], int size, T& minValue, int& minIndex, T& maxValue, int& maxIndex) {
    minValue = arr[0];
    minIndex = 0;
    maxValue = arr[0];
    maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
}

int main() {
    const int size = 10;
    int arr[size];

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }

    
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int minValue, minIndex, maxValue, maxIndex;
    findMinMax(arr, size, minValue, minIndex, maxValue, maxIndex);

   
    cout << "Min value: " << minValue << ", Index: " << minIndex << endl;
    cout << "Max value: " << maxValue << ", Index: " << maxIndex << endl;

    return 0;
}
