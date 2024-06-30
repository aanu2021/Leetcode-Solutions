class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int low = 1, high = 2*max(red, blue);
        int answer = -1;
        while(low <= high){
            int mid = (low + high)/2;
            int odd = (mid+1)/2;
            int even = mid/2;
            int firstReq = (odd*odd);
            int secondReq = (even*(even+1));
            if((red >= firstReq && blue >= secondReq) || (red >= secondReq && blue >= firstReq)){
                answer = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return answer;
    }
};

// 1 + 3 + 5 + .... M

// M/2 * (1 + 2*M - 1)
    
// M*M    

// 2 + 4 + 6 + .... N

// N/2 * (2 + 2*N)
    
//     N * (N+1)