#include <bits/stdc++.h>

using namespace std;

int gear[5][8];

void turn(int gearToTurn, int direction, int from) {
    if (from == 0) {
        if (gearToTurn < 4 && gear[gearToTurn][2] != gear[gearToTurn+1][6]) {
            turn(gearToTurn+1, direction*(-1), -1);
        }
        if (gearToTurn > 1 && gear[gearToTurn][6] != gear[gearToTurn-1][2]) {
            turn(gearToTurn-1, direction*(-1), 1);
        }
    }
    else if (from == -1) {
        if (gearToTurn < 4 && gear[gearToTurn][2] != gear[gearToTurn+1][6]) {
            turn(gearToTurn+1, direction*(-1), -1);
        }
    }
    else { 
        if (gearToTurn > 1 && gear[gearToTurn][6] != gear[gearToTurn-1][2]) {
            turn(gearToTurn-1, direction*(-1), 1);
        }
    }
    if (direction == 1) {
        //시계방향
        int temp;
        int prev = gear[gearToTurn][0];
        for (int i =1; i<8; i++) {
            temp = gear[gearToTurn][i];
            gear[gearToTurn][i] = prev;
            prev = temp; 
        }
        gear[gearToTurn][0] = prev;
    }
    else  {
        int temp;
        int prev = gear[gearToTurn][0];
        for (int i =7; i>0; i--) {
            temp = gear[gearToTurn][i];
            gear[gearToTurn][i] = prev;
            prev = temp; 
        }
        gear[gearToTurn][0] = prev;
    }
    
}


int main() {
    for (int i =1; i<5; i++) {
        string gearStr;
        cin>>gearStr;
        for (int j =0; j<gearStr.size(); j++) {
            gear[i][j] = gearStr[j] - '0';
        }
    }
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int gearToTurn, direction;
        cin>>gearToTurn>>direction;
        turn(gearToTurn, direction, 0);
    }
    int score = 0;
    for (int i =1; i<5; i++) {
        if (gear[i][0] == 1) {
            score += 1<<(i-1);
        }
    }
    cout<<score<<endl;
}