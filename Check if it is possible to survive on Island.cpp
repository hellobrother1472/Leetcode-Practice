#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int nS = S - S/7; // Calculating available days in which store is open as sunday is off.
        double num = double(double(S*M)/N); // Calculating total days required for shopping 
        num = ceil(num); // Taking the ceiling value as anything in point is the time from next day which is counted ans next day only
        if(num > nS) return -1; // If required days is greater than available days then return -1
        return num;
    }
};

int main(){

    return 0;
}