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
    
    bool static comp(const vector<int>&x, const vector<int>&y){
        return x[1] < y[1];
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j = 0;
        int q = queries.size();
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        vector<int>answer(q,-1);
        Trie obj;
        for(int i=0;i<q;i++){
            int xi = queries[i][0];
            int mi = queries[i][1];
            while(j<n && nums[j] <= mi){
                obj.insert(nums[j]);
                j++;
            }
            if(j==0){
                answer[queries[i][2]] = -1;
                continue;
            }
            else{
                answer[queries[i][2]] = obj.findMaxXor(xi);
            }
        }
        return answer;
    }
};