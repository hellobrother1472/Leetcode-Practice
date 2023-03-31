#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int , vector<int>,greater<int>> pq;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < hand.size() ; i++){
            mp[hand[i]]++;
        }
        for(auto x : mp) pq.push(x.first);
        while(!pq.empty()){
            int min = pq.top();
            for(int i = min ; i < min+groupSize ; i++){
                if(mp[i]>0){
                    mp[i]--;
                    if(mp[i] == 0 ){
                        if(pq.top() != i) return false;
                        pq.pop();
                    }
                }
                else return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}