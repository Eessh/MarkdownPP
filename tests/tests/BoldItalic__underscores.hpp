#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void BoldItalic__underscores() {
	MarkdownParser::Lexer lexer;
	const std::string md = "___Hola___";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold and Italic styling with underscores", "Checking lexer for bold and italic styling using underscores: ___Hola___");

	MarkdownParser::BoldItalicToken* t = dynamic_cast<MarkdownParser::BoldItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD_ITALIC)
		test.addError(new Utils::ValueError("type", "BOLD_ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola")
		test.addError(new Utils::ValueError("text", "Hola", t->text()));
	if (t->render() != "<em><strong>Hola</strong></em>")
		test.addError(new Utils::ValueError("render", "<em><strong>Hola</strong></em>", t->render()));

	test.log();
}