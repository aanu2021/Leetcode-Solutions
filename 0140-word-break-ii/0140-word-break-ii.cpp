class Solution {
public:
    
    unordered_set<string>S;
    
    void func(string &s, int i, int n, string sub, vector<string>&answer){
        if(i == n){
            sub.pop_back();
            answer.push_back(sub);
            return;
        }
        string str = "";
        for(int j=i;j<n;j++){
            str += s[j];
            if(S.find(str) != S.end()){
                func(s, j+1, n, sub + str + " ", answer);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        for(string &str : wordDict){
            S.insert(str);
        }
        vector<string>answer;
        func(s, 0, n, "", answer);
        return answer;
    }
};