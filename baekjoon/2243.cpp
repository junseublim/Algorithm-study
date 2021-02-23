#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;
int candies[MAX+1] = {0};
int n;

void add(int i, int x) {
    while (i<=MAX) {
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

int main() {
    scanf("%d", &n);
    int a,b,c;
    for (int i =0; i<n; i++) {
        scanf("%d", &a);
        if (a ==1) {
            scanf("%d", &b);
            int start = 1, end = MAX;
            int middle;
            while (start<end) {
                middle = (start+ end)/2;
                int curRank = sum(middle);
                if (curRank >= b) {
                    end = middle;
                }
                else {
                    start = middle+1;
                }
            }
            add(start, -1);
            printf("%d\n", start);
            
        }
        else {
            scanf("%d %d", &b, &c);
            add(b,c);
        }
    }
}