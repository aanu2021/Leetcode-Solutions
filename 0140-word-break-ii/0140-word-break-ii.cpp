class Solution {
public:
    
    vector<string>answer;
    unordered_set<string>S;
    
    void recursion(string &s,int i,int n,vector<string>&solution){
        if(i==n){
            string word = "";
            for(string &str : solution){
                word += str;
                word += " ";
            }
            word.pop_back();
            answer.push_back(word);
        }
        string str = "";
        for(int j=i;j<n;j++){
            str += s[j];
            if(S.find(str) != S.end()){
                solution.push_back(str);
                recursion(s,j+1,n,solution);
                solution.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        S.clear();
        answer.clear();
        vector<string>solution;
        for(string &str : wordDict){
            S.insert(str);
        }
        recursion(s,0,n,solution);
        return answer;
    }
};