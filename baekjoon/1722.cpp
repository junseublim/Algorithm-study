    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    vector<ll> f;
    vector<int> numbers;
    int main() {
        int N;
        int Q;
        cin>>N>>Q;
        f.assign(N+1, 0);
        numbers.assign(N+1, 0);
        f[1] = 1;
        f[0] = 1;
        for (int i =2; i<=N; i++) {
            f[i] = f[i-1] * i;
        }

        if (Q ==1) {
            ll query;
            cin>>query;
            int smallest = 1;
            vector<int> answer;
            while(N > 0) {
                if (f[N-1] < query) {
                    query -= f[N-1];
                    smallest++;
                }
                else {
                    for (int i = 1; i< numbers.size(); i++) {
                        if (numbers[i] == 0) {
                            smallest--;
                        }
                        if (smallest ==0) {
                            numbers[i] = 1;
                            answer.push_back(i);
                            break;
                        }
                    }
                    N--;
                    smallest = 1;
                }
            }
            for (auto x: answer) {
                cout<<x<<" ";
            }

        }
        else {
            vector<int> querySeq(N,0);
            for (int i =0; i<N; i++) {
                cin>>querySeq[i];
            }
            ll ans = 0;
            for (int i =1; i<=N; i++) {
                int alreadyUsed = 0;
                for (int j = 1; j< querySeq[i-1]; j++) {
                    if (numbers[j] != 0) {
                        alreadyUsed++;
                    }
                }
            ans += f[N-i]*(querySeq[i-1]-1-alreadyUsed);
            numbers[querySeq[i-1]] = 1;
            }
            cout<<ans+1<<endl;
            
        }
    }