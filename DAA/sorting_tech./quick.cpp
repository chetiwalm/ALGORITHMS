#include<iostream>
using namespace std;

void quickSortHelper(int input[] , int si , int ei){

  if(si >= ei)
    return;

  int count = 0;
  for(int i=si+1 ; i<=ei ; i++)
  {
    if(input[i] <= input[si])
      count++;
  }
  int temp = input[si + count];
  input[si + count] = input[si];
  input[si] = temp;

  int x = si + count;

  for(int i=si , j=ei ; i<x && j>x ;)
  {
    if(input[i] <= input[x] && input[j] > input[x])
    {
      i++;
      j--;
    }
    else if(input[i] > input[x] && input[j] > input[x])
      j--;
    else if(input[i] <= input[x] && input[j] <= input[x])
      i++;
    else if(input[i] > input[x] && input[j] <= input[x])
    {
      int temp = input[i];
      input[i] = input[j];
      input[j] = temp;
      i++;
      j--;
    }
  }
  quickSortHelper(input , si , x-1);
  quickSortHelper(input , x+1 , ei);
}
void quickSort(int input[], int size) {
  quickSortHelper(input , 0 , size-1);
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout<<endl;
    delete [] input;
}