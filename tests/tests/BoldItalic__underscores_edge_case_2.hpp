#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void BoldItalic__underscores_edge_case_2() {
	MarkdownParser::Lexer lexer;
	const std::string md = "___Hola____";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold an Italic styling using underscores, edge case", "");

	MarkdownParser::BoldItalicToken* t = dynamic_cast<MarkdownParser::BoldItalicToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldItalicToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD_ITALIC)
		test.addError(new Utils::ValueError("type", "BOLD_ITALIC", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola_")
		test.addError(new Utils::ValueError("text", "Hola_", t->text()));
	if (t->render() != "<em><strong>Hola_</strong></em>")
		test.addError(new Utils::ValueError("render", "<em><strong>Hola_</strong></em>", t->render()));

	test.log();
}