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
	if (!t)
		Utils__logFailedTest("Heading2");
	else if (t->type() == MarkdownParser::TokenType::HEADING && t->level() == 2 && t->text() == "Hola")
		Utils__logPassedTest("Heading2");
	else
		Utils__logFailedTest("Heading2");
	std::cout << "\n";
}