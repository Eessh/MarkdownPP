#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading1() {
	MarkdownParser::Lexer lexer;
	std::string md = "# Hola";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	MarkdownParser::HeadingToken* t = nullptr;

	t = dynamic_cast<MarkdownParser::HeadingToken*>(v[0]);
	if (!t)
		Utils__logFailedTest("Heading1");
	else if (t->type() == MarkdownParser::TokenType::HEADING && t->level() == 1 && t->text() == "Hola")
		Utils__logPassedTest("Heading1");
	else
		Utils__logFailedTest("Heading1");
	std::cout << "\n";
}