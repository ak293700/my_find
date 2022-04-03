#include "ast_evaluation.h"

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    if (b == 0)
        errx(1, "Division by zero not allowed!");
    return a / b;
}

int eval_expr(struct my_expr *expr)
{
    static int (*func_opt[])(int, int) = { [EXPR_ADDITION] = add,
                                           [EXPR_SUBTRACTION] = sub,
                                           [EXPR_MULTIPLICATION] = mul,
                                           [EXPR_DIVISION] = div };

    if (expr->type == EXPR_NUMBER) // Number
        return expr->data.value;

    if (expr->type == EXPR_NEGATION) // Compute left then return neg
        return -eval_expr(expr->data.children.left);

    // Else compute any operation
    int a = eval_expr(expr->data.children.left);
    int b = eval_expr(expr->data.children.right);
    return func_opt[expr->type](a, b);
}
