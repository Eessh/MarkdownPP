#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Italic__underscores_edge_case_1() {
	MarkdownParser::Lexer lexer;
	const std::string md = "__Hola_";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Italic styling using underscores, edge case", "");

	MarkdownParser::ItalicToken* t = dynamic_cast<MarkdownParser::ItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to ItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::ITALIC)
		test.addError(new Utils::ValueError("type", "ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "_Hola")
		test.addError(new Utils::ValueError("text", "_Hola", t->text()));
	if (t->render() != "<em>_Hola</em>")
		test.addError(new Utils::ValueError("render", "<em>_Hola</em>", t->render()));

	test.log();
}