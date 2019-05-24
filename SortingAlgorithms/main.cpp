#include <iostream>

using namespace std;
void Swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Display(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout <<arr[i] << " ";
    }
    cout <<endl;
}

void BubleSort(int arr[], int n){
    int j = n - 1;
    while(j >= 0){
        for(int i = 0; i < j; i++){
            if(arr[i] > arr[i+1]){
                Swap(&arr[i], &arr[i+1]);
            }
        }
        Display(arr, 10);
        j--;
    }
}

void SelectionSort(int arr[], int n){

    int i = 0;
    while(i < n){
        for(int j = n - 1; j > i;j--){
            if(arr[j] < arr[j-1]){
                Swap(&arr[j], &arr[j - 1]);
            }
        }
        Display(arr, 10);
        i++;
    }
}
int Partitining(int arr[], int low, int high){
    int i = low - 1;
    int pivot = arr[high];
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        int p = Partitining(arr, low, high);
        QuickSort(arr, p + 1, high);
        QuickSort(arr, low, p - 1);
    }
}






int main()
{
    cout << "Sorting Algorithms:" << endl;
    int arr[10] = {45, 22, 17,9, 7, 4, 2, 6, 5, 1};
    Display(arr, 10);
    //BubleSort(arr, 10);
    //SelectionSort(arr, 10);
    QuickSort(arr, 0, 9);
    Display(arr, 10);
    return 0;
}
