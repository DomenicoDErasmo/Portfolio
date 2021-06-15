import java.util.*;

abstract public class Problem
{
	public Problem()
	{
		this.args = new ArrayList<Object>();
	}
	public abstract void GenerateArguments();
	public abstract void SolveProblem ();
	protected ArrayList <Object> args;
}
