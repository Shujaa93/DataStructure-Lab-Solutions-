#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

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

    string line;
    getline(file, line);
    file.close();

    const int LIMIT = 5000;
    int arr[LIMIT];
    int count = 0;

    stringstream ss(line);
    string value;

    while (getline(ss, value, ',') && count < LIMIT) {
        arr[count++] = stoi(value);
    }

    auto start = high_resolution_clock::now();
    selectionSort(arr, count);
    auto end = high_resolution_clock::now();

    cout << "Selection Sort Completed\n";
    cout << "Total numbers sorted: " << count << endl;
    cout << "Selection Sort: "
         << duration_cast<milliseconds>(end - start).count()
         << " milliseconds\n";

    return 0;
}
