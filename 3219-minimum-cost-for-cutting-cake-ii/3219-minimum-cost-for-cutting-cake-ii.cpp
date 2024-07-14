class Solution {
public:
    
    typedef long long ll;
    
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        ll answer = 0LL, hCnt = 1LL, vCnt = 1LL;
        
        while(!hc.empty() || !vc.empty()){
            ll hCut = -1LL;
            ll vCut = -1LL;
            if(!hc.empty()) hCut = (ll)hc.back();
            if(!vc.empty()) vCut = (ll)vc.back();
            if(hCut >= vCut){
                answer += (hCut * vCnt);
                hCnt++;
                hc.pop_back();
            }
            else{
                answer += (vCut * hCnt);
                vCnt++;
                vc.pop_back();
            }
        }
        
        return answer;
    }
};