//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int min_soldiers(int arr[], int n, int k);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n, k;
        cin>> n >> k;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout << min_soldiers(arr, n, k) << endl;
        
    }
	
	return 0;
}
// } Driver Code Ends


int min_soldiers(int arr[], int n, int k){
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]%k != 0)
        {
            arr[i] = k - arr[i]%k;
        }
        else
            arr[i] = 0;
    }
    
    sort(arr, arr+n);
    
    int half, ans = 0;
    
    if(n%2==0)
    half = n/2;
    else
    half = n/2+1;
    
    for(int i=0; i<half; i++)
    ans+=arr[i];
    
    return ans;
}