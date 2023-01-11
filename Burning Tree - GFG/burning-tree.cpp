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
  
    unordered_map<Node*,Node*>parent;
    unordered_set<Node*>visited;
    
    bool isAbsent(Node*root){
        if(visited.find(root) == visited.end()) return true;
        else return false;
    }
    
    Node* findParent(Node* &root,int target){
        if(!root) return NULL;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        if(root->data == target) return root;
        Node*left = findParent(root->left,target);
        Node*right = findParent(root->right,target);
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    
    int timeForCompleteBurn(Node* &src){
        int timer = 0;
        queue<Node*>q;
        q.push(src);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                if(isAbsent(node)==false) continue;
                visited.insert(node);
                if(node->left && isAbsent(node->left)) q.push(node->left);
                if(node->right && isAbsent(node->right)) q.push(node->right);
                if(parent.find(node) != parent.end() && isAbsent(parent[node])) q.push(parent[node]);
            }
            timer++;
        }
        return timer - 1;
    }
  
    int minTime(Node* root, int target) 
    {
        if(!root) return 0;
        parent.clear();
        visited.clear();
        Node*src = findParent(root,target);
        return timeForCompleteBurn(src);
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