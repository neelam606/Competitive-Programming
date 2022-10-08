#include <bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{
    vector<vector <int>> t;
    for(int i = 0; i<n+1; i++)
    {
        vector <int> v;
        for(int j = 0; j<w+1; j++)
        {
            if(i==0 || j==0)
                v.push_back(0);
            else
                v.push_back(-1);
        }
        t.push_back(v);
    }
    
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<w+1; j++)
        {
            if(wt[i-1] <= j)
            {
                t[i][j] = max(t[i-1][j], val[i-1] + t[i-1][j-wt[i-1]]);
            }
            else
            {   
                t[i][j] = t[i-1][j];
            } 
        }
    }
    return t[n][w]; 

}

int main()
{
    int n = 3, w = 4, values[] = {1,2,3}, weights[] = {4,5,1};
    cout<<knapSack(w, weights, values, n)<<endl;
}
