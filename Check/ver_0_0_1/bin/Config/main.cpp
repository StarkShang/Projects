#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

extern bool test(std::stringstream &in);
int main(int argc, char* argv[]) {
	int total = 0;
	if (argc > 1) {
		total = atoi(argv[1]);
	}
	int count = 0;
	for (int i = 0; i < total; ++i) {
		char buffer[1024];
		std::cout << "[in]" << std::endl;
		std::cin.getline(buffer, 1024);
		std::stringstream ss(buffer);
		count += test(ss) ? 0 : 1;
	}
	
	if (0 == count) {
		std::cout << "[summary] All tests are passed!" << std::endl;
	} else if (1 == count) {
		std::cout << "[summary] 1 of " << total << " test case is not passed!" << std::endl;
	} else {
		std::cout << "[summary] " << count << " of " << total << " test cases are not passed!" << std::endl;
	}
    
    return 0;
}