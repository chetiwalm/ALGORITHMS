#include<iostream>
using namespace std;
void swap(int a[], int *g, int *b) {
    int temp;
    temp = a[*g];
    a[*g] = a[*b];
    a[*b] = temp;
}
void maxHeapify(int a[], int parent, int last) {
    int child;
    child = 2 * parent;
    while (child <= last) {
        if ((child + 1 <= last) && (a[child + 1] > a[child]))
            child++;
        if (a[parent] < a[child])
            swap(a, &parent, &child);
        parent = child;
        child = 2 * parent;
    }
}

void buildHeap(int a[], int last) {
    int i;
    for (i = last / 2; i > 0; i--) {
        maxHeapify(a, i, last);
    }
}

void heapSort(int a[], int last) {
    int l;
    l = 1;
    buildHeap(a, last);
    while (last > 1) {
        swap(a, &l, &last);
        last--;
        maxHeapify(a, 1, last);
    }
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

    //Print Dummy Array!
    for (int k = 0; k < 10; ++k) {
        cout << sirala[k] << " ";
    }
    cout << "\n";
    heapSort(sirala,10);
    for (int j = 0; j < 10; ++j) {
        cout << sirala[j] << " ";
    }
    cout<<endl;
    return 0;
}