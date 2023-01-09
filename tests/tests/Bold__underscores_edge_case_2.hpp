#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Bold__underscores_edge_case_2() {
	MarkdownParser::Lexer lexer;
	const std::string md = "__Hola___";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Bold styling using underscores, edge case", "");

	MarkdownParser::BoldToken* t = dynamic_cast<MarkdownParser::BoldToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to BoldToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::BOLD)
		test.addError(new Utils::ValueError("type", "BOLD", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->text() != "Hola_")
		test.addError(new Utils::ValueError("text", "Hola_", t->text()));
	if (t->render() != "<strong>Hola_</strong>")
		test.addError(new Utils::ValueError("render", "<strong>Hola_</strong>", t->render()));

	test.log();
}