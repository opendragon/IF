
// Generated from /Volumes/Shejidan/git.repositories/IF/non-iOS/../InitFile/InitFileParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "InitFileParserListener.h"


namespace InitParser {

/**
 * This class provides an empty implementation of InitFileParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  InitFileParserBaseListener : public InitFileParserListener {
public:

  virtual void enterConfiguration(InitFileParser::ConfigurationContext * /*ctx*/) override { }
  virtual void exitConfiguration(InitFileParser::ConfigurationContext * /*ctx*/) override { }

  virtual void enterNonEmptyObject(InitFileParser::NonEmptyObjectContext * /*ctx*/) override { }
  virtual void exitNonEmptyObject(InitFileParser::NonEmptyObjectContext * /*ctx*/) override { }

  virtual void enterEmptyObject(InitFileParser::EmptyObjectContext * /*ctx*/) override { }
  virtual void exitEmptyObject(InitFileParser::EmptyObjectContext * /*ctx*/) override { }

  virtual void enterPair(InitFileParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(InitFileParser::PairContext * /*ctx*/) override { }

  virtual void enterTag(InitFileParser::TagContext * /*ctx*/) override { }
  virtual void exitTag(InitFileParser::TagContext * /*ctx*/) override { }

  virtual void enterValue(InitFileParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(InitFileParser::ValueContext * /*ctx*/) override { }

  virtual void enterAddressValue(InitFileParser::AddressValueContext * /*ctx*/) override { }
  virtual void exitAddressValue(InitFileParser::AddressValueContext * /*ctx*/) override { }

  virtual void enterStringValue(InitFileParser::StringValueContext * /*ctx*/) override { }
  virtual void exitStringValue(InitFileParser::StringValueContext * /*ctx*/) override { }

  virtual void enterDoubleValue(InitFileParser::DoubleValueContext * /*ctx*/) override { }
  virtual void exitDoubleValue(InitFileParser::DoubleValueContext * /*ctx*/) override { }

  virtual void enterIntegerValue(InitFileParser::IntegerValueContext * /*ctx*/) override { }
  virtual void exitIntegerValue(InitFileParser::IntegerValueContext * /*ctx*/) override { }

  virtual void enterLiteralValue(InitFileParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(InitFileParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterNonEmptyArray(InitFileParser::NonEmptyArrayContext * /*ctx*/) override { }
  virtual void exitNonEmptyArray(InitFileParser::NonEmptyArrayContext * /*ctx*/) override { }

  virtual void enterEmptyArray(InitFileParser::EmptyArrayContext * /*ctx*/) override { }
  virtual void exitEmptyArray(InitFileParser::EmptyArrayContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace InitParser
