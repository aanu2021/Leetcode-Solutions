class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int countVowelPermutation(int n) {
        if(n==1) return 5;
        ll cntA = 1LL, cntE = 1LL, cntI = 1LL, cntO = 1LL, cntU = 1LL;
        for(int i=2;i<=n;i++){
            ll tempA = cntI + cntE + cntU;
            tempA %= M;
            ll tempE = cntA + cntI;
            tempE %= M;
            ll tempI = cntE + cntO;
            tempI %= M;
            ll tempO = cntI;
            tempO %= M;
            ll tempU = cntI + cntO;
            tempU %= M;
            cntA = tempA;
            cntE = tempE;
            cntI = tempI;
            cntO = tempO;
            cntU = tempU;
        }
        return ((cntA + cntE + cntI + cntO + cntU) % M);
    }
};

// a -> e
// e -> a, i
// i -> a, e, o, u
// o -> i, u
// u -> a


// a -> e, i, u