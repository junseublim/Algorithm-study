#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int maxNum = 0;
    vector<int> numbers (n, 0);
    vector<int> output (0,0);
    for (int i =0; i<n; i++) {
        cin>>numbers[i];
        maxNum = max(maxNum, numbers[i]);
    }
    vector<int> cnt (maxNum+1, 0);
    for (int i =0; i<n; i++) {
        cnt[numbers[i]]+=1;
    }
    while(output.size() < n) {
        cout<<output.size()<<endl;
        int maxCnt = 0;
        int maxValue = 0;
        for (int i =0; i<maxNum; i++) {
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                maxValue = i;
            }
            else if (cnt[i] == maxCnt) {
                for (int j =0; j<n; j++) {
                    if (numbers[j] == i) {
                        maxValue = i;
                        break;
                    }
                    else if (numbers[j] == maxValue) {
                        break;
                    }
                }
            }
        }
        cnt[maxValue] = 0;
        while(maxCnt--) {
            output.push_back(maxValue);
        }
    }
    for (int i =0; i<n; i++) {
        cout<<output[i]<<" ";
    }
    cout<<endl;

}