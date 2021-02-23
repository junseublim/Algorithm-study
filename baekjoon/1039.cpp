#include <bits/stdc++.h>

using namespace std;

string n;
int k;
string answer = "";
bool visited[1000001][11];
queue<pair<string, int> > q;
int biggest = 0;
void swap (char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(string cur, int currIdx, int cnt) {
    if (cnt == k) {
        int num = atoi(cur.c_str());
        if (num > biggest)  biggest = num;
        return;
    }
    for (int i =0; i<n.size(); i++) {
        if (i == currIdx) continue;
        swap(n[i], n[currIdx]);
    }
}

int main() {

    cin>>n;
    cin>>k;
    q.push(make_pair(n,0));
    while (!q.empty()) {
        pair<string, int> psi = q.front();
        q.pop();
        string num = psi.first;
        int numint = atoi(num.c_str());
        int cnt = psi.second;
        //cout<<numint<<" "<<cnt<<endl;
        if (cnt == k) {
            if (numint > biggest) biggest = numint;
            continue;
        }
        for (int i =0; i<n.size(); i++) {
            for (int j =0; j<n.size(); j++) {
                if (i == j) continue;
                if (i ==0 && n[j]=='0') continue;
                if (j ==0 && n[i]=='0') continue;
                string nxt = num;
                swap(&nxt[i], &nxt[j]);
                int nxtint = atoi(nxt.c_str());
                //cout<<"nxtint : "<<nxtint<<endl;
                if (!visited[nxtint][cnt+1]) {
                    visited[nxtint][cnt+1] = true;
                    q.push(make_pair(nxt,cnt+1));
                }
            }
        }
    }
    if (biggest == 0) {
        cout<<-1<<endl;
    }
    else cout<<biggest<<endl;
    

}