class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCnt = 0;
        int n = bank.size();
        int answer = 0;
        for(int i=0;i<n;i++){
            int currCnt = 0;
            for(char ch : bank[i]){
                if(ch == '1') currCnt++;
            }
            answer += (prevCnt*currCnt);
            if(currCnt != 0) prevCnt = currCnt;
        }
        return answer;
    }
};