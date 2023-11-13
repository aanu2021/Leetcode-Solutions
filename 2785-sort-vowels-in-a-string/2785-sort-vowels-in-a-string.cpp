class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }
    
    string sortVowels(string s) {
        string curr = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                curr += s[i];
            }
        }
        sort(curr.begin(),curr.end());
        reverse(curr.begin(),curr.end());
        for(int i=0;i<n;i++){
            if(isVowel(s[i])==false){
                continue;
            }
            else{
                s[i] = curr.back();
                curr.pop_back();
            }
        }
        return s;
    }
};