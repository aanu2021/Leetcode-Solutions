class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int ans = 0,pre = 0;
        for(int a:A){
            ans+=max(a-pre,0);
            pre = a;
        }
        return ans;
    }
};