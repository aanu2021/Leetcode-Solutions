class Solution {
    
    public boolean isOdd(char ch){
        int num = (int)(ch-'0');
        if(num%2 != 0) return true;
        else return false;
    }
    
    public String largestOddNumber(String num) {
        int n = num.length();
        for(int i=n-1;i>=0;i--){
            if(isOdd(num.charAt(i)) == true){
                return num.substring(0,i+1);
            }
        }
        return "";
    }
}