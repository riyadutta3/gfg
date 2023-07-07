//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
         vector<int> v;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = rows*cols;
        int count = 0;

        int srow=0, scol=0, lrow=rows-1, lcol=cols-1;

        while(count<total){
            for(int i=scol;count<total &&  i<=lcol; i++)
            {
                v.push_back(matrix[srow][i]);
                count++;
            }
            srow++;

            for(int i=srow;count<total &&  i<=lrow; i++)
            {
                v.push_back(matrix[i][lcol]);
                count++;
            }
            lcol--;

            for(int i=lcol;count<total &&  i>=scol; i--)
            {
                v.push_back(matrix[lrow][i]);
                count++;
            }
            lrow--;

            for(int i=lrow;count<total &&  i>=srow; i--)
            {
                v.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }

        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends