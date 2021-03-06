#include <bits/stdc++.h>

using namespace std;

int n;
int numbers[50];
int cache[50][50];
const int MIN = -987654321;
const int MAX = 987654321;
int numbergame(int s, int e){
    if (e-s == 0) {
        return numbers[s];
    }
    if (e-s == 1) {
        if (numbers[s]> numbers[e]) {
            return numbers[s] -numbers[e];
        }
        return numbers[e]-numbers[s];
    }
    int &ret = cache[s][e];
    if (ret != MIN) return ret;
    int oponent = MAX;
    ret = max(ret, numbers[s] - numbergame(s+1, e));
    ret = max(ret, numbers[e] - numbergame(s, e-1));
    ret = max(ret, -numbergame(s+2, e));
    ret = max(ret, -numbergame(s, e-2));
    return ret; 
    

}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n;
        for (int i=0; i<50; i++) {
            for (int j =0; j<50; j++) {
                cache[i][j] = MIN;
            }
        }
        for (int i =0; i<n;i++) {
            cin>>numbers[i];
        }
        cout<<numbergame(0,n-1)<<endl;
    }
}