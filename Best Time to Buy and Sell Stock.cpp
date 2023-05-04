#include <bits/stdc++.h>

using namespace std;

// Brut Force (But in this meathod time limit exceeds)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if ((prices[j] - prices[i]) > profit)
                {
                    profit = prices[j] - prices[i];
                }
            }
        }

        if (profit <= 0)
        {
            return 0;
        }
        else
        {
            return profit;
        }
    }
};

// This logic is to store the min number whenever we get and subtract it from the present number to get profit if it exceeds final profit which we have we change the value of final profit and after the iteration we have our max value.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int cProfit = 0;
        int rProfit = 0;

        for(int i = 0; i<prices.size();i++){
            if(prices[i] < min) min = prices[i];
            cProfit = prices[i] - min;
            if(cProfit > rProfit) rProfit = cProfit;
        }
        return rProfit;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2};
    cout << s.maxProfit(a);
    return 0;
}
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector <int> profits = { 0};
//         int maxprofit = 0;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             for (int j = i+1; j < prices.size(); j++)
//             {
//                 profits.push_back(prices[j] - prices[i]);
//             }

//         }
//         maxprofit = *max_element(profits.begin(),profits.end());

//         if(maxprofit > 0){
//             return maxprofit;
//         }
//         else{
//             return 0;
//         }
//     }
// };

// more optimized solution

// class Solution2{
// public:
//     int maxProfit(vector<int>& prices) {
//         int lsf = INT16_MAX;
//         int maxprofit = 0;
//         int pprofit = 0;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             if(prices[i] < lsf){
//                 lsf = prices[i];
//             }

//             pprofit = prices[i] - lsf;

//             if(maxprofit < pprofit){
//                 maxprofit = pprofit;
//             }
//         }

//     }
// };