class Solution {
public:
    
    vector<string>answer;
    unordered_map<char,string>mp;
    
    void recursion(string &digits,int i,string &solution,int n){
        if(i==n){
            answer.push_back(solution);
            return;
        }
        string possibilities = mp[digits[i]];
        for(char &ch : possibilities){
            solution += ch;
            recursion(digits,i+1,solution,n);
            solution.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();
        if(n==0){
            return {};
        }
        answer.clear();
        mp.clear();
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string solution = "";
        recursion(digits,0,solution,n);
        return answer;
        
    }
};