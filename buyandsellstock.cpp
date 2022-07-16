#include <iostream>
#include <vector>
#include <algorithm>

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
class SolutionTwo
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int pprofit = 0;
        int min = 32600;
        
        for (int i = 0; i < prices.size(); i++)
        {
            if(prices[i]< min){
                min = prices[i];
            }

            pprofit = prices[i] - min;

            if(profit < pprofit){
                profit = pprofit;
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