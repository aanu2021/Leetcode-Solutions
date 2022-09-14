struct Node{
  
    public:

    Node*links[26];
    int pscore;  // Corresponding Prefix Score
    int wscore;  // Score assigned to each word at its end
    
    bool containsKey(char ch){
        
        return links[ch-'a']!=NULL;
        
    }
    
    Node*get(char ch){
        
        return links[ch-'a'];
        
    }
    
    void put(char ch,Node*node){
        
        links[ch-'a']=node;
        
    }
    
    void set_prefix_Score(int sc){
        
        pscore+=sc;
        
    }
    
    void remove_prefix_Score(int sc){
        
        pscore-=sc;
        
    }
    
    int get_prefix_Score(){
        
        return pscore;
        
    }
    
    void set_word_Score(int sc){
        
        wscore+=sc;
        
    }
    
    void remove_word_Score(int sc){
        
        wscore-=sc;
        
    }
    
    int get_word_Score(){
        
        return wscore;
        
    }
    
};

class Trie{
    
  public:
    
    Node*root;
    
    Trie(){
    
        root=new Node();
        
    }
    
    
    void insert(string &word,int score){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                node->put(word[i],new Node());
                
            }
            
            node=node->get(word[i]);
            
            node->set_prefix_Score(score);
            
        }
        
            node->set_word_Score(score);
        
    }
    
    
    void remove(string &word,int score){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return;
                
            }
            
            node=node->get(word[i]);
            
            node->remove_prefix_Score(score);
            
        }
        
        node->remove_word_Score(score);
        
    }
    
    
    int isExist(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return 0;
                
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->get_word_Score();
        
    }
    
    int sum_score(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return 0;
                
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->get_prefix_Score();
        
    }
    
};


class MapSum {
public:
    
    Trie obj;
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        
        int already_exist=obj.isExist(key);
        
        if(already_exist){
            
            obj.remove(key,already_exist);
            
        }
        
        obj.insert(key,val);
        
    }
    
    int sum(string prefix) {
        
        return obj.sum_score(prefix);
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */