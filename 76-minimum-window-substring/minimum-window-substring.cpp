class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char,int> freq;
        for(char c:t) freq[c]++;
        int i =0;
        int j =0;
        int count =n;
        int start = 0;
        int mini  = INT_MAX;
        while(j<m){
            if(freq[s[j]]>0) count--;
            freq[s[j]]--;
            j++;
            while(count==0){
                if(j-i<mini){
                    mini = j-i;
                    start =i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0) count++;
                i++;
            }
        }

        return mini == INT_MAX ? "" : s.substr(start, mini);



    }
};