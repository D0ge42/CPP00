#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include "Phonebook.hpp"

/*Main method.
 * Its an infinite loop that will only stop if EXIT is selected
 * or if a given signal is sent.
 * It asks the user to select an option between ADD SEARCH and EXIT.
 * Uses getline to retrieve input from the stdinput stream.
 * It saves the returning string into a variable option and then proceed.*/

int main()
{
	std::string  opt;
	Phonebook pb;

	std::cout << "Welcome. This is Doge's Phonebook 📞 " << '\n';
	
	while(0x101010)
	{
		std::cout << "Please select one option:" << '\n';
		std::cout << " ADD ➕ | SEARCH 🔍 | EXIT 👋" << '\n';
		std::getline(std::cin,opt);
		if (!std::cin)
			return 1;
		if (opt.compare("ADD") == 0)
		{
			std::cout << "Add Option selected ➕\n";
			pb.add_or_replace_contact(&pb);
		}
		else if (opt.compare("SEARCH") == 0)
		{
			pb.display_contacts_list();
			std::string to_search;
			std::cout << "Search option selected 🔍\n";
			std::cout << "Who are you looking for? 👀" << '\n';
			std::getline(std::cin,to_search);
			if (!std::cin)
				return 1;
			if (to_search.length() == 0)
				continue;
			int num = std::atoi(to_search.c_str());
			pb.search_contact(num);
		}
		else if (opt.compare("EXIT") == 0)
		{
			std::cout << "Good bye 👋\n";
			exit(0);
		}
	}
}
