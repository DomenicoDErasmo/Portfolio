import java.util.*;

@SuppressWarnings("unchecked")
public class ShortestSubstring extends Problem
{

	public ShortestSubstring()
	{
		this.args = new ArrayList<Object>();
	}

	private String GenerateString()
	{
		Random rand = new Random();
		int bounds = rand.nextInt(15) + 5;
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
		TreeSet<Character> charSubset = (TreeSet<Character>) args.get(1);

		TreeSet<Character> encounteredCharacters = new TreeSet<Character>();
		int left = 0, right = 0;
		
		while(!encounteredCharacters.equals(charSubset))
		{
			char c = inputString.charAt(right);
			if (charSubset.contains(c))
			{
				encounteredCharacters.add(inputString.charAt(c));
			}
			System.out.println("encounteredCharacters:  " + encounteredCharacters.toString());
			System.out.println("charSubset: \t\t" + charSubset.toString());
			right++;
		}
		System.out.println(inputString.substring(0, right));
		
	}

}
