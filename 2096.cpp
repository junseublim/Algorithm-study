#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
vector<int> minV;

vector<int> maxV;
vector<int> minVP;
vector<int> maxVP;
int n;



int main() {
    
    cin>>n;
    minV.assign(3, INF);
    maxV.assign(3, 0);
    minVP.assign(3, INF);
    maxVP.assign(3, 0);
    int temp;
    for (int i =0; i<3; i++) {
        cin>>temp;
        minVP[i] = temp;
        maxVP[i] = temp;
    }
    for (int level = 1; level <n; level++) {
        for (int i=0; i<3; i++) {
            cin>>temp;
            if (i == 0) {
                minV[i] = min(minVP[i] + temp, minV[i]) ;
                maxV[i] = max(maxVP[i] + temp, maxV[i]) ;
                minV[i] = min(minVP[i+1] + temp, minV[i]) ;
                maxV[i] = max(maxVP[i+1] + temp, maxV[i]) ;
            }
            else if (i == 1) {
                minV[i] = min(minVP[i] + temp, minV[i]) ;
                maxV[i] = max(maxVP[i] + temp, maxV[i]) ;
                minV[i] = min(minVP[i-1] + temp, minV[i]);
                maxV[i] = max(maxVP[i-1] + temp, maxV[i]);
                minV[i] = min(minVP[i+1] + temp, minV[i]);
                maxV[i] = max(maxVP[i+1] + temp, maxV[i]);
            }
            else {
                minV[i] = min(minVP[i] + temp, minV[i]);
                maxV[i] = max(maxVP[i] + temp, maxV[i]);
                minV[i] = min(minVP[i-1] + temp, minV[i]);
                maxV[i] = max(maxVP[i-1] + temp, maxV[i]);
            }
            
        }
        for (int i=0; i<3; i++) {
            minVP[i] = minV[i];
            maxVP[i] = maxV[i];
            minV[i] = INF;
            maxV[i] = 0;
        }
       
        
    }
    cout<<*max_element(maxVP.begin(), maxVP.end())<<" "<<*min_element(minVP.begin(), minVP.end())<<endl;
}