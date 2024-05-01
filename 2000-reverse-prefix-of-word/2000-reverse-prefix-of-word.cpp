class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        if(index == -1) return word;
        int l = 0, r = index;
        while(l < r){
            char temp = word[l];
            word[l] = word[r];
            word[r] = temp;
            l++; r--;
        }
        return word;
    }
};