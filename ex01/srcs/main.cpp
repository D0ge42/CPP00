#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

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
			pb.search_contact(to_search);
		}
		else if (opt.compare("EXIT") == 0)
		{
			std::cout << "Good bye 👋\n";
			exit(0);
		}
	}
}
