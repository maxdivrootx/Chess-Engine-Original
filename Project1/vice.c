#include "stdio.h"
#include "defs.h"

int main() {
	
	AllInit();

	int index = 0;

	//Demo of sq64 to SQ120 vv
	for (index = 0; index < BRD_SQ_NUM; ++index) {
		if (index % 10 == 0) printf("\n");
		printf("%5d", Sq120toSq64[index]);
	}

	printf("\n");
	printf("\n");

	for (index = 0; index < 64; ++index) {
		if (index % 8 == 0) printf("\n");
		printf("%5d", Sq64toSq120[index]);
	}
	
	U64 playBitBoard = 1ULL;

	printf("\nStart:\n\n");
	PrintBitBoard(playBitBoard);

	playBitBoard |= (1ULL << SQ64(D2));
	printf("D2 Added: \n\n");
	PrintBitBoard(playBitBoard);

	playBitBoard |= (1ULL << SQ64(G2));
	printf("G2 Added: \n\n");
	PrintBitBoard(playBitBoard);



	int count = CNT(playBitBoard);

	printf("Count:%d\n", count);
	
	int sq64 = 0;
	while (playBitBoard) {
		sq64 = POP(&playBitBoard);
		printf("popped:%d\n", sq64);
		PrintBitBoard(playBitBoard);
	}

	for (index = 0; index < 64; index++)
	{
		printf("Index:%d", index);
		PrintBitBoard(SetMask[index]);
		printf("\n");
	}

	


	int	PieceOne = rand();
	int	PieceTwo = rand();
	int	PieceThree = rand();
	int	PieceFour = rand();

	printf("PieceOne:%X\n", PieceOne);
	printf("PieceTwo:%X\n", PieceTwo);
	printf("PieceThree:%X\n", PieceThree);
	printf("PieceFour:%X\n", PieceFour);

	int Key = PieceOne ^ PieceTwo ^ PieceThree ^ PieceFour;
	int TempKey = PieceOne;
	TempKey ^= PieceTwo;
	TempKey ^= PieceThree;
	TempKey ^= PieceFour;

	printf("Key:%X\n", Key);
	printf("TempKey:%X\n",TempKey);

	

	
	

	
	return 1;
}