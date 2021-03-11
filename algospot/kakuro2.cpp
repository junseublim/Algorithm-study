#include <bits/stdc++.h>

using namespace std;
int n, q;
const int MAXN = 20;
int candidates[10][46][1024];
int color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN];

void put (int y, int x, int val) {
    for (int h =0; h<2; h++) {
        known[hint[y][x][h]] += (1<<val);
    }
    
    value[y][x] = val;
}

void remove(int y, int x, int val) {
    for (int h=0; h<2; h++) {
        known[hint[y][x][h]] -=(1<<val);
    }
    
    value [y][x] = 0;
}

int getSize(int mask) {
    int sz = 0;
    for(int i = 2; i<1024; i*=2) {
        if (mask & i){
            sz++;
        }
    }
    return sz;
}

int getSum(int mask) {
    int sum = 0;
    for(int i = 2, j = 1; i<1024; i*=2) {
        if (mask & i){
            sum+=j;
        }
        j++;
    }
    return sum;
}

void generateCandidates() {
    memset(candidates, 0, sizeof(candidates));
    for (int i =0; i<1024; i+=2) {
        int l = getSize(i);
        int s = getSum(i);
        int subset = i;
        while(true) {
            candidates[l][s][subset] |= (i & ~subset);
            if (subset == 0) break;
            subset = (subset -1) & i;
        }
    }
} 


int getCandHint(int hint) {
    // cout<<"candiates length : "<<length[hint]<<" sum : "<<sum[hint]<<" known : "<<known[hint]<<" = "<<candidates[length[hint]][sum[hint]][known[hint]]<<endl;
    return candidates[length[hint]][sum[hint]][known[hint]];
}
int getCandCoord(int y, int x) {
    // cout<<"getCandHint "<<y<<" "<<x<<" = "<<hint[y][x][0]<<endl;
    // cout<<"getCandHint "<<y<<" "<<x<<" = "<<hint[y][x][1]<<endl;
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}
void printSol() {
    for (int i =0; i<n; i++) {
        for (int j =0; j<n; j++) {
            cout<<value[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
bool search() {
    //cout<<"search"<<endl;
    int y =-1, x = -1, minCands = 1023;
    for (int i =0; i<n; i++) {
        for (int j =0; j<n; j++) {
            if (color[i][j] == 1 && value[i][j] == 0) {
                int cands = getCandCoord(i,j);
                if (getSize(minCands) > getSize(cands)) {
                    minCands = cands;
                    y= i;
                    x= j;
                }
            }
        }
    }
    //cout<<"search y: "<<y<<endl;
    //cout<<"search minCands: "<<minCands<<endl;
    if (minCands == 0) return false;
    if (y == -1) {
        printSol();
        return true;
    }
    for (int val = 1; val <=9; val++) {
        if (minCands & (1<<val)) {
            put (y,x, val);
            if (search()) return true;
            remove(y,x,val);
        }
    }
    return false;
}

int main() {
    int C;
    cin>>C;
    generateCandidates();
    while(C--) {
        memset(value, 0,sizeof(value));
        memset(hint, 0,sizeof(hint));
        memset(known, 0,sizeof(known));
        memset(sum, 0,sizeof(sum));
        memset(length, 0,sizeof(length));
        cin>>n;
        for (int i=0; i<n; i++) {
            for(int j =0; j<n; j++) {
                cin>>color[i][j];
            }
        }
        cin>>q;
        for (int i =0; i<q; i++) {
            int y,x,direction, sumV;
            cin>>y>>x>>direction>>sumV;
            y-=1;
            x-=1;
            sum[i] = sumV;
            length[i] = 0;
            known[i] = 0;
            if (direction == 0) {
                x+=1;
                while(x<n && color[y][x] == 1) {
                    hint[y][x][0] = i;
                    length[i]++;
                    x++;
                }
            }
            else {
                y+=1;
                while(y<n && color[y][x] == 1) {
                    hint[y][x][1] = i;
                    length[i]++;
                    y++;
                }
            }
        }
        search();
    }
}