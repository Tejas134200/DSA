class Solution {
    public double[] internalAngles(int[] sides) {
        if((sides[0]+sides[1]<=sides[2])||
           (sides[1]+sides[2]<=sides[0])||
           (sides[2]+sides[0]<=sides[1])) return new double[]{};
        double a=(double)sides[0];
        double b=(double)sides[1];
        double c=(double)sides[2];
        double A=Math.toDegrees(Math.acos((b*b+c*c-a*a)/(2*b*c)));
        double B=Math.toDegrees(Math.acos((a*a+c*c-b*b)/(2*a*c)));
        double C=Math.toDegrees(Math.acos((b*b+a*a-c*c)/(2*b*a)));
        double[] ans={A,B,C};
        Arrays.sort(ans);
        return ans;
    }
}