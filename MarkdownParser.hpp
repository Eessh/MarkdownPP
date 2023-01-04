#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <stdexcept>

/**
 * MarkdownParser Namespace
 * TokenType Declaration
 * */
namespace MarkdownParser {

  /**
   * TokenType
   * 
   * */
  enum class TokenType {
    ROOT,
		HEADING,
		BOLD,
		ITALIC,
    BOLD_ITALIC,
		STRIKETHROUGH,
		INLINE_CODE,
		MULTILINE_CODE,
		QUOTE,
		LINK,
		IMAGE,
    ORDERED_LIST,
    UNORDERED_LIST,
		TEXT,
		TAB,
		NEWLINE
  };

};

/**
 * MarkdownParser Namespace
 * MarkdownDoc declaration
 * */
namespace MarkdownParser {

  /**
   * MarkdownDoc
   * 
   * */
  class MarkdownDoc {

  friend class Lexer;

  public:
    MarkdownDoc();
    MarkdownDoc(const std::string& filePath);

    void load(const std::string& filePath);
    void log();

  private:
    std::vector<std::string> text;
  };

};

/**
 * MarkdownParser Namespace
 * Token, and its derived classes declarations
 * */
namespace MarkdownParser {

  /**
   * Token
   * 
   * Base class for all types of tokens.
   * */
  class Token {
  public:
    const TokenType& type() const;
    virtual void log() const = 0;
    virtual std::string render() const = 0;

    // virtual const unsigned int& level() const;
    // virtual const std::string& text() const;
    // virtual const std::string& link() const;
    // virtual const std::string& source() const;

  protected:
    TokenType mType;
  };

  /**
   * Root Token
   * 
   * Composite Token, can have children tokens.
   * */
  class RootToken: public Token {
	public:
    RootToken();

    void log() const;
    std::string render() const;
  };

  /**
   * Heading Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class HeadingToken: public Token {
  public:
    HeadingToken(const unsigned int& level, const std::string& text);

    void log() const;
    std::string render() const;
    const unsigned int& level() const;
    const std::string& text() const;

  private:
    unsigned int mLevel;
    std::string mText;
  };

  /**
   * Bold Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class BoldToken: public Token {
  public:
    BoldToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Italic Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class ItalicToken: public Token {
  public:
    ItalicToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Bold & Italic Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class BoldItalicToken: public Token {
  public:
    BoldItalicToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Strikethrough Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class StrikethroughToken: public Token {
  public:
    StrikethroughToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Inline Code Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class InlineCodeToken: public Token {
  public:
    InlineCodeToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Multiline Code Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class MultilineCodeToken: public Token {
  public:
    MultilineCodeToken(const std::string& textWithNewlines);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Quote Token
   * 
   * Composite Token, can have children tokens.
   * */
  class QuoteToken: public Token {
  public:
    QuoteToken(const std::string& text);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Link Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class LinkToken: public Token {
  public:
    LinkToken(const std::string& text, const std::string& link);

    void log() const;
    std::string render() const;
    const std::string& text() const;
    const std::string& link() const;

  private:
    std::string mText, mLink;
  };

  /**
   * Image Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class ImageToken: public Token {
  public:
    ImageToken(const std::string& altText, const std::string& source);

    void log() const;
    std::string render() const;
    const std::string& text() const;
    const std::string& source() const;

  private:
    std::string mText, mSource;
  };

  /**
   * Ordered List Token
   * 
   * Composite Token, can have children tokens.
   * */
  class OrderedListToken: public Token {
  public:
    OrderedListToken();

    void log() const;
    std::string render() const;
  };

  /**
   * Unordered List Token
   * 
   * Composite Token, can have children tokens.
   * */
  class UnorderedListToken: public Token {
  public:
    UnorderedListToken();

    void log() const;
    std::string render() const;
  };

  /**
   * Text Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class TextToken: public Token {
  public:
    TextToken(const std::string& textWithNewlines);

    void log() const;
    std::string render() const;
    const std::string& text() const;

  private:
    std::string mText;
  };

  /**
   * Tab Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class TabToken: public Token {
  public:
    TabToken();

    void log() const;
    std::string render() const;
  };

  /**
   * Newline Token
   * 
   * Atomic Token, cannot have children tokens.
   * */
  class NewlineToken: public Token {
  public:
    NewlineToken();

    void log() const;
    std::string render() const;
  };

};

/**
 * MarkdownParser Namespace
 * Lexer Declaration
 * */
namespace MarkdownParser {

  /**
   * Lexer
   * 
   * */
  class Lexer {
  public:
    Lexer();

    const std::vector<Token*>& parseMarkdownStrToTokens(const std::string& mdStr);
    const std::vector<Token*>& parseMarkdownDocToTokens(const MarkdownDoc& mdDoc);

  private:
    std::vector<Token*> mTokens;
    unsigned long long int mIndex;

    void parseStr(const std::string& source);

    bool isSpecialChar(const char& c);
    void trimWhiteSpaces(std::string& text);

    void handleAsteriskOrUnderscore(const char& c, const std::string& source);

    void handleHash(const std::string& source);
    void handleAsterisk(const std::string& source);
    void handleUnderscore(const std::string& source);
    void handleTilda(const std::string& source);
    void handleBacktick(const std::string& source);
    void handleGreater(const std::string& source);
    void handleOpenSquaredBracket(const std::string& source);
    void handleExclamation(const std::string& source);
    void handleText(const std::string& source);
    void handleTab(const std::string& source);
    void handleNewline(const std::string& source);
  };

};




/**
 * Implementations
 * 
 * */

/**
 * Token Implementations
 * 
 * */
const MarkdownParser::TokenType& MarkdownParser::Token::type() const {
  return this->mType;
}

MarkdownParser::RootToken::RootToken() {
  this->mType = MarkdownParser::TokenType::ROOT;
}
void MarkdownParser::RootToken::log() const {
  std::cout << "<ROOT>";
}
std::string MarkdownParser::RootToken::render() const {
  return "";
}

/**
 * Heading Token Implementations
 * 
 * */
MarkdownParser::HeadingToken::HeadingToken(const unsigned int& level, const std::string& text) {
  if (level<1 || level>6) {
    throw std::runtime_error("Accepted levels for heading tokens: 1-6, but got level: "+std::to_string(level));
  }
  this->mType = MarkdownParser::TokenType::HEADING;
  this->mLevel = level;
  this->mText = text;
}
void MarkdownParser::HeadingToken::log() const {
  std::cout << "<HEADING-" << this->mLevel << ", Text: " << this->mText << ">";
}
std::string MarkdownParser::HeadingToken::render() const {
  std::string s = "<h";
  char levelChar = 48+this->mLevel;
  s.push_back(levelChar);
  s.push_back('>');
  s.append(mText);
  s.append("<h");
  s.push_back(levelChar);
  s.push_back('>');
  return s;
}
const unsigned int& MarkdownParser::HeadingToken::level() const {
  return this->mLevel;
}
const std::string& MarkdownParser::HeadingToken::text() const {
  return this->mText;
}

/**
 * Bold Token Implementations
 * 
 * */
MarkdownParser::BoldToken::BoldToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::BOLD;
  this->mText = text;
}
void MarkdownParser::BoldToken::log() const {
  std::cout << "<BOLD, Text: " << this->mText << ">";
}
std::string MarkdownParser::BoldToken::render() const {
  return "<strong>" + this->mText + "</strong>";
}
const std::string& MarkdownParser::BoldToken::text() const {
  return this->mText;
}

/**
 * Italic Token Implementations
 * 
 * */
MarkdownParser::ItalicToken::ItalicToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::ITALIC;
  this->mText = text;
}
void MarkdownParser::ItalicToken::log() const {
  std::cout << "<ITALIC, Text: " << this->mText << ">";
}
std::string MarkdownParser::ItalicToken::render() const {
  return "<em>" + this->mText + "</em>";
}
const std::string& MarkdownParser::ItalicToken::text() const {
  return this->mText;
}

/**
 * Bold & Italic Token Implementations
 * 
 * */
MarkdownParser::BoldItalicToken::BoldItalicToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::BOLD_ITALIC;
  this->mText = text;
}
void MarkdownParser::BoldItalicToken::log() const {
  std::cout << "<BOLD_ITALIC, Text: " << this->mText << ">";
}
std::string MarkdownParser::BoldItalicToken::render() const {
  return "<em><strong>" + this->mText + "</strong></em>";
}
const std::string& MarkdownParser::BoldItalicToken::text() const {
  return this->mText;
}

/**
 * Strikethrough Token Implementations
 * 
 * */
MarkdownParser::StrikethroughToken::StrikethroughToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::STRIKETHROUGH;
  this->mText = text;
}
void MarkdownParser::StrikethroughToken::log() const {
  std::cout << "<STRIKETHROUGH, Text: " << this->mText << ">";
}
std::string MarkdownParser::StrikethroughToken::render() const {
  return "<del>" + this->mText + "</del>";
}
const std::string& MarkdownParser::StrikethroughToken::text() const {
  return this->mText;
}

/**
 * Inline Code Token Implementations
 * 
 * */
MarkdownParser::InlineCodeToken::InlineCodeToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::INLINE_CODE;
  this->mText = text;
}
void MarkdownParser::InlineCodeToken::log() const {
  std::cout << "<INLINE_CODE, Text: " << this->mText << ">";
}
std::string MarkdownParser::InlineCodeToken::render() const {
  return "<code>" + this->mText + "</code>";
}
const std::string& MarkdownParser::InlineCodeToken::text() const {
  return this->mText;
}

/**
 * Multiline Code Token Implementations
 * 
 * */
MarkdownParser::MultilineCodeToken::MultilineCodeToken(const std::string& textWithNewlines) {
  this->mType = MarkdownParser::TokenType::MULTILINE_CODE;
  this->mText = textWithNewlines;
}
void MarkdownParser::MultilineCodeToken::log() const {
  std::cout << "<MULTILINE_CODE, Text: " << this->mText << ">";
}
std::string MarkdownParser::MultilineCodeToken::render() const {
  return "<pre>" + this->mText + "</pre>";
}
const std::string& MarkdownParser::MultilineCodeToken::text() const {
  return this->mText;
}

/**
 * Quote Token Implementations
 * 
 * */
MarkdownParser::QuoteToken::QuoteToken(const std::string& text) {
  this->mType = MarkdownParser::TokenType::QUOTE;
  this->mText = text;
}
void MarkdownParser::QuoteToken::log() const {
  std::cout << "<QUOTE, Text: " << this->mText << ">";
}
std::string MarkdownParser::QuoteToken::render() const {
  return "<div class=\"quote\">" + this->mText + "</div>";
}
const std::string& MarkdownParser::QuoteToken::text() const {
  return this->mText;
}

/**
 * Link Token Implementations
 * 
 * */
MarkdownParser::LinkToken::LinkToken(const std::string& text, const std::string& link) {
  this->mType = MarkdownParser::TokenType::LINK;
  this->mText = text;
  this->mLink = link;
}
void MarkdownParser::LinkToken::log() const {
  std::cout << "<LINK, Text: " << this->mText << ", Link: " << this->mLink << ">";
}
std::string MarkdownParser::LinkToken::render() const {
  return "<a href=\"" + this->mLink + "\">" + this->mText + "</a>";
}
const std::string& MarkdownParser::LinkToken::text() const {
  return this->mText;
}
const std::string& MarkdownParser::LinkToken::link() const {
  return this->mLink;
}

/**
 * Image Token Implementations
 * 
 * */
MarkdownParser::ImageToken::ImageToken(const std::string& altText, const std::string& source) {
  this->mType = MarkdownParser::TokenType::IMAGE;
  this->mText = altText;
  this->mSource = source;
}
void MarkdownParser::ImageToken::log() const {
  std::cout << "<IMAGE, Text: " << this->mText << ", Source: " << this->mSource << ">";
}
std::string MarkdownParser::ImageToken::render() const {
  return "<img src=\"" + this->mSource + "\" alt=\"" + this->mText + "\">";
}

/**
 * Text Token Implementations
 * 
 * */
MarkdownParser::TextToken::TextToken(const std::string& textWithNewlines) {
  this->mType = MarkdownParser::TokenType::TEXT;
  this->mText = textWithNewlines;
}
void MarkdownParser::TextToken::log() const {
  std::cout << "<TEXT, Text: " << this->mText << ">";
}
std::string MarkdownParser::TextToken::render() const {
  return this->mText;
}
const std::string& MarkdownParser::TextToken::text() const {
  return this->mText;
}

/**
 * Tab Token Implementations
 * 
 * */
MarkdownParser::TabToken::TabToken() {
  this->mType = MarkdownParser::TokenType::TAB;
}
void MarkdownParser::TabToken::log() const {
  std::cout << "<TAB>";
}
std::string MarkdownParser::TabToken::render() const {
  return "\t";
}

/**
 * Newline Token Implementations
 * 
 * */
MarkdownParser::NewlineToken::NewlineToken() {
  this->mType = MarkdownParser::TokenType::NEWLINE;
}
void MarkdownParser::NewlineToken::log() const {
  std::cout << "<NEWLINE>";
}
std::string MarkdownParser::NewlineToken::render() const {
  return "<br>";
}

/**
 * Lexer Implementations
 * 
 * */
MarkdownParser::Lexer::Lexer() {
  this->mTokens.clear();
  this->mIndex = 0;
}
const std::vector<MarkdownParser::Token*>& MarkdownParser::Lexer::parseMarkdownStrToTokens(const std::string& mdStr) {
  this->mTokens.clear();
  this->mIndex = 0;
  this->parseStr(mdStr);
  return this->mTokens;
}
const std::vector<MarkdownParser::Token*>& MarkdownParser::Lexer::parseMarkdownDocToTokens(const MarkdownDoc& mdDoc) {
  this->mTokens.clear();
  this->mIndex = 0;
  for (const std::string& line: mdDoc.text) {
    this->parseStr(line);
    this->mTokens.push_back(new NewlineToken());
    this->mIndex = 0;
  }
  this->mTokens.pop_back();
  return this->mTokens;
}
void MarkdownParser::Lexer::parseStr(const std::string& source) {
  while (this->mIndex < source.size()) {
    this->handleHash(source);
    this->handleAsterisk(source);
    this->handleUnderscore(source);
    this->handleTilda(source);
    this->handleBacktick(source);
    this->handleGreater(source);
    this->handleOpenSquaredBracket(source);
    this->handleExclamation(source);
    this->handleText(source);
    this->handleTab(source);
    this->handleNewline(source);
  }
}
bool MarkdownParser::Lexer::isSpecialChar(const char& c) {
  if (
    c == '#' ||
    c == '*' ||
    c == '_' ||
    c == '~' ||
    c == '`' ||
    c == '>' ||
    c == '[' ||
    c == ']' ||
    c == '!' ||
    c == '\t' ||
    c == '\n'
  ) {
    return true;
  }
  return false;
}
void MarkdownParser::Lexer::trimWhiteSpaces(std::string& text) {
  while (!text.empty() && text.front() == ' ') {
    text.erase(text.begin());
  }
  while(!text.empty() && text.back() == ' ') {
    text.erase(--text.end());
  }
}
void MarkdownParser::Lexer::handleHash(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '#') {
    return;
  }
  // finding level of heading
  unsigned int length = 0;
  while (this->mIndex < source.size() && source[this->mIndex] == '#') {
    this->mIndex++;
    length++;
  }
  // skipping whitespaces
  while (this->mIndex < source.size() && source[this->mIndex] == ' ') {
    this->mIndex++;
  }
  // finding text
  std::string text;
  while (this->mIndex < source.size() && source[this->mIndex] != '\n') {
    text.push_back(source[this->mIndex]);
    this->mIndex++;
  }
  // trimming whitespaces
  // this->trimWhiteSpaces(text);
  this->mTokens.push_back(new HeadingToken(length, text));
}
void MarkdownParser::Lexer::handleAsteriskOrUnderscore(const char& c, const std::string& source) {
  // finding length of opening asterisks
  unsigned int openingAsterisksLength = 0;
  while (this->mIndex < source.size() && source[this->mIndex] == c) {
    this->mIndex++;
    openingAsterisksLength++;
  }
  // finding text
  std::string text;
  while (this->mIndex < source.size() && source[this->mIndex] != c) {
    text.push_back(source[this->mIndex]);
    this->mIndex++;
  }
  // finding length of closing asterisks
  unsigned int closingAsterisksLength = 0;
  while (this->mIndex < source.size() && source[this->mIndex] == c) {
    this->mIndex++;
    closingAsterisksLength++;
  }
  // adding extra asterisks to text
  if (openingAsterisksLength > closingAsterisksLength) {
    for (unsigned int i=0; i<openingAsterisksLength-closingAsterisksLength; i++) {
      text.insert(text.begin(), c);
    }
  }
  else {
    for (unsigned int i=0; i<closingAsterisksLength-openingAsterisksLength; i++) {
      text.push_back(c);
    }
  }
  unsigned int minAsterisks = std::min(openingAsterisksLength, closingAsterisksLength);
  if (minAsterisks >= 3) {
    this->mTokens.push_back(new BoldItalicToken(text));
  }
  else if (minAsterisks >= 2) {
    this->mTokens.push_back(new BoldToken(text));
  }
  else if (minAsterisks >= 1) {
    this->mTokens.push_back(new ItalicToken(text));
  }
  else {
    this->mTokens.push_back(new TextToken(text));
  }
}
void MarkdownParser::Lexer::handleAsterisk(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '*') {
    return;
  }
  this->handleAsteriskOrUnderscore('*', source);
}
void MarkdownParser::Lexer::handleUnderscore(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '_') {
    return;
  }
  this->handleAsteriskOrUnderscore('_', source);
}
void MarkdownParser::Lexer::handleTilda(const std::string& source) {
  if (
    this->mIndex < source.size() &&
    (source[this->mIndex] != '~' || source[this->mIndex+1] != '~')
  ) {
    return;
  }
  this->mIndex++;
  // finding text
  std::string text;
  unsigned long long int i = this->mIndex;
  while (i < source.size() && source[i] != '~') {
    text.push_back(source[i]);
    i++;
  }
  // if it didn't find a matching tilda or found only one tilda
  if (i >= source.size() || source[i+1] != '~') {
    this->mTokens.push_back(new TextToken("~~"));
    return;
  }
  // if it found 2 matching tildas
  this->mIndex = i+1;
  this->mTokens.push_back(new StrikethroughToken(text));
}
void MarkdownParser::Lexer::handleBacktick(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '`') {
    return;
  }
  unsigned int openingBacktickLength = 0;
  while (this->mIndex < source.size() && source[this->mIndex] == '`') {
    openingBacktickLength++;
    this->mIndex++;
  }
  if (openingBacktickLength==2 || openingBacktickLength>3) {
    this->mIndex -= openingBacktickLength;
    this->handleText(source);
    return;
  }
  std::string code;
  while (this->mIndex < source.size() && source[this->mIndex] != '`') {
    code.push_back(source[this->mIndex]);
    this->mIndex++;
  }
  unsigned int closingBacktickLength = 0;
  while (this->mIndex < source.size() && source[this->mIndex] == '`') {
    closingBacktickLength++;
    this->mIndex++;
  }
  if (openingBacktickLength != closingBacktickLength) {
    this->mIndex -= openingBacktickLength+code.size()+closingBacktickLength;
    this->handleText(source);
    return;
  }
  if (openingBacktickLength == 1) {
    this->mTokens.push_back(new InlineCodeToken(code));
  }
  else {
    this->mTokens.push_back(new MultilineCodeToken(code));
  }
}
void MarkdownParser::Lexer::handleGreater(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '>') {
    return;
  }
  // skipping whitespaces
  while (this->mIndex < source.size() && source[this->mIndex] == ' ') {
    this->mIndex++;
  }
  // finding text
  std::string text;
  while (this->mIndex < source.size() && source[this->mIndex] != '\n') {
    text.push_back(source[this->mIndex]);
    this->mIndex++;
  }
  // trimming whitespaces
  this->trimWhiteSpaces(text);
}
void MarkdownParser::Lexer::handleOpenSquaredBracket(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '[') {
    return;
  }
  // TODO
}
void MarkdownParser::Lexer::handleExclamation(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '!') {
    return;
  }
  // TODO
}
void MarkdownParser::Lexer::handleText(const std::string& source) {
  if (this->mIndex < source.size() && this->isSpecialChar(source[this->mIndex])) {
    return;
  }
  std::string text;
  while (this->mIndex < source.size() && !this->isSpecialChar(source[this->mIndex])) {
    text.push_back(source[this->mIndex]);
    this->mIndex++;
  }
  this->mTokens.push_back(new TextToken(text));
}
void MarkdownParser::Lexer::handleTab(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '\t') {
    return;
  }
  this->mTokens.push_back(new TabToken());
}
void MarkdownParser::Lexer::handleNewline(const std::string& source) {
  if (this->mIndex < source.size() && source[this->mIndex] != '\n') {
    return;
  }
  this->mTokens.push_back(new NewlineToken());
}
