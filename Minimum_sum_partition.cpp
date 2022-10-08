#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)  
{
    int sum = 0;
    for(int i = 0; i<n; i++)
        sum = sum + arr[i];

    int required = sum/2, minimun = sum;
    int t[n+1][required+1];
    t[0][0] = 1;
    for(int i = 1; i<n+1; i++)
        t[i][0] = 1;
    for(int i = 1; i<required+1; i++)
        t[0][i] = 0;
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<required+1; j++)
        {
            if(arr[i-1]<=j)
            {
                if(t[i-1][j-arr[i-1]] == 1)
                {
                    minimun = min(minimun, sum - 2*j);
                    t[i][j] = 1;
                }
                else if(t[i-1][j] == 1)
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
    return minimun;
}
int main()
{
    int values[] = {1,6,11,5}, n = 4;
    cout<<minDifference(values, n)<<endl;
}