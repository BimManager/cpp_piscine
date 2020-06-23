// Author: kkozlov
#include <iostream>
#include <iomanip>

#include "Contact.h"

#define BOOK_SIZE 8
#define MAX_CHARS 9
#define N_FIELDS_SEARCH 3

#define ADD_CMD "ADD"
#define SEARCH_CMD "SEARCH"
#define EXIT_CMD "EXIT"

static std::string contact_fields[] = {
  "first name", "last name",
  "nickname", "login", "postal address",
  "email address", "phone number", "birthday date",
  "favorite meal", "underwear color", "darkest secret"
};

static void add_contact(Contact *contact) {
  int i;
  std::string input;

  i = -1;
  while (++i < N_FIELDS) {
    std::cout << "Please enter your " << contact_fields[i] << ':' << std::endl;
    std::cin >> input;
    contact->SetByIndex(i, input); 
  }
}

static void search_contact(Contact *phonebook, int n_entries) {
  std::string output;
  int idx;
  int i;
  int j;

  if (0 == n_entries) {
    std::cout << "The phone book is empty.\n";
    return ;
  }
  while (42) {
    i = -1;
    while (++i < n_entries) {
      std::cout << std::setw(10) << i + 1 << '|';
      j = -1;
      while (++j < N_FIELDS_SEARCH) {
        output = phonebook[i].GetByIndex(j);
        if (output.size() > 10) {
          output = output.substr(0,10);
          output.replace(9, 1, ".");
        }
        std::cout << std::setw(10) << output << '|';
      }
      std::cout << std::endl;
    }
    std::cout << "Please enter the index of the desired entry or type in 0 to quit:\n";
    std::cin >> idx;
    if (0 == idx)
      break ;
    if (idx <= 0 || idx > n_entries + 1)
      std::cout << "Something has gone wrong. Try again.\n";
    else {
      --idx;
      i = -1;
      while (++i < N_FIELDS)
        std::cout << phonebook[idx].GetByIndex(i) << std::endl;
    }
  }
}

int	main(void) {
  Contact phonebook[BOOK_SIZE];
  int n_entries;
  std::string input;

  n_entries = 0;
  while (42) {
    std::cout << "\nAvailable Commands:\n"
        "ADD: add a new contanct\n"
        "SEARCH: explore stored contacts\n"
        "EXIT: quit\n" << std::endl;
    std::cin >> input;
    if (0 == input.compare(ADD_CMD)) {
      if (BOOK_SIZE == n_entries) {
        std::cout << "The book is full. No more contacts may be added.\n";
        continue ; 
     }
      add_contact(&phonebook[n_entries++]);
    }
    else if (0 == input.compare(SEARCH_CMD))
      search_contact(phonebook, n_entries);
    else if (0 == input.compare(EXIT_CMD))
      break ;
  }
  return (0);
}
