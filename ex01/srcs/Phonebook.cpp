#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

/*Function used to add or replace a contact.
 * Params: Phonebook instance
 * Check if the number of contacts is greater than 7 (starts with ID 0).
 * If so it will replace the oldest one with a mod %8 on the last added_id.
 * It will then call add_contact with the ID to replace
 * else it will proceed to add the contact with a given ID.*/

void 	Phonebook::add_or_replace_contact(Phonebook *pb)
{
	std::string option;
	if (pb->number_of_contacts > 7)
	{
		std::cout << "Too many contacts. You're about to replace the oldest one" << '\n';
		std::cout << "Proceed? (y/n)" << '\n';
		std::getline(std::cin,option);
		if (!std::cin)
			return ;
		if (option.compare("y") == 0)
		{
			int id_to_replace = this->last_added_id % 8;
			printf("ID TO REPLACE = %i\n",id_to_replace);
			pb->add_contact(id_to_replace);
		}
		else if (option.compare("n") == 0)
			return;
		else
			std::cout << "Not a valid option" << '\n';
	}
	else
	{
		pb->add_contact(pb->last_added_id);
	}

}

/*Function to add a contact.
 * Params: ID to add to a certain contact.
 * Function used to guide the user trough the creation of a new contact.
 * It will save various info and then call a constructor with saved parameters.
 * The address of the instance of the Contact class is then assigned to the array of Contacts at certain ID.
 * This function is also responsible for updating the number of contacts. */

void    Phonebook::add_contact(int id)
{

	std::cout << "Enter contact first name" << '\n';
	std::string first_name = get_line();

	std::cout << "Enter contact last name" << '\n';
	std::string last_name =  get_line();

	std::cout << "Enter contact nickname" << '\n';
	std::string nickname = get_line();
	if (this->check_user_existence(nickname) == 1)
		return;

	std::cout << "Enter contact phone_number" << '\n';
	std::string phone_number = get_line();

	std::cout << "Enter darkest secret" << '\n';
	std::string darkest_secret = get_line();

	_contacts[id] =	Contact(id,first_name,last_name,nickname,phone_number,darkest_secret);
	this->last_added_id++;
	if (this->number_of_contacts > 7)
		return;
	this->number_of_contacts++;

}

/* Fuunction to search a contact.
 * Takes the ID to search inside the phonebook.
 * It will search the phonebook for a given ID.
 * If to_search is too high or the given ID is not found an error will be prompted.*/

void	Phonebook::search_contact(int to_search)
{
	int i = 0;
	if (to_search > 7)
	{
		std::cout << "Index is out of range. It must be in range from 0 to 8" << '\n';
		return;
	}
	while(i < this->number_of_contacts)
	{
		int current = this->_contacts[i].getId();
		if (current == to_search)
		{
			display_contact(&this->_contacts[i]);
			return;
		}
		else
		 i++;
	}
	std::cout << "❗The contact you're searching for its not in this Phonebook >:) " << '\n';
}

/* Params: nickname that is being searched.
 * Return value: 1 if a user with the same nickname is found. 0 if not.
 * Search if a user already exist in the phonebook by username. If a user with the same nickname
 * is found it will return 1.*/

int	Phonebook::check_user_existence(std::string to_search)
{
	int i = 0;
	while(i < this->number_of_contacts)
	{
		std::string current = this->_contacts[i].get_nickname();
		if (to_search.compare(current) == 0)
		{
			std::cout << "This person already exists in the phonebook" << '\n';
			return 1;
		}
		else
		 i++;
	}
	return 0;
}

/*Function that will display the entire contact list.
 * std::right and setw are used to obtain an equal spacings between tabs.
 * Then it just iterates trough the number of contacts and display them*/

void 	Phonebook::display_contacts_list()
{
	int i = 0;
	std::cout << std::right << std::setw(10) << "-------------------------------------------------------" << '\n';
	std::cout << std::right << std::setw(10) << "ID" << '|';
	std::cout << std::right << std::setw(10) << "FIRST_NAME" << '|';
	std::cout << std::right << std::setw(10) << "LAST_NAME" << '|';
	std::cout << std::right << std::setw(10) << "NICKNAME" << '|';
	std::cout << std::right << std::setw(10) << "PHONE_NUM" << '\n';
	std::cout << std::right << std::setw(10) << "-------------------------------------------------------" << '\n';
	while(i < this->number_of_contacts)
	{
		display_contact(&this->_contacts[i]);
		i++;
	}
}

/*Function to display a single contact.
 * It takes a pointer to a contact instance and display its various infos.
 * Spacing and right alignment is used to get equal spacing between tabs.
 * If a given value is larger then tab's width, last char will be replaced by a dot.*/

void 	Phonebook::display_contact(Contact *contact)
{
	// printf("Contact ID = %i\n", contact->getId());
	std::cout << std::right << std::setw(10) << contact->getId() << "|";
	if (contact->get_first_name().size() > 10)
		std::cout << std::right << std::setw(9) << contact->get_first_name().substr(0,9) << '.' << "|";
	else
	 	std::cout << std::right << std::setw(10) << contact->get_first_name().substr(0,10) << "|";

	if (contact->get_last_name().size() > 10)
		std::cout << std::right << std::setw(9) << contact->get_last_name().substr(0,9) << '.' << "|";
	else
	 	std::cout << std::right << std::setw(10) << contact->get_last_name().substr(0,10) << "|";

	if (contact->get_nickname().size() > 10)
		std::cout << std::right << std::setw(9) << contact->get_nickname().substr(0,9) << '.' << "|";
	else
	 	std::cout << std::right << std::setw(10) << contact->get_nickname().substr(0,10) << "|";

	if (contact->get_phone_number().size() > 10)
		std::cout << std::right << std::setw(9) << contact->get_phone_number().substr(0,9) << '.' << "|" << '\n';
	else
	 	std::cout << std::right << std::setw(10) << contact->get_phone_number().substr(0,10) << "|" << '\n';
	std::cout << std::right << std::setw(9) << "-------------------------------------------------------" << '\n';
}

/*Utils functions used to set,and retrieve info*/
std::string Phonebook::get_line()
{
	std::string input;
	while(input.length() < 1)
	{
		std::getline(std::cin,input);
		if (!std::cin)
			exit(1);

	}
	return input;
}

int Phonebook::show_contact_count() const
{
	return (number_of_contacts);
}


Phonebook::Phonebook()
{
	this->number_of_contacts = 0;
	this->last_added_id = 0;
}

Contact Phonebook::get_contact(int id)
{
	return this->_contacts[id];
}

Phonebook::~Phonebook()
{}

int Phonebook::get_last_added_id()
{
	return this->last_added_id;
}

int 	Phonebook::get_id()
{
	return this->id;
}
