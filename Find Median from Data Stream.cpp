#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    vector<int>arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        int length = arr.size();
        int ans = 0;
        if(length %2 == 0){
            int index = length/2;
            double ans = (double)(arr[index] + arr[index-1])/2;
            return ans; 
        }
        int index = length/2;
        return arr[index];
    }
};

// https://www.youtube.com/watch?v=itmhHWaHupI

/*
    Implement data structure that gets the median from a data stream

    Max heap of lower values & min heap of higher values, access to mids

    Time: O(log n) + O(1)
    Space: O(n)
*/

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty()) {
            lower.push(num);
            return;
        }
        
        if (lower.size() > higher.size()) {
            if (lower.top() > num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if (num > higher.top()) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;
        
        if (lower.size() == higher.size()) {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            if (lower.size() > higher.size()) {
                result = lower.top();
            } else {
                result = higher.top();
            }
        }
        
        return result;
    }
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
};

int main(){

    return 0;
}