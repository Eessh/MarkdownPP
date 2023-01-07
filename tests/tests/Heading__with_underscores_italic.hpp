#pragma once

#include <iostream>
#include "../../MarkdownParser.hpp"
#include "../utils.hpp"

void Heading__with_underscores_italic() {
	MarkdownParser::Lexer lexer;
	const std::string md = "# _Hola, I'm Eessh_";
	std::vector<MarkdownParser::Token*> v = lexer.parseMarkdownStrToTokens(md);

	Utils::Test test("Heading with italic styling using underscores", "Checking lexer for parsing level-1 heading with italic styling using underscores: \"# _Hola, I'm Eessh_\", this should not make heading italic, as heading is an AtomicToken.");

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
	if (t->text() != "_Hola, I'm Eessh_")
		test.addError(new Utils::ValueError("text", "_Hola, I'm Eessh_", t->text()));
	if (t->render() != "<h1>_Hola, I'm Eessh_</h1>")
		test.addError(new Utils::ValueError("render", "_Hola, I'm Eessh_", t->render()));

	test.log();
}