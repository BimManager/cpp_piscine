// Copyright 2020 kkozlov

#include "Logger.hpp"

int main(void) {
  Logger logger("test.log");

  logger.Log("LogToConsole", "Baz");
  logger.Log("LogToFile", "Foo");
  return (0);
}
