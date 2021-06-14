package studying;
import java.io.*;

public class ProblemDriver
{

	public ProblemDriver()
	{
		// TODO Auto-generated constructor stub
	}
	
	private static Problem ProblemFactory(String problem)
	{
		switch(problem)
		{
		case "shortest substring":	
			return new studying.ShortestSubstring();
		default: 
			return null;
		}
	}
	
	public static void main (String[] args) throws IOException
	{
		System.out.print("Enter a problem: ");
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String problem = reader.readLine();
		studying.Problem p = ProblemFactory(problem);
		p.GenerateArguments();
		p.SolveProblem();
	}
}
