#include <bits/stdc++.h>

using namespace std;

struct Info {
    int p1, p2;
    Info() {}
    
};

char str1[4010], str2[4010];
int len1,len2;
int dp[4010][4010];
Info tracking[1010][1010];

//p1, p2까지의 것들 중에서 LCS(꼭 p1,p2를 포함할 필요는 없음)
int calc(int p1, int p2) {
    if (p1 < 0 || p2 < 0) {
        return 0;
    }
    //이미 있음
    if (dp[p1][p2] != -1) {
        return dp[p1][p2];
    }
    //둘이 동일함. 이전 길이 +1 후 반환
    if (str1[p1] == str2[p2]) {
        dp[p1][p2] = calc(p1-1, p2-1) +1;
        tracking[p1][p2].p1 = p1-1;
        tracking[p1][p2].p2 = p2-1;
        return dp[p1][p2];
    }
    //둘이 다름. 한쪽씩 길이 줄여서 계산
    int tmp1, tmp2;
    tmp1 = calc(p1-1,p2);
    tmp2 = calc(p1,p2-1);
    if (tmp1 > tmp2) {
        dp[p1][p2] = tmp1;
        tracking[p1][p2].p1 = p1-1;
        tracking[p1][p2].p2 = p2;
    }
    else {
        dp[p1][p2] = tmp2;
        tracking[p1][p2].p1 = p1;
        tracking[p1][p2].p2 = p2-1;
    }
    return dp[p1][p2];
}

int main() {
    //-1로 초기화
    memset(dp, 0xff, sizeof(dp));
    scanf("%s", str1);
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    printf("%d\n", calc(len1-1, len2-1));
    int p1 = len1-1, p2= len2-1;
    vector<char> stk;
    while(0 <=p1 && 0 <=p2) {
        if (str1[p1] == str2[p2]) stk.push_back(str1[p1]);
        Info nxt = tracking[p1][p2];
        p1= nxt.p1;
        p2 = nxt.p2;
    }
    while(!stk.empty()){
        printf("%c", stk.back());
        stk.pop_back();
    }
}