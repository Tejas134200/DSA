class Solution {
public:
    long long sum(long long s, long long e) {
        long long n = e - s + 1;
        return n * (2 * s + (n - 1)) / 2;
    }

    bool isP(int n, long long m, int maxSum, int i) {
        long long sumi = 0;

        long long re = n - i;

        if (re == m) {
            sumi += sum(1, m);
        } 
        else if (re > m) {
            sumi += sum(1, m);
            re -= m;
            sumi += re;
        } 
        else {
            long long st = m - re + 1;
            sumi += sum(st, m);
        }

        re = i + 1;

        if (re == m) {
            sumi += sum(1, m);
        } 
        else if (re > m) {
            sumi += sum(1, m);
            re -= m;
            sumi += re;
        } 
        else {
            long long st = m - re + 1;
            sumi += sum(st, m);
        }

        sumi -= m;

        return sumi <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        long long l = 1;
        long long r = maxSum;

        while (l < r) {
            long long m = l + (r - l + 1) / 2;

            if (isP(n, m, maxSum, index))
                l = m;
            else
                r = m - 1;
        }

        return (int)l;
    }
};