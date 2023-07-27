//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int petrol = 0, distance = 0;
        
        for(int i=0; i<n; i++)
        {
            petrol += p[i].petrol;
            distance += p[i].distance;
        }
        
        if(petrol < distance)
        {
            return -1;
        }
        
        int rem = 0, start = 0;
        
        for(int i=0; i<n; i++)
        {
            rem += p[i].petrol - p[i].distance;
            
            if(rem < 0)
            {
                start = i+1;
                rem = 0;
            }
        }
        
        return start;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends