#include <iostream>
#include <string>
#include <sstream>
#include "test.hpp"

const std::string icmd = "-i";
const std::string ocmd = "-o";

void errorDisplay(std::string testIn, std::string testOut, std::string realOut) {
	std::cout << "\t[e] The input of the test case is(are) : " << testIn << std::endl;
	std::cout << "\t[e] The output of the test case is(are) : " << testOut << std::endl;
	std::cout << "\t[e] The output of the function is(are) : " << realOut << std::endl;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) return -1;

	int numOfCases = 0;
	int numOfNotPassed = 0;
	sscanf_s(argv[1], "%d", &numOfCases);

	for (int i = 1; i <= numOfCases; i++) {
		switch (i) {
			case 1: std::cout << "[i] Please input the " << i << "st test case : "; break;
			case 2: std::cout << "[i] Please input the " << i << "nd test case : "; break;
			case 3: std::cout << "[i] Please input the " << i << "rd test case : "; break;
			default: std::cout << "[i] Please input the " << i << "th test case : "; break;
		}

		std::string cmd; std::stringstream iss, oss;
		std::getline(std::cin, cmd);
		std::string::size_type iindex = cmd.find(icmd);
		std::string::size_type oindex = cmd.find(ocmd);
		if (std::string::npos != iindex) {
			auto params = cmd.substr(iindex + icmd.size(), ((std::string::npos != oindex && oindex > iindex) ? oindex : cmd.size()) - iindex - icmd.size());
			params.erase(0, params.find_first_not_of(" "));
			params.erase(params.find_last_not_of(" ") + 1);
			iss << params;
		}
		if (std::string::npos != oindex) {
			auto params = cmd.substr(oindex + ocmd.size(), ((std::string::npos != iindex && iindex > oindex) ? iindex : cmd.size()) - oindex - ocmd.size());
			params.erase(0, params.find_first_not_of(" "));
			params.erase(params.find_last_not_of(" ") + 1);
			oss << params;
		}
		bool isPass = test(iss, oss, errorDisplay);
		numOfNotPassed += !isPass;
	}
	
	switch (numOfNotPassed) {
		case 0 : std::cout << "[o] All test cases are passed." << std::endl; break;
		case 1 : std::cout << "[o] " << numOfNotPassed << " of " << numOfCases << " test case is not passed." << std::endl; break;
		default: std::cout << "[o] " << numOfNotPassed << " of " << numOfCases << " test cases are not passed." << std::endl; break;
	}

	return 0;
}