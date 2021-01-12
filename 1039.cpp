#include <bits/stdc++.h>

using namespace std;

string n;
int k;
string answer = "";

int findBiggest(int pos) {
    char b = n[pos];
    int index = pos;
    for (int i = pos+1; i<n.size(); i++) {
        if (n[i]> b) {
            b =n[i];
            index = i;
        }
        
    }
    return index;
}

void getMax(int pos) {
    if (k == 0) return;
    if (pos == n.size()-1) {
        if (pos-1 == 0 && n[pos] == '0' ) {
            n.clear();
            n =  "-1";
            return;
        } 
        char temp = n[pos];
        n[pos] = n[pos-1];
        n[pos-1] = temp;
        k--;
        getMax(pos);
    }
    int biggestIdx = findBiggest(pos);
    if (pos == 0) {
        if (n[biggestIdx] == '0') {
            n = "-1";
            return;
        }
    }
    
    if (pos != biggestIdx) {
        char temp = n[pos];
        n[pos] = n[biggestIdx];
        n[biggestIdx] = temp;
        k--;
    }
     getMax(pos+1);
   

}

int main() {

    cin>>n;
    cin>>k;
    getMax(0);
    cout<<n<<endl;

}