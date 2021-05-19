package hw6;

import java.util.*;
import java.io.*;

public class AddressBookReader
{

	public AddressBookReader(String file)
	{	
		inFile = file;
		for (String column: columns)
		{
			addrBook.put(column, new ArrayList<String>());
		}
		this.ReadAddressBook();
	}
	
	public LinkedHashMap<String, ArrayList<String>> GetAddrBook()
	{
		return addrBook;
	}
	
	public String[] GetColumns()
	{
		return columns;
	}
	
	private void ReadAddressBook()
	{
		try(BufferedReader reader = new BufferedReader(new FileReader(inFile))) 
		{
		    for(String line; (line = reader.readLine()) != null; ) 
		    {
		        String[] parsedLine = line.split(",");
		        for (int i = 0; i < columns.length; i++)
		        {
		        	addrBook.get(columns[i]).add(parsedLine[i]);
		        }
		        
		    }
		}
		catch (Exception e) 
		{
		    System.out.println("Error: No file opened");
		}
	}

	public String ToString()
	{
		StringBuffer buffer = new StringBuffer();
		
		for (int i = 0; i < addrBook.get(columns[0]).size(); i++)
		{
			for(int j = 0; j < columns.length; j++)
			{
				buffer.append(", " + columns[j] + ": ");
				buffer.append(addrBook.get(columns[j]).get(i));
			}
			buffer.append("\n");
		}
		
		return buffer.toString();
	}
	
	public String RowToString(int record)
	{
		StringBuffer row = new StringBuffer();
		
		for (int i = 0; i < columns.length; i++)
		{
			row.append(columns[i] + ": ");
			row.append(addrBook.get(columns[i]).get(record) + ", ");
		}
		
		return row.toString();
	}
	
	// fields
	private String inFile;
	private LinkedHashMap<String, ArrayList<String>> addrBook = new LinkedHashMap<String, ArrayList<String>>();
	private String[] columns = {"Last Name", "First Name", "Street", "Town", "State", "Phone Number"};
}
