#include <bits/stdc++.h>

using namespace std;
int N;
typedef pair<int, int> pii;
vector<int> v;
int maximum = 0;
stack<pii> s;
int main() {
    cin>>N;
    for (int i =1; i<=N; i++) {
        int temp;
        cin>>temp;
        stack<pii> t;
        int loc = i;
        maximum = max(maximum , temp);
        while(s.size()) {
            if (s.top().first >= temp) {
                if (temp*(i-s.top().second+1) > maximum) {
                    maximum = temp*(i-s.top().second+1);
                }
                loc = s.top().second;
                s.pop();
            }
            else {
                //s.top이 나보다 작음
                maximum = max(maximum, s.top().first*(i-s.top().second+1));
                t.push(s.top());
                s.pop();
            }
        }
        while(t.size()) {
            s.push(t.top());
            t.pop();
        }
        s.push(make_pair(temp,loc));
    }
    cout<<maximum<<endl;
}
