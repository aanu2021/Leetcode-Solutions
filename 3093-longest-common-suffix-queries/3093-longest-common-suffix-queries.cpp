struct Node{
    Node * links[26];
    bool endWord;
    int index;
    int len;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        endWord = false;
        index = -1;
        len = -1;
    }
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node * node){
        links[ch-'a'] = node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void setEndWord(){
        endWord = false;
    }
    bool isEndWord(){
        return endWord;
    }
};

class Solution {
public:
    
    Node * root = new Node();
    
    void insertWord(string &word, int idx){
        int n = word.length();
        Node * node = root;
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
                node = node->get(word[i]);
                node->index = idx;
                node->len = n;
            }
            else{
                node = node->get(word[i]);
                if(node->len > n){
                    node->len = n;
                    node->index = idx;
                }
            }
        }
    }
    
    int query(string &word, int priIndex){
        int answer = priIndex;
        Node * node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return answer;
            }
            node = node->get(word[i]);
            answer = node->index;
        }
        return answer;
    }
    
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int n = wc.size();
        int m = wq.size();
        int priIndex = -1;
        int minLen = 10000000000;
        
        for(int i=0;i<n;i++){
            reverse(wc[i].begin(),wc[i].end());
        }
        for(int i=0;i<m;i++){
            reverse(wq[i].begin(),wq[i].end());
        }
        
        for(int i=0;i<n;i++){
            int currLen = wc[i].length();
            if(currLen < minLen){
                minLen = currLen;
                priIndex = i;
            }
        }
        
        vector<int>answer(m, priIndex);
        for(int i=0;i<n;i++){
            insertWord(wc[i], i);
        }
        for(int i=0;i<m;i++){
            int val = query(wq[i], priIndex);
            answer[i] = val;
        }
        
        return answer;
    }
};


