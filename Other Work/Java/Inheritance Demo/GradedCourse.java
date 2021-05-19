package hw5;

public class GradedCourse extends Course
{

	public GradedCourse(int course_id, String description, String instructor)
	{
		super(course_id, description, instructor);
	}

	public GradedCourse(int course_id, String description, String instructor, int number_of_credits)
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
		buffer.append(", Grade = ");
		buffer.append(this.grade);
		return buffer.toString();
	}
	
	// getters and setters
	public int getGrade()
	{
		return grade;
	}
	public void setGrade(int grade)
	{
		this.grade = grade;
	}
	
	// private fields
	int grade;
}
