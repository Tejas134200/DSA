class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = 'z'+1;
        bool f = false;
        for(int i =0;i<letters.size();i++){
            if(letters[i]>target&&letters[i]<ans) f = true ,ans= letters[i];

        }
        return f==true?ans:letters[0];
    }
};