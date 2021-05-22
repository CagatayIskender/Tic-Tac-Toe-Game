#include <stdio.h>
#include <stdlib.h>
void atama(char[], int, char);
int kontrol(char[],int);
void yazdirma(char[], int, char, int);
int main()
{
	int x=0, z=0;
	while (z == 0)
	{
		char  p = 'X';
		int y = 1;
		char s[9] = { '1','2','3','4','5','6','7','8','9' };
		while (z != 1)
		{
			system("@cls||clear");

			yazdirma(s, y, p, z);
			atama(s, x, p);

			z = kontrol(s,z);
			

			if (z != 1)
			{
				if (y == 1)
				{
					p = 'O';
					y = 2;
				}
				else
				{
					p = 'X';
					y = 1;
				}
			}
		}
		system("@cls||clear");
		yazdirma(s, y, p, z);
		scanf_s("%d", &z);
	}
	return 0;
}
void atama(char s[], int x, char p)
{
	while (1)
	{
		scanf_s("%d", &x);
		if (s[x - 1] == 'X' || s[x - 1] == 'O') 
		{
			printf("The number is filled. Please select a different number\n");
		}
		else
		{
			s[x - 1] = p;
			break;
		}
	}

}
int kontrol(char s[], int z)
{
	int n = 0, y;
	char x = 'X';
	for (y = 0; y != 2; y += 1)
	{
		for (n = 0; n != 9; n += 3)
		{
			if (s[n] == x && s[n + 1] == x && s[n + 2] == x)
			{
				z = 1;
			}
		}
		for (n = 0; n != 3; n += 1)
		{
			if (s[n] == x && s[n + 3] == x && s[n + 6] == x)
			{
				z = 1;
			}
		}
		if (s[0] == x && s[4] == x && s[8] == x)
		{
			z = 1;
		}
		else if (s[2] == x && s[4] == x && s[6] == x)
		{
			z = 1;
		}
		x = 'O';
	}
	return z;
}
void yazdirma(char s[], int y, char p, int z)
{
	int x;
	for (x = 1; x < 10; x++)
	{
		printf("  %c  ",s[x-1]);
		if (x % 3 != 0)
			printf("|");
		if (x % 3 == 0 && x!=9)
			printf("\n----- ----- -----\n");
	}
	printf("\n Player %d--> ", y);
	if (z != 1)
		printf("%c\n Select a number than press enter:\n ", p);
	else
		printf("WON\n Press 0 to restart, Press 1 to exit\n");
}