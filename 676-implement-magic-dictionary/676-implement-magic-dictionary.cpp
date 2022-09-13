class Node{
    
  private:   
    
  Node*links[26];
  bool flag=false;
    
  public:  
    
  bool containsKey(char ch){
      
      return links[ch-'a']!=NULL;
      
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

class Trie{
    
  private:  
    
    Node*root; 
    
  public:
    
    Trie(){
        
        root=new Node();
        
    }
    
    void insert(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                node->put(word[i],new Node());
                
            }
            
            node=node->get(word[i]);
            
        }
        
        node->setEnd();
        
    }
    
    bool Search_Word(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                return false;
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->isEnd();
        
    }
    
};

class MagicDictionary {
public:
    
    Trie obj;
    
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        
       for(string str:dictionary){
           
           obj.insert(str);
           
       }
        
    }
    
    bool search(string word) {
        
        int n=word.size();
        
        for(int i=0;i<n;++i){
            
            char temp=word[i];
            
            for(char ch='a';ch<='z';ch++){
                
                if(ch==temp){
                    continue;
                }
                
                word[i]=ch;
                
                bool flag=obj.Search_Word(word);
                
                if(flag){return true;}
                
            }
            
            word[i]=temp;
            
        }
        
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */