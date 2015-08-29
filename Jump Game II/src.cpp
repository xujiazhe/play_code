

class Solution {
public:
    int jump(int A[], int n) {
        if( n<= 1 ){
            return 0;
        }
        // 0 1
        int maxIndex = 0;// this step max distance
        int step = 0;// current step over
        int nextMaxIndex = 0;// next step max distance
        for(size_t i = 0;i<n;i++){
            size_t m = A[i]+i;
            if( m > nextMaxIndex){
                nextMaxIndex = m;
            }
            if(nextMaxIndex >= n-1){
                break;
            }
            // nextMaxIndex = max(nextMaxIndex, A[i]+i);
            if(i == maxIndex){
                if( maxIndex == nextMaxIndex){
                    // A[i] == 0
                    // there‘re some can exceed position   1 1 0 1
                }
                step++;
                maxIndex = nextMaxIndex;
            }

        }
        return step+1;
    }
};
