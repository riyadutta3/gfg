//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S[j].charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.numIslands(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Pair{
    int first;
    int second;
    
    public Pair(int first, int second){
        this.first = first;
        this.second = second;
    }
}
class Solution {
    // Function to find the number of islands.
    public void bfs(int row, int col,char[][] grid, int[][] vis)
    {
        vis[row][col] = 1;
        
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(row, col));
        
        int n = grid.length;
        int m = grid[0].length;
        
        while(!q.isEmpty()){
            int r = q.peek().first;
            int c = q.peek().second;
            q.remove();
            
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(r+i>=0 && r+i<n && c+j>=0 && c+j<m && grid[r+i][c+j]=='1' && vis[r+i][c+j]==0){
                        vis[r+i][c+j] = 1;
                        q.add(new Pair(r+i, c+j));
                    }
                }
            }
            
        }
        
        
    }
    
    
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        int vis[][] = new int[n][m];
        
        int count = 0;
        
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(vis[row][col]==0 && grid[row][col]=='1'){
                    bfs(row, col, grid, vis);
                    count++;
                }
            }
        }
        
        return count;
    }
}