#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 20;
const int MIN_VAL = -20;
const int MAX_VAL = 50;

void fillArrayRecursive(int arr[], int size, int i = 0);
void printArrayRecursive(const int arr[], int size, int i = 0);
int countRecursive(const int arr[], int size, int i = 0);
int sumRecursive(const int arr[], int size, int i = 0);
void replaceRecursive(int arr[], int size, int i = 0);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int a[SIZE];

    fillArrayRecursive(a, SIZE);

    cout << "Original array:" << endl;
    printArrayRecursive(a, SIZE);
    cout << endl << "--------------------------------" << endl;

    int count = countRecursive(a, SIZE);
    int sum = sumRecursive(a, SIZE);

    cout << "Count of satisfying elements: " << count << endl;
    cout << "Sum of satisfying elements:   " << sum << endl;
    cout << "--------------------------------" << endl;

    replaceRecursive(a, SIZE);

    cout << "Modified array:" << endl;
    printArrayRecursive(a, SIZE);
    cout << endl;

    return 0;
}

void fillArrayRecursive(int arr[], int size, int i) {
    if (i >= size) return;

    arr[i] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
    fillArrayRecursive(arr, size, i + 1);
}

void printArrayRecursive(const int arr[], int size, int i) {
    if (i >= size) return;

    cout << setw(4) << arr[i];
    printArrayRecursive(arr, size, i + 1);
}

int countRecursive(const int arr[], int size, int i) {
    if (i >= size) return 0;

    int currentIsMatch = (arr[i] > 0 && i % 5 != 0) ? 1 : 0;

    return currentIsMatch + countRecursive(arr, size, i + 1);
}

int sumRecursive(const int arr[], int size, int i) {
    if (i >= size) return 0;

    int currentValue = (arr[i] > 0 && i % 5 != 0) ? arr[i] : 0;

    return currentValue + sumRecursive(arr, size, i + 1);
}

void replaceRecursive(int arr[], int size, int i) {
    if (i >= size) return;

    if (arr[i] > 0 && i % 5 != 0) {
        arr[i] = 0;
    }

    replaceRecursive(arr, size, i + 1);
}