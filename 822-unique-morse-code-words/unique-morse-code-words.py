class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse_code = {'a': '.-','b': '-...','c': '-.-.','d': '-..','e': '.','f': '..-.','g': '--.','h': '....','i': '..','j': '.---','k': '-.-','l': '.-..','m': '--','n': '-.','o': '---','p': '.--.','q': '--.-','r': '.-.','s': '...','t': '-','u': '..-','v': '...-','w': '.--','x': '-..-','y': '-.--','z': '--..'}
        out=[]
        for i in words:
            temp=""
            for j in i:
                temp=temp+morse_code[j]
            out.append(temp)
        return len(set(out))