#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int i =0, j= n-1;
    int ai, aj;
    int mn =987654321;
    while (i <j) {
        int temp = arr[i]+arr[j];
        if (abs(temp) < mn) {
            mn = abs(temp);
            ai = i; aj=j;
        }
        if (temp > 0) {
            j--;
        }
        else {
            i++;
        }
    }
    cout<<arr[ai]<<" "<<arr[aj]<<"\n";
}