//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    pair<bool,int> func(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = func(root->left);
        pair<bool,int> right = func(root->right);
        
        bool leftB = left.first;
        bool rightB = right.first;
        
        int leftH = left.second+1;
        int rightH = right.second+1;
        
        bool ans = ( abs(leftH-rightH) <= 1);
        
        
        pair<bool,int> res;
        res.second = max(leftH, rightH);
        if(leftB && rightB && ans)
        {
            res.first = true;
        }
        else
        {
            res.first = false;
        }
        
        return res;
    }
    
    bool isBalanced(Node *root)
    {
        return func(root).first;
    }
    
    
    // int height(Node* root)
    // {
    //     if(root==NULL)
    //     return 0;
        
    //     int left = height(root->left)+1;
    //     int right = height(root->right)+1;
        
    //     int ans = max(left, right);
        
    //     return ans;
    // }
    
    
    // bool isBalanced(Node *root)
    // {
    //     if(root==NULL)
    //     return true;
        
    //     bool left = isBalanced(root->left);
    //     bool right = isBalanced(root->right);
    //     bool diff = (abs(height(root->left)-height(root->right))<=1);
        
    //     if(left && right && diff)
    //     return true;
        
    //     return false;
    // }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends