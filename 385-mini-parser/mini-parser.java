class Solution {
    public NestedInteger deserialize(String s) {
        // If no brackets, it's just a number
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }

        Stack<NestedInteger> st = new Stack<>();
        NestedInteger curr = null;
        int num = 0;
        boolean neg = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '[') {
                if (curr != null) st.push(curr);
                curr = new NestedInteger();
            } 
            else if (c == '-') {
                neg = true;
            } 
            else if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == ',' || c == ']') {
                if (Character.isDigit(s.charAt(i - 1))) {
                    if (neg) num = -num;
                    curr.add(new NestedInteger(num));
                }
                num = 0;
                neg = false;

                if (c == ']' && !st.isEmpty()) {
                    NestedInteger parent = st.pop();
                    parent.add(curr);
                    curr = parent;
                }
            }
        }
        return curr;
    }
}
