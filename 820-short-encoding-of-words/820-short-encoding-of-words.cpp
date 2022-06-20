struct Node{
  
    Node*links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node*get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag=true;
    }
    
};


int ans=0;

class Trie{
  
    private : Node*root;
    
    public :
    
    Trie(){
        
        root=new Node();
        
    }
    
    bool insert(string &word){
        
        Node*node=root;
        
        bool pos=true;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                pos=false;
                node->put(word[i],new Node());
                
            }
            
            node=node->get(word[i]);
            
        }
        
        if(pos==false){
            
            node->setEnd();
            
        }
        
        return pos;
        
    }
    
};


class Solution {
public:
    
    bool static comp(string &s1,string &s2){
        return s1.length() > s2.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
        
        ans=0;
        
        sort(words.begin(),words.end(),comp);
        
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
        }
        
        Trie obj;
        
        for(int i=0;i<n;i++){
            
            bool flag=obj.insert(words[i]);
            
            if(flag==false){
                ans++;
                ans+=words[i].length();
            }
            
        }
        
        return ans;
        
    }
};