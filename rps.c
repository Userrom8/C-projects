#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int, int);
void display(int);

int main(int argc, char *argv[])
{
	int nor, input, n, p, su = 0, sc = 0;
	char ch;
	srand(time(0));
	do
	{
		su = 0, sc = 0;
		do
		{
			fflush(stdin);
			printf("How many rounds do you wanna play ?\n");
			scanf("%d", &nor);
			ch = getchar();
			if (ch != '\n')
				printf("Please enter a valid number !\n");
		} while (ch != '\n');
		printf("Let's start !!\n\n");
		for (int i = 0; i < nor; i++)
		{
			printf("\t\tRound %d :\nEnter '1' for rock, '2' for scissor and '3' for paper : ", i + 1);
			do
			{
				fflush(stdin);
				scanf("%d", &input);
				ch = getchar();
				if (ch != '\n' || input > 3 || input < 1)
					printf("Please enter a number between '1' and '3' : ");
			} while (ch != '\n' || input > 3 || input < 1);
			n = input - 1;
			printf("\n\nYou have played ");
			display(n);
			p = rand() % 3;
			printf("\nI play ");
			display(p);
			if (!game(n, p))
			{
				printf(" \n\nYou lost !");
				sc++;
			}
			else if (game(n, p) == 1)
			{
				printf("\n\nYou won !");
				su++;
			}
			else
				printf("\n\nIt's a draw !");
			printf("\nscore : %d(you) - %d(me)\n\n", su, sc);
		}
		if (su > sc)
			printf("\tCONGRATULATIONS, YOU ARE THE WINNER !!!\n\none more ?\n(y/n) :\n");
		else if (sc > su)
			printf("Better luck next time !\n\none more ?\n(y/n) :\n");
		else
			printf("rematch ?!\n(y/n) :\n");
		fflush(stdin);
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');
	printf("\n\tHave a good day.%c\n\t:)\n", ch);

	return 0;
}

int game(int x, int a)
{
	if (a != 2)
	{
		if (x != 2)
		{
			if (a < x)
				return (0);
			else if (a > x)
				return (1);
		}
		else if (a == 0)
			return (1);
		else if (a == 1)
			return (0);
	}
	else if (x == 0)
		return (0);
	else if (x == 1)
		return (1);

	return 2;
}

void display(int y)
{
	if (y == 0)
		printf("rock");
	else if (y == 1)
		printf("scissor");
	else
		printf("paper");
	printf(" !");
}