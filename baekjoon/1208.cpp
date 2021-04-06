#include <bits/stdc++.h>

using namespace std;
int n,s;
int smaller[1048576];
int bigger[1048576];

int nums[40];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    long long cnt = 0;
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    int half = n / 2;
    int smallSize = (1 << (n - half)), bigSize = (1 << half);
    for (int i = 0; i < smallSize; ++i)
        for (int j = 0; j < n - half; ++j)
            if (i & (1 << j)) smaller[i] += nums[j];

    for (int i = 0; i < bigSize; ++i)
        for (int j = 0; j < half; ++j)
            if (i & (1 << j)) bigger[i] += nums[j + (n - half)];

    sort(smaller, smaller+smallSize);
    sort(bigger, bigger+bigSize);
    int i =0, j = bigSize-1;
    int ii,jj;
    while ( i < smallSize && j >= 0) {
        int val = smaller[i] + bigger[j];
        if (val == s) {
            long long countFront = 1, countBack = 1;
            i++; j--;
            
            while (i < smallSize && smaller[i] == smaller[i - 1]) {
                i++;
                countFront++;
            }
            while (j < bigSize && bigger[j] == bigger[j + 1]) {
                j--;
                countBack++;
            }
            cnt += (countFront * countBack);
        }
        else if (val < s) {
            i++;
        }
        else if (val > s) {
            j--;
        }
    }
    if (s == 0) cnt--;
    cout<<cnt<<"\n";


}