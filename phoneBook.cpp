#include "phoneBook.hpp"

int	main() {
	std::string command;
	Book		phoneBook;
	int			oldContact = 0;
	int			i = -1;

	std::cout << "The Phone Book is ready to use!" << std::endl;
	std::cout << "Choose the command, and enter please: \n\tADD or SEARCH or EXIT" << std::endl;
	while(1) {
		std::cin >> std::ws >> command;
		if (command == "ADD") {
			i++;
			if (i == 8) {
				std::cout << "If you add new contact, you lost oldest contact!" << std::endl;
				phoneBook.add(oldContact);
				oldContact++;
				if (oldContact > 7)
					oldContact = 0;
				i = 7;
			}
			else
				phoneBook.add(i);
		}
		else if (command == "SEARCH") {
			phoneBook.search(i);
			if (i >= 0)
				phoneBook.info(i);
		}
		else if (command == "EXIT") {
			phoneBook.exit();
			break ;
		}
		else
			phoneBook.error();
	}
	return (0);
}
