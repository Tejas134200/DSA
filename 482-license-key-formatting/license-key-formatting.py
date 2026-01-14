class Solution( object ) :
    def licenseKeyFormatting( self, s, k ) :
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        s = s.replace('-', '').upper()
        output = []
        first = len(s) % k
        if first > 0 :
            output = [s[:first]]
        for index in range(first, len(s), k) :
            output.append(s[index:index + k])
        return "-".join(output)