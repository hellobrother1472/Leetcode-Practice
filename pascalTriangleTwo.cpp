#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>>total;
        vector<int>ans;
        
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i){
                    ans.push_back(1);
                }
                else{
                    int comp = total[i-1][j-1] + total[i-1][j];
                    ans.push_back(comp);
                }
            }
            total.push_back(ans);
            ans.clear();
        }
        
        return total[rowIndex];
        
    }
};

int main()
{

    return 0;
}