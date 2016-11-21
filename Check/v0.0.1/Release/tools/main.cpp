#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "test.hpp"

const std::string icmd = "-i";
const std::string ocmd = "-o";
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

		std::string cmd, iparams, oparams;
		std::getline(std::cin, cmd);
		std::string::size_type iindex = cmd.find(icmd);
		std::string::size_type oindex = cmd.find(ocmd);
		if (std::string::npos != iindex) {
			iparams = cmd.substr(iindex + icmd.size(), std::string::npos == oindex ? cmd.size() : abs((int)(iindex - oindex)) - icmd.size());
			iparams.erase(0, iparams.find_first_not_of(" "));
			iparams.erase(iparams.find_last_not_of(" ") + 1);
		}
		if (std::string::npos != oindex) {
			oparams = cmd.substr(oindex + ocmd.size(), std::string::npos == iindex ? cmd.size() : abs((int)(iindex - oindex)) - ocmd.size());
			oparams.erase(0, oparams.find_first_not_of(" "));
			oparams.erase(oparams.find_last_not_of(" ") + 1);
		}

		std::stringstream iss, oss;
		std::queue<std::string> ivect, ovect;
		iss << iparams;
		oss << oparams;
		while (!iss.eof())
		{
			std::string 
			ivect.push()
		}
		bool isPass = test(iss.iparams, oparams);
		numOfNotPassed += !isPass;
	}
	
	switch (numOfNotPassed) {
	case 0: std::cout << "[o] All test cases are passed." << std::endl; break;
		case 1: std::cout << "[o] " << numOfNotPassed << " of " << numOfCases << " test case is not passed." << std::endl; break;
		default: std::cout << "[o] " << numOfNotPassed << " of " << numOfCases << " test cases are not passed." << std::endl; break;
	}

	return 0;
}