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
    
    void func(TreeNode*&root,int count){
        
       if(!root){
           return;
       }
        
       count^=(1<<(root->val-1));
        
       func(root->left, count);
        
       func(root->right,count);
        
       if(!root->left && !root->right){
           
           if((count&(count-1))==0){
               
               paths++;
               
           }
           
       } 
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        memset(freq,0,sizeof(freq));
        
        func(root,0);
        
        return paths;
        
    }
};