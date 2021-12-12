#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	const char *face;
	const char *suit
}Card;

void fillDeck(Card * const wDesk, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main() {
	Card deck[52];
	const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
	const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	srand(time(0));
	fillDeck(deck, face, suit);
	shuffle(deck);
}
void fillDeck(Card * const wDesk, const char * wFace[], const char * wSuit[]) {
	for (int i = 0; i <= 51; i++) {
		wDesk[i].face = wFace[i % 13];
		wDesk[i].suit = wFace[i / 13];
	}
}
void shuffle(Card * const wDeck) {
	int j;
	Card temp;
	for (int i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
void deal(const Card * const wDeck) {
	for (int i = 0; i <= 51; i++) {
		printf("%5s of %-8s%s ", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "  " : "\n");
	}
}