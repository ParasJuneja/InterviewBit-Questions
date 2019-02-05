int* repeatedNumber(const int* A, int n1, int *len1) {
    
    long long i;
    long long x = 0, y = 0;
    for(i=0; i<n1; i++) {
        x += (i+1) - A[i];
        y += (long long)(i+1)*(i+1) -(long long)A[i]*A[i];
    }
    +
    int* B = (int*)malloc(sizeof(int)*2);
    *len1 = 2;
    B[0] = ((int)(y/x)-x)/2;
    B[1] = ((int)(y/x)+x)/2;
    return B;
}