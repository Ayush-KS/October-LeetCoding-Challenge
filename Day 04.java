// Remove Covered Intervals

class Solution {
    public int removeCoveredIntervals(int[][] iv) {
        Arrays.sort(iv, new Comparator<int[]>() { 
          @Override              
          public int compare(final int[] entry1,  
                             final int[] entry2) { 
  
            if (entry1[0] == entry2[0]) 
                return Integer.compare(entry2[1], entry1[1]); 
            else
                return Integer.compare(entry1[0], entry2[0]); 
          } 
        });
        int n = iv.length;
        int rem = 0;
        int imax = 0;
        
        for(int[] v : iv) {
            if(v[1] <= imax) {
                rem++;
            } else {
                imax = v[1];
            }
        }
        
        return n - rem;
    }
}