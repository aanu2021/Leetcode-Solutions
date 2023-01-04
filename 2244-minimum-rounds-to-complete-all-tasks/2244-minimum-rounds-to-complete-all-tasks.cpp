class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(int ele:tasks){
            freq[ele]++;
        }
        int total = 0;
        for(auto &itr:freq){
            int occurence = itr.second;
            // only invalid case , that we can't handle //
            if(occurence==1) return -1;
            total += (occurence/3);
            if(occurence%3) total++;
        }
        return total;
    }
};


/*

Goal : Minimum rounds to complete all the tasks

Restriction : You can complete 2/3 tasks at a time

first store the occurence of same difficulty level-ed tasks inside 
an unordered_map / freq array.

over here constraints are not feasible enough to use an array of 
that much size , so we need to go for unordered_map.

now after doing all this stuffs , we will iterate over the 
frequencies of each task.

And what we get there are multiple cases to think of ->

Case 1 : occurence == 1  --> invalid case (as we can complete 
neither 2 nor 3 tasks at a time).

Case 2 : occurence == 2 --> 1 operations (complete 2 tasks at a 
time)

Case 3 : occurence == 3 --> 1 operations (complete 3 tasks at a 
time)

Case 4 : occurence == 4 --> 2 operations (complete 2 tasks twice , 
remember we can't just complete 3 tasks , as it leaves only 1 tasks
for us which will be an invalid case)

Case 5 : occurence == 5 --> 2 operations (2 + 3)

Case 6 : occurence == 6 --> 2 operations (3 + 3)

Case 7 : occurence == 7 --> 3 operations (3 + 2 + 2) again (3+3+1)
is an invalid case.



So whats up ??? do you able to figure out the observation as well 
as the intuition ? 

1. for occ % 3 == 0 ---->  number of operations = (occ/3)

2. for occ % 3 == 1 ---->  number of operations = (occ/3) + 1

e.g : 4   = 2 + 2
      7   = 3 + 2 + 2
      10  = 3 + 3 + 2 + 2
      13  = 3 + 3 + 3 + 2 + 2
      16  = 3 + 3 + 3 + 3 + 2 + 2
      
      so basic observation is we have to complete 2 tasks twice , 
      and we are left with remaining occurence which are divisible 
      by 3.
      
3. for occ % 3 == 2 ----> number of operations = (occ/3) + 1

e.g : 5   = 3 + 2
      8   = 3 + 3 + 2
      11  = 3 + 3 + 3 + 2
      14  = 3 + 3 + 3 + 3 + 2
      
      so here the basic observation is we have to complete 2 tasks 
      once  and we are left with remaining occurences which are 
      divisible by 3.

      
      Time Complexity : O(N)
      Space Complecity : O(N)

*/