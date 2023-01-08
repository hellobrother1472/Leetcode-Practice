#include <bits/stdc++.h>
using namespace std;

// Approach is to simply sort the array and then decrease coins while iterating and increase the count accordingly.
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        for(int i = 0 ; i < costs.size() ; i++){
            if(coins-costs[i] >= 0){
                coins -= costs[i];
                count++;
            }
        }
        return count;
    }
};

// In this approach I am storing the frequency of the costs and then iterating frequencies to calculate the count.
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int icecreams = 0;

        vector<int> costsFrequency(m + 1);
        for (auto& cost : costs) {
            costsFrequency[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost) {
            // No ice cream is present costing 'cost'.
            if (costsFrequency[cost] == 0) {
                continue;
            }
            // We don't have enough 'coins' to even pick one ice cream.
            if (coins < cost) {
                break;
            }
            
            // Count how many icecreams of 'cost' we can pick with our 'coins'.
            // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            int count = min(costsFrequency[cost], coins / cost);
            // We reduce price of picked ice creams from our coins.
            coins -= cost * count;
            icecreams += count;
        }

        return icecreams;
    }
};
int main(){

    return 0;
}