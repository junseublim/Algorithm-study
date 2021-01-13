#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000001;
int candies[MAX] = {0};
int n;

void add(int i, int x) {
    while (i<=1000001) {
        candies[i] += x;
        i += i&-i;
    }
}
int sum(int i) {
    int s = 0;
    while (i>=1) {
        s += candies[i];
        i -= i&-i;
    }
    return s;
}
void getCandy(int rank) {
    int i = 0;
    int start = 1, end = MAX-1;
    int candy = MAX-1;
    int middle;
    while (start<=end) {
        middle = (start+ end)/2;
        //cout<<"middle: "<<middle<<endl;
        int curRank = sum(middle);
        //cout<<"curRank: "<<curRank<<endl;
        if (curRank < rank) {
            start = middle+1;
        }
        else if (curRank >= rank) {
            candy = middle;
            end = middle-1;
        }
    }
    printf("%d\n", candy);
    add(candy, -1);

}

int main() {
    scanf("%d", &n);
    int a,b,c;
    for (int i =0; i<n; i++) {
        cin>>a;
        if (a ==1) {
            cin>>b;
            getCandy(b);

        }
        else {
            cin>>b>>c;
            add(b,c);
        }
    }
}