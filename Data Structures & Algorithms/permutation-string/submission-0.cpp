class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1>len2) return false;

        for(int i=0; i<=len2-len1; i++){
            string sub = s2.substr(i, len1);
            sort(sub.begin(), sub.end());
            // string s1_sorted=s1;
            sort(s1.begin(), s1.end());
            if(sub==s1) return true;
        }
        return false;
    }
};
