#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading2() {
	MarkdownParser::Lexer lexer;
	std::string md = "## Hola";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	MarkdownParser::HeadingToken* t = nullptr;

	t = dynamic_cast<MarkdownParser::HeadingToken*>(v[0]);
	if (!t) {
		Utils__logFailedTest("Heading2", {"Unable to dynamic_cast Token* to HeadingToken*"});
		return;
	}

	bool allOk = true;
	std::vector<std::string> errorDesc;
	if (t->type() != MarkdownParser::TokenType::HEADING) {
		errorDesc.push_back("Type not equal:");
		errorDesc.push_back("  Expected: HEADING");
		errorDesc.push_back("  Recieved: " + MarkdownParser::tokenTypeToStr(t->type()));
		allOk = false;
	}
	if (t->level() != 2) {
		errorDesc.push_back("Level not equal:");
		errorDesc.push_back("  Expected: 2");
		errorDesc.push_back("  Recieved: " + t->level());
		allOk = false;
	}
	if (t->text() != "Hola") {
		errorDesc.push_back("Text not equal:");
		errorDesc.push_back("  Expected: Hola");
		errorDesc.push_back("  Recieved: " + t->text());
		allOk = false;
	}
	if (t->render() != "<h2>Hola</h2>") {
		errorDesc.push_back("Rendered output not equal:");
		errorDesc.push_back("  Expected: <h2>Hola</h2>");
		errorDesc.push_back("  Recieved: " + t->render());
		allOk = false;
	}
	if (allOk)
		Utils__logPassedTest("Heading2");
	else
		Utils__logFailedTest("Heading2", errorDesc);
	std::cout << "\n";
}