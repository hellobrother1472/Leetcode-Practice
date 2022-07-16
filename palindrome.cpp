#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int a = x;
        vector<int> arr;
        while(a>=1){
            arr.push_back(a%10);
            a = a/10;
        }

        for (int i = 0 ,j = arr.size(); i <= j ; i++ ,j--)
        {
            if(arr[j] != arr[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    class Solution s;
    bool ans = s.isPalindrome(12331);
    cout << ans ;
    return 0;
}



// bool isPalindrome(int x) {
    //     vector<int> a ;
    //     if(x<0){
    //         return false;
    //     }
    //     int n = x;
    //     while(n >= 1){
    //         a.push_back(n%10);
    //         n = n / 10;
    //     }
    //     int i = 0 , j = a.size()-1;
    //     while(i<j){
    //         if(a[i] != a[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }