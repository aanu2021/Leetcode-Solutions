struct Node{
  
    Node*links[26];
    bool endWord;
    string eW;
    
    bool containsKey(char ch){
        
        return links[ch-'a']!=NULL;
        
    }
    
    Node*get(char ch){
        
        return links[ch-'a'];
        
    }
    
    void put(char ch,Node*node){
        
        links[ch-'a'] = node;
        
    }
    
};

void addWords(Node*root,string word){
    
    Node*node = root;
    
    for(int i=0;i<word.length();i++){
        
        if(!node->containsKey(word[i])){
            node->put(word[i],new Node());
        }
        
        node = node->get(word[i]);
    
    }
    
    node->endWord = true;
    node->eW = word;
    
}

void search(Node*root,int k,vector<string>&list){
    
    if(root==NULL) return;
    
    if(root->endWord==true){
        
        root->endWord = false;
        list.push_back(root->eW);
        
    }
    
    if(list.size()==k) return;
    
    for(char ch='a';ch<='z';ch++){
        
        if(root->containsKey(ch)){
            
            search(root->links[ch-'a'],k,list);
            
        }
        
    }
    
}

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        unordered_map<string,int>freq;
        
        for(int i=0;i<n;i++){
            freq[words[i]]++;
        }
        
        vector<Node*>arr(n+1);
        
        for(auto itr:freq){
            
            if(arr[itr.second]==NULL){
                
                arr[itr.second] = new Node();
                
            }
            
            addWords(arr[itr.second],itr.first);
            
        }
        
        vector<string>list;
        
        for(int i=n;i>=1;i--){
            
            search(arr[i],k,list);
            
        }
        
        return list;
        
    }
};