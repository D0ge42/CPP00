#ifndef CONTACTS_HPP 
#define CONTACTS_HPP

#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

class Contact
{
	private:
		int id;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string phone_number;
	public:
		void search_contact();
		void setId(int id);
		int getId();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_phone_number();
		std::string get_nickname();
		std::string get_darkest_secret();
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname
				,std::string phone_number, std::string darkest_secret);
		~Contact();
};


#endif

