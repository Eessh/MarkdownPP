#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Italic__asterisks_edge_case_1() {
	MarkdownParser::Lexer lexer;
	const std::string md = "**Hola*";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Italic styling using asterisks, edge case", "");

	MarkdownParser::ItalicToken* t = dynamic_cast<MarkdownParser::ItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to ItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::ITALIC)
		test.addError(new Utils::ValueError("type", "ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "*Hola")
		test.addError(new Utils::ValueError("text", "*Hola", t->text()));
	if (t->render() != "<em>*Hola</em>")
		test.addError(new Utils::ValueError("render", "<em>*Hola</em>", t->render()));

	test.log();
}