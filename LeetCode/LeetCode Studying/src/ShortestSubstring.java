import java.util.*;

public class ShortestSubstring extends Problem
{
	public ShortestSubstring()
	{
		this.args = new ArrayList<Object>();
	}

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
		System.out.println("inputString: " + args.get(0));
		System.out.println("charSubset: " + args.get(1) + "\n");
		String inputString = (String) args.get(0);
		int left = 0;
		int right = 0;
		int min = inputString.length();
		
		// TODO: implement algorithm

		System.out.println("Minimum Substring: " + inputString.substring(left, right));
		System.out.println("Minimum Substring Length: " + min);
	}

}