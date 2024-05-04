class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int answer = 0, L = 0, R = n-1;
        while(L <= R){
            if(L == R){
                answer++;
                break;
            }
            if(people[L] + people[R] <= limit){
                answer++;
                L++;
                R--;
            }
            else{
                answer++;
                R--;
            }
        }
        return answer;
    }
};