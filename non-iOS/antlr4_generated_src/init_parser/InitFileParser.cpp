
// Generated from /Volumes/Shejidan/git.repositories/IF/non-iOS/../InitFile/InitFileParser.g4 by ANTLR 4.8


#include "InitFileParserListener.h"

#include "InitFileParser.h"


using namespace antlrcpp;
using namespace InitParser;
using namespace antlr4;

InitFileParser::InitFileParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

InitFileParser::~InitFileParser() {
  delete _interpreter;
}

std::string InitFileParser::getGrammarFileName() const {
  return "InitFileParser.g4";
}

const std::vector<std::string>& InitFileParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& InitFileParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ConfigurationContext ------------------------------------------------------------------

InitFileParser::ConfigurationContext::ConfigurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

InitFileParser::ObjectContext* InitFileParser::ConfigurationContext::object() {
  return getRuleContext<InitFileParser::ObjectContext>(0);
}

tree::TerminalNode* InitFileParser::ConfigurationContext::EOF() {
  return getToken(InitFileParser::EOF, 0);
}

InitFileParser::ArrayContext* InitFileParser::ConfigurationContext::array() {
  return getRuleContext<InitFileParser::ArrayContext>(0);
}


size_t InitFileParser::ConfigurationContext::getRuleIndex() const {
  return InitFileParser::RuleConfiguration;
}

void InitFileParser::ConfigurationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfiguration(this);
}

void InitFileParser::ConfigurationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfiguration(this);
}

InitFileParser::ConfigurationContext* InitFileParser::configuration() {
  ConfigurationContext *_localctx = _tracker.createInstance<ConfigurationContext>(_ctx, getState());
  enterRule(_localctx, 0, InitFileParser::RuleConfiguration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case InitFileParser::OPEN_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(22);
        object();
        setState(23);
        match(InitFileParser::EOF);
        break;
      }

      case InitFileParser::OPEN_SQUARE: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        array();
        setState(26);
        match(InitFileParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

InitFileParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t InitFileParser::ObjectContext::getRuleIndex() const {
  return InitFileParser::RuleObject;
}

void InitFileParser::ObjectContext::copyFrom(ObjectContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NonEmptyObjectContext ------------------------------------------------------------------

tree::TerminalNode* InitFileParser::NonEmptyObjectContext::OPEN_CURLY() {
  return getToken(InitFileParser::OPEN_CURLY, 0);
}

std::vector<InitFileParser::PairContext *> InitFileParser::NonEmptyObjectContext::pair() {
  return getRuleContexts<InitFileParser::PairContext>();
}

InitFileParser::PairContext* InitFileParser::NonEmptyObjectContext::pair(size_t i) {
  return getRuleContext<InitFileParser::PairContext>(i);
}

tree::TerminalNode* InitFileParser::NonEmptyObjectContext::CLOSE_CURLY() {
  return getToken(InitFileParser::CLOSE_CURLY, 0);
}

std::vector<tree::TerminalNode *> InitFileParser::NonEmptyObjectContext::COMMA() {
  return getTokens(InitFileParser::COMMA);
}

tree::TerminalNode* InitFileParser::NonEmptyObjectContext::COMMA(size_t i) {
  return getToken(InitFileParser::COMMA, i);
}

InitFileParser::NonEmptyObjectContext::NonEmptyObjectContext(ObjectContext *ctx) { copyFrom(ctx); }

void InitFileParser::NonEmptyObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonEmptyObject(this);
}
void InitFileParser::NonEmptyObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonEmptyObject(this);
}
//----------------- EmptyObjectContext ------------------------------------------------------------------

tree::TerminalNode* InitFileParser::EmptyObjectContext::OPEN_CURLY() {
  return getToken(InitFileParser::OPEN_CURLY, 0);
}

tree::TerminalNode* InitFileParser::EmptyObjectContext::CLOSE_CURLY() {
  return getToken(InitFileParser::CLOSE_CURLY, 0);
}

InitFileParser::EmptyObjectContext::EmptyObjectContext(ObjectContext *ctx) { copyFrom(ctx); }

void InitFileParser::EmptyObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyObject(this);
}
void InitFileParser::EmptyObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyObject(this);
}
InitFileParser::ObjectContext* InitFileParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 2, InitFileParser::RuleObject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ObjectContext *>(_tracker.createInstance<InitFileParser::NonEmptyObjectContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(30);
      match(InitFileParser::OPEN_CURLY);
      setState(31);
      pair();
      setState(36);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(32);
          match(InitFileParser::COMMA);
          setState(33);
          pair(); 
        }
        setState(38);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(40);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == InitFileParser::COMMA) {
        setState(39);
        match(InitFileParser::COMMA);
      }
      setState(42);
      match(InitFileParser::CLOSE_CURLY);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ObjectContext *>(_tracker.createInstance<InitFileParser::EmptyObjectContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(44);
      match(InitFileParser::OPEN_CURLY);
      setState(45);
      match(InitFileParser::CLOSE_CURLY);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

InitFileParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

InitFileParser::TagContext* InitFileParser::PairContext::tag() {
  return getRuleContext<InitFileParser::TagContext>(0);
}

tree::TerminalNode* InitFileParser::PairContext::COLON() {
  return getToken(InitFileParser::COLON, 0);
}

InitFileParser::ValueContext* InitFileParser::PairContext::value() {
  return getRuleContext<InitFileParser::ValueContext>(0);
}


size_t InitFileParser::PairContext::getRuleIndex() const {
  return InitFileParser::RulePair;
}

void InitFileParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void InitFileParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

InitFileParser::PairContext* InitFileParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 4, InitFileParser::RulePair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    tag();
    setState(49);
    match(InitFileParser::COLON);
    setState(50);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TagContext ------------------------------------------------------------------

InitFileParser::TagContext::TagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::TagContext::STRING1() {
  return getToken(InitFileParser::STRING1, 0);
}

tree::TerminalNode* InitFileParser::TagContext::STRING2() {
  return getToken(InitFileParser::STRING2, 0);
}

tree::TerminalNode* InitFileParser::TagContext::NAME() {
  return getToken(InitFileParser::NAME, 0);
}


size_t InitFileParser::TagContext::getRuleIndex() const {
  return InitFileParser::RuleTag;
}

void InitFileParser::TagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag(this);
}

void InitFileParser::TagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag(this);
}

InitFileParser::TagContext* InitFileParser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 6, InitFileParser::RuleTag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case InitFileParser::STRING1: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        dynamic_cast<TagContext *>(_localctx)->dq = match(InitFileParser::STRING1);
        break;
      }

      case InitFileParser::STRING2: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        dynamic_cast<TagContext *>(_localctx)->sq = match(InitFileParser::STRING2);
        break;
      }

      case InitFileParser::NAME: {
        enterOuterAlt(_localctx, 3);
        setState(54);
        dynamic_cast<TagContext *>(_localctx)->na = match(InitFileParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

InitFileParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

InitFileParser::LiteralValueContext* InitFileParser::ValueContext::literalValue() {
  return getRuleContext<InitFileParser::LiteralValueContext>(0);
}

InitFileParser::AddressValueContext* InitFileParser::ValueContext::addressValue() {
  return getRuleContext<InitFileParser::AddressValueContext>(0);
}

InitFileParser::DoubleValueContext* InitFileParser::ValueContext::doubleValue() {
  return getRuleContext<InitFileParser::DoubleValueContext>(0);
}

InitFileParser::IntegerValueContext* InitFileParser::ValueContext::integerValue() {
  return getRuleContext<InitFileParser::IntegerValueContext>(0);
}

InitFileParser::ObjectContext* InitFileParser::ValueContext::object() {
  return getRuleContext<InitFileParser::ObjectContext>(0);
}

InitFileParser::ArrayContext* InitFileParser::ValueContext::array() {
  return getRuleContext<InitFileParser::ArrayContext>(0);
}

InitFileParser::StringValueContext* InitFileParser::ValueContext::stringValue() {
  return getRuleContext<InitFileParser::StringValueContext>(0);
}


size_t InitFileParser::ValueContext::getRuleIndex() const {
  return InitFileParser::RuleValue;
}

void InitFileParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void InitFileParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

InitFileParser::ValueContext* InitFileParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 8, InitFileParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case InitFileParser::TRUE_VALUE:
      case InitFileParser::FALSE_VALUE:
      case InitFileParser::NULL_VALUE: {
        enterOuterAlt(_localctx, 1);
        setState(57);
        literalValue();
        break;
      }

      case InitFileParser::IPV4_ADDRESS: {
        enterOuterAlt(_localctx, 2);
        setState(58);
        addressValue();
        break;
      }

      case InitFileParser::SIGNED_DOUBLE: {
        enterOuterAlt(_localctx, 3);
        setState(59);
        doubleValue();
        break;
      }

      case InitFileParser::SIGNED_INTEGER: {
        enterOuterAlt(_localctx, 4);
        setState(60);
        integerValue();
        break;
      }

      case InitFileParser::OPEN_CURLY: {
        enterOuterAlt(_localctx, 5);
        setState(61);
        object();
        break;
      }

      case InitFileParser::OPEN_SQUARE: {
        enterOuterAlt(_localctx, 6);
        setState(62);
        array();
        break;
      }

      case InitFileParser::STRING1:
      case InitFileParser::STRING2:
      case InitFileParser::STRING3:
      case InitFileParser::STRING4:
      case InitFileParser::NAME: {
        enterOuterAlt(_localctx, 7);
        setState(63);
        stringValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddressValueContext ------------------------------------------------------------------

InitFileParser::AddressValueContext::AddressValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::AddressValueContext::IPV4_ADDRESS() {
  return getToken(InitFileParser::IPV4_ADDRESS, 0);
}


size_t InitFileParser::AddressValueContext::getRuleIndex() const {
  return InitFileParser::RuleAddressValue;
}

void InitFileParser::AddressValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddressValue(this);
}

void InitFileParser::AddressValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddressValue(this);
}

InitFileParser::AddressValueContext* InitFileParser::addressValue() {
  AddressValueContext *_localctx = _tracker.createInstance<AddressValueContext>(_ctx, getState());
  enterRule(_localctx, 10, InitFileParser::RuleAddressValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    dynamic_cast<AddressValueContext *>(_localctx)->add = match(InitFileParser::IPV4_ADDRESS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringValueContext ------------------------------------------------------------------

InitFileParser::StringValueContext::StringValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::StringValueContext::STRING1() {
  return getToken(InitFileParser::STRING1, 0);
}

tree::TerminalNode* InitFileParser::StringValueContext::STRING2() {
  return getToken(InitFileParser::STRING2, 0);
}

tree::TerminalNode* InitFileParser::StringValueContext::NAME() {
  return getToken(InitFileParser::NAME, 0);
}

tree::TerminalNode* InitFileParser::StringValueContext::STRING3() {
  return getToken(InitFileParser::STRING3, 0);
}

tree::TerminalNode* InitFileParser::StringValueContext::STRING4() {
  return getToken(InitFileParser::STRING4, 0);
}


size_t InitFileParser::StringValueContext::getRuleIndex() const {
  return InitFileParser::RuleStringValue;
}

void InitFileParser::StringValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringValue(this);
}

void InitFileParser::StringValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringValue(this);
}

InitFileParser::StringValueContext* InitFileParser::stringValue() {
  StringValueContext *_localctx = _tracker.createInstance<StringValueContext>(_ctx, getState());
  enterRule(_localctx, 12, InitFileParser::RuleStringValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case InitFileParser::STRING1: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        dynamic_cast<StringValueContext *>(_localctx)->dq = match(InitFileParser::STRING1);
        break;
      }

      case InitFileParser::STRING2: {
        enterOuterAlt(_localctx, 2);
        setState(69);
        dynamic_cast<StringValueContext *>(_localctx)->sq = match(InitFileParser::STRING2);
        break;
      }

      case InitFileParser::NAME: {
        enterOuterAlt(_localctx, 3);
        setState(70);
        dynamic_cast<StringValueContext *>(_localctx)->na = match(InitFileParser::NAME);
        break;
      }

      case InitFileParser::STRING3: {
        enterOuterAlt(_localctx, 4);
        setState(71);
        dynamic_cast<StringValueContext *>(_localctx)->edq = match(InitFileParser::STRING3);
        break;
      }

      case InitFileParser::STRING4: {
        enterOuterAlt(_localctx, 5);
        setState(72);
        dynamic_cast<StringValueContext *>(_localctx)->esq = match(InitFileParser::STRING4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleValueContext ------------------------------------------------------------------

InitFileParser::DoubleValueContext::DoubleValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::DoubleValueContext::SIGNED_DOUBLE() {
  return getToken(InitFileParser::SIGNED_DOUBLE, 0);
}


size_t InitFileParser::DoubleValueContext::getRuleIndex() const {
  return InitFileParser::RuleDoubleValue;
}

void InitFileParser::DoubleValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoubleValue(this);
}

void InitFileParser::DoubleValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoubleValue(this);
}

InitFileParser::DoubleValueContext* InitFileParser::doubleValue() {
  DoubleValueContext *_localctx = _tracker.createInstance<DoubleValueContext>(_ctx, getState());
  enterRule(_localctx, 14, InitFileParser::RuleDoubleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    dynamic_cast<DoubleValueContext *>(_localctx)->nu = match(InitFileParser::SIGNED_DOUBLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerValueContext ------------------------------------------------------------------

InitFileParser::IntegerValueContext::IntegerValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::IntegerValueContext::SIGNED_INTEGER() {
  return getToken(InitFileParser::SIGNED_INTEGER, 0);
}


size_t InitFileParser::IntegerValueContext::getRuleIndex() const {
  return InitFileParser::RuleIntegerValue;
}

void InitFileParser::IntegerValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerValue(this);
}

void InitFileParser::IntegerValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerValue(this);
}

InitFileParser::IntegerValueContext* InitFileParser::integerValue() {
  IntegerValueContext *_localctx = _tracker.createInstance<IntegerValueContext>(_ctx, getState());
  enterRule(_localctx, 16, InitFileParser::RuleIntegerValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    dynamic_cast<IntegerValueContext *>(_localctx)->nu = match(InitFileParser::SIGNED_INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

InitFileParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* InitFileParser::LiteralValueContext::TRUE_VALUE() {
  return getToken(InitFileParser::TRUE_VALUE, 0);
}

tree::TerminalNode* InitFileParser::LiteralValueContext::FALSE_VALUE() {
  return getToken(InitFileParser::FALSE_VALUE, 0);
}

tree::TerminalNode* InitFileParser::LiteralValueContext::NULL_VALUE() {
  return getToken(InitFileParser::NULL_VALUE, 0);
}


size_t InitFileParser::LiteralValueContext::getRuleIndex() const {
  return InitFileParser::RuleLiteralValue;
}

void InitFileParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void InitFileParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

InitFileParser::LiteralValueContext* InitFileParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 18, InitFileParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case InitFileParser::TRUE_VALUE: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        dynamic_cast<LiteralValueContext *>(_localctx)->tv = match(InitFileParser::TRUE_VALUE);
        break;
      }

      case InitFileParser::FALSE_VALUE: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        dynamic_cast<LiteralValueContext *>(_localctx)->fv = match(InitFileParser::FALSE_VALUE);
        break;
      }

      case InitFileParser::NULL_VALUE: {
        enterOuterAlt(_localctx, 3);
        setState(81);
        dynamic_cast<LiteralValueContext *>(_localctx)->nv = match(InitFileParser::NULL_VALUE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

InitFileParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t InitFileParser::ArrayContext::getRuleIndex() const {
  return InitFileParser::RuleArray;
}

void InitFileParser::ArrayContext::copyFrom(ArrayContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NonEmptyArrayContext ------------------------------------------------------------------

tree::TerminalNode* InitFileParser::NonEmptyArrayContext::OPEN_SQUARE() {
  return getToken(InitFileParser::OPEN_SQUARE, 0);
}

std::vector<InitFileParser::ValueContext *> InitFileParser::NonEmptyArrayContext::value() {
  return getRuleContexts<InitFileParser::ValueContext>();
}

InitFileParser::ValueContext* InitFileParser::NonEmptyArrayContext::value(size_t i) {
  return getRuleContext<InitFileParser::ValueContext>(i);
}

tree::TerminalNode* InitFileParser::NonEmptyArrayContext::CLOSE_SQUARE() {
  return getToken(InitFileParser::CLOSE_SQUARE, 0);
}

std::vector<tree::TerminalNode *> InitFileParser::NonEmptyArrayContext::COMMA() {
  return getTokens(InitFileParser::COMMA);
}

tree::TerminalNode* InitFileParser::NonEmptyArrayContext::COMMA(size_t i) {
  return getToken(InitFileParser::COMMA, i);
}

InitFileParser::NonEmptyArrayContext::NonEmptyArrayContext(ArrayContext *ctx) { copyFrom(ctx); }

void InitFileParser::NonEmptyArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonEmptyArray(this);
}
void InitFileParser::NonEmptyArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonEmptyArray(this);
}
//----------------- EmptyArrayContext ------------------------------------------------------------------

tree::TerminalNode* InitFileParser::EmptyArrayContext::OPEN_SQUARE() {
  return getToken(InitFileParser::OPEN_SQUARE, 0);
}

tree::TerminalNode* InitFileParser::EmptyArrayContext::CLOSE_SQUARE() {
  return getToken(InitFileParser::CLOSE_SQUARE, 0);
}

InitFileParser::EmptyArrayContext::EmptyArrayContext(ArrayContext *ctx) { copyFrom(ctx); }

void InitFileParser::EmptyArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyArray(this);
}
void InitFileParser::EmptyArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<InitFileParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyArray(this);
}
InitFileParser::ArrayContext* InitFileParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 20, InitFileParser::RuleArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ArrayContext *>(_tracker.createInstance<InitFileParser::NonEmptyArrayContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(84);
      match(InitFileParser::OPEN_SQUARE);
      setState(85);
      value();
      setState(90);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(86);
          match(InitFileParser::COMMA);
          setState(87);
          value(); 
        }
        setState(92);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == InitFileParser::COMMA) {
        setState(93);
        match(InitFileParser::COMMA);
      }
      setState(96);
      match(InitFileParser::CLOSE_SQUARE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ArrayContext *>(_tracker.createInstance<InitFileParser::EmptyArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(98);
      match(InitFileParser::OPEN_SQUARE);
      setState(99);
      match(InitFileParser::CLOSE_SQUARE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> InitFileParser::_decisionToDFA;
atn::PredictionContextCache InitFileParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN InitFileParser::_atn;
std::vector<uint16_t> InitFileParser::_serializedATN;

std::vector<std::string> InitFileParser::_ruleNames = {
  "configuration", "object", "pair", "tag", "value", "addressValue", "stringValue", 
  "doubleValue", "integerValue", "literalValue", "array"
};

std::vector<std::string> InitFileParser::_literalNames = {
  "", "", "", "", "", "", "", "", "'\"'", "'''", "", "", "", "", "", "", 
  "", "", "'{'", "'}'", "'['", "']'", "','", "':'"
};

std::vector<std::string> InitFileParser::_symbolicNames = {
  "", "TRUE_VALUE", "FALSE_VALUE", "NULL_VALUE", "IPV4_ADDRESS", "SIGNED_DOUBLE", 
  "UNSIGNED_DOUBLE", "SIGNED_INTEGER", "DOUBLE_Q", "SINGLE_Q", "STRING1", 
  "STRING2", "STRING3", "STRING4", "NAME", "COMMENT_POUND", "COMMENT_SLASHES", 
  "COMMENT_C_STYLE", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_SQUARE", "CLOSE_SQUARE", 
  "COMMA", "COLON", "WS"
};

dfa::Vocabulary InitFileParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> InitFileParser::_tokenNames;

InitFileParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1a, 0x69, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x1f, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x25, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x28, 0xb, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3a, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x43, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x4c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x55, 0xa, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x5b, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x5e, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x61, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x67, 0xa, 0xc, 0x3, 0xc, 0x2, 0x2, 
    0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 
    0x2, 0x2, 0x72, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x32, 0x3, 0x2, 0x2, 0x2, 0x8, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x42, 0x3, 0x2, 0x2, 0x2, 0xc, 0x44, 0x3, 0x2, 0x2, 0x2, 0xe, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x54, 0x3, 0x2, 0x2, 0x2, 0x16, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x19, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1a, 0x7, 0x2, 0x2, 
    0x3, 0x1a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x16, 0xc, 0x2, 
    0x1c, 0x1d, 0x7, 0x2, 0x2, 0x3, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0x14, 0x2, 0x2, 0x21, 0x26, 0x5, 
    0x6, 0x4, 0x2, 0x22, 0x23, 0x7, 0x18, 0x2, 0x2, 0x23, 0x25, 0x5, 0x6, 
    0x4, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x2b, 0x7, 0x18, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 
    0x15, 0x2, 0x2, 0x2d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x14, 
    0x2, 0x2, 0x2f, 0x31, 0x7, 0x15, 0x2, 0x2, 0x30, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x33, 0x5, 0x8, 0x5, 0x2, 0x33, 0x34, 0x7, 0x19, 0x2, 0x2, 0x34, 
    0x35, 0x5, 0xa, 0x6, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3a, 
    0x7, 0xc, 0x2, 0x2, 0x37, 0x3a, 0x7, 0xd, 0x2, 0x2, 0x38, 0x3a, 0x7, 
    0x10, 0x2, 0x2, 0x39, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x43, 0x5, 0x14, 0xb, 0x2, 0x3c, 0x43, 0x5, 0xc, 0x7, 0x2, 
    0x3d, 0x43, 0x5, 0x10, 0x9, 0x2, 0x3e, 0x43, 0x5, 0x12, 0xa, 0x2, 0x3f, 
    0x43, 0x5, 0x4, 0x3, 0x2, 0x40, 0x43, 0x5, 0x16, 0xc, 0x2, 0x41, 0x43, 
    0x5, 0xe, 0x8, 0x2, 0x42, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x45, 0x7, 0x6, 0x2, 0x2, 0x45, 0xd, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x4c, 0x7, 0xc, 0x2, 0x2, 0x47, 0x4c, 0x7, 0xd, 0x2, 0x2, 0x48, 0x4c, 
    0x7, 0x10, 0x2, 0x2, 0x49, 0x4c, 0x7, 0xe, 0x2, 0x2, 0x4a, 0x4c, 0x7, 
    0xf, 0x2, 0x2, 0x4b, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x7, 0x7, 0x2, 0x2, 0x4e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x9, 0x2, 0x2, 0x50, 0x13, 0x3, 0x2, 0x2, 0x2, 0x51, 0x55, 
    0x7, 0x3, 0x2, 0x2, 0x52, 0x55, 0x7, 0x4, 0x2, 0x2, 0x53, 0x55, 0x7, 
    0x5, 0x2, 0x2, 0x54, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0x16, 0x2, 0x2, 0x57, 0x5c, 0x5, 0xa, 0x6, 0x2, 
    0x58, 0x59, 0x7, 0x18, 0x2, 0x2, 0x59, 0x5b, 0x5, 0xa, 0x6, 0x2, 0x5a, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x7, 0x18, 
    0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x17, 0x2, 0x2, 
    0x63, 0x67, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x16, 0x2, 0x2, 0x65, 
    0x67, 0x7, 0x17, 0x2, 0x2, 0x66, 0x56, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd, 0x1e, 0x26, 
    0x2a, 0x30, 0x39, 0x42, 0x4b, 0x54, 0x5c, 0x60, 0x66, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

InitFileParser::Initializer InitFileParser::_init;
