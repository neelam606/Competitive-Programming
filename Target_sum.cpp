#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
    int sum = 0;
    for(int i = 0; i<nums.size(); i++)
        sum = sum + nums[i];

    int required = abs(target)+sum;

    if(required%2 != 0)
        return 0;
    else
    {
        required = required/2;
        int t[nums.size()+1][required+1];
        t[0][0] = 1;
        for(int i = 1; i<nums.size()+1; i++)
            t[i][0] = 1;
        for(int i = 1; i<required+1; i++)
            t[0][i] = 0;

        for(int i = 1; i<nums.size()+1; i++)
        {
            for(int j = 0; j<required+1; j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[nums.size()][required];
    }
}

int main()
{
    vector <int> values =  {1,1,1,1,1};
    int  target = 3;
    cout<<findTargetSumWays(values, target)<<endl;
}