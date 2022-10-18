#include <bits/stdc++.h>
using namespace std;

// Filling and clearing the stack according to condition and at final I have the stack full of the required elements.
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        stack<int> st;
        vector<int>ans;
        st.push(a[0]);
        int min = a[0];  // minimum value till now
        for (int i = 1; i < n; i++)
        {
            if(a[i] > min){ // if the present value is greater it means that we have to pop() until it met the correct condition and continue our traverse
                while(!st.empty() && st.top() < a[i]){
                    st.pop();
                }
                min = a[i];
                st.push(a[i]);
            }
            else{
                // if it is less than the st.top() then simply push and make it equal to min.
                st.push(a[i]);
                min = a[i];
            }
        }

        // Put it into the vector
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // reverse the vector
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Using the concept that the leader element should be greater than max element in the right.

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> v;
        
        int max = a[n-1];
        
        //We start traversing the array from last element.
        for(int i =n-1; i >= 0; i--){
            //Comparing the current element with the maximum element stored. 
            //If current element is greater than max, we add the element.
            if(a[i] >= max){
                //Updating the maximum element.
                max = a[i];
                //Storing the current element in vector for leaders.
                v.push_back(max);
            }
        }
        //Finally reversing the vector in which leaders are stored.
        reverse(v.begin(), v.end());
        //returning the vector.
        return v;
        
    }
};

int main()
{

    return 0;
}