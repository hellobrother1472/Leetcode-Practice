#include <bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        long long modulo = pow(10,9);
        modulo += 7;
        for(int i = 0 ; i < arr.size();i++){
            int min = INT_MAX;
            for(int j = i ; j < arr.size(); j++){
                if(arr[j] < min) min = arr[j];
                sum += min;
                sum = sum % modulo;
            }
        }        
        return sum;
    }
};

// let's say we are on any index i so the number of times it gets counted in sum is the total number of subsets in which it is the minimum element.
// So to find that we are first getting total number of consecutive elements on left and right of the number, and it is done using concept of finding nearest small number on left and right, and using that I am finding the total number of element greter on left and right side both.
// So after finding that total occurance, what we add in sum is (total element greater in right + 1) * (total element greater in left + 1) * element.
// 

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        vector<int>left_min;
        vector<int>right_min;
        long long sum = 0;
        long long modulo = pow(10,9);
        modulo += 7;
        
        for(int i = 0 ; i < arr.size();i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()){
                st.push(i);
                left_min.push_back(i);
            }
            else{
                left_min.push_back(i - st.top() -1);
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i = arr.size()-1 ; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()){
                st.push(i);
                right_min.push_back(arr.size() - i -1);
            }
            else{
                right_min.push_back(st.top() - i -1);
                st.push(i);
            }
        }
        reverse(right_min.begin(),right_min.end());
        for(int i = 0 ; i < arr.size();i++){
            int left = left_min[i] + 1;
            int right = right_min[i] + 1;  
            sum += (long long)left* (long long)right* (long long)arr[i];
            sum = sum % modulo;      
        }
        return sum;
    }
};

int main(){
    

    return 0;
}