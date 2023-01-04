#pragma once

#include <iostream>
#include <string>
#include "./color.hpp"

void Utils__printTestDescription(const std::string& testName, const std::string& testDesc) {
	std::cout << "";
}

void Utils__logPassedTest(const std::string& testName, const std::string& description = "") {
	std::cout << dye::green("Passed").invert() << " " << testName;
	if (description != "") {
		std::cout << description << "\n";
	}
}

void Utils__logFailedTest(const std::string& testName, const std::string& description = "") {
	std::cout << dye::red("Failed").invert() << " " << testName;
	if (description != "") {
		std::cout << description << "\n";
	}
}