#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include "Contacts.hpp"

/*Standard constructor of the Contact Class*/
Contact::Contact()
{}

/*Constructor with parameters.
 * It will create an instance of the Class with parameters already set to a given value*/

Contact::Contact(int id,std::string first_name, std::string last_name, std::string nickname, std::string phone_number , std::string darkest_secret)
{
	this->id = id;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

/*Destructor of the class*/

Contact::~Contact()
{}

/*Getters and setters*/

int	Contact::getId()
{
	return this->id;
}

void Contact::setId(int id)
{
	this->id = id;
}

std::string Contact::get_first_name()
{
	return this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name;
}
std::string Contact::get_phone_number()
{
	return this->phone_number;
}
std::string Contact::get_nickname()
{
	return this->nickname;
}
std::string Contact::get_darkest_secret()
{
	return this->darkest_secret;
}
