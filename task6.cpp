#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findMode(int arr[], int size) {
    vector<int> modes;
    if (size <= 0 || arr == nullptr) return modes;

    map<int, int> freq;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxCount) {
            maxCount = freq[arr[i]];
        }
    }

    for (auto const &p : freq) {
        if (p.second == maxCount) {
            modes.push_back(p.first);
        }
    }
    return modes;
}

void printModes(const vector<int> &modes) {
    if (modes.empty()) {
        cout << "Empty array / No mode" << endl;
        return;
    }
    for (int m : modes) {
        cout << m << " ";
    }
    cout << endl;
}

int main() {
    cout << "Histogram Analysis" << endl;

    
    int arr1[] = { 1, 3, 3, 3, 2, 4, 2, 5 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Test Unique mode: ";
    printModes(findMode(arr1, size1));

    
    int arr2[] = { 1, 2, 2, 3, 3, 4 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Test Multiple modes: ";
    printModes(findMode(arr2, size2));

    
    int arr3[] = {};
    cout << "Test Empty array: ";
    printModes(findMode(arr3, 0));

    return 0;
}
