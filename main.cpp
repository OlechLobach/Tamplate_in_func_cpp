#include <iostream>
using namespace::std;

template <typename T>
void reverseOrder(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    const int size = 5;
    int arr[size] ;

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseOrder(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}