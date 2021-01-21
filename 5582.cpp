#include<bits/stdc++.h>

using namespace std;

char str1[4010], str2[4010];
int len1, len2;
typedef pair<int, int> pii;
int track[4010][4010];
int maximum = 0;
void calc() {
    for (int p1 = 0; p1<len1; p1++) {
        for (int p2 = 0; p2<len2; p2++) {
            if (str1[p1] == str2[p2]) {
                if (p1 == 0 || p2 == 0) {
                    track[p1][p2] = 1;
                }
                else {
                    track[p1][p2] = track[p1-1][p2-1] + 1;
                }
            maximum = max(maximum, track[p1][p2]);
            }
            else {
                track[p1][p2] = 0;
            }
             //cout<<"track["<<p1<<"]["<<p2<<"] = "<<track[p1][p2]<<endl;
        }
    }
}

int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    memset(track, 0xff, sizeof(track));
    len1 = strlen(str1);
    len2 = strlen(str2);
    calc();
    // for (int i=0; i<len1; i++) {
    //     for (int j=0; j<len2;j++) {
    //         cout<<track[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    printf("%d", maximum);
}