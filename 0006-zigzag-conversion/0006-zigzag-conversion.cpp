class Solution {
public:
    string convert(string s, int row) {
        if(row == 1) return s;
        int n = s.length();
        vector<string>vec(row);
        int r = 0,idx = 0;
        int flag = 0;
        while(idx < n){
            if(r == row-1){
                vec[r] += s[idx++];
                if(flag){
                    flag = false;
                    r--;
                }
            }
            else if(r == 0){
                vec[r] += s[idx++];
                if(!flag){
                    flag = true;
                    r++;
                }
            }
            else{
                vec[r] += s[idx++];
                if(flag){
                    r++;
                }
                else{
                    r--;
                }
            }
        }
        string ans = "";
        for(int i=0;i<row;i++){
            for(int j=0;j<vec[i].length();j++){
                ans += vec[i][j];
            }
        }
        return ans;
    }
};

  