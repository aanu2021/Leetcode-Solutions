class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length();
        int n = b.length();
        int i=m-1 , j=n-1;
        int bit = 0, carry = 0;
        string res = "";
        while(i>=0 || j>=0){
            bit = carry;
            if(i>=0){
                bit += (a[i]-'0');
                i--;
            }
            if(j>=0){
                bit += (b[j]-'0');
                j--;
            }
            carry = bit/2;
            bit = bit%2;
            res += (char)(bit+'0');
        }
        if(carry){
            res += (char)(carry+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};