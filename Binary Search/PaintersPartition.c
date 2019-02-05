int paint(int C, int B, int* A, int n1) {
    if(n1 == 1) {
        return A[0] * B;
    }
    
    long int left = -1, right, mid, psum, count, i, max;
    for(i = 0; i < n1; i++) {
        right += A[i];
        left = (A[i] > left) ? A[i] : left;
    }
    
    while(left < right){
        psum = 0;
        max = 0;
        count = 0;
        
        mid = left + (right - left) / 2;
        
        for (i = 0; i < n1; i++){
            if ((psum + A[i]) <= mid){
                psum += A[i];
            } else{
                count++;
                psum = A[i];
            }
        }
        count++;
        if(count > C) left = mid + 1;
        else right = mid;
    }
    return (right * B) % 10000003;
}