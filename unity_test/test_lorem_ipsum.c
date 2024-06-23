#include "test_get_next_line.h"

int			fd;
char		*expect;
char		*given;

void	setUp(void)
{
	fd = open("lorem_ipsum.txt", O_RDONLY);
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
	expect = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
	given = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expect, given);
}

static void	test_get_next_line_thirdLine(void)
{
	int	i;

	expect = "Sed quis dignissim mauris.\n";
	i = 0;
	while (i++ < 2)
	{
		given = get_next_line(fd);
		free(given);
	}
	given = get_next_line(fd);
	TEST_ASSERT_EQUAL_STRING(expect, given);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line_firstLine);
	RUN_TEST(test_get_next_line_thirdLine);
	return (UNITY_END());
}
