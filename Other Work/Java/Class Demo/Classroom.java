package homework4;

public class Classroom
{
	private homework4.student[] students;
	private int classSize;
	
	// getters
	public homework4.student[] GetStudents()
	{
		return students;
	}
	
	public int GetClassSize()
	{
		return classSize;
	}
	
	// setters
	public void SetStudents(homework4.student[] students)
	{
		this.students = students;
	}
	
	public void SetClassSize(int classSize)
	{
		this.classSize = classSize;
	}
	
	// constructors
	Classroom(int size)
	{
		this.classSize = size;
		this.students = new homework4.student[size];
	}
	
	// other methods
	public void PrintStudents()
	{
		for (int i = 0; i < classSize; i++)
		{
			System.out.println(students[i].ToString());
		}
	}
}
