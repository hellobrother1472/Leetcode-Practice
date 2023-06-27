#include <bits/stdc++.h>
using namespace std;

// First fill the pqOne queue and then the other and add only when one element gets poped out and i <= j so that to remove repetition.
// So tie is resolved by smaller index element
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pqOne,pqTwo;
        int i = 0, j = n-1;
        long long cost = 0;
        while( i <= j && pqOne.size() < candidates) pqOne.push(costs[i++]);
        while( i <= j && pqTwo.size() < candidates) pqTwo.push(costs[j--]);
        while(k > 0){
            int oneTop = (pqOne.size() > 0) ? pqOne.top() : INT_MAX;
            int twoTop = (pqTwo.size() > 0) ? pqTwo.top() : INT_MAX;
            if(oneTop <= twoTop){
                cost+= oneTop;
                pqOne.pop();
                if(i <= j) pqOne.push(costs[i++]);
            }
            else{
                cost+= twoTop;
                pqTwo.pop();
                if(i <= j) pqTwo.push(costs[j--]);
            }
            k--;
        }
        return cost;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pqOne,pqTwo;
        int i = 0, j = n-1;
        long long cost = 0;
        while(k > 0){
            while( i <= j && pqOne.size() < candidates) pqOne.push(costs[i++]);
            while( i <= j && pqTwo.size() < candidates) pqTwo.push(costs[j--]);
            int oneTop = (pqOne.size() > 0) ? pqOne.top() : INT_MAX;
            int twoTop = (pqTwo.size() > 0) ? pqTwo.top() : INT_MAX;
            if(oneTop <= twoTop){
                cost+= oneTop;
                pqOne.pop();
            }
            else{
                cost+= twoTop;
                pqTwo.pop();
            }
            k--;
        }
        return cost;
    }
};

int main(){

    return 0;
}