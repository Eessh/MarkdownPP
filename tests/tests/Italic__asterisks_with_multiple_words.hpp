#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Italic__asterisks_with_multiple_words() {
	MarkdownParser::Lexer lexer;
	const std::string md = "*Hola, I'm Eessh*";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Italic styling with asterisks, with multiple words", "Checking parser for italic styling using asterisks, with multiple words: *Hola, I'm Eessh*");

	MarkdownParser::ItalicToken* t = dynamic_cast<MarkdownParser::ItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to ItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::ITALIC)
		test.addError(new Utils::ValueError("type", "ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola, I'm Eessh")
		test.addError(new Utils::ValueError("text", "Hola, I'm Eessh", t->text()));
	if (t->render() != "<em>Hola, I'm Eessh</em>")
		test.addError(new Utils::ValueError("render", "<em>Hola, I'm Eessh</em>", t->render()));

	test.log();
}