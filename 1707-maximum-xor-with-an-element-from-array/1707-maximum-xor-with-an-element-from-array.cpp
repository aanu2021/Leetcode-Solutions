struct Node{
  
    Node*links[2];
    
    bool containsKey(int bit){
        
        return (links[bit]!=NULL);
        
    }
    
    Node*get(int bit){
        
        return links[bit];
        
    }
    
    void put(int bit,Node*node){
        
        links[bit]=node;
        
    }
    
};


class Trie{
    
  private: Node*root;
    
  public:
    
     Trie(){
         
         root=new Node();
         
     }
    
     void insert(int num){
         
         Node*node=root;
         
         for(int i=31;i>=0;i--){
             
             int bit=(num>>i)&1;
             
             if(!node->containsKey(bit)){
                 node->put(bit,new Node());
             }
             
             node=node->get(bit);
             
         }
         
     }
    
     int maxNum(int num){
         
         Node*node=root;
         
         int ans=0;
         
         for(int i=31;i>=0;i--){
             
             int bit=(num>>i)&1;
             
             if(node->containsKey(1-bit)){
                 ans|=(1<<i);
                 node=node->get(1-bit);
             }
             
             else{
                 node=node->get(bit);
             }
             
         }
         
         return ans;
         
     }
    
};


class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sz=queries.size();
        
        int n=nums.size();
        
        vector<vector<int>>vec(sz);
        
        for(int i=0;i<sz;++i){
            
            vec[i]={queries[i][0],queries[i][1],i};
            
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        sort(nums.begin(),nums.end());
        
        int idx=0;
        
        Trie obj;
        
        vector<int>ans(sz,-1);
        
        for(int i=0;i<sz;i++){
            
            int xi=vec[i][0];
            int mi=vec[i][1];
            int j=vec[i][2];
            
            while(idx<n && nums[idx]<=mi){
                
                obj.insert(nums[idx]);
                idx++;
                
            }
            
            if(idx==0){
                ans[j]=-1;
                continue;
            }
            
            else{
                ans[j]=obj.maxNum(xi);
            }
            
        }
        
        return ans;
        
    }
};