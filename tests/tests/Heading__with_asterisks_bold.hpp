#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading__with_asterisks_bold() {
	MarkdownParser::Lexer lexer;
	const std::string md = "# **Hola, I'm Eessh**";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Heading with bold styling using asterisks", "Checking lexer for parsing level-1 heading with bold styling using asterisks: \"# **Hola, I'm Eessh**\", this should not make heading bold, as heading is an AtomicToken.");

	MarkdownParser::HeadingToken* t = dynamic_cast<MarkdownParser::HeadingToken*>(v[0]);
	if (!t) {
		test.addError(new Utils::RuntimeError("Unable to dynamic_cast Token* to HeadingToken*"));
		test.log();
		return;
	}

	if (t->type() != MarkdownParser::TokenType::HEADING)
		test.addError(new Utils::ValueError("type", "HEADING", MarkdownParser::tokenTypeToStr(t->type())));
	if (t->level() != 1)
		test.addError(new Utils::ValueError("level", "1", std::to_string(t->level())));
	if (t->text() != "**Hola, I'm Eessh**")
		test.addError(new Utils::ValueError("text", "*Hola, I'm Eessh*", t->text()));
	if (t->render() != "<h1>**Hola, I'm Eessh**</h1>")
		test.addError(new Utils::ValueError("render", "<h1>**Hola I'm Eessh**</h1>", t->render()));

	test.log();
}