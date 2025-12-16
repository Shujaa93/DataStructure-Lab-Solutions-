#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

// Optimized Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {

    ifstream file("numbers.txt");
    if (!file) {
        cout << "Error: numbers.txt not found!" << endl;
        return 1;
    }

    // Read the entire line (comma-separated numbers)
    string line;
    getline(file, line);
    file.close();

    const int LIMIT = 5000;   // use only few thousand numbers
    int arr1[LIMIT];
    int arr2[LIMIT];
    int count = 0;

    stringstream ss(line);
    string value;

    // Read first LIMIT numbers
    while (getline(ss, value, ',') && count < LIMIT) {
        arr1[count] = stoi(value);
        arr2[count] = arr1[count]; // copy for second sort
        count++;
    }

    // Bubble Sort timing
    auto start = high_resolution_clock::now();
    bubbleSort(arr1, count);
    auto end = high_resolution_clock::now();
    auto bubbleTime = duration_cast<milliseconds>(end - start).count();

    // Selection Sort timing
    start = high_resolution_clock::now();
    selectionSort(arr2, count);
    end = high_resolution_clock::now();
    auto selectionTime = duration_cast<milliseconds>(end - start).count();

    cout << "Total numbers used: " << count << endl;
    cout << "Bubble Sort Time: " << bubbleTime << " milliseconds" << endl;
    cout << "Selection Sort Time: " << selectionTime << " milliseconds" << endl;

    return 0;
}
