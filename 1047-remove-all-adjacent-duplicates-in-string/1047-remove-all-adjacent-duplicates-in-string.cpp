class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        int left = 1, right = 1;
        while(right < n){
            if(left > 0 && s[left-1] == s[right]){
                left--;
                right++;
            }
            else{
                s[left] = s[right];
                left++;
                right++;
            }
        }
        return s.substr(0,left);
    }
};