import java.util.*;

public class ShortestSubstring extends Problem
{
	private String GenerateString()
	{
		Random rand = new Random();
		int bounds = rand.nextInt(15) + 10;
		StringBuffer buffer = new StringBuffer();
		for (int i = 0; i < bounds; i++)
		{
			char c = (char) (rand.nextInt(25) + 97);
			buffer.append(c);
		}
		return buffer.toString();
	}
	
	private ArrayList<Character> GetAllCharacters(String str)
	{
		ArrayList<Character> allCharacters = new ArrayList<Character>();
		
		for (int i = 0; i < str.length(); i++)
		{
			Character c = str.charAt(i);
			if (!allCharacters.contains(c))
			{
				allCharacters.add(c);
			}
		}
		return allCharacters;
	}
	
	private TreeSet<Character> GenerateCharacterSubset(String str)
	{
		Random rand = new Random();
		ArrayList<Character> allCharacters = GetAllCharacters(str);
		TreeSet<Character> subsetCharacters = new TreeSet<Character>();
		int numCharacters = rand.nextInt(allCharacters.size() - 3) + 3;
		for (int i = 0; i < numCharacters; i++)
		{
			char next = allCharacters.get(rand.nextInt(allCharacters.size()));
			if (!subsetCharacters.contains(next))
			{
				subsetCharacters.add(next);
			}
		}
		return subsetCharacters;
	}
	
	@Override
	public void GenerateArguments()
	{
		String inputString = GenerateString();
		TreeSet<Character> charSubset = GenerateCharacterSubset(inputString);
		args.add(inputString);
		args.add(charSubset);
	}

	@Override
	public void SolveProblem()
	{
		String inputString = (String) args.get(0);
		TreeSet<Character> charSubset = (TreeSet<Character>)args.get(1);
		int left = 0, right = 0, min = inputString.length(), charactersEncountered = 0;
		HashMap<Character, Integer> substringLetters = new HashMap<>();
		
		// TODO: implement algorithm
		while (right < inputString.length())
		{
			char currentRight = inputString.charAt(right);
			if (charSubset.contains(currentRight))
			{
				substringLetters.put(currentRight, substringLetters.getOrDefault(currentRight, 0) + 1);
				if (substringLetters.get(currentRight) == 1)
				{
					charactersEncountered++;
				}
			}
			right++;

			if (charactersEncountered == charSubset.size())
			{
				while (charactersEncountered == charSubset.size())
				{
					Character currentLeft = (Character)inputString.charAt(left);
					if (charSubset.contains(currentLeft))
					{
						substringLetters.computeIfPresent(currentLeft, (k, v) -> v - 1);
						if (substringLetters.get(currentLeft) == 0)
						{
							charactersEncountered--;
						}
					}
					left++;
				}
				if (right - left + 1  < min)
				{
					min = right - left + 1;
				}
			}
		}
		System.out.println("Initial String: " + inputString);
		System.out.println("Subset of Characters: " + charSubset);
		System.out.println("Minimum Substring Length: " + min);
	}
}
