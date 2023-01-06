#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../termcolor/termcolor.hpp"

void Utils__printTestDescription(const std::string& testName, const std::string& testDesc) {
	std::cout << "";
}

void Utils__logPassedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << termcolor::on_bright_green << termcolor::bright_white << "Passed" << termcolor::reset << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc)
		std::cout << termcolor::yellow << desc << termcolor::reset << "\n";
}

void Utils__logFailedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << termcolor::on_bright_red << termcolor::bright_white << "Failed" << termcolor::reset << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc)
		std::cout << termcolor::red << desc << termcolor::reset << "\n";
}