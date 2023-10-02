class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.length();
        int alice = 0, bob = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                int j = i;
                while(j<n && s[j]=='A'){
                    j++;
                }
                alice += max(j-i-2,0);
                i = j;
                i--;
            }
            else{
                int j = i;
                while(j<n && s[j]=='B'){
                    j++;
                }
                bob += max(j-i-2,0);
                i = j;
                i--;
            }
        }
        if(alice > bob){
            return true;
        }
        else{
            return false;
        }
    }
};