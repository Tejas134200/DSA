class Solution {
public:

    unordered_map<int,string> units, tens, teens;

    string htu(int h, int t, int u){
        string ans = "";

        if(h > 0){
            ans += units[h] + " Hundred";
        }

        if(t == 1){ 
            if(!ans.empty()) ans += " ";
            ans += teens[u];
            return ans;
        }

        if(t > 1){
            if(!ans.empty()) ans += " ";
            ans += tens[t];
        }

        if(u > 0){
            if(!ans.empty()) ans += " ";
            ans += units[u];
        }

        return ans;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        units = {
            {1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},
            {5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}
        };

        tens = {
            {2,"Twenty"},{3,"Thirty"},{4,"Forty"},
            {5,"Fifty"},{6,"Sixty"},{7,"Seventy"},
            {8,"Eighty"},{9,"Ninety"}
        };

        teens = {
            {0,"Ten"},{1,"Eleven"},{2,"Twelve"},{3,"Thirteen"},
            {4,"Fourteen"},{5,"Fifteen"},{6,"Sixteen"},
            {7,"Seventeen"},{8,"Eighteen"},{9,"Nineteen"}
        };

        vector<int> dig(10, 0);
        int i = 9;
        while(num > 0){
            dig[i--] = num % 10;
            num /= 10;
        }

        string ans = "";

        if(dig[0] > 0){
            ans += units[dig[0]] + " Billion";
        }

        string part = htu(dig[1], dig[2], dig[3]);
        if(!part.empty()){
            if(!ans.empty()) ans += " ";
            ans += part + " Million";
        }

        part = htu(dig[4], dig[5], dig[6]);
        if(!part.empty()){
            if(!ans.empty()) ans += " ";
            ans += part + " Thousand";
        }

        part = htu(dig[7], dig[8], dig[9]);
        if(!part.empty()){
            if(!ans.empty()) ans += " ";
            ans += part;
        }

        return ans;
    }
};