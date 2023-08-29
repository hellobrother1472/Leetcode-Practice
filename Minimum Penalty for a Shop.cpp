#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        unordered_map<char,int> right;
        unordered_map<char,int> left;
        for(char a : customers) right[a]++;;

        int minIndex = 0, minPanelty = INT_MAX;
        for(int i = 0; i <= customers.size(); i++){
            if(i == 0){
                minPanelty = min(minPanelty,right['Y']);
                minIndex = i;
            }
            else{
                right[customers[i-1]]--;
                left[customers[i-1]]++;
                if(minPanelty > right['Y'] + left['N']){
                    minPanelty = right['Y'] + left['N'];
                    minIndex = i;
                }
            }
        } 
        return minIndex;
    }
};

int main(){
    return 0;
}