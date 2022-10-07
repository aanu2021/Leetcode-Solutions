/*

Goal : Maximum value of overlapped intervals at some points each
time after adding a new interval.How many intervals cover a 
single point ???

Approach : Sweep Line Algorithm [Differential Array]

Algorithm : We should take care of maximum number of intervals 
which are intersected at a particular point.

Now , the problem boils down to find out the maximum number of 
intervals which are met with each other at a particular point.

For , these we will use a map to store the contribution of each
and every interval , i.e Give it a (+1) for the starting point
and (-1) for the ending point. Now , we will calculate the prefix
sum of the points from the very first to the end , figure out 
their overall impact.

T.c : O(N^2)
S.C : O(N)

*/

class MyCalendarThree {
public:
    
    map<int,int>diff;
   
    MyCalendarThree() {

        diff.clear();
        
    }
    
    int book(int start, int end) {
        
        int curr = 0;
        int maxi = 0;
        
        diff[start]++;
        diff[end]--;
        
        for(auto itr:diff){
            
            curr += itr.second;
            maxi = max(maxi,curr);
            
        }
        
        return maxi;
        
    }
};

