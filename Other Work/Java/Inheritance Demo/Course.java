package hw5;

abstract public class Course
{
	public class PassFailCourse
	{

		public PassFailCourse()
		{
			// TODO Auto-generated constructor stub
		}

	}
	// constructors
	public Course(int course_id, String description, String instructor)
	{
		this.course_id = course_id;
		this.description = description;
		this.instructor = instructor;
	}
	
	public Course(int course_id, String description, String instructor, int number_of_credits)
	{
		this(course_id, description, instructor);
		this.number_of_credits = number_of_credits;
	}
	
	// other functions
	abstract public String ToString();
	
	// getters and setters
	public int getCourseId()
	{
		return course_id;
	}
	public void setCourseId(int course_id)
	{
		this.course_id = course_id;
	}
	public String getDescription()
	{
		return description;
	}
	public void setDescription(String description)
	{
		this.description = description;
	}
	public String getInstructor()
	{
		return instructor;
	}
	public void setInstructor(String instructor)
	{
		this.instructor = instructor;
	}
	public int getNumberOfCredits()
	{
		return number_of_credits;
	}
	public void setNumberOfCredits(int number_of_credits)
	{
		this.number_of_credits = number_of_credits;
	}
	
	// private fields
	protected int course_id;
	protected String description;
	protected String instructor;
	protected int number_of_credits;
	
}
