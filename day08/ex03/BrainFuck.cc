// Copyright 2020 kkozlov

#include <string>
#include <fstream>

#include "BrainFuck.h"
#include "IncrementPointer.h"
#include "DecrementPointer.h"
#include "IncrementByte.h"
#include "DecrementByte.h"
#include "WhileStart.h"
#include "WhileEnd.h"
#include "AcceptByte.h"
#include "OutputByte.h"

PFN BrainFuck::ops_tab_[TAB_SIZE] = {
  ['>'] = &IncrementPointer::Create,
  ['<'] = &DecrementPointer::Create,
  ['+'] = &IncrementByte::Create,
  ['-'] = &DecrementByte::Create,
  ['['] = &WhileStart::Create,
  [']'] = &WhileEnd::Create,
  [','] = &AcceptByte::Create,
  ['.'] = &OutputByte::Create
};

std::size_t const BrainFuck::kBufSize_ = 8 * 4096;

BrainFuck *BrainFuck::instance_ = NULL;

BrainFuck::BrainFuck(void) {
  ptr_ = reinterpret_cast<char *>(malloc(kBufSize_));
  bzero(ptr_, kBufSize_);
}

BrainFuck::~BrainFuck(void) {
  if (instance_) {
    std::list<IInstruction *>::iterator begIt = ops_.begin();
    std::list<IInstruction *>::iterator endIt = ops_.end();
    while (begIt != endIt) {
      delete *begIt;
      ++begIt;
    }
    delete ptr_;
    delete instance_;
  }
}

BrainFuck *BrainFuck::GetInstance(void) {
    if (!instance_)
      instance_ = new BrainFuck();
    return instance_;
}

int BrainFuck::ReadFromFile(std::string const &filename) {
  std::string line;
  std::ifstream ifs(filename, std::ios::binary);
  if (ifs.is_open()) {
    while (std::getline(ifs, line))
      ParseLine(line);
    ifs.close();
    return 0;
  } else {
    std::cerr << "Unable to open file " << filename << std::endl;
    return 1;
  }
}

int BrainFuck::ParseLine(std::string &line) {
  std::string::iterator itBeg = line.begin();
  std::string::iterator itEnd = line.end();
  while (itBeg != itEnd) {
    if (ops_tab_[static_cast<int>(*itBeg)]) {
      ops_.push_back((*ops_tab_[static_cast<int>(*itBeg)])());
      }
    ++itBeg;
  }
  return 1;
}

int BrainFuck::Run(void) {
  int res;
  std::list<IInstruction *>::iterator tmp;
  std::list<IInstruction *>::iterator startIt = ops_.begin();
  std::list<IInstruction *>::iterator endIt = ops_.end();
  while (startIt != endIt) {
    if (1 == (res = (*startIt)->Execute(&ptr_))) {
      if (*ptr_) {
        loops_.push(startIt);
      } else {
        while (startIt != endIt && NULL == dynamic_cast<WhileEnd *>(*startIt))
          ++startIt;
      }
    } else if (2 == res) {
      if (*ptr_) {
        startIt = loops_.top();
      } else {
        loops_.pop();
      }
    }
    ++startIt;
  }
  return 0;
}
