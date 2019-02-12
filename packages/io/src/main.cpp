#include <stdio.h>
#include <iostream>
#include <string>
#include "Connection.cpp"

int main() {
  Connection conn("test");
  std::cout << "write file\n";
  conn.write("{\"hello\": \"from cpp!\"}");
  //   std::cout << conn.getFilePath();
  std::cout << "contents " << conn.getContents();
}