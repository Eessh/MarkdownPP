#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading5() {
	MarkdownParser::Lexer lexer;
	const std::string md = "##### Hola";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Heading5", "Checking lexer for parsing level-5 heading token: \"##### Hola\"");

	MarkdownParser::HeadingToken* t = nullptr;
	t = dynamic_cast<MarkdownParser::HeadingToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to HeadingToken*"));
		return;
	}

	if (t->type() != MarkdownParser::TokenType::HEADING)
		test.addError(new Utils::ValueError("type", "HEADING", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->level() != 5)
		test.addError(new Utils::ValueError("level", "5", std::to_string(t->level())));
	if (t->text() != "Hola")
		test.addError(new Utils::ValueError("text", "Hola", t->text()));
	if (t->render() != "<h5>Hola</h5>")
		test.addError(new Utils::ValueError("render", "<h5>Hola</h5>", t->render()));

	test.log();
}