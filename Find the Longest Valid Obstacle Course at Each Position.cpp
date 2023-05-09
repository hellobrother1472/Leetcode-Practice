#include <bits/stdc++.h>
using namespace std;

// This problem is same as longest increasing subsequence because we have to find the length of previous obstacle which satisfies the condition.

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>dp(n,1);
        for(int i = 0; i < n;i++){
            for(int j = 0; j<i; j++ ){
                if(obstacles[i] >= obstacles[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
};

// Using Binary search - https://youtu.be/on2hvxBXJH4?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY (With few modification)

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>temp,ans;
        temp.push_back(obstacles[0]);
        ans.push_back(temp.size());
        for(int i = 1 ; i < obstacles.size(); i++){
            if(obstacles[i] >= temp.back()){
                temp.push_back(obstacles[i]);
                ans.push_back(temp.size());
            }
            else{
                int ind = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
                temp[ind] = obstacles[i];
                ans.push_back(ind+1);
            }
        }
        return ans;
    }
};


// Test case explaination
/* Sure, let me explain each step of the problem in more detail.

Given the array obstacles, we need to find the length of the longest obstacle course at each position such that:

We choose any number of obstacles between 0 and i inclusive.
We must include the ith obstacle in the course.
We must put the chosen obstacles in the same order as they appear in obstacles.
Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
Let's take the first example, obstacles = [1, 2, 3, 2].

Step 1: i = 0

The first index of obstacles is 1. So, there is only one obstacle available at index 0. Therefore, the longest obstacle course that can be built starting with this obstacle is of length 1.

Hence, ans[0] = 1.

Step 2: i = 1

The second index of obstacles is 2. There are two possible obstacle courses that we can build starting with the first two obstacles. They are:

[1, 2] (length 2)
[1] (length 1)
Both of these obstacle courses satisfy the given conditions. However, the first obstacle course is longer than the second one.

Therefore, the longest obstacle course that can be built starting with the first two obstacles is of length 2.

Hence, ans[1] = 2.

Step 3: i = 2

The third index of obstacles is 3. There are three possible obstacle courses that we can build starting with the first three obstacles. They are:

[1, 2, 3] (length 3)
[1, 3] (length 2)
[2, 3] (length 2)
All of these obstacle courses satisfy the given conditions. However, the first obstacle course is the longest one.

Therefore, the longest obstacle course that can be built starting with the first three obstacles is of length 3.

Hence, ans[2] = 3.

Step 4: i = 3

The fourth index of obstacles is 2. There are four possible obstacle courses that we can build starting with the first four obstacles. They are:

[1, 2, 3, 2] (length 3)
[1, 2, 2] (length 3)
[1, 3, 2] (length 2)
[2, 3, 2] (length 2)
All of these obstacle courses satisfy the given conditions. However, the first and second obstacle courses have the same length of 3, which is the longest length.

Therefore, the longest obstacle course that can be built starting with all four obstacles is of length 3.

Hence, ans[3] = 3.

So, the final output array ans is [1, 2, 3, 3].

*/

int main(){

    return 0;
}