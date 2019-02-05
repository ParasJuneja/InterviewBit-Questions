 #define MAX( a, b ) ( ( a > b) ? a : b ) 
int coverPoints(int* A, int n1, int* B, int n2){ 
    int sx =0, sy= 0, sum = 0;
    int i;
    for(i=0;i<n1-1;i++){
        sum += MAX((abs(A[i]-A[i+1])),(abs(B[i]-B[i+1])));
    }
    return sum;
}