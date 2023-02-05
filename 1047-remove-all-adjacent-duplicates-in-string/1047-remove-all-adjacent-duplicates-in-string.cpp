class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        if(n==1) return s;
        int left = 1 , right = 1;
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
        while(s.length() > left){
            s.pop_back();
        }
        return s;
    }
};