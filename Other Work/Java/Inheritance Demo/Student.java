package hw5;

public abstract class Student
{

// static fields
protected static int classNumber = 472;
protected static int studentCount;
protected static String className = "Class 77-B";
protected static String instructor = "Greene";

// instance fields
protected int studentId;
protected String firstName;
protected String lastName;
protected String address;
protected String city;
protected String email;
protected int num_courses;
protected hw5.Course[] courses = new hw5.Course[50];

// getters
public static int GetClassNumber()
{
	return classNumber;
}

public static int GetStudentCount()
{
	return studentCount;
}

public static String GetClassName()
{
	return className;
}

public static String GetInstructor()
{
	return instructor;
}

public int GetStudentId()
{
	return studentId;
}

public String GetFirstName()
{
	return firstName;
}

public String GetLastName()
{
	return lastName;
}

public String GetAddress()
{
	return address;
}

public String GetCity()
{
	return city;
}

public String GetEmail()
{
	return email;
}

public hw5.Course[] GetCourses()
{
	return courses;
}

// setters
public static void SetClassNumber(int classNumber)
{
	Student.classNumber = classNumber;
}

public static void SetStudentCount(int studentCount)
{
	Student.studentCount = studentCount;
}

public static void SetClassName(String className)
{
	Student.className = className;
}

public static void SetInstructor(String instructor)
{
	Student.instructor = instructor;
}

public void SetStudentId(int studentId)
{
	this.studentId = studentId;
}

public void SetFirstName(String firstName)
{
	this.firstName = firstName;
}

public void SetLastName(String lastName)
{
	this.lastName = lastName;
}

public void SetAddress(String address)
{
	this.address = address;
}

public void SetCity(String city)
{
	this.city = city;
}

public void SetEmail(String email)
{
	this.email = email;
}

// constructors
public Student(String firstName, String lastName)
{
	this.firstName = firstName;
	this.lastName = lastName;
	this.studentId = 1000 + GetStudentCount();
	SetStudentCount(GetStudentCount() + 1);
}

public Student(String firstName, String lastName, String address, String city, String email)
{
	this(firstName, lastName);
	this.address = address;
	this.city = city;
	this.email = email;
}

// other methods
public String ToString()
{
	System.out.println("----------------");
	System.out.println("Courses:");
	System.out.println("----------------");
	for (int i = 0; i < 50; i++)
	{
		if (this.courses[i] == null)
		{
			continue;
		}
		else
		{
			System.out.println(this.courses[i].ToString());
		}
	}
	System.out.println("----------------");
	StringBuffer buffer = new StringBuffer("Name: " + firstName);
	buffer.append(" " + lastName);
	buffer.append(", Address: " + address);
	buffer.append(", City: " + city);
	buffer.append(", Email: " + email);
	return buffer.toString();
}

public void AddCourse(hw5.Course course)
{
	if (num_courses < 50)
	{
		courses[num_courses] = course;
		num_courses++;
	}
}

protected int GetPassCriteria(hw5.GradedCourse course)
{
	return course.getGrade();
}

protected boolean GetPassCriteria(hw5.PassFailCourse course)
{
	return course.GetPass();
}

abstract public boolean isGraduateEligible();

abstract protected int PassedReqs();

}
