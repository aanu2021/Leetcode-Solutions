struct Node{
   Node*links[2];
   Node(){
       links[0] = NULL;
       links[1] = NULL;
   } 
   bool containsKey(int bit){
       return (links[bit] != NULL);
   } 
   Node*get(int bit){
       return links[bit];
   } 
   void put(int bit,Node*node){
       links[bit] = node;
   }  
};

class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node*node = root;
        for(int bit=31;bit>=0;bit--){
            int b = 0;
            if((num&(1<<bit))) b = 1;
            if(!node->containsKey(b)){
                node->put(b,new Node());
            }
            node = node->get(b);
        }
    }
    int findMaxXor(int ele){
        Node*node = root;
        int xorSum = 0;
        for(int bit=31;bit>=0;bit--){
            int b = 0;
            if((ele&(1<<bit))) b = 1;
            if(!node->containsKey(1-b)){
                node = node->get(b);
            }
            else{
                xorSum |= (1<<bit);
                node = node->get(1-b);
            }
        }
        return xorSum;
    }
};

class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie obj;
        for(int i=0;i<n;i++){
            obj.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, obj.findMaxXor(nums[i]));
        }
        return maxi;
    }
};