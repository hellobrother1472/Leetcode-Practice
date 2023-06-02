#include <bits/stdc++.h>
using namespace std;

// First mapping the id with entry station and time.
// At checkout accesing the value and maintaining the sum and count map;
class UndergroundSystem {
public:
    map<int,pair<int,string>>mp;
    map<string,map<string,int>>count;
    map<string,map<string,int>>sum;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id].first = t;
        mp[id].second = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string prev = mp[id].second;
        sum[prev][stationName] += t - mp[id].first;
        count[prev][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)sum[startStation][endStation]/count[startStation][endStation];
    }
};

int main(){

    return 0;
}