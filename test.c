#include "get_next_line.h"
#include <fcntl.h> // for open(), O_RDONLY
#include <stdio.h>

void create_test_file(const char *filename, const char *content)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// open is to open/create a file
	// O_WRONLY: open in write only mode
	// O_CREAT: only conducts if the file doesnt exists
	// O_TRUNC: if the file existed, it will be rewritten
	// 0644 permission control
	if(fd == -1)
	{
		perror("error creating test file");
		exit(EXIT_FAILURE);
	}
}

void run_test(const char *filename,int test_num, const char *description)
{
	int fd;
	char *line;
	int line_count = 0;

	printf("\n--- Test %d: %s (File: %s, BUFFER_SIZE = %d) ---\n", test_num, description, filename, BUFFER_SIZE);
	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("Error opening file");
		printf("skipping test %d.\n", test_num);
		return;
	}
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
		{
			printf("EOF OR ERROR");
			break;
		}
		line_count++;
		printf("Line %d: \"%s\"", line_count, line);
		printf("\n");
		free(line);
	}
	printf("--- End of Test %d ---\n", test_num);
	close(fd);
}

void test_multiple_fds(void)
{
	printf("\n---Test: M FDS ---\n");
	int fd1, fd2, fd3;
	char *line1, *line2, *line3;
	int i = 0;

	create_test_file("test_files/fd1.txt", "Line 1.1\nLine 1.2\nLine 1.3\n");
	create_test_file("test_files/fd2.txt", "ABC\nDEF\nGHI\n");
	create_test_file("test_files/fd3.txt", "1\n2\n3\n4\n");

	fd1 = open("test_files/fd1.txt", O_RDONLY);
	fd2 = open("test_files/fd2.txt", O_RDONLY);
	fd3 = open("test_files/fd3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("error in multiple fds check");
		if(fd1 != -1) close (fd1);
		if(fd2 != -1) close (fd2);
		if(fd3 != -1) close (fd3);
		return;

	}

	while(1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if(!line1 && !line2 && !line3)
			break;
		if(line1)
		{
			printf("fd1 Line : \"%s\"\n", line1);
			free(line1);
		}
		if(line2)
		{
			printf("fd2 Line : \"%s\"\n", line2);
			free(line2);
		}
		if(line3)
		{
			printf("fd2 Line : \"%s\"\n", line3);
			free(line3);
		}
	i++;
	if(i > 100)
	{
		printf("too many iterations");
		break;
	}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	printf("--- End of Multiple FD Test ---\n");
}