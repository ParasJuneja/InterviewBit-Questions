int maxArr(int* A, int n1) {
    int min = INT_MAX, max = INT_MIN, min2 = INT_MAX, max2 = INT_MIN;
    int i;
    for(i=0; i<n1; i++){
        if(A[i]+i > max) max = A[i]+i;
        if(A[i]+i < min) min = A[i]+i;
        if(A[i]-i < min2) min2 = A[i]-i;
        if(A[i]-i > max2) max2 = A[i]-i;
    }
    if(abs(max-min) > abs(max2-min2)) return max-min;
    else return max2-min2;
}