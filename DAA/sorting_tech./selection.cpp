#include <iostream>
#include <cstdlib>

using namespace std;
void selectionSort(int dizi[], int elemanSayisi) {
    int i, j, enKucuk, temp;
    for (i = 0; i < elemanSayisi - 1; i++) {
        enKucuk = i;
        for (j = i + 1; j < elemanSayisi; j++) {
            if (dizi[j] < dizi[enKucuk])
                enKucuk = j;
        }
        temp = dizi[i];
        dizi[i] = dizi[enKucuk];
        dizi[enKucuk] = temp;
    }
}
int main() {
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
    selectionSort(sirala,10);
    for (int j = 0; j < 10; ++j) {
        cout << sirala[j] << " ";
    }
    cout<<endl;
    return 0;
}