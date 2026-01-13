class Solution(object):
    def generateTag(self, caption):
        words = caption.split()
        if not words:
            return "#"
        
        s = "#" + words[0].lower()
        
        for i in range(1, len(words)):
            s += words[i].capitalize()
        if len(s)<=100:
            return s
        a =""
        for i in range(0,100):
            a+=s[i]
        return a
