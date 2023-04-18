#include <bits/stdc++.h>
using namespace std;

// Code not working
// appraoch is to iterate the array and find out the maximum trains that can be valid on that platform and make that index of vector to be -1 and then in second interation I am trying to do it for 2nd platform so as II repeat it I will get total no. of platform required

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    	for(int i = 0 ; i < n ; i++){
    	    pair<int,int>p = make_pair(dep[i],arr[i]);// pair.first = departure and pair.second = arrival
    	    minHeap.push(p);
    	}
    	
    	vector<pair<int,int>>v;
    	while(!minHeap.empty()){
    	    v.push_back(minHeap.top());
    	    minHeap.pop();
    	}
    	
    	int totalTrains = n, i = 0,ans = 0;
    	while(totalTrains > 0){
    	    if(totalTrains == 1) return ans+1;
    	    while(v[i].first == -1 && i < n) i++;
    	    int dep = v[i].first;
    	    while(i<n){
    	        v[i].first = -1;
                v[i].second = -1;
    	        while(v[i].second < dep && i < n) i++;
    	        if(i < n) dep = v[i].first;
                totalTrains--;
    	    }
    	    i=0;
    	    ans++;
    	}
    	return ans;
    }
};

// Working approach - https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
// Considering the overall timing of arrival and departure on station (not on platform) and assigning platform accordingly and at last we have maxPlatform value.
// If thier is a train which is arrived but not departed and then again some other trains come then at that condition we need to give them an seperate platform so platform count increases.
// Once an already arrived train departed then the platform is vacant and platform in use count decreases.
// So i iterate until the arrival time is greater than current departure time which is j, so as many times i increases it means requirement for number of platform increses. (we can do all this because array is sorted).
// So as we reach an i where departure value is less then we iterate till the departure value is greater than i because as arrival is greater currently it means some trains will leave making platform vacant, and every step of j counts that how many platform are free now which decreases count of platform in use.
// This process continue until any of i or j reaches the end, and we got our answer.
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep,dep+n);
    	int platform = 0, maxPlatform = 0;
    	int i = 0, j = 0;
    	while(i<n && j < n){
    	    while(dep[j] >= arr[i] && i < n){
    	        i++;
    	        platform++;
    	        if(platform > maxPlatform) maxPlatform = platform;
    	    }
    	    while(dep[j] < arr[i] && j < n){
    	        j++;
    	        platform--;
    	        if(platform > maxPlatform) maxPlatform = platform;
    	    }
    	}
    	return maxPlatform;
    }

int main(){

    return 0;
}