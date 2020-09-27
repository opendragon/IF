
// Generated from /Volumes/Shejidan/git.repositories/IF/non-iOS/../InitFile/InitFileLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace InitParser {


class  InitFileLexer : public antlr4::Lexer {
public:
  enum {
    TRUE_VALUE = 1, FALSE_VALUE = 2, NULL_VALUE = 3, IPV4_ADDRESS = 4, SIGNED_DOUBLE = 5,
    UNSIGNED_DOUBLE = 6, SIGNED_INTEGER = 7, DOUBLE_Q = 8, SINGLE_Q = 9,
    STRING1 = 10, STRING2 = 11, STRING3 = 12, STRING4 = 13, NAME = 14, COMMENT_POUND = 15,
    COMMENT_SLASHES = 16, COMMENT_C_STYLE = 17, OPEN_CURLY = 18, CLOSE_CURLY = 19,
    OPEN_SQUARE = 20, CLOSE_SQUARE = 21, COMMA = 22, COLON = 23, WS = 24
  };

  InitFileLexer(antlr4::CharStream *input);
  ~InitFileLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace InitParser
