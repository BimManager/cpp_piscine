// Copyright 2020 kkozlov

#include <ctime>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Logger.hpp"

const PFN Logger::kDispatchTable[] = {
  &Logger::LogToConsole, &Logger::LogToFile };
const char *Logger::kFunctionNames[] = {
  "LogToConsole", "LogToFile" };

Logger::Logger(const std::string& filename)
    : filename_(filename) {
}

void Logger::Log(const std::string& dest, const std::string& message) const {
  (void)dest;
  (void)message;
  int i = sizeof(kFunctionNames) / sizeof(kFunctionNames[0]);
  while (i--)
    if (0 == dest.compare(kFunctionNames[i]))
      (this->*kDispatchTable[i])(message);
}

std::string Logger::MakeLogEntry(const std::string& message) const {
  std::string log;
  time_t now;
  struct tm *time;
  char prevFill;
  std::stringstream buffer;
  std::streambuf *old;

  now = std::time(NULL);
  time = std::localtime(&now);
  old = std::cout.rdbuf(buffer.rdbuf());
  prevFill = std::cout.fill('0');
  std::cout << '[' << time->tm_year + 1900
            << '-' << std::setw(2) << time->tm_mon + 1
            << '-' << std::setw(2) << time->tm_mday
            << 'T' << std::setw(2) << time->tm_hour
            << ':' << std::setw(2) << time->tm_min
            << ':' << std::setw(2) << time->tm_sec
            << ']' << ' ' << message;
  log = buffer.str();
  std::cout.rdbuf(old);
  std::cout.fill(prevFill);
  return log;
}

void Logger::LogToConsole(const std::string& message) const {
  std::cout << MakeLogEntry(message) << std::endl;
}

void Logger::LogToFile(const std::string& message) const {
  std::ofstream ofs(filename_, std::ios_base::binary);
  ofs << MakeLogEntry(message) << std::endl;
  ofs.close();
}
