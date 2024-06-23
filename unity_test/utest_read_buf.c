#include "test_get_next_line.h"

int			fd;
char		last;
char		*expect;
char		*expect_buf;
char		*buf;
char		*given;

void	setUp(void)
{
	fd = open("lorem_ipsum.txt", O_RDONLY);
	if (fd == -1)
		TEST_IGNORE_MESSAGE("Could not load file 'lorem_ipsum.txt'.");
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (buf == NULL)
		TEST_IGNORE_MESSAGE("Could not allocate memory to buffer.");
	bzero(buf, BUFFER_SIZE);
	given = NULL;
	last = 0;
}

void	tearDown(void)
{
	if (fd != -1)
		close(fd);
	if (buf != NULL)
		free(buf);
	if (given != NULL)
		free(given);
}

static void	test_read_buf_firstLine(void)
{
	expect = "Lorem ipsum dolor sit amet, consectetur ad";
	expect_buf = "Lorem ipsum dolor sit amet, consectetur ad";
	TEST_ASSERT_EQUAL_PTR(buf, read_buf(buf, &given, &last, fd));
	TEST_ASSERT_EQUAL_MEMORY(expect_buf, buf, BUFFER_SIZE);
	TEST_ASSERT_EQUAL_STRING(expect, given);
	TEST_ASSERT_EQUAL_CHAR('d', last);
}

static void	test_read_buf_secondLine(void)
{
	expect = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
	expect_buf = "Lorem ipsum dolor sit amet, consectetur ad";
	read_buf(buf, &given, &last, fd);
	TEST_ASSERT_EQUAL_MEMORY(expect_buf, buf, BUFFER_SIZE);
	TEST_ASSERT_EQUAL_PTR(buf, read_buf(buf, &given, &last, fd));
	expect_buf = "ipiscing elit.\nor sit amet, consectetur ad";
	TEST_ASSERT_EQUAL_MEMORY(expect_buf, buf, BUFFER_SIZE);
	TEST_ASSERT_EQUAL_STRING(expect, given);
	TEST_ASSERT_EQUAL_CHAR('\n', last);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_read_buf_firstLine);
	RUN_TEST(test_read_buf_secondLine);
	return (UNITY_END());
}
