#include <bits/stdc++.h>

using namespace std;

int* BubbleSort(int* arr) {
    for (int i =0; i<20; i++) {
        for (int j =1; j<20-i; j++) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;

}

int* SelectionSort(int* arr) {
    for (int i =0; i<20; i++) {
        int minimum = arr[i];
        for (int j =i+1; j<20; j++) {
            if (arr[j] < minimum) {
                minimum = arr[j];
            }
        }
        arr[i] = minimum;
    }
    return arr;

}

int* InsertionSort(int* arr) {
    for (int i =0; i<20; i++) {
        for (int j =i-1; j>=0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
    return arr;
}


int main(){
    int arr[20] = {10,9,8,6,7,5,4,2,3,1,12,13,34,45,67,55,22,11,103,14};
    int* ans = BubbleSort(arr);
    for (int i =0; i< 20; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans = SelectionSort(arr);
    for (int i =0; i< 20; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans = InsertionSort(arr);
    for (int i =0; i< 20; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}