// Generated from /Users/njaffe/git.repositories/IF/InitFile/InitFileLexer.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class InitFileLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"TRUE_VALUE", "FALSE_VALUE", "NULL_VALUE", "IPV4_ADDRESS", "INT3", "SIGNED_DOUBLE", 
			"UNSIGNED_DOUBLE", "DIGIT", "INT", "EXP", "SIGN", "SIGNED_INTEGER", "DOUBLE_Q", 
			"SINGLE_Q", "STRING1", "STRING2", "STRING3", "STRING4", "ESC1", "ESC2", 
			"UNICODE", "HEX", "SAFE_CODE_POINT1", "SAFE_CODE_POINT2", "NAME", "COMMENT_POUND", 
			"COMMENT_SLASHES", "COMMENT_C_STYLE", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_SQUARE", 
			"CLOSE_SQUARE", "COMMA", "COLON", "WS"
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


	public InitFileLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "InitFileLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\32\u0111\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\4\3\4\3\4\3\4\3\4\3\5\5\5[\n\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\6\3\6\3\6\5\6h\n\6\5\6j\n\6\3\7\5\7m\n\7\3\7\3\7\3\b\3\b\3\b\7\bt\n\b"+
		"\f\b\16\bw\13\b\3\b\5\bz\n\b\3\b\3\b\3\b\5\b\177\n\b\3\b\3\b\3\b\5\b\u0084"+
		"\n\b\3\t\3\t\3\n\6\n\u0089\n\n\r\n\16\n\u008a\3\13\3\13\5\13\u008f\n\13"+
		"\3\13\3\13\3\f\3\f\3\r\5\r\u0096\n\r\3\r\3\r\3\16\3\16\3\17\3\17\3\20"+
		"\3\20\3\20\6\20\u00a1\n\20\r\20\16\20\u00a2\3\20\3\20\3\21\3\21\3\21\6"+
		"\21\u00aa\n\21\r\21\16\21\u00ab\3\21\3\21\3\22\3\22\3\22\3\23\3\23\3\23"+
		"\3\24\3\24\3\24\5\24\u00b9\n\24\3\25\3\25\3\25\5\25\u00be\n\25\3\26\3"+
		"\26\3\26\3\26\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32\7\32\u00ce"+
		"\n\32\f\32\16\32\u00d1\13\32\3\33\3\33\7\33\u00d5\n\33\f\33\16\33\u00d8"+
		"\13\33\3\33\6\33\u00db\n\33\r\33\16\33\u00dc\3\33\3\33\3\34\3\34\3\34"+
		"\3\34\7\34\u00e5\n\34\f\34\16\34\u00e8\13\34\3\34\6\34\u00eb\n\34\r\34"+
		"\16\34\u00ec\3\34\3\34\3\35\3\35\3\35\3\35\7\35\u00f5\n\35\f\35\16\35"+
		"\u00f8\13\35\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\37\3\37\3 \3 \3!\3!"+
		"\3\"\3\"\3#\3#\3$\6$\u010c\n$\r$\16$\u010d\3$\3$\5\u00d6\u00e6\u00f6\2"+
		"%\3\3\5\4\7\5\t\6\13\2\r\7\17\b\21\2\23\2\25\2\27\2\31\t\33\n\35\13\37"+
		"\f!\r#\16%\17\'\2)\2+\2-\2/\2\61\2\63\20\65\21\67\229\23;\24=\25?\26A"+
		"\27C\30E\31G\32\3\2\26\4\2VVvv\4\2TTtt\4\2WWww\4\2GGgg\4\2HHhh\4\2CCc"+
		"c\4\2NNnn\4\2UUuu\4\2PPpp\3\2\62;\4\2--//\13\2$$\61\61^^ddhhppttvvxx\13"+
		"\2))\61\61^^ddhhppttvvxx\5\2\62;CHch\5\2\2!$$^^\5\2\2!))^^\4\2C\\c|\6"+
		"\2\62;C\\aac|\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2\u011e\2\3\3\2\2\2\2\5"+
		"\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\31\3\2\2\2"+
		"\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2"+
		"\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2"+
		"\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\3I\3\2\2\2"+
		"\5N\3\2\2\2\7T\3\2\2\2\tZ\3\2\2\2\13d\3\2\2\2\rl\3\2\2\2\17\u0083\3\2"+
		"\2\2\21\u0085\3\2\2\2\23\u0088\3\2\2\2\25\u008c\3\2\2\2\27\u0092\3\2\2"+
		"\2\31\u0095\3\2\2\2\33\u0099\3\2\2\2\35\u009b\3\2\2\2\37\u009d\3\2\2\2"+
		"!\u00a6\3\2\2\2#\u00af\3\2\2\2%\u00b2\3\2\2\2\'\u00b5\3\2\2\2)\u00ba\3"+
		"\2\2\2+\u00bf\3\2\2\2-\u00c5\3\2\2\2/\u00c7\3\2\2\2\61\u00c9\3\2\2\2\63"+
		"\u00cb\3\2\2\2\65\u00d2\3\2\2\2\67\u00e0\3\2\2\29\u00f0\3\2\2\2;\u00fe"+
		"\3\2\2\2=\u0100\3\2\2\2?\u0102\3\2\2\2A\u0104\3\2\2\2C\u0106\3\2\2\2E"+
		"\u0108\3\2\2\2G\u010b\3\2\2\2IJ\t\2\2\2JK\t\3\2\2KL\t\4\2\2LM\t\5\2\2"+
		"M\4\3\2\2\2NO\t\6\2\2OP\t\7\2\2PQ\t\b\2\2QR\t\t\2\2RS\t\5\2\2S\6\3\2\2"+
		"\2TU\t\n\2\2UV\t\4\2\2VW\t\b\2\2WX\t\b\2\2X\b\3\2\2\2Y[\7B\2\2ZY\3\2\2"+
		"\2Z[\3\2\2\2[\\\3\2\2\2\\]\5\13\6\2]^\7\60\2\2^_\5\13\6\2_`\7\60\2\2`"+
		"a\5\13\6\2ab\7\60\2\2bc\5\13\6\2c\n\3\2\2\2di\5\21\t\2eg\5\21\t\2fh\5"+
		"\21\t\2gf\3\2\2\2gh\3\2\2\2hj\3\2\2\2ie\3\2\2\2ij\3\2\2\2j\f\3\2\2\2k"+
		"m\5\27\f\2lk\3\2\2\2lm\3\2\2\2mn\3\2\2\2no\5\17\b\2o\16\3\2\2\2pq\5\23"+
		"\n\2qu\7\60\2\2rt\5\21\t\2sr\3\2\2\2tw\3\2\2\2us\3\2\2\2uv\3\2\2\2vy\3"+
		"\2\2\2wu\3\2\2\2xz\5\25\13\2yx\3\2\2\2yz\3\2\2\2z\u0084\3\2\2\2{|\7\60"+
		"\2\2|~\5\23\n\2}\177\5\25\13\2~}\3\2\2\2~\177\3\2\2\2\177\u0084\3\2\2"+
		"\2\u0080\u0081\5\23\n\2\u0081\u0082\5\25\13\2\u0082\u0084\3\2\2\2\u0083"+
		"p\3\2\2\2\u0083{\3\2\2\2\u0083\u0080\3\2\2\2\u0084\20\3\2\2\2\u0085\u0086"+
		"\t\13\2\2\u0086\22\3\2\2\2\u0087\u0089\5\21\t\2\u0088\u0087\3\2\2\2\u0089"+
		"\u008a\3\2\2\2\u008a\u0088\3\2\2\2\u008a\u008b\3\2\2\2\u008b\24\3\2\2"+
		"\2\u008c\u008e\t\5\2\2\u008d\u008f\5\27\f\2\u008e\u008d\3\2\2\2\u008e"+
		"\u008f\3\2\2\2\u008f\u0090\3\2\2\2\u0090\u0091\5\23\n\2\u0091\26\3\2\2"+
		"\2\u0092\u0093\t\f\2\2\u0093\30\3\2\2\2\u0094\u0096\5\27\f\2\u0095\u0094"+
		"\3\2\2\2\u0095\u0096\3\2\2\2\u0096\u0097\3\2\2\2\u0097\u0098\5\23\n\2"+
		"\u0098\32\3\2\2\2\u0099\u009a\7$\2\2\u009a\34\3\2\2\2\u009b\u009c\7)\2"+
		"\2\u009c\36\3\2\2\2\u009d\u00a0\5\33\16\2\u009e\u00a1\5\'\24\2\u009f\u00a1"+
		"\5/\30\2\u00a0\u009e\3\2\2\2\u00a0\u009f\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2"+
		"\u00a0\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3\u00a4\3\2\2\2\u00a4\u00a5\5\33"+
		"\16\2\u00a5 \3\2\2\2\u00a6\u00a9\5\35\17\2\u00a7\u00aa\5)\25\2\u00a8\u00aa"+
		"\5\61\31\2\u00a9\u00a7\3\2\2\2\u00a9\u00a8\3\2\2\2\u00aa\u00ab\3\2\2\2"+
		"\u00ab\u00a9\3\2\2\2\u00ab\u00ac\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ae"+
		"\5\35\17\2\u00ae\"\3\2\2\2\u00af\u00b0\5\33\16\2\u00b0\u00b1\5\33\16\2"+
		"\u00b1$\3\2\2\2\u00b2\u00b3\5\35\17\2\u00b3\u00b4\5\35\17\2\u00b4&\3\2"+
		"\2\2\u00b5\u00b8\7^\2\2\u00b6\u00b9\t\r\2\2\u00b7\u00b9\5+\26\2\u00b8"+
		"\u00b6\3\2\2\2\u00b8\u00b7\3\2\2\2\u00b9(\3\2\2\2\u00ba\u00bd\7^\2\2\u00bb"+
		"\u00be\t\16\2\2\u00bc\u00be\5+\26\2\u00bd\u00bb\3\2\2\2\u00bd\u00bc\3"+
		"\2\2\2\u00be*\3\2\2\2\u00bf\u00c0\7w\2\2\u00c0\u00c1\5-\27\2\u00c1\u00c2"+
		"\5-\27\2\u00c2\u00c3\5-\27\2\u00c3\u00c4\5-\27\2\u00c4,\3\2\2\2\u00c5"+
		"\u00c6\t\17\2\2\u00c6.\3\2\2\2\u00c7\u00c8\n\20\2\2\u00c8\60\3\2\2\2\u00c9"+
		"\u00ca\n\21\2\2\u00ca\62\3\2\2\2\u00cb\u00cf\t\22\2\2\u00cc\u00ce\t\23"+
		"\2\2\u00cd\u00cc\3\2\2\2\u00ce\u00d1\3\2\2\2\u00cf\u00cd\3\2\2\2\u00cf"+
		"\u00d0\3\2\2\2\u00d0\64\3\2\2\2\u00d1\u00cf\3\2\2\2\u00d2\u00d6\7%\2\2"+
		"\u00d3\u00d5\13\2\2\2\u00d4\u00d3\3\2\2\2\u00d5\u00d8\3\2\2\2\u00d6\u00d7"+
		"\3\2\2\2\u00d6\u00d4\3\2\2\2\u00d7\u00da\3\2\2\2\u00d8\u00d6\3\2\2\2\u00d9"+
		"\u00db\t\24\2\2\u00da\u00d9\3\2\2\2\u00db\u00dc\3\2\2\2\u00dc\u00da\3"+
		"\2\2\2\u00dc\u00dd\3\2\2\2\u00dd\u00de\3\2\2\2\u00de\u00df\b\33\2\2\u00df"+
		"\66\3\2\2\2\u00e0\u00e1\7\61\2\2\u00e1\u00e2\7\61\2\2\u00e2\u00e6\3\2"+
		"\2\2\u00e3\u00e5\13\2\2\2\u00e4\u00e3\3\2\2\2\u00e5\u00e8\3\2\2\2\u00e6"+
		"\u00e7\3\2\2\2\u00e6\u00e4\3\2\2\2\u00e7\u00ea\3\2\2\2\u00e8\u00e6\3\2"+
		"\2\2\u00e9\u00eb\t\24\2\2\u00ea\u00e9\3\2\2\2\u00eb\u00ec\3\2\2\2\u00ec"+
		"\u00ea\3\2\2\2\u00ec\u00ed\3\2\2\2\u00ed\u00ee\3\2\2\2\u00ee\u00ef\b\34"+
		"\2\2\u00ef8\3\2\2\2\u00f0\u00f1\7\61\2\2\u00f1\u00f2\7,\2\2\u00f2\u00f6"+
		"\3\2\2\2\u00f3\u00f5\13\2\2\2\u00f4\u00f3\3\2\2\2\u00f5\u00f8\3\2\2\2"+
		"\u00f6\u00f7\3\2\2\2\u00f6\u00f4\3\2\2\2\u00f7\u00f9\3\2\2\2\u00f8\u00f6"+
		"\3\2\2\2\u00f9\u00fa\7,\2\2\u00fa\u00fb\7\61\2\2\u00fb\u00fc\3\2\2\2\u00fc"+
		"\u00fd\b\35\2\2\u00fd:\3\2\2\2\u00fe\u00ff\7}\2\2\u00ff<\3\2\2\2\u0100"+
		"\u0101\7\177\2\2\u0101>\3\2\2\2\u0102\u0103\7]\2\2\u0103@\3\2\2\2\u0104"+
		"\u0105\7_\2\2\u0105B\3\2\2\2\u0106\u0107\7.\2\2\u0107D\3\2\2\2\u0108\u0109"+
		"\7<\2\2\u0109F\3\2\2\2\u010a\u010c\t\25\2\2\u010b\u010a\3\2\2\2\u010c"+
		"\u010d\3\2\2\2\u010d\u010b\3\2\2\2\u010d\u010e\3\2\2\2\u010e\u010f\3\2"+
		"\2\2\u010f\u0110\b$\2\2\u0110H\3\2\2\2\33\2Zgiluy~\u0083\u008a\u008e\u0095"+
		"\u00a0\u00a2\u00a9\u00ab\u00b8\u00bd\u00cf\u00d6\u00dc\u00e6\u00ec\u00f6"+
		"\u010d\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}