#include <bits/stdc++.h>
using namespace std;

// Approach is to calculate the distance of point from origin which is root(x^2 + y^2) or as we only want for comarison so ignore root and get the top k smallest distances with their respective points and return it.
// I am using pair to store and heap to sort, and just keeping the length of heap <=k and at last I am pushing it into answer.

class Solution {
public:
    int distance(int x, int y){
        int a = pow(x,2);
        int b = pow(y,2);
        return a+b;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // a max heap
        priority_queue<pair<int,int>> maxHeap;

        for(int i = 0 ; i < points.size() ; i++){
            int dist = distance(points[i][0], points[i][1]);
            // pair of distance and index;
            pair<int,int>p;
            p.first = dist;
            p.second = i;

            maxHeap.push(p);
            if(maxHeap.size() > k) maxHeap.pop();
        }
        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}