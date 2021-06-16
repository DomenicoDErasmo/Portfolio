import java.io.*;

public class ProblemDriver
{
	private static Problem ProblemFactory(String problem)
	{
		switch(problem)
		{
		case "shortest substring":	
			return new ShortestSubstring();
		case "biggest subarray":
			return new BiggestSubarray();
		case "balanced parentheses":
			return new BalancedParentheses();
		case "substring below target":
			return new SubstringBelowTarget();
		case "merged times":
			return new MergedTimes();
		default: 
			return null;
		}
	}
	
	public static void main (String[] args) throws IOException
	{
		System.out.print("Enter a problem: ");
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String problem = reader.readLine();
		Problem p = ProblemFactory(problem);
		p.GenerateArguments();
		p.SolveProblem();
	}
}
