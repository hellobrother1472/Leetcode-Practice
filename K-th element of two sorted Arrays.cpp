#include <bits/stdc++.h>

using namespace std;

// Brute force which takes O(n) time complexity and O(1) space complexity
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int count = 0;
        int lastEle = 0;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (count == k)
                return lastEle;

            if (arr1[i] > arr2[j])
            {
                lastEle = arr2[j];
                j++;
                count++;
            }
            else
            {
                lastEle = arr1[i];
                i++;
                count++;
            }
        }

        for (i; i < n; i++)
        {
            if (count == k)
                return lastEle;
            lastEle = arr1[i];
            count++;
        }
        for (j; j < m; j++)
        {
            if (count == k)
                return lastEle;
            lastEle = arr2[j];
            count++;
        }
        return -1;
    }
};

// Most optimal solution
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m > n) {
            return kthElement(arr2, arr1, n, m, k); 
        }
        
        int low = max(0,k-m), high = min(k,n);
        
        while(low <= high) {
            int cut1 = (low + high)/2; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
                
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 1; 
    }
};


int main()
{

    return 0;
}