int books(int* a, int n1, int B) {
        if(B>n1)return -1;
        int left = 0, right = 0, mid;
        int i;
        for(i=0; i<n1; i++){
                right += a[i];
        }
        int sum = 0, count = 0, max = 0;
        while(left<right){
                mid = (left+right)/2;
                sum = 0;
                max = 0;
                count = 1;
                for(i=0;i<n1;i,i++){
                        if(sum+a[i] <= mid) sum += a[i];
                        else{
                                sum = a[i];
                                count++;
                        }
                        if(sum > max) max = sum;
                }
                if(count < B) right = mid;
                else if(count > B) left = mid+1;
                else break;
        }
        return max;
}