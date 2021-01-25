#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
const int NEGINF = -1000000001;
const int MAX = 50001;

typedef struct Node {
    int start;
    int end;
    int maxR;
    Node() {start = NEGINF; end = NEGINF; maxR = 0;};
    Node(int s, int e, int m) {
        start = s;
        end = e;
        maxR = m;
    };
} Node;

vector<int> inputs;
Node maxRain[MAX];
Node segment[MAX*4];
unordered_map<int, int> yearRain;

Node cmp(Node a, Node b) {
    Node c;
    if (a.maxR > b.maxR) {
        c = Node(a.start, b.end, a.maxR);
    }
    else {
        c = Node(a.start, b.end, b.maxR);
    }
    if (c.end == NEGINF) {
        c.end = a.end;
    }
    return c;
}

Node init(int node, int s, int e) {
    if (s == e) {
        segment[node] = maxRain[s];
    }
    else {
        segment[node] = cmp(init(node*2, s, (s+e)/2), init(node*2+1, (s+e)/2+1, e));
    }
    return segment[node];
}
int currMax = NEGINF;

void getMax(int s, int e, int idx) {
    Node curr = segment[idx];
    // cout<<"segment["<<idx<<"] = "<<segment[idx].maxR<<endl;
    // cout<<curr.start<< " "<<curr.end<<endl;
    // cout<<s<<" "<<e<<endl;
    //if (s > e) return;
    if (curr.end < s || curr.start > e) return;
    if (s <= curr.start && e >= curr.end) {
        //cout<<"check MAx"<<endl;
        currMax = max(currMax, curr.maxR);
        return;
    }
    if (idx*2 >= MAX*4 || segment[idx*2].maxR == 0) {
        return;
    }
    getMax(s, e, idx*2);
    if (idx*2+1 >= MAX*4 || segment[idx*2+1].maxR == 0) {
        return;
    }
    getMax(s,e, idx*2+1);
}

int main() {
    scanf("%d", &n);
    inputs.assign(n+1, NEGINF);
    int year, rain;
    for (int i =1; i<=n; i++) {
        scanf("%d", &year);
        scanf("%d", &rain);
        inputs[i] = year;
        maxRain[i] = Node(year, year, rain);
        yearRain[year] = rain;
    }
    init(1,1, n);
    // for (int i =1; i<=n*4; i++) {
    //     cout<<segment[i].start<< " "<<segment[i].end<< " "<<segment[i].maxR<<"\n";  
    // }
    scanf("%d", &m);
    int year1, year2;
    for (int i =0; i<m; i++) {
        scanf("%d", &year1);
        scanf("%d", &year2);
        getMax(year1+1, year2-1, 1);
        //cout<<"currMAx: "<<currMax<<"\n";
        if (!yearRain.count(year2)) {
            //x값이 존재안함
            if (yearRain.count(year1)) {
                if (currMax >= yearRain[year1]) {
                    printf("false\n");
                }
                else {
                    printf("maybe\n");
                }
            }
            else printf("maybe\n");
        }
        else if (yearRain[year2] <= currMax) {
            printf("false\n");
        }
        else{
            //x,y 값이 모두 존재
            int year1Idx = lower_bound(inputs.begin(), inputs.end(), year1) - inputs.begin();
            int year2Idx = lower_bound(inputs.begin(), inputs.end(), year2) - inputs.begin();
            if (year2Idx- year1Idx == year2-year1) {
                //중간에 없는게 없다
                if (yearRain[year2] <= yearRain[year1]) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
            }
            else {
                //중간에 없는게 존재
                if (yearRain.count(year1)) {
                    if (yearRain[year2] <= yearRain[year1]) {
                        printf("maybe\n");
                    }
                    else {
                        printf("false\n");
                    }
                }
                else {
                    
                    printf("maybe\n");
                }
            }
        }
        //cout<<currMax<<"\n";
        currMax = NEGINF;
    }

}