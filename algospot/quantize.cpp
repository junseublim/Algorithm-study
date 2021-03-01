#include <bits/stdc++.h>
using namespace std;
int cache[101][11];
int n;
int s;
vector<int> nums;
const int INF = 987654321;

int minError(int start, int end) {
    int avg = 0;
    for (int i =start; i<=end; i++) {
        avg += nums[i];
    }
    avg = round(double(avg)/(end-start+1));
    int minE = 0;
    for (int i =start; i<=end; i++) {
        minE += pow(nums[i] - avg, 2);
    }
    return minE;
}

int quantize(int from, int parts) {
    if (from == n) {
        return 0;
    }
    if (parts == 0) return INF;
    int &ret =  cache[from][parts];
    if (ret != -1) return ret;
    ret = INF;
    for (int partSize = 1; from + partSize <=n ; partSize++) {
        ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
    }
    return ret;
}
int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n>>s;
        nums.clear();
        for (int i=0; i<=100; i++) {
            memset(cache[i], -1, sizeof(cache[i]));
        }
        for (int i=0; i<n;i++) {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end());
        cout<< quantize(0,s)<<endl;
    }
}