package hw5;

public class HighSchoolStudent extends Student
{

	public HighSchoolStudent(String firstName, String lastName)
	{
		super(firstName, lastName);
	}

	public HighSchoolStudent(String firstName, String lastName, String address, String city, String email)
	{
		super(firstName, lastName, address, city, email);
	}

	@Override
	public boolean isGraduateEligible()
	{
		if (PassedReqs() >= 24)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	@Override
	protected int PassedReqs()
	{
		int passed_courses = 0;
		for (int i = 0; i < num_courses; i++)
		{
			if (courses[i].getClass().getName() == "hw5.GradedCourse")
			{
				if(GetPassCriteria((GradedCourse)courses[i]) >= 70)
				{
					passed_courses ++;
				}
			}
			else if (courses[i].getClass().getName() == "hw5.PassFailCourse")
			{
				if (GetPassCriteria((PassFailCourse)courses[i]) == true)
				{
					passed_courses ++;
				}
			}
		}
		return passed_courses;
	}

}
