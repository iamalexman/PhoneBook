#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

class	Contacts {
private:
	std::string		firstName;
	std::string 	lastName;
	std::string 	nickName;
	std::string 	phoneNumber;
	std::string 	darkestSecret;
public:
	std::string fName() { return (firstName); }
	void setFName (std::string command) { firstName = command; }
	std::string lName () { return (lastName); }
	void setLName (std::string command) { lastName = command; }
	std::string nick () { return (nickName); }
	void setNick (std::string command) { nickName = command; }
	std::string phone () { return (phoneNumber); }
	void setPhone (std::string command) { phoneNumber = command; }
	std::string secret () { return (darkestSecret); }
	void setSecret (std::string command) { darkestSecret = command; }
	Contacts (){}
	~Contacts (){};
};

class Book {
public:
	std::string str;
	void add (int numOfContacts) {
		std::cout << "Please, enter first name: " << std::endl;
		std::getline(std::cin >> std::ws, str);
		listUsers[numOfContacts].setFName(str);
		std::cout << "Please, enter last name: " << std::endl;
		std::getline(std::cin >> std::ws, str);
		listUsers[numOfContacts].setLName(str);
		std::cout << "Please, enter nickname: " << std::endl;
		std::getline(std::cin >> std::ws, str);
		listUsers[numOfContacts].setNick(str);
		std::cout << "Please, enter phone number: " << std::endl;
		std::getline(std::cin >> std::ws, str);
		listUsers[numOfContacts].setPhone(str);
		std::cout << "Please, enter your darkest secret: " << std::endl;
		std::getline(std::cin >> std::ws, str);
		listUsers[numOfContacts].setSecret(str);
		std::cout << "Great! New User added to Phone Book!" << std::endl;
		numOfContacts++;
	}
	void info(int i) {
		std::string lineNum;
		int num = 0;

		std::cout << std::endl;
		std::cout << "Choose id number to see more info, please." << std::endl;
		std::cout << std::endl;
		std::cin >> lineNum;
		if (std::cin.eof())
			std::exit(0);
		if (isdigit(lineNum[0]))
			num = atoi(lineNum.c_str());
		if (i < 0 || num < 0 || num > 8 || !isdigit(lineNum[0]) || num > i) {
			std::cout << std::endl;
			std::cout << "I don't see this id number on the contact list!" << std::endl;
			std::cout << "Enter SEARCH and try to enter correct id number, please." << std::endl;
			return ;
		}
		else {
			std::cout << std::endl;
			std::cout << "First name is:   " << std::setfill(' ') << listUsers[num].fName() << std::endl;
			std::cout << "Last name is:    " << std::setfill(' ') << listUsers[num].lName() << std::endl;
			std::cout << "Nickname is:     " << std::setfill(' ') << listUsers[num].nick() << std::endl;
			std::cout << "Phone number is: " << std::setfill(' ') << listUsers[num].phone() << std::endl;
			std::cout << "Secret is:       " << std::setfill(' ') << listUsers[num].secret() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Enter ADD or SEARCH or EXIT, please." << std::endl;
	}

	void printContactsList (int i) {
		int num = -1;

		std::cout << "_________________________________________" << std::endl;
		std::cout << "|    |          |           |           |" << std::endl;
		std::cout << "| id |   NAME   |  SURNAME  |   PHONE   |" << std::endl;
		std::cout << "|____|__________|___________|___________|" << std::endl;
		if (i >= 0) {
		while (++num <= i) {
			std::cout << "|   " << id << "|";
			if (listUsers[id].fName().length() > 10)
				std::cout << std::setfill(' ') << std::setw(10) << listUsers[id].fName().substr(0, 9).append(".");
			else
				std::cout << std::right << std::setfill(' ') << std::setw(10) << listUsers[id].fName();
			std::cout << "| ";
			if (listUsers[id].lName().length() > 10)
				std::cout << std::setfill(' ') << std::setw(10) << listUsers[id].lName().substr(0, 9).append(".");
			else
				std::cout << std::right << std::setfill(' ') << std::setw(10) << listUsers[id].lName();
			std::cout << "| ";
			if (listUsers[id].nick().length() > 10)
				std::cout << std::setfill(' ') << std::setw(10) << listUsers[id].nick().substr(0, 9).append(".");
			else
				std::cout << std::right << std::setfill(' ') << std::setw(10) << listUsers[id].nick();
			std::cout << "|" << std::endl;
			std::cout << "|---------------------------------------|" << std::endl;
			id++;
			}
		}
		else {
			std::cout << "|                                       |" << std::endl;
			std::cout << "| Contact list is empty, ADD first user |" << std::endl;
		}
		std::cout << "|_______________________________________|" << std::endl;
		id = 0;
	}
	void search (int i) {
			printContactsList(i);
	}
	void error () {
		std::cout << "I don't know what does it mean, but you can try again!" << std::endl;
		std::cout << "Enter ADD or SEARCH or EXIT, please." << std::endl;
	}
	void exit () {}
	Book(){ return; }
	~Book(){ std::cout << "See you later!" << std::endl; }
private:
	Contacts listUsers[8];
	int	id;
};

#endif
