package hw6;

import java.util.*;
import java.io.*;

public class Menu
{

	public Menu(hw6.AddressBookReader reader)
	{
		this.reader = reader;
		this.menu = BuildMenu();
	}

	public void Run()
	{
		while(true)
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			System.out.print(menu);
			try
			{
				String input = reader.readLine();
				try
				{
					int command = Integer.parseInt(input);
					if (command == 1)
					{
						System.out.println("Enter a last name to search for: ");
						input = reader.readLine();
						FindAddress(input);
					}
					else
					{
						System.out.println("Goodbye");
						break;
					}
				}
				catch (Exception error)
				{
					System.out.println("Invalid input. Goodbye");
					break;
				}
			} 
			catch (IOException e)
			{
				System.out.println("Error: Couldn't read user input.");
			}
		}
	}
	
	private String BuildMenu()
	{
		StringBuffer buffer = new StringBuffer();
		buffer.append("Select one of the following choices:\n");
		buffer.append("1. Search by last name\n");
		buffer.append("2. Exit\n");
		return buffer.toString();
	}
	
	private void FindAddress(String search)
	{
		String column = reader.GetColumns()[0];
		ArrayList <String> lastNames = reader.GetAddrBook().get(column);
		boolean found = false;
		for (int i = 0; i < lastNames.size(); i++)
		{
			String addrBookEntry = lastNames.get(i).toLowerCase();
			String query = search.toLowerCase();
			if (addrBookEntry.contains(query))
			{
				System.out.println(reader.RowToString(i));
				found = true;
			}
		}
		if (!found)
		{
			System.out.println("No match");
		}
	}
	
	private hw6.AddressBookReader reader;
	private String menu;
}
