#ifndef __AST_UNARY_OPERATOR_NODE_H
#define __AST_UNARY_OPERATOR_NODE_H

#include "AST/expression.hpp"
#include "visitor/AstNodeVisitor.hpp"
// VER.Heart-Under-Blade
class UnaryOperatorNode : public ExpressionNode {
public:
	UnaryOperatorNode(const uint32_t line, const uint32_t col,
		const char *op_type, ExpressionNode *operand);
	~UnaryOperatorNode() = default;

	const char *getOperatorCString() const { return op.c_str(); }
	void accept(AstNodeVisitor &p_visitor) override { p_visitor.visit(*this); }
	void visitChildNodes(AstNodeVisitor &p_visitor);
private:
	const std::string op; // operator
	ExpressionNode *opd; // operand
};

#endif
