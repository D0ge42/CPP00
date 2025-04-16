#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

/*Here we can find the main methods of the Phonebook Class.
 * Add will let us add a contact to the phonebook
 * Search will let us search a contact inside the phonebook */

Phonebook::Phonebook()
{
	this->number_of_contacts = 0;
}

Contact Phonebook::get_contact(int id)
{
	return this->_contacts[id];
}

Phonebook::~Phonebook()
{}

std::string Phonebook::get_line()
{
	std::string input;
	while(input.length() < 1)
	{
		if (!(std::getline(std::cin,input)))
			return NULL;
	}
	return input;
}

int 	Phonebook::get_id()
{
	return this->id;
}

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

void	Phonebook::search_contact(std::string to_search)
{
	int i = 0;
	while(i < this->number_of_contacts)
	{
		std::string current = this->_contacts[i].get_nickname();
		if (to_search.compare(current) == 0)
		{
			display_contact(&this->_contacts[i]);
			return;
		}
		else
		 i++;
	}
	std::cout << "❗The contact you're searching for its not in this Phonebook >:) " << '\n';
}

void 	Phonebook::add_or_replace_contact(Phonebook *pb)
{
	std::string option;
	if (pb->number_of_contacts > 7)
	{
		std::cout << "Too many contacts. You're about to replace the oldest one" << '\n';
		std::cout << "Proceed? (y/n)" << '\n';
		std::getline(std::cin,option);
		if (option.compare("y") == 0)
		{
			int id_to_replace = this->number_of_contacts % 8;
			pb->add_contact(id_to_replace);
		}
		else if (option.compare("n") == 0)
			return;
		else
			std::cout << "Not a valid option" << '\n';
	}
	else
	{
		pb->add_contact(pb->number_of_contacts);
	}
		
}

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
	this->number_of_contacts++;
}

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

void 	Phonebook::display_contact(Contact *contact)
{

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
		std::cout << std::right << std::setw(9) << contact->get_phone_number().substr(0,9) << '.' << "|";
	else
	 	std::cout << std::right << std::setw(10) << contact->get_phone_number().substr(0,10) << "|" << '\n';
	std::cout << std::right << std::setw(10) << "-------------------------------------------------------" << '\n';
}


int Phonebook::show_contact_count() const
{
	return (number_of_contacts);
}
//
// void Phonebook::display_contact(int i)const
// {
// 	_contacts[i].showContact();
// }
// 
