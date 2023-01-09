#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void BoldItalic__asterisks_edge_case_1() {
	MarkdownParser::Lexer lexer;
	const std::string md = "****Hola***";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold an Italic styling using asterisks, edge case", "");

	MarkdownParser::BoldItalicToken* t = dynamic_cast<MarkdownParser::BoldItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD_ITALIC)
		test.addError(new Utils::ValueError("type", "BOLD_ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "*Hola")
		test.addError(new Utils::ValueError("text", "*Hola", t->text()));
	if (t->render() != "<em><strong>*Hola</strong></em>")
		test.addError(new Utils::ValueError("render", "<em><strong>*Hola</strong></em>", t->render()));

	test.log();
}