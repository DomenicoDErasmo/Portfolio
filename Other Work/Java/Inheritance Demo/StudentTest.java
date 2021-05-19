package hw5;

import java.util.Random;

public class StudentTest
{
	// TODO: Add StudentTest functionality to main
	// TODO: Add option of including strings as course grade
	public static void main(String[] args)
	{
		hw5.Student[] students = new hw5.Student[8];
		
		String[] first_names = {"Domenico", "Kevin", "Nora", "Miguel", "Leana", "Emma", "Vincent", "Jeannette"};
	    String[] last_names = {"D'Erasmo", "Gabayan", "Lotfy", "Gaspar", "Pili", "Nikols", "Lam", "He"};
	    Random rand = new Random();
	    int num_courses;
	    
	    for (int i = 0; i < 4; i++)
	    {
	    	num_courses = rand.nextInt(21) + 10;
	    	students[i] = new hw5.HighSchoolStudent(first_names[i], last_names[i]);
	    	FillClasses(students[i], num_courses, rand);
	    	
		}
	    for (int i = 4; i < 8; i++)
	    {
	    	num_courses = rand.nextInt(21) + 10;
	    	students[i] = new hw5.CollegeStudent(first_names[i], last_names[i]);
	    	FillClasses(students[i], num_courses, rand);
		}
	    for (int i = 0; i < students.length; i++)
	    {
	    	String grad_status = students[i].isGraduateEligible() ? "Can Graduate" : "Not eligible";
	    	System.out.print(students[i].ToString() + " " + grad_status);
	    }
	}
	
	private static void FillClasses(hw5.Student student, int num_courses, Random rand)
	{
		for (int j = 0; j < num_courses; j++)
    	{
			int course_type = rand.nextInt(2); // [0...1]
			if (student.getClass().getName() == "hw5.HighSchoolStudent")
			{
				// homework specification: call basic course constructor
				if(course_type == 0) // graded course
				{
					hw5.GradedCourse course = new hw5.GradedCourse (j, "course" + j, "teacher" + j);
					int grade = rand.nextInt(46) + 55;    // [0...45] + 55 = [55...100]
		    		course.setGrade(grade);
		    		student.AddCourse(course);
				}
				else // pass-fail course
				{
					hw5.PassFailCourse course = new hw5.PassFailCourse (j, "course" + j, "teacher" + j);
					int pass = rand.nextInt(10);
					course.SetPass(pass > 1);
					student.AddCourse(course);
				}
			}
			else
			{
				
				int credits = rand.nextInt(3) + 10;	  // [0...2] + 3 = [10...12]
				
				// homework specification: call course constructor with number of credits
				if(course_type == 0) // graded course
				{
					hw5.GradedCourse course = new hw5.GradedCourse (j, "course" + j, "teacher" + j, credits);
					int grade = rand.nextInt(46) + 55;    // [0...45] + 55 = [55...100]
		    		course.setGrade(grade);
		    		student.AddCourse(course);
				}
				else // pass-fail course
				{
					hw5.PassFailCourse course = new hw5.PassFailCourse (j, "course" + j, "teacher" + j, credits);
					int pass = rand.nextInt(10);
					course.SetPass(pass > 1);
					student.AddCourse(course);
				}
			}
    	}
	}

}
