int Sqrt(int A) {
    int i;
    
    int left=0, right=A, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(mid*mid == A)return mid;
        else if((long long)mid*mid <A) left = mid + 1;
        else right = mid - 1;
    }
    return right;
    
}