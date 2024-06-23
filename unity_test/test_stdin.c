#include "test_get_next_line.h"

int			fd;
char		*expect;
char		*given;

void	setUp(void)
{
	fd = 0;
	given = NULL;
}

void	tearDown(void)
{
	if (given != NULL)
		free(given);
}

static void	test_get_next_line_firstLine_basicInput(void)
{
	write(1, "Write: 42Prague\n", 17);
	expect = "42Prague\n";
	given = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expect, given);
}

static void	test_get_next_line_multipleLines(void)
{
	int	i;

	write(1,
			"Write: "
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
			"Nulla bibendum imperdiet urna, "
			"nec volutpat ligula dictum iaculis.\n"
			"Sed quis dignissim mauris.\n",
			159);
	expect = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
	given = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expect, given);
	free(given);
	i = 1;
	while (i++ < 2)
	{
		given = get_next_line(fd);
		free(given);
	}
	expect = "Sed quis dignissim mauris.\n";
	given = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expect, given);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_firstLine_basicInput);
	RUN_TEST(test_get_next_line_multipleLines);
	return (UNITY_END());
}
