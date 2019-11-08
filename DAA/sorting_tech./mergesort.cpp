#include <iostream>
using namespace std;

void merge(int input[] , int si, int ei){
  int n = ei - si + 1;
  int temp[n] , i, j, k = 0;
  int mid = (si + ei)/2;
  for(i=si , j=mid+1 ; i<=mid && j<=ei ; k++)
  {
    if(input[i] < input[j])
    {
      temp[k] = input[i];
      i++;
    }
    else
    {
      temp[k] = input[j];
      j++;
    }
  }
  while(i<=mid)
  {
    temp[k] = input[i];
    i++;
    k++;
  }
  while(j<=ei)
  {
    temp[k] = input[j];
    j++;
    k++;
  }
  for(int k=0 ; k<n ; k++)
  {
    input[si + k] = temp[k];
  }
}
void mergeSortHelper(int input[] , int si , int ei){
  if(si >= ei)
    return;

  int mid = (si + ei)/2;
  mergeSortHelper(input , si , mid);
  mergeSortHelper(input , mid + 1 , ei);
  merge(input , si , ei);
}

void mergeSort(int input[], int size){
  mergeSortHelper(input , 0 , size-1);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  cout<<endl;
}