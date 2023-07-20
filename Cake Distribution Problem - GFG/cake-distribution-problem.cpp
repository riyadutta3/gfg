//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool check(vector<int>& arr, int n, int k, int mid)
    {
        int sum=0, count=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            if(sum>=mid)
            {
                count++;
                sum=0;
            }
        }
        
        return count>=k+1;
    }
    
    int maxSweetness(vector<int>& sweetness, int n, int k) {
      int start = INT_MAX;
      int end=0;
      
      for(int i=0;i<n;i++)
      {
          if(sweetness[i] < start)
          start = sweetness[i];
          
          end+=sweetness[i];
      }
      
      int ans;
      
      while(start<=end)
      {
          int mid = (start+end)/2;
          
          if(check(sweetness, n , k, mid))
          {
             ans = mid;
             start = mid+1;
          }
          else
          {
             end = mid-1;
          }
      }
      
      return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends