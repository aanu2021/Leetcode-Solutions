class Solution {
public:
    
    bool isVowel(char ch){
        
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        
        return false;
        
    }
    
    string reverseVowels(string s) {
        
        int n = s.length();
        
        int i = 0, j = n-1;
        
        while(i<=j){
            
            while(i<=j && isVowel(s[i])==false){
                i++;
            }
            
            while(i<=j && isVowel(s[j])==false){
                j--;
            }
            
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
            }
            
            i++;
            j--;
            
        }
        
        return s;
        
    }
};
