import java.util.*;

@SuppressWarnings("unchecked")
public class SubstringBelowTarget extends Problem 
{
    private void PrintMap(Map<Character, Integer> map)
    {
        for (char key : map.keySet())
        {
            System.out.print(key + ": " + map.get(key) + ", ");
        }
        System.out.print("\n");
    }

    public void GenerateArguments()
    {
        // generate string
        int length = rand.nextInt(6) + 10;
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < length; i++)
        {
            char ch = (char) (rand.nextInt(25) + 97);
            buffer.append(ch);
        }
        String inputString = buffer.toString();
        args.add(inputString);

        // generate target
        int target = rand.nextInt(42) + 100;
        args.add(target);

        // generate mapping
        TreeMap<Character, Integer> map = new TreeMap<Character, Integer>();
        for (int i = 0; i < inputString.length(); i++)
        {
            if(!map.containsKey(inputString.charAt(i)))
            {
                map.put(inputString.charAt(i), rand.nextInt(10) + 6);
            }
        }
        args.add(map);
    }

    public void SolveProblem()
    {
        // unpack args
        String inputString = (String)args.get(0);
        int target = (int)args.get(1);
        TreeMap<Character, Integer> map = (TreeMap<Character, Integer>)args.get(2);
        int left = 0, right = 0, currentTotal = 0, maxSize = 0;

        while(right < inputString.length())
        {
            // if adding the next character means is still less than target, increment right
            // else, increment right and left until current_total < target
            //      for each such increment, we must add map[right+1] - map[left] then increment right and left
            if (right < inputString.length() && currentTotal + map.get(inputString.charAt(right)) < target)
            {
                currentTotal += map.get(inputString.charAt(right));
                right++;
            }
            else
            {
                // done incrementing right, check if this current substring is the biggest
                if (right - left > maxSize)
                {
                    maxSize = right - left;
                }
                // now, we shift left and right until the sliding window is less than target
                while(right < inputString.length() && currentTotal + map.get(inputString.charAt(right)) >= target)
                {
                    currentTotal += (map.get(inputString.charAt(right)) - map.get(inputString.charAt(left)));
                    right++;
                    left++;

                    if (currentTotal == target && right - left > maxSize)
                    {
                        maxSize = right - left;
                    }
                }
            }
        }
        System.out.println("inputString: " + inputString);
        System.out.println("target: " + target);
        PrintMap(map);
        System.out.println("maxSize: " + maxSize);
        System.out.println("currentSubstring: " + inputString.substring(left, right));
    }
}
