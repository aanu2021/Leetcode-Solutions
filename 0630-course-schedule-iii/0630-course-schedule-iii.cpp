class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[1] < y[1];
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        
        priority_queue<int>pq;
        int timer = 0, cnt = 0;
        
        sort(c.begin(),c.end(),comp);
        
        for(int i=0;i<c.size();i++){
            if(timer+c[i][0] <= c[i][1]){
                timer += c[i][0];
                pq.push(c[i][0]);
                cnt++;
            }
            else if(!pq.empty() && pq.top() > c[i][0]){
                timer -= pq.top();
                pq.pop();
                timer += c[i][0];
                pq.push(c[i][0]);
            }
        }
        
        return cnt;
        
    }
};


/*


100,200   1000,1250   200,1280   2000,3200

timer = 2300

pq : {2000,200,100}

Approach : Sort the courses in the ascending order of their 
endingTime , why???

It will enable us to take maximum amount of courses in between.

Then start picking the courses , if total time required to take the
course is <= lasttime , then increment number of courses picked 
till now , otherwise we need to skip it . Wait only skipping these
course without considering its effect is not optimal at all.


So in that scenario , we will compare the current course's duration
with the maximum duration among the courses , which we are already 
taken. If current duration < maximum available duration , then it 
is most optimal not to pick that course in the past , rather pick 
the current course will minimize the total time required to take 
the maximum possible courses. 



*/