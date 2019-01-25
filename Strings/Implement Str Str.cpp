int strStr(const char* A, const char* B) {
    char *result = malloc(strlen(A) + strlen(B) + 1);
    strcpy(result, B);
    strcat(result, "$");
    strcat(result, A);
    int i,l=0,r=0;
    int len = strlen(result);
    int arr[len];
    arr[0]=0;
    for(i=1; i < len; i++) {
        if(i > r) {
            l = i;
            r = i;
            while(result[r] == result[r-l] && r < len) {
                r++;
            }
            arr[i] = r-l;
            r--;
        }
        else{
            if(arr[i-l] < r-i+1) {
                arr[i] = arr[l];
            }
            else{
                l = i;
                r = i;
                while(result[r] == result[r-l] && r < len) r++;
                arr[i] = r-l;
                r--;
            }
        }
    }
    for(i=0; i < len; i++)
         if(arr[i] == strlen(B)) return i-strlen(B)-1;
         +
    return -1;
}
