//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int low=0, high=n-1;
        int mini=INT_MAX;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[low]<=arr[high])
            {
                mini=min(mini,arr[low]);
                return mini;
            }
            
            if(arr[low]<=arr[mid]){
                mini=min(mini, arr[low]);
                low=mid+1;
            }
            else if(arr[low]>arr[mid]){
                mini=min(mini,arr[mid]);
                high=mid-1;
            }
        }
        
        return mini;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends