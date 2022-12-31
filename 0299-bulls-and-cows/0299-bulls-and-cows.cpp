class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        vector<int>freq1(10,0);
        vector<int>freq2(10,0);
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]) x++;
            else{
                freq1[secret[i]-'0']++;
                freq2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            y+=min(freq1[i],freq2[i]);
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};