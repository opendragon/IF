// Generated from /Users/njaffe/git.repositories/IF/InitFile/InitFileParser.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class InitFileParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		TRUE_VALUE=1, FALSE_VALUE=2, NULL_VALUE=3, IPV4_ADDRESS=4, SIGNED_DOUBLE=5, 
		UNSIGNED_DOUBLE=6, SIGNED_INTEGER=7, DOUBLE_Q=8, SINGLE_Q=9, STRING1=10, 
		STRING2=11, STRING3=12, STRING4=13, NAME=14, COMMENT_POUND=15, COMMENT_SLASHES=16, 
		COMMENT_C_STYLE=17, OPEN_CURLY=18, CLOSE_CURLY=19, OPEN_SQUARE=20, CLOSE_SQUARE=21, 
		COMMA=22, COLON=23, WS=24;
	public static final int
		RULE_configuration = 0, RULE_object = 1, RULE_pair = 2, RULE_tag = 3, 
		RULE_value = 4, RULE_addressValue = 5, RULE_stringValue = 6, RULE_doubleValue = 7, 
		RULE_integerValue = 8, RULE_literalValue = 9, RULE_array = 10;
	private static String[] makeRuleNames() {
		return new String[] {
			"configuration", "object", "pair", "tag", "value", "addressValue", "stringValue", 
			"doubleValue", "integerValue", "literalValue", "array"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "'\"'", "'''", null, 
			null, null, null, null, null, null, null, "'{'", "'}'", "'['", "']'", 
			"','", "':'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "TRUE_VALUE", "FALSE_VALUE", "NULL_VALUE", "IPV4_ADDRESS", "SIGNED_DOUBLE", 
			"UNSIGNED_DOUBLE", "SIGNED_INTEGER", "DOUBLE_Q", "SINGLE_Q", "STRING1", 
			"STRING2", "STRING3", "STRING4", "NAME", "COMMENT_POUND", "COMMENT_SLASHES", 
			"COMMENT_C_STYLE", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_SQUARE", "CLOSE_SQUARE", 
			"COMMA", "COLON", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "InitFileParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public InitFileParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ConfigurationContext extends ParserRuleContext {
		public ObjectContext object() {
			return getRuleContext(ObjectContext.class,0);
		}
		public TerminalNode EOF() { return getToken(InitFileParser.EOF, 0); }
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ConfigurationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_configuration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterConfiguration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitConfiguration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitConfiguration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConfigurationContext configuration() throws RecognitionException {
		ConfigurationContext _localctx = new ConfigurationContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_configuration);
		try {
			setState(28);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_CURLY:
				enterOuterAlt(_localctx, 1);
				{
				setState(22);
				object();
				setState(23);
				match(EOF);
				}
				break;
			case OPEN_SQUARE:
				enterOuterAlt(_localctx, 2);
				{
				setState(25);
				array();
				setState(26);
				match(EOF);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ObjectContext extends ParserRuleContext {
		public ObjectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object; }
	 
		public ObjectContext() { }
		public void copyFrom(ObjectContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NonEmptyObjectContext extends ObjectContext {
		public TerminalNode OPEN_CURLY() { return getToken(InitFileParser.OPEN_CURLY, 0); }
		public List<PairContext> pair() {
			return getRuleContexts(PairContext.class);
		}
		public PairContext pair(int i) {
			return getRuleContext(PairContext.class,i);
		}
		public TerminalNode CLOSE_CURLY() { return getToken(InitFileParser.CLOSE_CURLY, 0); }
		public List<TerminalNode> COMMA() { return getTokens(InitFileParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(InitFileParser.COMMA, i);
		}
		public NonEmptyObjectContext(ObjectContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterNonEmptyObject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitNonEmptyObject(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitNonEmptyObject(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class EmptyObjectContext extends ObjectContext {
		public TerminalNode OPEN_CURLY() { return getToken(InitFileParser.OPEN_CURLY, 0); }
		public TerminalNode CLOSE_CURLY() { return getToken(InitFileParser.CLOSE_CURLY, 0); }
		public EmptyObjectContext(ObjectContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterEmptyObject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitEmptyObject(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitEmptyObject(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ObjectContext object() throws RecognitionException {
		ObjectContext _localctx = new ObjectContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_object);
		int _la;
		try {
			int _alt;
			setState(46);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				_localctx = new NonEmptyObjectContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(30);
				match(OPEN_CURLY);
				setState(31);
				pair();
				setState(36);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(32);
						match(COMMA);
						setState(33);
						pair();
						}
						} 
					}
					setState(38);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				}
				setState(40);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(39);
					match(COMMA);
					}
				}

				setState(42);
				match(CLOSE_CURLY);
				}
				break;
			case 2:
				_localctx = new EmptyObjectContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				match(OPEN_CURLY);
				setState(45);
				match(CLOSE_CURLY);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PairContext extends ParserRuleContext {
		public TagContext tag() {
			return getRuleContext(TagContext.class,0);
		}
		public TerminalNode COLON() { return getToken(InitFileParser.COLON, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public PairContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pair; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterPair(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitPair(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitPair(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PairContext pair() throws RecognitionException {
		PairContext _localctx = new PairContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_pair);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			tag();
			setState(49);
			match(COLON);
			setState(50);
			value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TagContext extends ParserRuleContext {
		public Token dq;
		public Token sq;
		public Token na;
		public TerminalNode STRING1() { return getToken(InitFileParser.STRING1, 0); }
		public TerminalNode STRING2() { return getToken(InitFileParser.STRING2, 0); }
		public TerminalNode NAME() { return getToken(InitFileParser.NAME, 0); }
		public TagContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tag; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterTag(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitTag(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitTag(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TagContext tag() throws RecognitionException {
		TagContext _localctx = new TagContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_tag);
		try {
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING1:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				((TagContext)_localctx).dq = match(STRING1);
				}
				break;
			case STRING2:
				enterOuterAlt(_localctx, 2);
				{
				setState(53);
				((TagContext)_localctx).sq = match(STRING2);
				}
				break;
			case NAME:
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				((TagContext)_localctx).na = match(NAME);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ValueContext extends ParserRuleContext {
		public LiteralValueContext literalValue() {
			return getRuleContext(LiteralValueContext.class,0);
		}
		public AddressValueContext addressValue() {
			return getRuleContext(AddressValueContext.class,0);
		}
		public DoubleValueContext doubleValue() {
			return getRuleContext(DoubleValueContext.class,0);
		}
		public IntegerValueContext integerValue() {
			return getRuleContext(IntegerValueContext.class,0);
		}
		public ObjectContext object() {
			return getRuleContext(ObjectContext.class,0);
		}
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public StringValueContext stringValue() {
			return getRuleContext(StringValueContext.class,0);
		}
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_value);
		try {
			setState(64);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE_VALUE:
			case FALSE_VALUE:
			case NULL_VALUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(57);
				literalValue();
				}
				break;
			case IPV4_ADDRESS:
				enterOuterAlt(_localctx, 2);
				{
				setState(58);
				addressValue();
				}
				break;
			case SIGNED_DOUBLE:
				enterOuterAlt(_localctx, 3);
				{
				setState(59);
				doubleValue();
				}
				break;
			case SIGNED_INTEGER:
				enterOuterAlt(_localctx, 4);
				{
				setState(60);
				integerValue();
				}
				break;
			case OPEN_CURLY:
				enterOuterAlt(_localctx, 5);
				{
				setState(61);
				object();
				}
				break;
			case OPEN_SQUARE:
				enterOuterAlt(_localctx, 6);
				{
				setState(62);
				array();
				}
				break;
			case STRING1:
			case STRING2:
			case STRING3:
			case STRING4:
			case NAME:
				enterOuterAlt(_localctx, 7);
				{
				setState(63);
				stringValue();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AddressValueContext extends ParserRuleContext {
		public Token add;
		public TerminalNode IPV4_ADDRESS() { return getToken(InitFileParser.IPV4_ADDRESS, 0); }
		public AddressValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addressValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterAddressValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitAddressValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitAddressValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AddressValueContext addressValue() throws RecognitionException {
		AddressValueContext _localctx = new AddressValueContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_addressValue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			((AddressValueContext)_localctx).add = match(IPV4_ADDRESS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringValueContext extends ParserRuleContext {
		public Token dq;
		public Token sq;
		public Token na;
		public Token edq;
		public Token esq;
		public TerminalNode STRING1() { return getToken(InitFileParser.STRING1, 0); }
		public TerminalNode STRING2() { return getToken(InitFileParser.STRING2, 0); }
		public TerminalNode NAME() { return getToken(InitFileParser.NAME, 0); }
		public TerminalNode STRING3() { return getToken(InitFileParser.STRING3, 0); }
		public TerminalNode STRING4() { return getToken(InitFileParser.STRING4, 0); }
		public StringValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterStringValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitStringValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitStringValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StringValueContext stringValue() throws RecognitionException {
		StringValueContext _localctx = new StringValueContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_stringValue);
		try {
			setState(73);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING1:
				enterOuterAlt(_localctx, 1);
				{
				setState(68);
				((StringValueContext)_localctx).dq = match(STRING1);
				}
				break;
			case STRING2:
				enterOuterAlt(_localctx, 2);
				{
				setState(69);
				((StringValueContext)_localctx).sq = match(STRING2);
				}
				break;
			case NAME:
				enterOuterAlt(_localctx, 3);
				{
				setState(70);
				((StringValueContext)_localctx).na = match(NAME);
				}
				break;
			case STRING3:
				enterOuterAlt(_localctx, 4);
				{
				setState(71);
				((StringValueContext)_localctx).edq = match(STRING3);
				}
				break;
			case STRING4:
				enterOuterAlt(_localctx, 5);
				{
				setState(72);
				((StringValueContext)_localctx).esq = match(STRING4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DoubleValueContext extends ParserRuleContext {
		public Token nu;
		public TerminalNode SIGNED_DOUBLE() { return getToken(InitFileParser.SIGNED_DOUBLE, 0); }
		public DoubleValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_doubleValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterDoubleValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitDoubleValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitDoubleValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DoubleValueContext doubleValue() throws RecognitionException {
		DoubleValueContext _localctx = new DoubleValueContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_doubleValue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(75);
			((DoubleValueContext)_localctx).nu = match(SIGNED_DOUBLE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntegerValueContext extends ParserRuleContext {
		public Token nu;
		public TerminalNode SIGNED_INTEGER() { return getToken(InitFileParser.SIGNED_INTEGER, 0); }
		public IntegerValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integerValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterIntegerValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitIntegerValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitIntegerValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IntegerValueContext integerValue() throws RecognitionException {
		IntegerValueContext _localctx = new IntegerValueContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_integerValue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			((IntegerValueContext)_localctx).nu = match(SIGNED_INTEGER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralValueContext extends ParserRuleContext {
		public Token tv;
		public Token fv;
		public Token nv;
		public TerminalNode TRUE_VALUE() { return getToken(InitFileParser.TRUE_VALUE, 0); }
		public TerminalNode FALSE_VALUE() { return getToken(InitFileParser.FALSE_VALUE, 0); }
		public TerminalNode NULL_VALUE() { return getToken(InitFileParser.NULL_VALUE, 0); }
		public LiteralValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literalValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterLiteralValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitLiteralValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitLiteralValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralValueContext literalValue() throws RecognitionException {
		LiteralValueContext _localctx = new LiteralValueContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_literalValue);
		try {
			setState(82);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE_VALUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(79);
				((LiteralValueContext)_localctx).tv = match(TRUE_VALUE);
				}
				break;
			case FALSE_VALUE:
				enterOuterAlt(_localctx, 2);
				{
				setState(80);
				((LiteralValueContext)_localctx).fv = match(FALSE_VALUE);
				}
				break;
			case NULL_VALUE:
				enterOuterAlt(_localctx, 3);
				{
				setState(81);
				((LiteralValueContext)_localctx).nv = match(NULL_VALUE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayContext extends ParserRuleContext {
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
	 
		public ArrayContext() { }
		public void copyFrom(ArrayContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NonEmptyArrayContext extends ArrayContext {
		public TerminalNode OPEN_SQUARE() { return getToken(InitFileParser.OPEN_SQUARE, 0); }
		public List<ValueContext> value() {
			return getRuleContexts(ValueContext.class);
		}
		public ValueContext value(int i) {
			return getRuleContext(ValueContext.class,i);
		}
		public TerminalNode CLOSE_SQUARE() { return getToken(InitFileParser.CLOSE_SQUARE, 0); }
		public List<TerminalNode> COMMA() { return getTokens(InitFileParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(InitFileParser.COMMA, i);
		}
		public NonEmptyArrayContext(ArrayContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterNonEmptyArray(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitNonEmptyArray(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitNonEmptyArray(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class EmptyArrayContext extends ArrayContext {
		public TerminalNode OPEN_SQUARE() { return getToken(InitFileParser.OPEN_SQUARE, 0); }
		public TerminalNode CLOSE_SQUARE() { return getToken(InitFileParser.CLOSE_SQUARE, 0); }
		public EmptyArrayContext(ArrayContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).enterEmptyArray(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InitFileParserListener ) ((InitFileParserListener)listener).exitEmptyArray(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InitFileParserVisitor ) return ((InitFileParserVisitor<? extends T>)visitor).visitEmptyArray(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_array);
		int _la;
		try {
			int _alt;
			setState(100);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				_localctx = new NonEmptyArrayContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(84);
				match(OPEN_SQUARE);
				setState(85);
				value();
				setState(90);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(86);
						match(COMMA);
						setState(87);
						value();
						}
						} 
					}
					setState(92);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
				}
				setState(94);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(93);
					match(COMMA);
					}
				}

				setState(96);
				match(CLOSE_SQUARE);
				}
				break;
			case 2:
				_localctx = new EmptyArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(98);
				match(OPEN_SQUARE);
				setState(99);
				match(CLOSE_SQUARE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\32i\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4"+
		"\f\t\f\3\2\3\2\3\2\3\2\3\2\3\2\5\2\37\n\2\3\3\3\3\3\3\3\3\7\3%\n\3\f\3"+
		"\16\3(\13\3\3\3\5\3+\n\3\3\3\3\3\3\3\3\3\5\3\61\n\3\3\4\3\4\3\4\3\4\3"+
		"\5\3\5\3\5\5\5:\n\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6C\n\6\3\7\3\7\3\b\3"+
		"\b\3\b\3\b\3\b\5\bL\n\b\3\t\3\t\3\n\3\n\3\13\3\13\3\13\5\13U\n\13\3\f"+
		"\3\f\3\f\3\f\7\f[\n\f\f\f\16\f^\13\f\3\f\5\fa\n\f\3\f\3\f\3\f\3\f\5\f"+
		"g\n\f\3\f\2\2\r\2\4\6\b\n\f\16\20\22\24\26\2\2\2r\2\36\3\2\2\2\4\60\3"+
		"\2\2\2\6\62\3\2\2\2\b9\3\2\2\2\nB\3\2\2\2\fD\3\2\2\2\16K\3\2\2\2\20M\3"+
		"\2\2\2\22O\3\2\2\2\24T\3\2\2\2\26f\3\2\2\2\30\31\5\4\3\2\31\32\7\2\2\3"+
		"\32\37\3\2\2\2\33\34\5\26\f\2\34\35\7\2\2\3\35\37\3\2\2\2\36\30\3\2\2"+
		"\2\36\33\3\2\2\2\37\3\3\2\2\2 !\7\24\2\2!&\5\6\4\2\"#\7\30\2\2#%\5\6\4"+
		"\2$\"\3\2\2\2%(\3\2\2\2&$\3\2\2\2&\'\3\2\2\2\'*\3\2\2\2(&\3\2\2\2)+\7"+
		"\30\2\2*)\3\2\2\2*+\3\2\2\2+,\3\2\2\2,-\7\25\2\2-\61\3\2\2\2./\7\24\2"+
		"\2/\61\7\25\2\2\60 \3\2\2\2\60.\3\2\2\2\61\5\3\2\2\2\62\63\5\b\5\2\63"+
		"\64\7\31\2\2\64\65\5\n\6\2\65\7\3\2\2\2\66:\7\f\2\2\67:\7\r\2\28:\7\20"+
		"\2\29\66\3\2\2\29\67\3\2\2\298\3\2\2\2:\t\3\2\2\2;C\5\24\13\2<C\5\f\7"+
		"\2=C\5\20\t\2>C\5\22\n\2?C\5\4\3\2@C\5\26\f\2AC\5\16\b\2B;\3\2\2\2B<\3"+
		"\2\2\2B=\3\2\2\2B>\3\2\2\2B?\3\2\2\2B@\3\2\2\2BA\3\2\2\2C\13\3\2\2\2D"+
		"E\7\6\2\2E\r\3\2\2\2FL\7\f\2\2GL\7\r\2\2HL\7\20\2\2IL\7\16\2\2JL\7\17"+
		"\2\2KF\3\2\2\2KG\3\2\2\2KH\3\2\2\2KI\3\2\2\2KJ\3\2\2\2L\17\3\2\2\2MN\7"+
		"\7\2\2N\21\3\2\2\2OP\7\t\2\2P\23\3\2\2\2QU\7\3\2\2RU\7\4\2\2SU\7\5\2\2"+
		"TQ\3\2\2\2TR\3\2\2\2TS\3\2\2\2U\25\3\2\2\2VW\7\26\2\2W\\\5\n\6\2XY\7\30"+
		"\2\2Y[\5\n\6\2ZX\3\2\2\2[^\3\2\2\2\\Z\3\2\2\2\\]\3\2\2\2]`\3\2\2\2^\\"+
		"\3\2\2\2_a\7\30\2\2`_\3\2\2\2`a\3\2\2\2ab\3\2\2\2bc\7\27\2\2cg\3\2\2\2"+
		"de\7\26\2\2eg\7\27\2\2fV\3\2\2\2fd\3\2\2\2g\27\3\2\2\2\r\36&*\609BKT\\"+
		"`f";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}