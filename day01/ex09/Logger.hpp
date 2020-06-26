// Copyright 2020 kkozlov

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>

class Logger;

typedef void (Logger::*PFN) (const std::string&) const;

class Logger {
 public:
  explicit Logger(const std::string& filename);
  void Log(const std::string& dest, const std::string& message) const;
 private:
  std::string filename_;
  static const char *kFunctionNames[2];
  static const PFN kDispatchTable[];

  std::string MakeLogEntry(const std::string& message) const;
  void LogToConsole(const std::string& message) const;
  void LogToFile(const std::string& message) const;
};

#endif  // LOGGER_HPP_
