#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
vector<int> v;

int main() {
    int n, m;
    scanf("%d", &n);
    v.assign(n,0);
    for(int i =0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        v[i]= temp;
    }
    sort(v.begin(), v.end());
    
    scanf("%d", &m);
    int middle, front, back, found;
    for(int i =0; i<m; i++) {
        int temp;
        scanf("%d", &temp);
        front = 0;
        back = v.size()-1;
        found = 0;
        while (front <= back) {
            middle = (back+front)/2;
            if (v[middle] == temp) {
                found = 1;
                break;
            } 
            else if (v[middle] < temp) {
                front = middle +1;
            }
            else {
                back = middle - 1;
            }
        }
        if (found) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }

    }
}