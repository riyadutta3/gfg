//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  void func(Node* root, int count, int& ans)
    {
        if(root == NULL)
        return;
        
        
        if(root->left == NULL && root->right == NULL)
        {
            ans = max(count, ans);
            return;
        }
        
        
        func(root->left, count+1, ans);
        func(root->right, count+1, ans);
    }
    
    void findPath(Node* root, int val, vector<Node*> &path, bool &var)
{
    if(root == NULL)
    return; 
    
    if(var==false)
    path.push_back(root);
        
    if(root->data == val)
    {
        var = true;
        return; 
    }
    
    if(var == false)
    findPath(root->left, val, path, var);
    
    if(var == false)
   findPath(root->right, val, path, var);
    
    if(var == false)
    path.pop_back();
    
    return;
}


    int minTime(Node* root, int target) 
    {
        vector<Node*> path;
        bool var = false;
        int count = 1, ans = 0;
        
        findPath(root, target, path, var);
        
        int n = path.size();
        Node* temp = path[n-1];
        
        
        func(temp->left,count,ans); //left sub tree of current node
        
        func(temp->right,count, ans); //right sub tree of current node
        
        int i = n-2;
        int dist = 1;
        
        while(i>=0)
        {
            temp = path[i];
            count = dist + 1;
            // cout<<temp->data<<endl;
            Node* node = path[i+1];
            
            if(temp->left && temp->left->data == node->data)
            {
                if(temp->right)
                func(temp->right, count, ans);
                else
                ans = max(ans, dist);
            }
            else if(temp->right && temp->right->data == node->data)
            {
                if(temp->left)
                func(temp->left, count, ans);
                else
                ans = max(ans, dist);
            }
            
            // ans = max(ans,count);
            
            dist++;
            i--;
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends