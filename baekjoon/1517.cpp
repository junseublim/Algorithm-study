#include <bits/stdc++.h>
#define MAX 5000000

using namespace std;
int n;
int num[MAX];
int temp[MAX];
long long total = 0;

void merge(int s, int mid, int e) {
    int i = s;
    int j = mid+1;
    long long cnt = (mid-s+1);
    int k =0;
    while ( i <= mid &&  j <= e) {
        if (num[i] <= num[j]) {
            temp[k] = num[i];
            cnt--;
            i++;
        }
        else {
            temp[k] = num[j];
            total += cnt;
            j++;
        }
        k++;
    }
    while ( i <= mid) {
        temp[k] = num[i];
        i++;
        k++;
    }
    while (j<=e){
        temp[k] = num[j];
        k++;
        j++;
    }
    for (int l =0; l<k; l++) {
        num[s+l] = temp[l];
    }
}

void mergeSort(int s, int e) {
    if (s >= e) return;
    int mid = (s+e)/2;
    mergeSort(s,mid);
    mergeSort(mid+1,e);
    merge(s,mid,e);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i =0; i<n; i++) {
        cin>>num[i];
    }
    mergeSort(0,n-1);
    // for (int i =0; i<n; i++) {
    //     cout<<num[i]<<" ";

    // }
    cout<<total<<"\n";
}