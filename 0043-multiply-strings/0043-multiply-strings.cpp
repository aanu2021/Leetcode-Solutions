class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.length();
        int n = num2.length();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int>values(m+n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currVal = (num1[j]-'0')*(num2[i]-'0');
                int currSum = currVal + values[i+j];
                values[i+j] = (currSum % 10);
                values[i+j+1] += (currSum / 10);
            }
        }
        while(values.size() && values.back() == 0){
            values.pop_back();
        }
        reverse(values.begin(),values.end());
        string ans = "";
        for(int i=0;i<values.size();i++){
            ans += (char)(values[i] + '0');
        }
        return ans;
    }
};

/*
1 2 3
4 5 6
0 1 2    
     
    
5 6 0 8 8 
0 1 2 3 4   
 */
    