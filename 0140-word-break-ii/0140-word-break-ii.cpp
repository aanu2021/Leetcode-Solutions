struct Node{
    Node*links[26];
    bool endWord;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        endWord = false;
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
    bool isEndWord(){
        return endWord;
    }
    void setEndWord(){
        endWord = true;
    }
};

class Solution {
public:
    
    Node * root = new Node();
    
    void insertWord(string &str){
        int n = str.length();
        Node * node = root;
        for(int i=0;i<n;i++){
            if(!node->containsKey(str[i])){
                node->put(str[i], new Node());
            }
            node = node->get(str[i]);
        }
        node->setEndWord();
    }
    
    void recursion(string &s, int i, int n, string solution, vector<string>&answer){
        if(i == n){
            solution.pop_back();
            answer.push_back(solution);
            return;
        }
        string str = "";
        Node * node = root;
        for(int j=i;j<n;j++){
            str += s[j];
            if(!node->containsKey(s[j])){
                break;
            }
            node = node->get(s[j]);
            if(node->isEndWord()){
                recursion(s, j+1, n, solution + str + " ", answer);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        for(string str : wordDict){
            insertWord(str);
        }
        vector<string>answer;
        string solution = "";
        recursion(s, 0, n, "", answer);
        return answer;
    }
};