package homework4;

public class Main
{
	public static void main(String args[])
	{
		String[] firstNames = new String[]{"John", "Arlind", "Lindsay", "Samuel", "Charles"};
		String[] lastNames = new String[]{"Marx", "Stafaj", "O'Neal", "Sultan", "Merril"};
		String[] addresses = new String[]{"42 Wallaby Way", "11 Fake Street", "917 Park Avenue", "66 Straya Court", "53 Levin Lane"};
		String [] cities = new String[] {"Bostoff", "Zoo York", "Philhofstraa", "Oceanttle", "Demycenaet"};
		String[] emails = new String[] {"jmarx@school.com", "TA@school.com", "loneal@school.com", "ssultan@fordham.edu", "cmerill@school.com"};
		
		homework4.Classroom classroom = new homework4.Classroom(5);
		homework4.student[] students = new homework4.student[5];
		
		for(int i = 0; i < 2; i++)
		{
			students[i] = new homework4.student(firstNames[i], lastNames[i]);
		}
		for(int i = 2; i < 5; i++)
		{
			students[i] = new homework4.student(firstNames[i], lastNames[i], addresses[i], cities[i], emails[i]);
		}
		classroom.SetStudents(students);
		System.out.println("---------------------");
		classroom.PrintStudents();
		System.out.println("---------------------");
		// modify values using setters
		for (int i = 0; i < 5; i++)
		{
			if (classroom.GetStudents()[i].GetAddress() == null)
			{
				classroom.GetStudents()[i].SetAddress(addresses[i]);
			}
			if (classroom.GetStudents()[i].GetCity() == null)
			{
				classroom.GetStudents()[i].SetCity(cities[i]);
			}
			if (classroom.GetStudents()[i].GetEmail() == null)
			{
				classroom.GetStudents()[i].SetEmail(emails[i]);
			}
		}
		System.out.println("---------------------");
		classroom.PrintStudents();
		System.out.println("---------------------");
		// modify values using setters and getters
		classroom.GetStudents()[0].SetFirstName(students[1].GetFirstName());
		classroom.GetStudents()[0].SetLastName(students[1].GetLastName());
		classroom.GetStudents()[0].SetAddress(students[1].GetAddress());
		classroom.GetStudents()[0].SetCity(students[1].GetCity());
		classroom.GetStudents()[0].SetEmail(students[1].GetEmail());
		System.out.println("---------------------");
		classroom.PrintStudents();
		System.out.println("---------------------");
	}
}
