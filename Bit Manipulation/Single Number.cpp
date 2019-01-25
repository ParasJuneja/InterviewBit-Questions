int singleNumber(const int* A, int n1) {
    int i = 0, k = A[0];
    for(i=1; i<n1; i++){
        k = k^A[i];
    }
    return k;
}