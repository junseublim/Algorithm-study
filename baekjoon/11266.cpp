#include <bits/stdc++.h>

using namespace std;

int v, e,cnt = 0, visit_order[10010], num = 1;
bool ans[10010];
vector<int> adj[10010];

//예외: 루트일 경우
//나의 방문순서와 자식들이 만나는 방문순서중 가장 작은 값을 비교
int dfs(int parent, int cur, bool isRoot) {
    int min_vist_order = 987654321; //내 자식들이 만날 수 있는 점중에서 가장 작은 점
    int chlcnt = 0;
    visit_order[cur] = num;
    num++;
    for (int i =0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == parent) continue;
        if (visit_order[nxt]) {
            min_vist_order = min(min_vist_order, visit_order[nxt]);
        }
        else {
            int temp = dfs(cur, nxt, false);
            min_vist_order = min(min_vist_order, temp);
            if (!isRoot && temp >= visit_order[cur]) {
                ans[cur] = true;
            }
            chlcnt++;
        }
    } 
    //리프노드면 단절점 처리 해주지 않음
    if (adj[cur].size() == 1) {
        return visit_order[cur];
    }
    if (isRoot) {
        //예외 처리
        //자식이 두개이상인지 체크
        //두개 이상이면 단절점
        if (chlcnt >=2) {
            ans[cur] = true;
        }
        return 0;
    }
    return min(min_vist_order,visit_order[cur]); //내가 만난 점중에서 방문순서가 가장 낮은 점 반환;
}

int main() {
    scanf("%d%d", &v,&e);
    for (int i =0; i<e; i++) {
        int a,b;
        scanf("%d%d", &a, &b );
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=v; i++) {
        if (visit_order[i] == 0) {
            dfs(0, i, true);
        }
    }
    for (int i = 1; i<=v; i++) {
        if (ans[i]) cnt++;
    }
    printf("%d\n", cnt);
    for (int i =1; i<= v; i++ ) {
        if (ans[i]) {
            printf("%d ", i);
        }
    }
}