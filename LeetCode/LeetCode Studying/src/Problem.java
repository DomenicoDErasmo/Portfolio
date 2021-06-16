import java.util.*;

abstract public class Problem
{
	public Problem()
	{
		this.args = new ArrayList<Object>();
		this.rand = new Random();
	}
	public abstract void GenerateArguments();
	public abstract void SolveProblem ();
	protected ArrayList <Object> args;
	Random rand;
}
