#include <iostream>
#include <cstdlib>
using namespace std;
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main() {
    //Create Dummy Array!!!
    int sirala[10];
    
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            sirala[i] = i;
        }
        else {
            sirala[i] = 10 - i;
        }
    }
    for (int k = 0; k < 10; ++k) {
        cout << sirala[k] << " ";
    }
    cout << "\n";
    radixSort(sirala,10);

    for (int j = 0; j < 10; ++j) {
        cout << sirala[j] << " ";
    }
    cout<<endl;
    return 0;
}