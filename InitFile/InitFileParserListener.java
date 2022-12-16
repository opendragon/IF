// Generated from /Users/njaffe/git.repositories/IF/InitFile/InitFileParser.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link InitFileParser}.
 */
public interface InitFileParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link InitFileParser#configuration}.
	 * @param ctx the parse tree
	 */
	void enterConfiguration(InitFileParser.ConfigurationContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#configuration}.
	 * @param ctx the parse tree
	 */
	void exitConfiguration(InitFileParser.ConfigurationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code nonEmptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 */
	void enterNonEmptyObject(InitFileParser.NonEmptyObjectContext ctx);
	/**
	 * Exit a parse tree produced by the {@code nonEmptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 */
	void exitNonEmptyObject(InitFileParser.NonEmptyObjectContext ctx);
	/**
	 * Enter a parse tree produced by the {@code emptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 */
	void enterEmptyObject(InitFileParser.EmptyObjectContext ctx);
	/**
	 * Exit a parse tree produced by the {@code emptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 */
	void exitEmptyObject(InitFileParser.EmptyObjectContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#pair}.
	 * @param ctx the parse tree
	 */
	void enterPair(InitFileParser.PairContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#pair}.
	 * @param ctx the parse tree
	 */
	void exitPair(InitFileParser.PairContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#tag}.
	 * @param ctx the parse tree
	 */
	void enterTag(InitFileParser.TagContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#tag}.
	 * @param ctx the parse tree
	 */
	void exitTag(InitFileParser.TagContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#value}.
	 * @param ctx the parse tree
	 */
	void enterValue(InitFileParser.ValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#value}.
	 * @param ctx the parse tree
	 */
	void exitValue(InitFileParser.ValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#addressValue}.
	 * @param ctx the parse tree
	 */
	void enterAddressValue(InitFileParser.AddressValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#addressValue}.
	 * @param ctx the parse tree
	 */
	void exitAddressValue(InitFileParser.AddressValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#stringValue}.
	 * @param ctx the parse tree
	 */
	void enterStringValue(InitFileParser.StringValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#stringValue}.
	 * @param ctx the parse tree
	 */
	void exitStringValue(InitFileParser.StringValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#doubleValue}.
	 * @param ctx the parse tree
	 */
	void enterDoubleValue(InitFileParser.DoubleValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#doubleValue}.
	 * @param ctx the parse tree
	 */
	void exitDoubleValue(InitFileParser.DoubleValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#integerValue}.
	 * @param ctx the parse tree
	 */
	void enterIntegerValue(InitFileParser.IntegerValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#integerValue}.
	 * @param ctx the parse tree
	 */
	void exitIntegerValue(InitFileParser.IntegerValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link InitFileParser#literalValue}.
	 * @param ctx the parse tree
	 */
	void enterLiteralValue(InitFileParser.LiteralValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link InitFileParser#literalValue}.
	 * @param ctx the parse tree
	 */
	void exitLiteralValue(InitFileParser.LiteralValueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code nonEmptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 */
	void enterNonEmptyArray(InitFileParser.NonEmptyArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code nonEmptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 */
	void exitNonEmptyArray(InitFileParser.NonEmptyArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code emptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 */
	void enterEmptyArray(InitFileParser.EmptyArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code emptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 */
	void exitEmptyArray(InitFileParser.EmptyArrayContext ctx);
}