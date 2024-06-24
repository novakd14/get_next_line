#include "test_get_next_line.h"

int			fd;
char		*expect;
char		*given;

void	setUp(void)
{
	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
		TEST_IGNORE_MESSAGE("Could not load file 'lorem_ipsum.txt'.");
	given = NULL;
}

void	tearDown(void)
{
	if (fd != -1)
		close(fd);
	if (given != NULL)
		free(given);
}

static void	test_get_next_line_firstLine(void)
{
	given = get_next_line(fd);
	TEST_ASSERT_NULL(given);
}

static void	test_get_next_line_secondLine(void)
{
	int	i;

	expect = NULL;
	i = 0;
	while (i++ < 1)
		given = get_next_line(fd);
	given = get_next_line(fd);
	TEST_ASSERT_NULL(given);
}

static void	test_get_next_line_thirdLine(void)
{
	int	i;

	expect = NULL;
	i = 0;
	while (i++ < 2)
		given = get_next_line(fd);
	given = get_next_line(fd);
	TEST_ASSERT_NULL(given);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_firstLine);
	RUN_TEST(test_get_next_line_secondLine);
	RUN_TEST(test_get_next_line_thirdLine);
	return (UNITY_END());
}
