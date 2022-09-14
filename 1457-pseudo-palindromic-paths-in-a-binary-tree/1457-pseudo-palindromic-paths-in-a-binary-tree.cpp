class Solution {
public:
    
    int paths=0;
    
    int freq[10];
    
    bool isPalindrome(){
        
        int odd=0,even=0;
        
        for(int i=0;i<10;++i){
            
            if(freq[i]){
                
                if(freq[i]%2){
                    odd++;
                }else{
                    even++;
                }
                
            }
            
        }
        
        return odd<=1;
        
    }
    
    void func(TreeNode*&root){
        
        if(!root){
            return;
        }
        
        freq[root->val]++;
        
        if(root && !root->left && !root->right){
            
            if(isPalindrome()){
                
                paths++;
                
            }
            
        }
        
        func(root->left);
        
        func(root->right);
        
        freq[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        memset(freq,0,sizeof(freq));
        
        func(root);
        
        return paths;
        
    }
};