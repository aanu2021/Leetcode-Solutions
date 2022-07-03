class Solution {
public:
    
    bool func(TreeNode*root,int value,string&path){
        
        if(root==NULL){
            return false;
        }
        
        if(root->val==value){
            path+="X";
            return true;
        }
        
        if(func(root->left,value,path)){
            
            path+="L";
            
        }
        
        else if(func(root->right,value,path)){
            
            path+="R";
            
        }
        
        return !path.empty();
        
    }
    
    string getDirections(TreeNode* root, int sV, int dV) {
       
        string path1="";
        string path2="";
        
        func(root,sV,path1);
        
        func(root,dV,path2);
        
        // path1.pop_back();
        // path2.pop_back();
        
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        
        path1.pop_back();
        path2.pop_back();
        
       
//         reverse(path1.begin(),path1.end());
        
//         reverse(path2.begin(),path2.end());
        
        int sz1=path1.length();
        
        int sz2=path2.length();
        
        int i=0;
        
        for(i=0;i<min(sz1,sz2);++i){
            if(path1[i]!=path2[i]){
                break;
            }
        }
        
        // cout<<path1<<" "<<path2<<endl;
        
        int idx=i;
        
        string res="";
        
        for(int i=idx;i<sz1;++i){
            res+="U";
        }
        
        for(int i=idx;i<sz2;++i){
            res+=path2[i];
        }
        
        return res;
    }
};