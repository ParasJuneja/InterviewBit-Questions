int singleNumber(const int* A, int n1) {
    int a[32] = {0};
    int i = 0;
    int j = 0;
    //memset(a, 0, sizeof(int));
    int result = 0;
    for(j=0; j<32; j++){
    for(i=0; i<n1; i++){
        if((A[i]>>j)&1) a[j]++;
    }
    printf("\n");
    }
    for(i=0; i<32; i++){
        result |= (a[i]%3)<<i;
    }
    return result;
}