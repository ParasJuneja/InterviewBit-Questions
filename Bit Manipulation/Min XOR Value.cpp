 int* cmp(int* A, int*B){
     return *A - *B;
 }
 
int findMinXor(int* A, int n1) {
    qsort(A, n1, sizeof(int), cmp);
    int i, min = INT_MAX, exor;
    for(i=0; i<n1-1;i++){
        exor = A[i]^A[i+1];
        if(exor < min) min = exor;
    }
    return exor;
}