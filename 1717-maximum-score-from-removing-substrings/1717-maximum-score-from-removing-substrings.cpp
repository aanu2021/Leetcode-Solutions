class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>S;
        int n = s.length();
        int cost = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                if(!S.empty() && S.top() == 'a'){
                    S.pop();
                    cost += x;
                }
                else{
                    S.push(s[i]);
                }
            }
            else{
                S.push(s[i]);
            }
        }
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        reverse(res.begin(),res.end());
        
        for(int i=0;i<res.length();i++){
            if(res[i] == 'a'){
                if(!S.empty() && S.top() == 'b'){
                    S.pop();
                    cost += y;
                }
                else{
                    S.push(res[i]);
                }
            }
            else{
                S.push(res[i]);
            }
        }
        
        // cout<<cost<<"\n";
        int maxCost = cost;
        cost = 0;
        while(!S.empty()) S.pop();
        
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(!S.empty() && S.top() == 'b'){
                    S.pop();
                    cost += y;
                }
                else{
                    S.push(s[i]);
                }
            }
            else{
                S.push(s[i]);
            }
        }
        
        res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        
        reverse(res.begin(),res.end());
        
        for(int i=0;i<res.length();i++){
            if(res[i] == 'b'){
                if(!S.empty() && S.top() == 'a'){
                    S.pop();
                    cost += x;
                }
                else{
                    S.push(res[i]);
                }
            }
            else{
                S.push(res[i]);
            }
        }
        
        // cout<<cost<<"\n";
        maxCost = max(maxCost, cost);
        return maxCost;
        
    }
};

// c d b c a b

// x = 0   y = 3*5