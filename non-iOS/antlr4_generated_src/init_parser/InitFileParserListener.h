
// Generated from /Volumes/Shejidan/git.repositories/IF/non-iOS/../InitFile/InitFileParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "InitFileParser.h"


namespace InitParser {

/**
 * This interface defines an abstract listener for a parse tree produced by InitFileParser.
 */
class  InitFileParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterConfiguration(InitFileParser::ConfigurationContext *ctx) = 0;
  virtual void exitConfiguration(InitFileParser::ConfigurationContext *ctx) = 0;

  virtual void enterNonEmptyObject(InitFileParser::NonEmptyObjectContext *ctx) = 0;
  virtual void exitNonEmptyObject(InitFileParser::NonEmptyObjectContext *ctx) = 0;

  virtual void enterEmptyObject(InitFileParser::EmptyObjectContext *ctx) = 0;
  virtual void exitEmptyObject(InitFileParser::EmptyObjectContext *ctx) = 0;

  virtual void enterPair(InitFileParser::PairContext *ctx) = 0;
  virtual void exitPair(InitFileParser::PairContext *ctx) = 0;

  virtual void enterTag(InitFileParser::TagContext *ctx) = 0;
  virtual void exitTag(InitFileParser::TagContext *ctx) = 0;

  virtual void enterValue(InitFileParser::ValueContext *ctx) = 0;
  virtual void exitValue(InitFileParser::ValueContext *ctx) = 0;

  virtual void enterAddressValue(InitFileParser::AddressValueContext *ctx) = 0;
  virtual void exitAddressValue(InitFileParser::AddressValueContext *ctx) = 0;

  virtual void enterStringValue(InitFileParser::StringValueContext *ctx) = 0;
  virtual void exitStringValue(InitFileParser::StringValueContext *ctx) = 0;

  virtual void enterDoubleValue(InitFileParser::DoubleValueContext *ctx) = 0;
  virtual void exitDoubleValue(InitFileParser::DoubleValueContext *ctx) = 0;

  virtual void enterIntegerValue(InitFileParser::IntegerValueContext *ctx) = 0;
  virtual void exitIntegerValue(InitFileParser::IntegerValueContext *ctx) = 0;

  virtual void enterLiteralValue(InitFileParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(InitFileParser::LiteralValueContext *ctx) = 0;

  virtual void enterNonEmptyArray(InitFileParser::NonEmptyArrayContext *ctx) = 0;
  virtual void exitNonEmptyArray(InitFileParser::NonEmptyArrayContext *ctx) = 0;

  virtual void enterEmptyArray(InitFileParser::EmptyArrayContext *ctx) = 0;
  virtual void exitEmptyArray(InitFileParser::EmptyArrayContext *ctx) = 0;


};

}  // namespace InitParser
