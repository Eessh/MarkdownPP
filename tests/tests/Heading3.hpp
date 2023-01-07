#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading3() {
	MarkdownParser::Lexer lexer;
	const std::string md = "### Hola";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Heading3", "Checking lexer for parsing level-3 heading token: \"### Hola\"");

	MarkdownParser::HeadingToken* t = nullptr;
	t = dynamic_cast<MarkdownParser::HeadingToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to HeadingToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::HEADING)
		test.addError(new Utils::ValueError("type", "HEADING", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->level() != 3)
		test.addError(new Utils::ValueError("level", "3", std::to_string(t->level())));
	if (t->text() != "Hola")
		test.addError(new Utils::ValueError("text", "Hola", t->text()));
	if (t->render() != "<h3>Hola</h3>")
		test.addError(new Utils::ValueError("render", "<h3>Hola</h3>", t->render()));

	test.log();
}