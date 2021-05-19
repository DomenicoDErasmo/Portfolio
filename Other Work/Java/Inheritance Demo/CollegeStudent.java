package hw5;

public class CollegeStudent extends Student
{

	public CollegeStudent(String firstName, String lastName)
	{
		super(firstName, lastName);
	}

	public CollegeStudent(String firstName, String lastName, String address, String city, String email)
	{
		super(firstName, lastName, address, city, email);
	}

	@Override
	public boolean isGraduateEligible()
	{
		if (PassedReqs() >= 132)
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
		int passed_credits = 0;
		for (int i = 0; i < num_courses; i++)
		{
			if (courses[i].getClass().getName() == "hw5.GradedCourse")
			{
				if(GetPassCriteria((GradedCourse)courses[i]) >= 70)
				{
					passed_credits += courses[i].getNumberOfCredits();
				}
			}
			else if (courses[i].getClass().getName() == "hw5.PassFailCourse")
			{
				if (GetPassCriteria((PassFailCourse)courses[i]) == true)
				{
					passed_credits += courses[i].getNumberOfCredits();
				}
			}
		}
		return passed_credits;
	}

}
