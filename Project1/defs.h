#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

/*Define Debug(for ASSERTION )*/
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) {
printf("%s - Failed", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf(" At Line %d ", __LINE__); \
exit(1);

}


#endif // !1


#define NAME "vice 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

typedef unsigned long long U64;

    enum {
    EMPTY, wP, wN, WB, WR, wQ, WK, bP, DN, BB, DR, bQ, BK
    };

    enum { WHITE, BLACK, BOTH };
    enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE
    };
    enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
    enum {
        A1 = 21, B1, C1, D1, E1, F1, G1, H1,
        A2 = 31, B2, C2, D2, E2, F2, G2, H2,
        A3 = 41, B3, C3, D3, E3, F3, G3, H3,
        A4 = 51, B4, C4, D4, E4, F4, G4, H4,
        A5 = 61, B5, C5, D5, E5, F5, G5, H5,
        A6 = 71, B6, C6, D6, E6, F6, G6, H6,
        A7 = 81, B7, C7, D7, E7, F7, G7, H7,
        A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD
    };



    enum { FALSE, TRUE };

    enum {WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8};

    typedef struct {
        int move;
        int castlePerm;
        int enPas;
        int fiftyMove;
        U64 poskey;

    } S_UNDO;
    
    typedef struct {
        int pieces[BRD_SQ_NUM];
        U64 pawns[3];

        int KingSq[2];

        int side; //side to move
        int enPas;//en Passant square
        int fiftyMove;//rule

        int ply;//half moves
        int hisPly;//total half moves

        U64 posKey; // unique key for each position
        
        int castlePerm;

        int pceNum[13];
        int bigPce[3];//pieces bigger than pawns
        int majPce[3];//pieces like queen and rooks
        int minPce[3];//pieces like bishops and knights
        
        S_UNDO history[MAXGAMEMOVES];

    } S_BOARD;

    // piece list
    int pList[13][10];

    /* GLOBALS */   
    extern int Sq120toSq64[BRD_SQ_NUM];
    extern int Sq64toSq120[64];
    extern U64 SetMask[64];
    extern U64 ClearMask[64];
    U64 PieceKeys[13][120];
    U64 SideKey;
    U64 CastleKeys[16];

    

    /* FUNCTIONS */

    //init.c
    extern void AllInit();



    //bitboards.c
    extern void PrintBitBoard(U64 bb);
    extern int PopBit(U64* bb);
    extern int CountBits(U64 b);
    
    //hashkeys.c
    extern U64 GeneratePosKey(const S_BOARD* pos);

    //boards.c
    extern void ResetBoard(S_BOARD* pos);


    /* MACROS*/
    #define FR2SQ(f,r) ((21 + (f)) + ((r)*10))
    #define SQ64(sq120) Sq120toSq64[sq120]
    #define SQ120(sq64) (Sq64ToSq120[(sq64)])
    #define POP(b) PopBit(b)
    #define CNT(b) CountBits(b)
    

    

#endif // !DEFS_H

