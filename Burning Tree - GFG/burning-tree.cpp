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

class Solution {
  public:
  
    int ans = 0;
  
    int calcHeight(Node*&root,int leaf){
        
        if(!root) return 0;
        
        int lh = calcHeight(root->left,leaf);
        int rh = calcHeight(root->right,leaf);
        
        if(root->data == leaf){
            ans = 1 + max(lh,rh);
        }
        
        return 1 + max(lh,rh);
        
    }
  
    int func(Node* &root,int target,int &dist){
        if(!root) return 0;
        if(root->data == target){
            dist = 0;
        }
        int ldist = -1, rdist = -1;
        int lh = func(root->left,target,ldist);
        int rh = func(root->right,target,rdist);
        if(ldist != -1){
            dist = ldist + 1;
            ans = max(ans,dist + rh);
        }
        else if(rdist != -1){
            dist = rdist + 1;
            ans = max(ans,dist + lh);
        }
        return 1 + max(lh,rh);
    } 
  
    int minTime(Node* root, int target) 
    {
       if(!root) return 0;
       if(!root->left && !root->right) return 0;
       ans = 0;
       int dist = -1;
       calcHeight(root,target);
       ans--;
       func(root,target,dist);
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