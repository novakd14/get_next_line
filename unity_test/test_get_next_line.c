#include "get_next_line_test.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_get_next_line_STDIN(void)
{
	char	*expect;
	char	*given;

	expect = "";
	given = get_next_line(0);
	TEST_ASSERT_EQUAL_STRING(expect, given);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_STDIN);
	return (UNITY_END());
}
