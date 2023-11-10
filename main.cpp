#include <iostream>

using namespace::std;

template <typename T>
bool isPrime(T num) {
    if (num <= 1) {
        return false;
    }
    for (T i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

template <typename T>
int countPrimes(const T arr[], int size, int primeCounts[]) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) {
            ++count;
            ++primeCounts[arr[i]];
        }
    }
    return count;
}

int main() {
    const int size = 10;
    int arr[size];

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 20;
    }

    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    const int maxNumber = 20;  
    int primeCounts[maxNumber] = { 0 };

    int primeCount = countPrimes(arr, size, primeCounts);

    cout << "Number of prime numbers: " << primeCount << endl;

    for (int i = 0; i < maxNumber; ++i) {
        if (primeCounts[i] > 0) {
            cout << "Number: " << i << ", Repeated: " << primeCounts[i] << " times" << endl;
        }
    }

    return 0;
}
