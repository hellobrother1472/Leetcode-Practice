#include <bits/stdc++.h>
using namespace std;

// each request has two options; the first is to accept this and move the employee in request [x, y] from building x to y and the second is to ignore it. Since, in the end, we need to check if the change in each building is zero, we need to have an array where the indices for each building will store the current employee count that has entered or left it.
class Solution {
public:
    int answer = 0;

    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count) {
        if (index == requests.size()) {
            // Check if all buildings have an in-degree of 0.
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    return;
                }
            }
            
            answer = max(answer, count);
            return;
        }
        
        // Consider this request, increment and decrement for the buildings involved.
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;
        // Move on to the next request and also increment the count of requests.
        maxRequest(requests, indegree, n, index + 1, count + 1);
        // Backtrack to the previous values to move back to the original state before the second recursion.
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        
        // Ignore this request and move on to the next request without incrementing the count.
        maxRequest(requests, indegree, n, index + 1, count);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        maxRequest(requests, indegree, n, 0, 0);
        
        return answer;
    }
};

// For optimization purpose we can use bitmasking to represent indegree

int main(){

    return 0;
}