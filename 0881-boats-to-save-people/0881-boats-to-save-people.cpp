class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int boats = 0;
        int left = 0, right = n-1;
        while(left <= right){
            if(left == right){
                boats++; break;
            }
            else{
                if(people[left] + people[right] > limit){
                    boats++;
                    right--;
                }
                else{
                    boats++;
                    left++;
                    right--;
                }
            }
        }
        return boats;
    }
};