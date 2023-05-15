#include <bits/stdc++.h>
using namespace std;

// The approach is to check every possible combination and keeping the track of all combinations, and we are keeping track of what is picked or not picked using array picked.

// Reccursive
class Solution {
public:
    int backtrack(vector<int>& nums, vector<bool>& picked, int pairsPicked) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            if (picked[firstIndex]) {
                continue;
            }
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
                if (picked[secondIndex]) {
                    continue;
                }

                // Both numbers are marked as picked.
                picked[firstIndex] = true;
                picked[secondIndex] = true;

                // Calculate score of current pair of numbers, and the remaining array.
                int score = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]) + backtrack(nums, picked, pairsPicked + 1);

                // Store the maximum score.
                maxScore = max(maxScore, score);

                // We will use old picked vector in loop's next iteration, 
                // means we discarded the picked number and backtracked.
                picked[firstIndex] = false;
                picked[secondIndex] = false;
            }
        }

        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        vector<bool> picked(nums.size(), false);
        return backtrack(nums, picked, 0);
    }
};

// Memoized
// toDecimal(picked) convert the array into decimal form like [true,false,true] --> 101
class Solution {
private:
    // Converts the picked vector to decimal value to be used as an index in memo
    int toDecimal(vector<bool>& picked) {
        int decimal = 0;
        for (int i = 0; i < picked.size(); i++) {
            decimal += (int)picked[i] * pow(2, i);
        }
        return decimal;
    }
    int backtrack(vector<int>& nums, vector<bool>& picked, int pairsPicked, vector<vector<int>>& memo) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        // Check if this state is already computed
        if (memo[pairsPicked][toDecimal(picked)] != -1) {
            return memo[pairsPicked][toDecimal(picked)];
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            if (picked[firstIndex]) {
                continue;
            }
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
                if (picked[secondIndex]) {
                    continue;
                }

                // Both numbers are marked as picked.
                picked[firstIndex] = true;
                picked[secondIndex] = true;

                // Calculate score of current pair of numbers, and the remaining array.
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, picked, pairsPicked + 1, memo);

                // Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore);

                // We will use old picked vector in loop's next iteration, 
                // means we discarded the picked number and backtracked.
                picked[firstIndex] = false;
                picked[secondIndex] = false;
            }
        }

        // Save the computed state in memo
        memo[pairsPicked][toDecimal(picked)] = maxScore;

        return maxScore;
    }

public:
    int maxScore(vector<int>& nums) {
        vector<bool> picked(nums.size(), false);
        vector<vector<int>> memo(nums.size() + 1, vector<int>(1 << nums.size(), -1));
        return backtrack(nums, picked, 0, memo);
    }
};

// Memoization using bit masking - masking is used to keep track of the items picked
class Solution {
public:
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        // If we already solved this sub-problem then return the stored result.
        if (memo[mask] != -1) {
            return memo[mask];
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
    
                // If the numbers are same, or already picked, then we move to next number.
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }

                // Both numbers are marked as picked in this new mask.
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));

                // Calculate score of current pair of numbers, and the remaining array.
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

                // Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore);
                // We will use old mask in loop's next interation, 
                // means we discarded the picked number and backtracked.
            }
        }

        // Store the result of the current sub-problem.
        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size(); // 2^(nums array size)
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }
};

int main(){

    return 0;
}