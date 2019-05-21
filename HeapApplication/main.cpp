#include <iostream>

using namespace std;
void Insert(int arr[], int n){
    int temp = arr[n];
    int i = n;
    while(i > 1 && arr[i/2] < temp){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void Remove(int arr[], int n){
    int temp = arr[1];
    arr[1] = arr[n];
    int i = 1;
    int j = i*2;
    while(j < n - 1){
        if(arr[j] < arr[j + 1]){
            j = j + 1;
        }
        if(arr[j] > arr[i]){
            int a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
            i = j;
            j = 2*i;
        } else{
            break;
        }
    }
    arr[n] = temp;
}

void Display(int arr[], int n){
    for(int i= 1; i <= n; i++){
       cout <<arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Heap!" << endl;
    int arr[9] = {0, 15, 12, 30, 20, 40, 6, 10, 45};
    for(int i = 1; i <= 8; i++){
        Insert(arr, i);
    }

    Display(arr, 8);
    Remove(arr, 8);
    Display(arr, 8);
    Remove(arr, 7);
    Display(arr, 8);
    Remove(arr, 6);
    Display(arr, 8);
    Remove(arr, 5);
    Display(arr, 8);
    Remove(arr, 4);
    Display(arr, 8);
    Remove(arr, 3);
    Display(arr, 8);
    Remove(arr, 2);
    Display(arr, 8);
    Remove(arr, 1);
    Display(arr, 8);

    return 0;
}
