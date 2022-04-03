#include "main.h"

int main(int argc, char *argv[])
{
    // Do this because we do not care the first arg
    argc--;
    argv++;

    int frontier = delimit_arg(argc, argv, is_starting_point);

    struct ast *ast = build_ast(argc - frontier, argv + frontier);
    // ast_print(ast);

    if (frontier == 0)
        ls(".", ast);
    else
    {
        for (int i = 0; i < frontier; i++)
            ls(argv[i], ast);
    }

    ast_free(ast);

    return 0;
}
