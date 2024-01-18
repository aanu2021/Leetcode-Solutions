class Solution {
public:
    
    int sod(int num){
        int sum = 0;
        while(num){
            int rem = (num%10);
            sum += rem;
            num /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        unordered_map<int,int>freq;
        for(int i=1;i<=n;i++) freq[sod(i)]++;
        int maxFreq = 0;
        for(auto &itr : freq) maxFreq = max(maxFreq, itr.second);
        int cnt = 0;
        for(auto &itr : freq){
            if(itr.second == maxFreq) cnt++;
        }
        return cnt;
    }
};