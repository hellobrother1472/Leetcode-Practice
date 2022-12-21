#include <bits/stdc++.h>
using namespace std;

// Wrong solution in which I thought that I have to choose one from the given array

class Solution {
public:

    bool check(vector<int> piles, int h, int k, int n){ // Checking the answer.
        int i = 0;
        while(i<n && h > 0){
            if(piles[i] <= k){ // If less than k then make it zero and move ahead
                piles[i] = 0;
                i++;
            }
            else{ // else wait their and reduce it by k.
                piles[i] -= k;
            }

            h--;
        }
        if(piles[n-1] == 0){ // if last element is 0 it means that it satisfies the check
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin() , piles.end());
        if(h == n){
            return piles[n-1];
        }
        int start = 0 , end = n-1, ans = piles[n-1];
        while(start <= end){
            int mid = start + (end - start)/2;
            bool checkRes = check(piles,h,piles[mid],n);
            if(checkRes == true){ // If it is true then put it in answer and check for the lower options
                if(piles[mid] <= ans){
                    ans = piles[mid];
                }
                end = mid - 1;
            }
            else{ // Now if it is false then it means the element is greater than the mid value.
                start = mid + 1;
            }
        } 
        return ans;
    }
};

// Logic is that I am taking the arrays largest element and then I take start at 1 and end at the largest element. After that I applied the logic of binary search and check all the values to be valid or not and then get the answer.
// Time complexity = O(nlog(n)) + O(n)
class Solution {
public:

    bool check(vector<int> piles, int h, int k, int n){ // Function that validates using the concept of dividing and getting the multiples of hours
        long long count = 0;
        for(int j = 0 ; j< n; j++){
            if(piles[j]%k == 0){
                count += (piles[j]/k);
            }
            else{
                count += (1 + (piles[j]/k)); // 1 is added here because "/" gives floor value
            }
        }
        if(count <= h){
            return true;
        }
        return false;
    }

    int maximum(vector<int> piles, int n){ // Function to find max value
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(piles[i] >= ans){
                ans = piles[i];
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxVal = maximum(piles,n);
        if(h == n){
            return maxVal;
        }
        int start = 1 , end = maxVal, ans = maxVal;
        while(start <= end){
            int mid = start + (end - start)/2;
            bool checkRes = check(piles,h,mid,n);
            if(checkRes == true){
                if(mid < ans){
                    ans = mid;
                }
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        } 
        return ans;
    }
};

int main(){
    

    return 0;
}