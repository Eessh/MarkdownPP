#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include "../termcolor/termcolor.hpp"

void printTestBuilderDesc() {
	std::cout << "TestBuilder Usage:\n";
	std::cout << "  This program needs 2 arguments: path to tests folder, path to output main.cpp file\n";
	std::cout << "  Command: TestBuilder.exe <path_to_tests> <path_to_output_file>\n";
	std::cout << "  Example: TestBuilder.exe ./tests ./main.cpp\n";
}

void createFile(const std::filesystem::path& filePath) {
	std::ofstream o{filePath};
}

int main(int argc, char** argv) {
	if (argc < 2 || argc > 3) {
		printTestBuilderDesc();
		return 0;
	}

	std::string testDirPath = argv[1], outputCodePath = argv[2];
	std::vector<std::string> fileNames;

	createFile(outputCodePath);

	std::ofstream outputCodeFile(outputCodePath);

	for (const std::filesystem::directory_entry& dirEntry: std::filesystem::directory_iterator(testDirPath)) {
		if (outputCodeFile.is_open()) {
			outputCodeFile << "#include \"" << testDirPath << dirEntry.path().filename().string() << "\"\n";
		}
		fileNames.push_back(dirEntry.path().stem().string());
	}

	for (const std::string& file: fileNames) {
		std::cout << "Found Test: " << termcolor::bright_yellow << file << termcolor::reset << "\n";
	}

	std::cout << "Found " << termcolor::bright_green << fileNames.size() << termcolor::reset << " Tests.\n";

	if (outputCodeFile.is_open()) {
		outputCodeFile << "\nint main() {\n\tstd::cout << \"\\n\";\n";
		for (const std::string& testName: fileNames) {
			outputCodeFile << "\t" << testName << "();\n";
		}
		outputCodeFile << "\treturn 0;\n}";
	}

	outputCodeFile.close();

	return 0;
}