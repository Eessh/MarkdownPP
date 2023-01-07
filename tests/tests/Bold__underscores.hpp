#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Bold__underscores() {
	MarkdownParser::Lexer lexer;
	const std::string md = "__Hola__";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold styling with underscores", "Checking lexer for bold styling using underscores: __Hola__");

	MarkdownParser::BoldToken* t = dynamic_cast<MarkdownParser::BoldToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD)
		test.addError(new Utils::ValueError("type", "BOLD", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola")
		test.addError(new Utils::ValueError("text", "Hola", t->text()));
	if (t->render() != "<strong>Hola</strong>")
		test.addError(new Utils::ValueError("render", "<strong>Hola</strong>", t->render()));

	test.log();
}