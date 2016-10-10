typedef enum piece
{
	EMPTY = 0,
	PAWN = 1,
	KNIGHT = 3,
	BISHOP = 3,
	ROOK = 5,
	QUEEN = 9,
	KING = 200
} Piece;


typedef enum color
{
	BLACK,
	WHITE
} Color;


typedef struct square
{
	Piece piece;
	Color color;
} Square;


Square board[8][8] = { {(Square){EMPTY, BLACK}} };

void initialize_board()
{
	for (int i = 0; i < 8; ++i) {
		board[1][i].piece = PAWN; 
		board[0][i].color = BLACK; 
		board[1][i].color = BLACK; 
		board[6][i].piece = PAWN; 
		board[7][i].color = WHITE; 
		board[6][i].color = WHITE; 
		for (int j = 2; j < 5; ++j) {
			board[i][j].piece = EMPTY;
			board[i][j].color = BLACK;
		}
	}
	board[0][0].piece = ROOK;
	board[0][7].piece = ROOK;
	board[7][0].piece = ROOK;
	board[7][7].piece = ROOK;
	board[0][1].piece = KNIGHT;
	board[0][6].piece = KNIGHT;
	board[7][1].piece = KNIGHT;
	board[7][6].piece = KNIGHT;
	board[0][2].piece = BISHOP;
	board[0][5].piece = BISHOP;
	board[7][2].piece = BISHOP;
	board[7][5].piece = BISHOP;
	board[0][3].piece = QUEEN;
	board[0][4].piece = KING;
	board[7][3].piece = QUEEN;
	board[7][4].piece = KING;
}
