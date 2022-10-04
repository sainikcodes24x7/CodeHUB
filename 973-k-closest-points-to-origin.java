class Solution {
    public int[][] kClosest(int[][] points, int k) {
        double d[] = new double[points.length];
        int x[][] = new int[k][points[0].length];
        int min = 0;
        
        //calc dist from origin of all points
        for(int i = 0; i < points.length; i++)
        {
            d[i] = dist(points[i]);
        }
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < points.length; j++)
            {
                if(d[j] < d[min])
                    min = j;
            }
            //System.out.println(points[min][0] + " " + points[min][1] + " " + min);
            x[i][0] = points[min][0];
            x[i][1] = points[min][1];
            points[min][0] = 10000;
            points[min][1] = 10000;
            d[min] = 10000*10000;
        }
        return x;
    }
    
    double dist(int[] p1)
    {
        return Math.sqrt(p1[0]*p1[0] + p1[1]*p1[1]);
    }
}
