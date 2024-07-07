struct Node{
    
   Node * links[26];
   bool endWord;
   int wordCost;
    
   Node(){
       endWord = false;
       wordCost = -1;
       for(int i=0;i<26;i++){
           links[i] = NULL;
       }
   } 
   bool containsKey(char ch){
       return (links[ch-'a'] != NULL);
   } 
   Node * get(char ch){
       return links[ch-'a'];
   } 
   void put(char ch, Node * node){
       links[ch-'a'] = node;
   }                 
   void setEndWord(int cost){
       endWord = true;
       if(wordCost == -1) wordCost = cost;
       else wordCost = min(wordCost, cost);
   }                 
   bool getEndWord(){
       return endWord;
   }           
                    
};

class Solution {
public:
    
    typedef long long ll;
    
    Node * root = new Node();
    
    void insertWord(string &word, int cost){
        Node * node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEndWord(cost);
    }
    
    vector<ll>dp;
    const ll INF = 1000000000;
    
    ll func(string &str, int i, int n){
        if(i == n) return 0LL;
        if(dp[i] != -1LL) return dp[i];
        Node * node = root;
        ll minCost = INF;
        for(int j=i;j<n;j++){
            if(!node->containsKey(str[j])) break;
            node = node->get(str[j]);
            if(node->getEndWord() == true){
                minCost = min(minCost, node->wordCost + func(str, j+1, n));
            }
        }
        return dp[i] = minCost;
    }
    
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        int n = target.length();
        for(int i=0;i<words.size();i++){
            insertWord(words[i], costs[i]);
        }
        
        dp.clear();
        dp = vector<ll>(n, -1LL);
        ll ans = func(target, 0, n);
        return ans >= INF ? -1 : ans;
    
    }
};