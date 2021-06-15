import java.util.*;

abstract public class Problem
{
	public Problem()
	{
		
	}
	public abstract void GenerateArguments();
	public abstract void SolveProblem ();
	protected ArrayList <Object> args;
}
