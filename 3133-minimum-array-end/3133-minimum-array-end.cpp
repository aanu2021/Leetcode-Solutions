class Solution {
public:
    
    typedef long long ll;
    
    long long minEnd(int n, int x) {
        ll ele = (ll)x;
        string str = "";
        for(int i=60;i>=0;i--){
            if((ele&(1LL<<i))){
                str += "1";
            }
            else{
                str += "0";
            }
        }
        ll answer = 0LL;
        n--;
        if(n == 0) return (ll)x;
        string req = "";
        while(n > 0){
            req += (char)(n%2 + '0');
            n /= 2;
        }
        reverse(req.begin(),req.end());
        for(int i=str.length() - 1;i>=0;i--){
            if(req.length() == 0) break;
            if(str[i] == '0'){
                str[i] = req.back();
                req.pop_back();
            }
            else{
                continue;
            }
        }
        // cout<<str<<"\n";
        for(int i=0;i<str.length();i++){
            answer *= 2LL;
            if(str[i] == '1'){
                answer++;
            }
        }
        return answer;
    }
};

/*

bitwise and of all the elements should be equal to x

a0 a1 a2 a3 a4 a5

x  x  x  x  x  x


100 101 110
     
    1 0 1 1 1
    
    x = 5
    
    1 0 0 1 1 1 1
    
    n = 19
    
    1 0 0 1 1
    
    
    
*/    
    