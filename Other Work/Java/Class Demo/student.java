package homework4;

public class student
{

// static fields
private static int classNumber = 472;
private static int studentCount;
private static String className = "Class 77-B";
private static String instructor = "Greene";

// instance fields
private int studentId;
private String firstName;
private String lastName;
private String address;
private String city;
private String email;

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

// setters
public static void SetClassNumber(int classNumber)
{
	student.classNumber = classNumber;
}

public static void SetStudentCount(int studentCount)
{
	student.studentCount = studentCount;
}

public static void SetClassName(String className)
{
	student.className = className;
}

public static void SetInstructor(String instructor)
{
	student.instructor = instructor;
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
public student(String firstName, String lastName)
{
	this.firstName = firstName;
	this.lastName = lastName;
	this.studentId = 1000 + GetStudentCount();
	SetStudentCount(GetStudentCount() + 1);
}

public student(String firstName, String lastName, String address, String city, String email)
{
	this(firstName, lastName);
	this.address = address;
	this.city = city;
	this.email = email;
}

// other methods
public String ToString()
{
	StringBuffer buffer = new StringBuffer("Name: " + firstName);
	buffer.append(" " + lastName);
	buffer.append(", Address: " + address);
	buffer.append(", City: " + city);
	buffer.append(", Email: " + email);
	return buffer.toString();
}

}
