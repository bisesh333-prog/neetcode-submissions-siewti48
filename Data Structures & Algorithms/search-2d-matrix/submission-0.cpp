class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lr = 0, rr = m-1;
        while(lr<=rr){
            int midr = lr + (rr-lr)/2;
            if(target == matrix[midr][0]){
                return true;
            }
            else if(target>matrix[midr][0]){
                if(target<=matrix[midr][n-1]){
                    int lc=0, rc=n-1;
                    while(lc<=rc){
                        int midc = lc+ (rc-lc)/2;
                        if(target==matrix[midr][midc]){
                            return true;
                        }
                        else if(target>matrix[midr][midc]){
                            lc = midc+1;
                        }
                        else if(target<matrix[midr][midc]){
                            rc = midc-1;
                        }
                    }
                    return false;
                }
                else{
                    lr = midr+1;
                }
            }
            else if(target<matrix[midr][0]){
                rr=midr-1;
            }
        }
        return false;
    }
};
