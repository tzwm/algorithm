//There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
    bool isASmaller(int A[], int i, int B[], int j) {
        return A[i] < B[j];
    }
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int k = 0;
        if((m + n) % 2 == 0)
            k = (m+n) / 2;
        else
            k = (m+n+1) / 2;
            
        double ret = 0;
        while(true){
            if(i+j == k-1) {
                if(i<m && j<n) {
                    if(isASmaller(A, i, B, j)){
                        ret = A[i++];
                    } else {
                        ret = B[j++];
                    }
                } else {
                    if(i==m){
                        ret = B[j++];
                    } else {
                        ret = A[i++];
                    }
                }
                
                if((m+n) % 2 ==0) {
                    if(i<m && j<n) {
                        if(isASmaller(A, i, B, j)){
                            ret = (ret + A[i++]) / 2;
                        } else {
                            ret = (ret + B[j++]) / 2;
                        }
                    } else {
                        if(i==m){
                            ret = (ret + B[j++]) / 2;
                        } else {
                            ret = (ret + A[i++]) / 2;
                        }
                    }
                }
                
                break;
            }
            
            if(i==m){
                j++;
                continue;
            }
            if(j==n){
                i++;
                continue;
            }
            if(isASmaller(A, i, B, j))
                i++;
            else
                j++;
        }
        
        return ret;
    }
};

