#include <iostream>

using namespace std;
void merging(int arr[], int low, int mid, int high){
    int B[100];
    int i = low;
    int k = low;
    int j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
            B[k++] = arr[j++];
        } else{
            B[k++] = arr[i++];
        }
    }
    while(i <= mid){
        B[k++] = arr[i++];
    }

    while(j <= high){
        B[k++] = arr[j++];
    }

    for(int m = low; m <= high; m++)
        arr[m] = B[m];

}

void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (high + low)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merging(arr, low,mid,  high);
    }
}

void Display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout <<arr[i] <<" ";
    }
    cout << endl;
}

int main()
{
    cout << "Merge Sort:" << endl;
    int arr[8] = {7, 8, 9, 11, 2, 3, 4, 5};
    Display(arr, 8);
    MergeSort(arr, 0, 7);
    Display(arr, 8);
    return 0;
}
