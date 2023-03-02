class Solution {
public:
    
    int num_of_dig(int num){
        int len = 0;
        while(num){
            len++;
            num /= 10;
        }
        return len;
    }
    
    int compress(vector<char>& chars) {
        int currLen = 0;
        int idx = 0;
        int n = chars.size();
        for(int i=0;i<n;i++){
            int j = i;
            int cnt = 0;
            while(j < n && chars[j]==chars[i]){
                cnt++; j++;
            }
            currLen++;
            chars[idx++] = chars[i];
            if(cnt > 1){
                string num = to_string(cnt);
                currLen += num.length();
                for(int ele = 0;ele < num.length();ele++){
                    chars[idx++] = num[ele];
                }
            }
            i = j;
            i--;
        }
        return currLen;
    }
};