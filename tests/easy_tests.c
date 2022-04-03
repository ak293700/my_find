#include <criterion/criterion.h>
#include <unistd.h>

#include "../src/main.h"

Test(Basics, not_a_test)
{
    cr_assert_eq(1, 1);
}
