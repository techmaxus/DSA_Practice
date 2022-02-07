// 389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            freq[t[i]-'a']--;
            if(freq[t[i]-'a']<0) return t[i];
        }
        for(int i=0;i<26;i++){
            if(freq[i]<0) return 'a'+i;
        }
        return 'a';
    }
};
