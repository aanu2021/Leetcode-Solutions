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
        int n = chars.size();
        int currLen = 0;
        int idx = 0;
        for(int i=0;i<n;i++){
            int j = i;
            int cnt = 0;
            while(j<n && chars[j]==chars[i]){
                cnt++; j++;
            }
            chars[idx++] = chars[i];
            currLen++;
            if(cnt > 1){
                int numLen = num_of_dig(cnt);
                for(int j=idx+numLen-1;j>=idx;j--){
                    chars[j] = (char)((cnt%10) + '0');
                    cnt /= 10;
                }
                currLen += numLen;
                idx += numLen;
            }
            i = j;
            i--;
        }
        return currLen;
    }
};