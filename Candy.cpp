#include <bits/stdc++.h>
using namespace std;

// First making an helper vector and storing 1 in all boxes as we have to give atleast one to everyone.
// Then start the loop and start comparing and making changes according to given requirements. If I found small element somewhere then I try to make the helper increase.
// After that due to first iteration their some increases left, which if we move it again backward then it will be resolved , to see what is resolved, dry run on [1,6,10,8,7,3,2]

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        int ans = 0;
        vector<int>helper(n,1);
        for(int i = 0 ; i < n; i++){
            if(i > 0 && i < n-1){
                if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
                    helper[i] = max(helper[i+1], helper[i-1]) + 1;
                    continue;
                }
                else if(ratings[i] > ratings[i-1]){
                    helper[i] = helper[i-1] + 1;
                    continue;
                }
                else if(ratings[i] > ratings[i+1]){
                    helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == 0){
                if(ratings[i] > ratings[i+1]){
                    helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == n-1){
                if(ratings[i] > ratings[i-1]){
                    helper[i] = helper[i-1] + 1;
                }
            }
            
        }
        for(int i = n-1 ; i >= 0; i--){
            if(i > 0 && i < n-1){
                if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i-1] && helper[i] <= helper[i+1]) helper[i] = max(helper[i+1], helper[i-1]) + 1;
                    else if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                    else if(helper[i] <= helper[i+1])helper[i] = helper[i+1] + 1;
                }
                else if(ratings[i] > ratings[i-1]){
                    if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                }
                else if(ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i+1]) helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == 0){
                if(ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i+1]) helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == n-1){
                if(ratings[i] > ratings[i-1]){
                    if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                }
            }
        }
        for(int i = 0 ; i < n; i++ ){
            ans += helper[i];
        }
        return ans;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        int ans = 0;
        vector<int>helper(n,1);
        for(int i = 0 ; i < n; i++){
            if(i > 0 && i < n-1 && ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
                helper[i] = max(helper[i+1], helper[i-1]) + 1;
            }
            else if(i > 0 && ratings[i] > ratings[i-1]){
                helper[i] = helper[i-1] + 1;
            }
            else if(i == 0 && ratings[i] > ratings[i+1]){
                helper[i] = helper[i+1] + 1;
            }
            
        }
        for(int i = n-1 ; i >= 0; i--){
            if(i > 0 && i < n-1){
                if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i-1] && helper[i] <= helper[i+1]) helper[i] = max(helper[i+1], helper[i-1]) + 1;
                    else if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                    else if(helper[i] <= helper[i+1])helper[i] = helper[i+1] + 1;
                }
                else if(ratings[i] > ratings[i-1]){
                    if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                }
                else if(ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i+1]) helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == 0){
                if(ratings[i] > ratings[i+1]){
                    if(helper[i] <= helper[i+1]) helper[i] = helper[i+1] + 1;
                }
            }
            else if(i == n-1){
                if(ratings[i] > ratings[i-1]){
                    if(helper[i] <= helper[i-1]) helper[i] = helper[i-1] + 1;
                }
            }
        }
        for(int i = 0 ; i < n; i++ ){
            ans += helper[i];
        }
        return ans;
    }
};

// We use one array to track the number of candies for each student. We initially assign one candy to each student, then update the candies array while traversing the array from left to right and again from right to left. We update a student's candy count only if their rating is higher than their neighbor's rating and has fewer or equal candies.

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};

int main(){

    return 0;
}