#include "Contact.h"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void Contact::SetByIndex(int idx, std::string& data) {
  if (idx >= N_FIELDS)
    return ;
  this->fields_[idx] = data;
}

const std::string& Contact::GetByIndex(int idx) const {
  if (idx >= N_FIELDS)
    throw "Index is out of range";
  return this->fields_[idx];
}
