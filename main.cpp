#include "MarkdownParser.hpp"

int main() {

  std::vector<MarkdownParser::Token*> v = {
    new MarkdownParser::RootToken(),
    new MarkdownParser::HeadingToken(1, "Hola")
  };

  v[0]->log();
  v[1]->log();
  
  return 0;
}
