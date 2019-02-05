 int gcd(int A, int B){
     if(B == 0) return A;
     else  return gcd(B, (A%B));
 }
 
int cpFact(int A, int B) {
    int flag = 0;
    if(B>A){
        A = A + B;
        B = A - B;
        A = A - B;
        flag = 1;
    }
    int a = gcd(A, B);
    while(a > 1){
        if(!flag)A /= a;
        else B /= a;
        a = gcd(A, B);
        //printf("%d\n",a);
    }
    if(flag)return B;
    else return A;
}