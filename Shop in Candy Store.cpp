#include <bits/stdc++.h>
using namespace std;

// Make use of two pointer to find the lowest amount to be spend, we want to buy lowest amount item and take higher amount item as bonus, so sort it so that we have lowest price items at front and then take 1 from front and k from last until all are covered doing this will give us the answer.
// Similar logic for highest also.

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        sort(candies, candies+N);
        vector<int>ans(2);
        int highest = 0, lowest = 0;
        int i = 0, j = N-1 ;
        while(j >= i){
            lowest += candies[i];
            i += 1;
            j -= k;
        }
        i = 0;
        j = N-1;
        while(j >= i){
            highest += candies[j];
            i += k;
            j -= 1;
        }
        ans[0] = lowest;
        ans[1] = highest;
        return ans;
    }
};

int main(){

    return 0;
}