#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void BoldItalic__underscores_with_multiple_words() {
	MarkdownParser::Lexer lexer;
	const std::string md = "___Hola, I'm Eessh___";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold and Italic styling using underscores, with multiple words", "Checking lexer for bold and italic styling using underscores, with multiple words: ***Hola, I'm Eessh***");

	MarkdownParser::BoldItalicToken* t = dynamic_cast<MarkdownParser::BoldItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD_ITALIC)
		test.addError(new Utils::ValueError("type", "BOLD_ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola, I'm Eessh")
		test.addError(new Utils::ValueError("text", "Hola, I'm Eessh", t->text()));
	if (t->render() != "<em><strong>Hola, I'm Eessh</strong></em>")
		test.addError(new Utils::ValueError("render", "<em><strong>Hola, I'm Eessh</strong></em>", t->render()));

	test.log();
}