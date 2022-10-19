/*

Time Complexity  : O(N*M)
Space Complexity : O(N)

*/


struct Node{

    Node*links[26];
    string ew;
    
    bool containsKey(char ch){
        
        return (links[ch-'a']!=NULL);
        
    }
    
    Node*get(char ch){
        
        return links[ch-'a'];
        
    }
    
    void put(char ch,Node*node){
        
        links[ch-'a'] = node;
        
    }
    
};


void addWords(Node*&root,string word){
    
    Node*node = root;
    
    for(int i=0;i<word.length();i++){
        
        if(!node->containsKey(word[i])){
            
            node->put(word[i],new Node());
            
        }
        
        node = node->get(word[i]);
        
    }
    
    node->ew = word;
    
}


void searchWords(Node*&root,int k,vector<string>&list){
    
    if(root==NULL) return;
    
    if(list.size()==k) return;
    
    if(root->ew!="") list.push_back(root->ew);
    
    for(char ch='a';ch<='z';ch++){
        
        if(root->containsKey(ch)){
            
            searchWords(root->links[ch-'a'],k,list);
            
        }
        
    }
    
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        vector<Node*>freq(n+1);
        
        for(int i=0;i<=n;i++){
            
            freq[i] = new Node();
            
        }
        
        vector<string>list;
        
        for(auto itr:mp){
            
            addWords(freq[itr.second],itr.first);
            
        }
        
        for(int i=n;i>=1;i--){
            
            searchWords(freq[i],k,list);
            
        }
        
        return list;
        
    }
};