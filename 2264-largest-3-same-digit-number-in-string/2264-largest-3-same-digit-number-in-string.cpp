class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>freq(10,0);
        int n = num.length();
        for(int i=0;i<=n-3;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                freq[num[i]-'0']++;
            }
        }
        for(int i=9;i>=0;i--){
            if(freq[i] > 0){
                string res = "";
                res += (char)(i+'0');
                res += (char)(i+'0');
                res += (char)(i+'0');
                return res;
            }
        }
        return "";
    }
};