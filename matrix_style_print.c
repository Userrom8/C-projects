#include <stdio.h>
#include <time.h>
// recommend delay time : 25
#define DELAY_t 25

void delay(int n_s)
{
	int ms = 1000 * n_s;
	clock_t start_time = clock();
	while (clock() < start_time + ms)
		;
}

void append(char *s, char c)
{
	int i = 0;
	while (s[i])
		i++;
	s[i] = c;
	s[++i] = '\0';
}

void print(char *c, char *str)
{
	int i, j = 0;
	if ((int)c[j] < 65)
	{
		if (c[j + 1])
		{
			append(str, c[j]);
			print(c + 1, str);
		}
		else
		{
			append(str, c[j]);
			printf("%s", str);
		}
	}
	else
	{
		for (i = 65; i <= (int)c[j]; i++)
		{
			if ((int)c[j] > 90 && (int)c[j] < 97)
			{
				delay(DELAY_t);
				printf("%s%c\n", str, (char)i);
			}
			else if (i < 91 || i > 96)
			{
				delay(DELAY_t);
				printf("%s%c\n", str, (char)i);
			}
			if (i == (int)c[j] && c[j + 1])
			{
				append(str, c[j]);
				print(c + 1, str);
			}
		}
	}
}

void matrix_print(char *string)
{
	int i = 0;
	while (string[i])
		i++;
	char s[i + 1];
	print(string, s);
}

int main()
{
	matrix_print("Hello World ! my name is Userrom...up for a coffee ^_^ ?");
	return 0;
}