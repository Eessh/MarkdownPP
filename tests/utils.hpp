#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "./color.hpp"

void Utils__printTestDescription(const std::string& testName, const std::string& testDesc) {
	std::cout << "";
}

void Utils__logPassedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << dye::light_green("Passed").invert() << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc) {
		std::cout << dye::yellow(desc) << "\n";
	}
}

void Utils__logFailedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << dye::light_red("Failed").invert() << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc) {
		std::cout << dye::red(desc) << "\n";
	}
}