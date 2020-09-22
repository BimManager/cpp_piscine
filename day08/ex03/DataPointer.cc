// Copyright 2020 kkozlov

#include "DataPointer.h"

std::size_t const DataPointer::kNbBytes = 8 * 4096;

DataPointer::DataPointer(void) {
  raw_p = reinterpret_cast<char *>(std::malloc(kNbBytes));
  bzero(raw_p, kNbBytes);
}

DataPointer::~DataPointer(void) {
  free(raw_p);
}

void DataPointer::RunInstruction(std::list<IInstruction *>::iterator &it) {
  IInstruction *op = dynamic_cast<IInstruction *>(*it);
  Execute(op, &it);
}


