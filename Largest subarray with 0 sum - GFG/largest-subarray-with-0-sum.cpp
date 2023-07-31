//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        int sum = 0, len = 0, maxlen = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
            
            if(sum==0)
            {
                len = i+1;
                if(len > maxlen)
                maxlen = len;
                
                continue;
            }
            
            if(mp.find(sum)!=mp.end())
            {
                len = i - mp[sum];
                if(len > maxlen)
                maxlen = len;
            }
            else
            {
                mp[sum] = i;
            }
            
        }
        
        return maxlen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends