#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

class Solution 
{
    public:
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        vector<int>ans(2);
        vector<int>slots(n,0);
        int count = 0, profit = 0;
        for(int i = 0 ; i < n; i++){
            int j = arr[i].dead-1;
            while(j >= 0){
                if(slots[j] == 0) {
                    slots[j] = 1;
                    profit += arr[i].profit;
                    count++;
                    break;
                }
                j--;
            }
        }
        ans[0] = count;
        ans[1] = profit;
        return ans;
    } 
};

int main(){

    return 0;
}