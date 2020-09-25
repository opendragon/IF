// Generated from /Volumes/Shejidan/git.repositories/IF/InitFile/InitFileParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link InitFileParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface InitFileParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link InitFileParser#configuration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConfiguration(InitFileParser.ConfigurationContext ctx);
	/**
	 * Visit a parse tree produced by the {@code nonEmptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonEmptyObject(InitFileParser.NonEmptyObjectContext ctx);
	/**
	 * Visit a parse tree produced by the {@code emptyObject}
	 * labeled alternative in {@link InitFileParser#object}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEmptyObject(InitFileParser.EmptyObjectContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#pair}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPair(InitFileParser.PairContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#tag}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTag(InitFileParser.TagContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValue(InitFileParser.ValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#addressValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddressValue(InitFileParser.AddressValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#stringValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringValue(InitFileParser.StringValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#doubleValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDoubleValue(InitFileParser.DoubleValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#integerValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerValue(InitFileParser.IntegerValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link InitFileParser#literalValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteralValue(InitFileParser.LiteralValueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code nonEmptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonEmptyArray(InitFileParser.NonEmptyArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code emptyArray}
	 * labeled alternative in {@link InitFileParser#array}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEmptyArray(InitFileParser.EmptyArrayContext ctx);
}