#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Bold__asterisks_with_multiple_words() {
	MarkdownParser::Lexer lexer;
	const std::string md = "**Hola, I'm Eessh**";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold styling with asterisks, with multiple words", "Checking lexer for Bold styling using asterisks, with multiple words: **Hola, I'm Eessh**");

	MarkdownParser::BoldToken* t = dynamic_cast<MarkdownParser::BoldToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD)
		test.addError(new Utils::ValueError("type", "BOLD", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola, I'm Eessh")
		test.addError(new Utils::ValueError("text", "Hola, I'm Eessh", t->text()));
	if (t->render() != "<strong>Hola, I'm Eessh</strong>")
		test.addError(new Utils::ValueError("render", "<strong>Hola, I'm Eessh</strong>", t->render()));

	test.log();
}