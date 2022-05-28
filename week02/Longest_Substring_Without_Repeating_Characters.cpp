#Time Complexity :O(N)
#Space Complexity:O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int l=0,r=0,counts=0, len=0;

        while(r<s.size()){
            freq[s[r]]++;
            if(freq[s[r]]>1)
                counts++;
            r++;
            while(counts>0){
                freq[s[l]]--;
                if(freq[s[l]]==1)counts--;
                l++;
            }
            len=max(len,r-l);

        }
        return len;
    }
};
