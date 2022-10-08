#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for(int i = 0; i<nums.size(); i++)
        sum = sum + nums[i];

    if(sum %2!=0)
        return false;
    else
    {
        sum = sum/2;
        int t[nums.size()+1][sum+1];
        t[0][0] = 1;
        for(int j = 1; j<sum+1; j++)
            t[0][j] = 0;
        for(int j = 1; j<nums.size()+1; j++)
            t[j][0] = 1;        

        for(int i = 1; i<nums.size()+1; i++)
        {
            for(int j = 1; j<sum+1; j++)
            {
                if(nums[i-1]<=j)
                {
                    if(t[i-1][j] == 1 || t[i-1][j-nums[i-1]] == 1)
                        t[i][j] = 1;
                    else
                        t[i][j] = 0; 
                }
                else
                {
                    t[i][j] = t[i-1][j]; 
                }
            }
        }
        if(t[nums.size()][sum] == 1)
            return true;
        else
            return false;
    }
}

int main()
{
    vector<int>values = {1,5,11,5};
    cout<<canPartition(values)<<endl;
}