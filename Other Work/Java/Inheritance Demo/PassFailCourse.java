package hw5;

public class PassFailCourse extends Course
{

	public PassFailCourse(int course_id, String description, String instructor)
	{
		super(course_id, description, instructor);
	}
	
	public PassFailCourse(int course_id, String description, String instructor, int number_of_credits)
	{
		super(course_id, description, instructor, number_of_credits);
	}

	public String ToString()
	{
		StringBuffer buffer = new StringBuffer();
		buffer.append("Course ID = ");
		buffer.append(this.course_id);
		buffer.append(", Description = ");
		buffer.append(this.description);
		buffer.append(", Instructor = ");
		buffer.append(this.instructor);
		buffer.append(", Number of Credits = ");
		buffer.append(this.number_of_credits);
		buffer.append(", Pass = ");
		buffer.append(this.pass);
		return buffer.toString();
	}
	
	// getters and setters
	public boolean GetPass()
	{
		return pass;
	}
	
	public void SetPass(boolean pass)
	{
		this.pass = pass;
	}
	
	// private fields
	private boolean pass;
}
