#include<iostream>
using namespace std;
void shellSort(int dizi[], int elemanSayisi) {
    int j;
    for (int gap = elemanSayisi / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < elemanSayisi; ++i) {
            int temp = dizi[i];
            for (j = i; j >= gap && temp < dizi[j - gap]; j -= gap) {
                dizi[j] = dizi[j - gap];
            }
            dizi[j] = temp;
        }
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
    shellSort(sirala,10);
    for (int j = 0; j < 10; ++j) {
        cout << sirala[j] << " ";
    }
    cout<<endl;
    return 0;
}