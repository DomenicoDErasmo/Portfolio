package hw6;

public class AddressBook
{

	public static void main(String[] args)
	{
		String file = "resources/addrbook";
		hw6.AddressBookReader reader = new hw6.AddressBookReader(file);
		hw6.Menu menu = new hw6.Menu(reader);
		menu.Run();
	}

}