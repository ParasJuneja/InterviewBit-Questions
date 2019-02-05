int maxSubArray(const int* A, int n1) {
    int sum = 0, max = -99999999, k = 0, l = 1, flag = 0;
    while(k<n1){
        sum += A[k];
        flag = 0;
        if(sum < A[k]){
            k = l;
            l++;
            sum = 0;
            flag = 1;
         }
         else k++;
        if(sum > max && flag==0) max = sum;
    }
    return max;
}