class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    map<TreeNode*,ll>sum_sub;
    
    ll maxproduct=0LL;
    
    ll grand_total=0LL;
    
    int preprocessing(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }
        
        ll leftval=preprocessing(root->left);
        
        ll rightval=preprocessing(root->right);
        
        sum_sub[root]=root->val+leftval+rightval;
        
        return sum_sub[root];
                
    }
    
    
    void func(TreeNode*root){
        
       if(root==NULL){
           return;
       }
        
       if(root->left!=NULL){
           
           ll cand1=sum_sub[root->left];
           
           ll cand2=grand_total-cand1;
           
           maxproduct=max(maxproduct,(cand1*cand2));
           
       } 
        
       
       if(root->right!=NULL){
           
           ll cand1=sum_sub[root->right];
           
           ll cand2=grand_total-cand1;
           
           maxproduct=max(maxproduct,(cand1*cand2));
           
       }
        
        
       func(root->left);
       
       func(root->right); 
        
    }
    
    
    int maxProduct(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        preprocessing(root);
        
        grand_total=sum_sub[root];
        
        func(root);
        
        return mod(maxproduct);
        
    }
};