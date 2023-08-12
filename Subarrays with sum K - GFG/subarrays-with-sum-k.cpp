//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        int presum = 0;
        int count=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n;i++)
        {
            presum+=arr[i];
            if(presum==k)
            count++;
            
            if(mp.find(presum-k)!=mp.end())
            count+=mp[presum-k];
            
            mp[presum]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends