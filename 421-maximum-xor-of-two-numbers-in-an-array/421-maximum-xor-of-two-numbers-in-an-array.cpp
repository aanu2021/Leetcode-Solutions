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
                node=node->get(1-bit);
                ans|=(1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
        
        int n=nums.size();
        
        Trie obj;
        
        for(auto ele:nums){
            obj.insert(ele);
        }
        
        int maxval=0;
        
        for(auto ele:nums){
            maxval=max(maxval,obj.maxNum(ele));
        }
        
        return maxval;
        
    }
};