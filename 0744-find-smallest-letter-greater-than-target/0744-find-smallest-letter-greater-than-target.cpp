class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        if(letters.back() <= target){
            return letters[0];
        }
        
        int n = letters.size();
        int low = 0, high = n-1;
        
        char answer;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(letters[mid] > target){
                answer = letters[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return answer;
        
    }
};