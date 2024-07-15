class Solution {
public:
    
    map<int,vector<pair<int,int>>>mp;
    
    TreeNode*func(int val){
        
        TreeNode*root=new TreeNode(val);
        
        if(mp[val].size()==0){
            return root;
        }
        
        else if(mp[val].size()==1){
            
            auto curr=mp[val][0];
            
            int child=curr.first;
            int valc=curr.second;
            
            if(valc==0){
                root->right=func(child);
            }
            
            else{
                root->left=func(child);
            }
            
        }
        
        else if(mp[val].size()==2){
            
            auto curr1=mp[val][0];
            
            int child1=curr1.first;
            int valc1=curr1.second;
            
            if(valc1==0){
                root->right=func(child1);
            }
            
            else{
                root->left=func(child1);
            }
            
            
             auto curr2=mp[val][1];
            
            int child2=curr2.first;
            int valc2=curr2.second;
            
            if(valc2==0){
                root->right=func(child2);
            }
            
            else{
                root->left=func(child2);
            }
            
            
        }
        
        return root;
        
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int,int>mapp;
        
        for(int i=0;i<d.size();i++){
            
            mapp[d[i][1]]++;
            
            mp[d[i][0]].push_back({d[i][1],d[i][2]});
            
        }
        
        
        int val=-1;
        
        for(int i=0;i<d.size();i++){
            
            if(mapp[d[i][0]]==0){
                val=d[i][0];
                break;
            }
            
        }
        
        
        TreeNode*root=func(val);
        
        return root;
        
    }
};