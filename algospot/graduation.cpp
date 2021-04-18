#include <bits/stdc++.h>

using namespace std;
const int MAXN = 12;
const int INF = 987654321;
int n,m,k,l;
//i번째 학기에 개설되는 과목
int classes[10];

int cache[10][1<<MAXN];

//i번째 과목의 선수과목의 집합
int prerequisite[MAXN];

int bitCnt(int num) {
    int i = 0;
    int cnt = 0;
    while( 1<<i <= num) {
        if (1<<i & num) cnt++;
        i++; 
    }
    return cnt;
}

int graduate(int semester, int taken) {
    if (bitCnt(taken)>=k) return 0;
    if (semester == m) return INF;
    int& ret = cache[semester][taken];
    if (ret != -1) return ret;
    ret = INF;
    int canTake = (classes[semester] & ~taken);
    for (int i =0; i<n; i++) {
        if ((prerequisite[i] & taken) != prerequisite[i] && (canTake & 1<<i) ) {
            canTake &= ~(1<<i);
        }
    }
    for (int take = canTake; take>0; take = ((take-1) & canTake)) {
        if (bitCnt(take) > l) continue;
        ret = min(ret, graduate(semester+1, take | taken) +1);
    }
    ret = min(ret, graduate(semester+1, taken));
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n>>k>>m>>l;
        int needTake = 0;
        int taken = 0;
        for (int i=0; i<k; i++) {
            needTake |= 1<<i;
        }
        memset(cache, -1, sizeof(cache));
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));
        for (int i =0; i<n; i++) {
            int pre;
            cin>>pre;
            for (int j=0; j<pre; j++) {
                int num ;
                cin>>num;
                prerequisite[i] |= 1<<num;
            }
        }
        for (int i=0; i<m; i++) {
            int cnt;
            cin>>cnt;
            for (int j =0; j<cnt; j++) {
                int cl;
                cin>>cl;
                classes[i] |= 1<<cl;
            }
        }
        int v = graduate(0, taken);
        if (v == INF) {
            cout<<"IMPOSSIBLE\n";
        }
        else {
            cout<<v<<"\n";
            
        }
    }

}