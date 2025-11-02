class Solution {
public:
    bool isAnagram(string s, string t) {
        // brute-force
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // if(s==t)
        // {
        //     return true;
        // }
        // return false;


        //optimal

        int freq[256];

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }

        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]--;
        }

        for(int i=0;i<256;i++)
        {
            if(freq[i]!=0)
            {
                return false;
            }
           
        }
         return true;
    }
};