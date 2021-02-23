#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
vector<tuple<int, int, int>> presidents;

void add(int num) {
    for (int i =0; i< presidents.size(); i++) {
        if (get<0>(presidents[i]) == -1) {
            presidents[i] = {num, 1, 0};
            break;
        }
    }
    //cout<<"added: "<<num<<endl;
}

void replace(int num) {
    tuple<int,int, int> min = {-1,1001, -1};
    for (int i =0; i< presidents.size(); i++) {
        if (get<1>(presidents[i]) <  get<1>(min)) {
            min = {i, get<1>(presidents[i]), get<2>(presidents[i]) };
        }
        else if (get<1>(presidents[i]) ==  get<1>(min) && get<2>(presidents[i]) > get<2>(min)) {
            min = {i, get<1>(presidents[i]), get<2>(presidents[i]) };
        }
    }
    presidents[get<0>(min)] = {num, 1, 0};
    //cout<<"replaced: "<<get<0>(min)<< "with "<<num<<endl;
}

void increase(int num) {
    for (int i =0; i< presidents.size(); i++) {
        if (get<0>(presidents[i]) == num) {
            get<1>(presidents[i]) += 1;
            break;
        }
    }
    //cout<<"incresed: "<<num<<endl;
}

bool exist(int num) {
    
    for (int i =0; i< presidents.size(); i++) {
        if (get<0>(presidents[i]) == num) {
            return true;
        }
    }
    return false;
}

void sortAndPrint() {
    sort(presidents.begin(), presidents.end());
    for (int i =0; i< presidents.size(); i++) {
        if (get<0>(presidents[i]) == -1) {
            continue;
        }
        cout<<get<0>(presidents[i])<< " ";
    }
}

void tick() {
    for (int i =0; i< presidents.size(); i++) {
        get<2>(presidents[i])++;
    }
}
int main() {
    int n, k;
    cin>>n>>k;
    presidents.assign(n, {-1, 0, 0});
    int size = 0;
    for (int i = 0; i<k; i++ ) {
        int temp;
        cin>>temp;
        if (size != n) {
            if (exist(temp)) {
                increase(temp);
            }
            else {
                add(temp);
                size++;
            }
        }
        else if (exist(temp)){
            increase(temp);
        }
        else {
            replace(temp);
        }
        tick();
    }
    sortAndPrint();
}