#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  std::string sym;
  std::cout << "Enter a stock symbol: ";
  while (std::cin >> sym) {
    if (false) {
      std::cout << "Stock " 
		<< std::endl;
    }
    else {
      std::cout << "Symbol '" << sym << "' not found." << std::endl;
    }
    std::cout << "Enter a stock symbol: ";
  }
  return 0;
}
