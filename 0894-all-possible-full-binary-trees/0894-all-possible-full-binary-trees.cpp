class Solution {
public:
    
    vector<TreeNode*>recursion(int n){
       
        vector<TreeNode*>answer;
        
        if(n==1){
            return {new TreeNode(0)};
        }
        for(int i=0;i<n;i++){
            int x = i;
            int y = n-i-1;
            if(x%2 == 0 || y%2 == 0) continue;
            for(auto l : recursion(x)){
                for(auto r : recursion(y)){
                    TreeNode*node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    answer.push_back(node);
                }
            }
        }
        return answer;
        
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        return recursion(n);
    }
};

// 7 - 1 = 6
    
// 1 5
// 3 3 
// 5 1    
    
//      1
//     / \
//    2   3