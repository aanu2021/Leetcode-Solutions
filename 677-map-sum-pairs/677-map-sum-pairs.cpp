struct Node{
  
    public:

    Node*links[26];
    int score;
    bool flag=false;
    int wscore;
    
    bool containsKey(char ch){
        
        return links[ch-'a']!=NULL;
        
    }
    
    Node*get(char ch){
        
        return links[ch-'a'];
        
    }
    
    void put(char ch,Node*node){
        
        links[ch-'a']=node;
        
    }
    
    void setScore(int sc){
        
        score+=sc;
        
    }
    
    void setEnd(){
        
        flag=true;
        
    }
    
    void removeScore(int sc){
        
        score-=sc;
        
    }
    
    int getScore(){
        
        return score;
        
    }
    
    bool isEnd(){
        
        return flag;
        
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
            
            node->setScore(score);
            
        }
        
        node->setEnd();
        
        node->wscore+=score;
        
    }
    
    void remove(string &word,int score){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return;
                
            }
            
            node=node->get(word[i]);
            
            node->removeScore(score);
            
        }
        
        node->wscore-=score;
        
    }
    
    int isExist(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return 0;
                
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->wscore;
        
    }
    
    int sum_score(string &word){
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                
                return 0;
                
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->getScore();
        
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