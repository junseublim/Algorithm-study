#include <bits/stdc++.h>

using namespace std;
bool isPalindrome[2001][2001];
int numbers[2001];
int n;
void makePaline() {
    for (int i=1; i<=n; i++) {
        int j=i-1, k=i+1;
        isPalindrome[i][i] = true;
        while(j>0 && k<=n && numbers[j] == numbers[k]){
            isPalindrome[j][k] = true;
            j--;k++;
        }
    }
    for (int i=1; i<n; i++) {
        int j=i, k=i+1;
        while(j>0 && k<=n && numbers[j] == numbers[k]){
            isPalindrome[j][k] = true;
            j--;k++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>numbers[i];
    }
    int m;
    cin>>m;
    makePaline();
    int a,b;
    for(int i=0; i<m;i++) {
        cin>>a>>b;
        cout<<(isPalindrome[a][b] ? "1" : "0")<<"\n";
    }

}