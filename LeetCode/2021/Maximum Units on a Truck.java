class Solution 
{
    public int maximumUnits(int[][] boxTypes, int truckSize) 
    {
        // greedy algorithm
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
        int totalUnits = 0;
        int currentBox = 0;
        while (truckSize > 0 && currentBox < boxTypes.length)
        {
            int boxesToAdd = Math.min(boxTypes[currentBox][0], truckSize);
            totalUnits += boxesToAdd * boxTypes[currentBox][1];
            truckSize -= boxesToAdd;
            currentBox++;
        }
        return totalUnits;
    }
}
