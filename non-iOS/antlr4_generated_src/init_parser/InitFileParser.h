
// Generated from /Volumes/Shejidan/git.repositories/IF/non-iOS/../InitFile/InitFileParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace InitParser {


class  InitFileParser : public antlr4::Parser {
public:
  enum {
    TRUE_VALUE = 1, FALSE_VALUE = 2, NULL_VALUE = 3, IPV4_ADDRESS = 4, SIGNED_DOUBLE = 5, 
    UNSIGNED_DOUBLE = 6, SIGNED_INTEGER = 7, DOUBLE_Q = 8, SINGLE_Q = 9, 
    STRING1 = 10, STRING2 = 11, STRING3 = 12, STRING4 = 13, NAME = 14, COMMENT_POUND = 15, 
    COMMENT_SLASHES = 16, COMMENT_C_STYLE = 17, OPEN_CURLY = 18, CLOSE_CURLY = 19, 
    OPEN_SQUARE = 20, CLOSE_SQUARE = 21, COMMA = 22, COLON = 23, WS = 24
  };

  enum {
    RuleConfiguration = 0, RuleObject = 1, RulePair = 2, RuleTag = 3, RuleValue = 4, 
    RuleAddressValue = 5, RuleStringValue = 6, RuleDoubleValue = 7, RuleIntegerValue = 8, 
    RuleLiteralValue = 9, RuleArray = 10
  };

  InitFileParser(antlr4::TokenStream *input);
  ~InitFileParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ConfigurationContext;
  class ObjectContext;
  class PairContext;
  class TagContext;
  class ValueContext;
  class AddressValueContext;
  class StringValueContext;
  class DoubleValueContext;
  class IntegerValueContext;
  class LiteralValueContext;
  class ArrayContext; 

  class  ConfigurationContext : public antlr4::ParserRuleContext {
  public:
    ConfigurationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjectContext *object();
    antlr4::tree::TerminalNode *EOF();
    ArrayContext *array();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigurationContext* configuration();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ObjectContext() = default;
    void copyFrom(ObjectContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NonEmptyObjectContext : public ObjectContext {
  public:
    NonEmptyObjectContext(ObjectContext *ctx);

    antlr4::tree::TerminalNode *OPEN_CURLY();
    std::vector<PairContext *> pair();
    PairContext* pair(size_t i);
    antlr4::tree::TerminalNode *CLOSE_CURLY();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EmptyObjectContext : public ObjectContext {
  public:
    EmptyObjectContext(ObjectContext *ctx);

    antlr4::tree::TerminalNode *OPEN_CURLY();
    antlr4::tree::TerminalNode *CLOSE_CURLY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ObjectContext* object();

  class  PairContext : public antlr4::ParserRuleContext {
  public:
    PairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagContext *tag();
    antlr4::tree::TerminalNode *COLON();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PairContext* pair();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *dq = nullptr;;
    antlr4::Token *sq = nullptr;;
    antlr4::Token *na = nullptr;;
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING1();
    antlr4::tree::TerminalNode *STRING2();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TagContext* tag();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralValueContext *literalValue();
    AddressValueContext *addressValue();
    DoubleValueContext *doubleValue();
    IntegerValueContext *integerValue();
    ObjectContext *object();
    ArrayContext *array();
    StringValueContext *stringValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValueContext* value();

  class  AddressValueContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *add = nullptr;;
    AddressValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IPV4_ADDRESS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddressValueContext* addressValue();

  class  StringValueContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *dq = nullptr;;
    antlr4::Token *sq = nullptr;;
    antlr4::Token *na = nullptr;;
    antlr4::Token *edq = nullptr;;
    antlr4::Token *esq = nullptr;;
    StringValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING1();
    antlr4::tree::TerminalNode *STRING2();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING3();
    antlr4::tree::TerminalNode *STRING4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringValueContext* stringValue();

  class  DoubleValueContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nu = nullptr;;
    DoubleValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIGNED_DOUBLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DoubleValueContext* doubleValue();

  class  IntegerValueContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nu = nullptr;;
    IntegerValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIGNED_INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntegerValueContext* integerValue();

  class  LiteralValueContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *tv = nullptr;;
    antlr4::Token *fv = nullptr;;
    antlr4::Token *nv = nullptr;;
    LiteralValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE_VALUE();
    antlr4::tree::TerminalNode *FALSE_VALUE();
    antlr4::tree::TerminalNode *NULL_VALUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralValueContext* literalValue();

  class  ArrayContext : public antlr4::ParserRuleContext {
  public:
    ArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArrayContext() = default;
    void copyFrom(ArrayContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NonEmptyArrayContext : public ArrayContext {
  public:
    NonEmptyArrayContext(ArrayContext *ctx);

    antlr4::tree::TerminalNode *OPEN_SQUARE();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *CLOSE_SQUARE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EmptyArrayContext : public ArrayContext {
  public:
    EmptyArrayContext(ArrayContext *ctx);

    antlr4::tree::TerminalNode *OPEN_SQUARE();
    antlr4::tree::TerminalNode *CLOSE_SQUARE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ArrayContext* array();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace InitParser
