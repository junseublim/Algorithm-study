#include <bits/stdc++.h>

using namespace std;
int nums[100000];
vector<int> negs;
vector<int> zeros;
int n,k;

int negGo(int s, int e, int left, int right, int idx) {
    //cout<<"s: "<<s<<" e : "<<e<<" left: "<<left<<" right: "<<right<<endl;
    int val = 0;
    int mid = (left+right)/2;
    if (s == left && e == right) {
        return negs[idx];
    }
    if (s <= mid) {
        val += negGo(s, min(e,mid), left, mid,idx*2);
    }
    if (e > mid) {
        val += negGo(max(s, mid+1), e, mid+1, right, idx*2+1);
    }
    return val;
}
int zeroGo(int s, int e, int left, int right, int idx) {
    int val = 0;
    int mid = (left+right)/2;
    if (s == left && e == right) {
        return zeros[idx];
    }
    if (s <= mid) {
        val += zeroGo(s, mid, left, mid,idx*2);
    }
    if (e > mid) {
        val += zeroGo(mid+1, e, mid+1, right, idx*2+1);
    }
    return val;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>k){
        int p = ceil(log2(n));
        int range = pow(2, p);
        negs.assign(range*2, 0);
        zeros.assign(range*2, 0);
        for (int i =0; i<n; i++) {
            cin>>nums[i];
            if (nums[i] == 0) {
                negs[range+i] = 0;
                zeros[range+i] = 1;
            }
            else if (nums[i]< 0) {
                negs[range+i] = 1;
                zeros[range+i] = 0;
            }
            else {
                negs[range+i] = 0;
                zeros[range+i] = 0;
            }
        }
        for (int i = range-1; i>0; i--) {
            negs[i] += negs[i*2+1];
            negs[i] += negs[i*2];
            zeros[i] += zeros[i*2+1];
            zeros[i] += zeros[i*2];
        }
        //cout<<"\n negs: ";
        for (int i =1; i<range*2; i++) {
            //cout<<negs[i]<<" ";
        }
        //cout<<"\n zeros: ";
        for (int i =1; i<range*2; i++) {
            //cout<<zeros[i]<<" ";
        }
        //cout<<"\n";
        for (int i =0; i<k; i++) {
            char c;
            int a,b;
            cin>>c>>a>>b;
            if (c == 'C') {
                nums[a] = b;
                int tempRange = range-1;
                if (nums[a] == 0) {
                    negs[tempRange+a] = 0;
                    zeros[tempRange+a] = 1;
                }
                else if (nums[a]< 0) {
                    negs[tempRange+a] = 1;
                    zeros[tempRange+a] = 0;
                    }
                else {
                    negs[tempRange+a] = 0;
                    zeros[tempRange+a] = 0;
                }
                int idx = (tempRange+a)/2;
                while (idx >= 1) {
                    negs[idx] = negs[idx*2] + negs[idx*2+1];
                    zeros[idx] = zeros[idx*2] + zeros[idx*2+1];
                    idx /=2;
                }
                //cout<<"\n negs: ";
                for (int i =1; i<range*2; i++) {
                    //cout<<negs[i]<<" ";
                }
                //cout<<"\n zeros: ";
                for (int i =1; i<range*2; i++) {
                    //cout<<zeros[i]<<" ";
                }
                //cout<<"\n";
            }
            else {
                int negcnt = negGo(a,b, 1, range, 1);
                int zerocnt = zeroGo(a,b, 1, range, 1);
                //cout<<negcnt<<" "<<zerocnt<<endl;
                if (zerocnt) cout<<0;
                else if (negcnt%2 == 1) cout<<"-";
                else cout<<"+";
            }

        }
        cout<<"\n";
    }
}