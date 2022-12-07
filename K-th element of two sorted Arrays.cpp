#include <bits/stdc++.h>

using namespace std;

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

int main()
{

    return 0;
}