#include <bits/stdc++.h>
using namespace std;

// The approach is that first I am filling the imaginary array with 1. which decreases maxSum to maxSum - n
// Now the intution is that (which comes while solving and visualizing on notebook), for first time the given index increases, after that to increase it further I have to increase it's left and right such that abs difference keeps <= 1. And as we go further I have to increase the total elements whose value is increasing on the side. So that is intution behind the code now code will teach itself.
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int totalInLeft = index - 0;
        int totalInRight = n - index - 1; 
        int loopCount = 0;
        maxSum = maxSum - n;
        int maxVal = 1;
        while(maxSum > 0){
            int left = totalInLeft, right = totalInRight;
            if(loopCount <= totalInLeft) left = loopCount;
            if(loopCount <= totalInRight) right = loopCount;
            maxSum = maxSum - (left + right);
            if(maxSum > 0){
                maxVal++;
                maxSum--;
            }
            loopCount++;
        }
        return maxVal;
    }
};

// The above approach give TLE because we are doing many unneccary while loop.
// As our loopvalue increases greater than number on left and number on right, we are always doing same thing.
// So to avoid that as soon as this condition occur I am breaking from the loop.
// Now as we know that in every iteration all the element will be increases by 1 and if the remaining sum.
// So now we just divide the remaining sum with n and see how many times it occur, because number of times it occur means number of times our value increases.
// So our final answer becomes maxVal + div
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int totalInLeft = index - 0;
        int totalInRight = n - index - 1; 
        int loopCount = 0;
        maxSum = maxSum - n;
        int maxVal = 1;
        while(maxSum > 0){
            int left = totalInLeft, right = totalInRight;
            if(loopCount > totalInLeft && loopCount > totalInRight) break;
            if(loopCount <= totalInLeft) left = loopCount;
            if(loopCount <= totalInRight)  right = loopCount;
            maxSum = maxSum - (left + right);
            if(maxSum > 0){
                maxVal++;
                maxSum--;
            }
            loopCount++;
        }
        int div = maxSum/n;
        return maxVal+div;
    }
};
int main(){

    return 0;
}