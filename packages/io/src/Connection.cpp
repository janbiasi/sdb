#include <fstream>
#include <iostream>
#include <string>
#include "lib/sha256.h"

const std::string &ext = "sdb";

class Connection {
  std::string fileName;
  bool open;
  static int count;

  // constructor
 public:
  Connection(std::string name) {
    if (count > 10) {
      throw std::range_error("Connection maximum of 10 exceeded");
    }
    fileName = name;
    Connection::count++;
  };

  // get file path for current connection
  const std::string getFilePath() const {
    std::string stringBuilder;
    stringBuilder.append(fileName);
    stringBuilder.append(".");
    stringBuilder.append(ext);
    return stringBuilder;
  };

  // get file contents
  const std::string getContents() const {
    std::string content;
    std::ifstream streamContents(getFilePath());
    content.assign((std::istreambuf_iterator<char>(streamContents)),
                   (std::istreambuf_iterator<char>()));
    return content;
  }

  // write file contents
  void write(std::string content) {
    std::ofstream outputStream(getFilePath());
    outputStream << content;
  }
};

int Connection::count = 0;