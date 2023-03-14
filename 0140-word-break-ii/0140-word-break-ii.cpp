class Solution {
public:
    
    vector<string>answer;
    unordered_set<string>dict;
    
    void func(string &s,int i,int n,vector<string> &solution){
        if(i==n){
            string word = "";
            for(string &str : solution){
                word += str;
                word += " ";
            }
            word.pop_back();
            answer.push_back(word);
            return;
        }
        string word = "";
        for(int j=i;j<n;j++){
            word += s[j];
            if(dict.find(word) != dict.end()){
                solution.push_back(word);
                func(s,j+1,n,solution);
                solution.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        for(string &str : wordDict){
            dict.insert(str);
        }
        vector<string>solution;
        func(s,0,n,solution);
        return answer;
    }
};