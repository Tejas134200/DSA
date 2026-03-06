class Solution {
public:
    int ans = 0;
    
    int func(int i , const string& w){ 
        int j = i;
        int n = w.size();
        
        if(w[j] != 'a') return j + 1; 
        
        while(j < n && w[j] == 'a') j++;
        if(j == n) return n;
        
        if(w[j] != 'e') return j; 
        while(j < n && w[j] == 'e') j++;
        if(j == n) return n;
        
        if(w[j] != 'i') return j; 
        while(j < n && w[j] == 'i') j++;
        if(j == n) return n;
        
        if(w[j] != 'o') return j; 
        while(j < n && w[j] == 'o') j++;
        if(j == n) return n;
        
        if(w[j] != 'u') return j; 
        while(j < n && w[j] == 'u') j++;
        
        ans = max(ans , j - i);
        return j;
    }
    
    int longestBeautifulSubstring(string word) {
        int i = 0;
        ans = 0;
        while(i < word.size()){
            i = func(i , word);
        }
        return ans;
    }
};