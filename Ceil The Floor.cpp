#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // first is floor and second is ceiling
    pair <int , int> ans;
    ans.first = -1;
    ans.second = -1;
    for(int i = 0 ; i< n ; i++){
        if(arr[i] <= x && arr[i] > ans.first){
            ans.first = arr[i];
        }
        
        if((arr[i]>=x && ans.second == -1) || (arr[i]>=x && arr[i]<ans.second)){
            ans.second = arr[i];
        } 
    }
    return ans;
}

int main(){
    

    return 0;
}