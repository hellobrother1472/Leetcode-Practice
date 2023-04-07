#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        priority_queue<pair<double, pair<int, int>>> maxHeap; // ratio, value, weight
        double ans = 0;
        for (int i = 0; i < n; i++) {
            double ratio = (double) arr[i].value / arr[i].weight;
            pair<double, pair<int, int>> p;
            p.first = ratio;
            p.second = make_pair(arr[i].value, arr[i].weight);
            maxHeap.push(p);
        }

        while (!maxHeap.empty() && W > 0) {
            pair<double, pair<int, int>> top = maxHeap.top();
            if (top.second.second <= W) {
                ans += top.second.first;
                W -= top.second.second;
            } else {
                ans += top.first * W;
                W = 0;
            }
            maxHeap.pop();
        }

        return ans;
    }
};


int main(){

    return 0;
}