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
    
    void func(TreeNode*&root,int odd,int even){
        
        if(!root){
            return;
        }
        
        int prev_freq=freq[root->val];
        
        if(prev_freq){
            
            if(prev_freq%2){
                odd--;
            }else{
                even--;
            }
            
        }
        
        freq[root->val]++;
        
        int new_freq=freq[root->val];
        
        if(new_freq){
            
            if(new_freq%2){
                odd++;
            }else{
                even++;
            }
            
        }
        
        if(root && !root->left && !root->right){
            
            if(odd<=1){
                
                paths++;
                
            }
            
        }
        
        func(root->left,odd,even);
        
        func(root->right,odd,even);
        
            if(new_freq%2){
                odd--;
            }else{
                even--;
            }
        
        freq[root->val]--;
        
            int curr_freq=freq[root->val];
        
            if(curr_freq){
                
                if(curr_freq%2){
                    odd++;
                }else{
                    even++;
                }
                
            } 
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        memset(freq,0,sizeof(freq));
        
        func(root,0,0);
        
        return paths;
        
    }
};