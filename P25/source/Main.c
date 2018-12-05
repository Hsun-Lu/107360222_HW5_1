#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);

int main(void)
{
	const char *suit[4] = { "¬õ¤ß","¤è¶ô","±öªá","¶Â®ç" };
	const char *face[13] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	int deck[4][13] = { 0 };

	srand(time(0));

	shuffle(deck);
	deal(deck, face, suit);

	system("pause");
	return 0;
}

void shuffle(int wDeck[][13])
{
	int row, column, card;

	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int row, column, card;

	for (card = 0; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card) printf("%5s %-8s%c", wSuit[row], wFace[column], card % 2 == 0 ? '\n' : '\t');
			}
		}
	}
}