#include <bits/stdc++.h>
using namespace std;

// The approach is to make a window size of k and taking the sum of that from last and then just increasing i and decreasing j for k times as we got only k chances

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // return 0;
        int score = 0, dk = k;
        int i = -1, j = cardPoints.size()-1, count = 0,n = cardPoints.size();

        while(dk > 0){ // getting sum of last k elements.
            score += cardPoints[j];
            dk--;
            j--;
        }
        j++;

        int dummy = score; // creating a dummy to compare
        // running while loop k times and checking every possible substring according to given condition and increasing and decreasing j and i accordingly.
        while(k > 0){
            dummy -= cardPoints[j];
            j++;
            i++;
            dummy += cardPoints[i];
            if(dummy > score) score = dummy;
            k--;
        }
        return score;
    }
};

int main(){

    return 0;
}