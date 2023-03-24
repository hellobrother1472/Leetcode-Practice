#include <bits/stdc++.h>
using namespace std;

// The question is simply to find maximum size subarray which only contains only two types of fruits.
// In first approach I am using simple array to track the types, so in this approach I am first iterating to get first two types and storing it in array.
// After that increasing the initial window until it is valid.
// Now run a while loop if the current value of j is not equal to any of the type then make current j = v[1] and its previous element be i and be v[0] now expand the window both sides and store the length if it is greater than ans.
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int>v(2,-1);
        int i = 0, j = 0, ans = 0,n = fruits.size();

        v[0] = fruits[i];

        // Iterating for getting first two types.
        while(j<n && fruits[j] == v[0]) j++;
        cout << j << endl;
        if(j>=n) return fruits.size();
        v[1] = fruits[j];

        // Increasing the initial window until it is valid.
        while(j<n && (fruits[j] == v[1]||fruits[j] == v[0] )) j++;
        if(j>=n) return fruits.size();

        ans += j - i; // Storing the result in answer

        while( i < n && j < n){
            if(fruits[j] != v[0] || fruits[j] != v[1]){
                v[1] = fruits[j];
                v[0] = fruits[j-1];
                i = j-1;
                while(fruits[i] == v[0]) i--;
                i++;
                while(j<n && (fruits[j] == v[1]||fruits[j] == v[0] )) j++;
                if(j-i > ans) ans = j-i;
            }
        }
        return ans;
    }
};

// This appraoch is similar to above just in this appraoch unordered map is used
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // We use a hash map 'basket' to store the number of each type of fruit.
        unordered_map<int, int> basket;
        int left = 0, maxPicked = 0;
        
        // Add fruit from the right index (right) of the window.
        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            // Update maxPicked.
            maxPicked = max(maxPicked, right - left + 1);
        }
        
        // Return maxPicked as the maximum number of fruits we can collect.
        return maxPicked;
    }
};

int main(){

    return 0;
}