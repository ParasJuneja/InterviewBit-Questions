string Solution::countAndSay(int A) {
    int i, z, count;
    int len;
    string s1 = "1";
    string s2 = "";
    for(z=0; z<A-1; z++) {
        len = s1.length();
        for(i=0; i<len; i++) {
            count = 1;
            while(i < len-1 && s1[i] == s1[i+1]) {
                i++;
                count++;
            }
            s2 += to_string(count) + s1[i];
        }
        s1 = s2;
        s2 = "";
    }
    return s1;
}
