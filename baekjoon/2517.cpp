#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> runners;
vector<int> possible;
vector<pair<int,int>> temp;
void Merge(int s, int m, int e);

void mergesort(int s, int e) {
    if (s<e) {
        int mid = (s+e)/2;
        mergesort(s,mid);
        mergesort(mid+1, e);
        Merge(s,mid, e);
    }
}

void Merge(int s, int mid , int e) {
    //cout<<"merge"<<s<<" "<<e<<endl;
    int p1= s;
    int p2 = mid+1;
    int k = s;
    while(p1<= mid && p2<= e){
        if (runners[p1].first >= runners[p2].first){
            temp[k++] = (runners[p1++]);
        }
        else {
            int inverseCount = mid-p1+1;
            //cout<<"Add inverseCount to"<<runners[p2].second<< " "<<inverseCount<<endl;
            possible[runners[p2].second] += inverseCount;
            temp[k++] = runners[p2++];
        }
    }
    while(p1 <= mid) {
        temp[k++] = runners[p1++];
    }
    while(p2 <= e) {
        temp[k++] = runners[p2++];
    }
    for (int i =s; i<=e; i++) {
        runners[i] = temp[i];
    }

} 

int main() {
    scanf("%d", &n);
    runners.assign(n, {0,0});
    temp.assign(n, {0,0});
    possible.assign(n+1, 0);
    for (int i =0; i<n; i++) {
        int ability;
        scanf("%d", &ability);
        runners[i] = {ability, i+1};
    }
    mergesort(0, runners.size() -1);
    for (int i =1; i<=n; i++) {
        printf("%d\n", i-possible[i]);
    }
}