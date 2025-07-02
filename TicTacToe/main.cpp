#include <bits/stdc++.h>
using namespace std;

enum PieceType
{
    O,
    X
};

// Base playing piece class
class PlayingPiece
{
    PieceType pieceType;

public:
    PlayingPiece(PieceType pieceType)
    {
        this->pieceType = pieceType;
    }

    PieceType getPieceType()
    {
        return pieceType;
    }
};

class PlayingPieceX : public PlayingPiece
{
public:
    PlayingPieceX() : PlayingPiece(PieceType::X) {}
};

class PlayingPieceO : public PlayingPiece
{
public:
    PlayingPieceO() : PlayingPiece(PieceType::O) {}
};

class Board
{
    int size;
    vector<vector<PlayingPiece *>> board;

public:
    Board(int size)
    {
        this->size = size;
        board.resize(size, vector<PlayingPiece *>(size, nullptr));
    }

    int getSize()
    {
        return this->size;
    }

    PlayingPiece *getPiece(int row, int col)
    {
        return board[row][col];
    }

    bool addPiece(int x, int y, PlayingPiece *playingPiece)
    {
        if (board[x][y] != nullptr && playingPiece != nullptr)
            return false;

        board[x][y] = playingPiece;
        return true;
    }

    int getFreeCells()
    {
        int freeCells = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == nullptr)
                    freeCells++;
            }
        }
        return freeCells;
    }

    void printBoard()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (board[i][j] == nullptr)
                {
                    cout << "- ";
                }
                else if (board[i][j]->getPieceType() == PieceType::X)
                {
                    cout << "X ";
                }
                else
                {
                    cout << "O ";
                }
            }
            cout << endl;
        }
    }
};

class Player
{
    string name;
    PlayingPiece *playingPiece;

public:
    Player(string name, PlayingPiece *playingPiece)
    {
        this->name = name;
        this->playingPiece = playingPiece;
    }

    string getName()
    {
        return this->name;
    }

    PlayingPiece *getPlayingPiece()
    {
        return this->playingPiece;
    }
};

// Move class for undo support
class Move
{
    int row;
    int col;
    PlayingPiece *piece;

public:
    Move(int row, int col, PlayingPiece *piece)
        : row(row), col(col), piece(piece) {}

    int getRow() { return row; }
    int getCol() { return col; }
    PlayingPiece *getPiece() { return piece; }

    void setRow(int r) { this->row = r; }
    void setCol(int c) { this->col = c; }
    void setPiece(PlayingPiece *p) { this->piece = p; }
};

class TicTacToeGame
{
    deque<Player *> players;
    Board *gameBoard;
    stack<Move> moveHistory;

public:
    void initializeGame()
    {
        PlayingPieceX *crossPiece = new PlayingPieceX();
        Player *player1 = new Player("Player1", crossPiece);
        players.push_back(player1);

        PlayingPieceO *zeroPiece = new PlayingPieceO();
        Player *player2 = new Player("Player2", zeroPiece);
        players.push_back(player2);

        gameBoard = new Board(3);
    }

    bool isThereWinner(int row, int col, PieceType pieceType)
    {
        bool rowMatch = true, colMatch = true, diagonalMatch = true, antiDiagonalMatch = true;
        int size = gameBoard->getSize();

        for (int i = 0; i < size; i++)
        {
            if (gameBoard->getPiece(row, i) == nullptr || gameBoard->getPiece(row, i)->getPieceType() != pieceType)
                rowMatch = false;
            if (gameBoard->getPiece(i, col) == nullptr || gameBoard->getPiece(i, col)->getPieceType() != pieceType)
                colMatch = false;
        }

        for (int i = 0; i < size; i++)
        {
            if (gameBoard->getPiece(i, i) == nullptr || gameBoard->getPiece(i, i)->getPieceType() != pieceType)
                diagonalMatch = false;
            if (gameBoard->getPiece(i, size - 1 - i) == nullptr || gameBoard->getPiece(i, size - 1 - i)->getPieceType() != pieceType)
                antiDiagonalMatch = false;
        }

        return rowMatch || colMatch || diagonalMatch || antiDiagonalMatch;
    }

    bool undo()
    {
        if (moveHistory.empty())
            return false;

        Move lastMove = moveHistory.top();
        moveHistory.pop();

        // Remove the last piece from the board
        gameBoard->addPiece(lastMove.getRow(), lastMove.getCol(), nullptr);

        Player *undoPlayer = players.back();
        players.pop_back();
        players.push_front(undoPlayer);
        cout << "Undo successful! " << undoPlayer->getName() << " will play again.\n";
        return true;
    }

    string startGame()
    {
        bool noWinner = true;
        while (noWinner)
        {
            Player *playerTurn = players.front();

            gameBoard->printBoard();

            int freeCells = gameBoard->getFreeCells();
            if (freeCells == 0)
            {
                noWinner = false;
                continue;
            }

            int row, col;
            cout << "Player: " << playerTurn->getName() << " Enter row,col (or -1 -1 to undo): ";
            cin >> row >> col;

            // Handle undo request
            if (row == -1 && col == -1)
            {
                if (!undo())
                {
                    cout << "Nothing to undo!" << endl;
                }
                continue; // ❗ Do not pop
            }

            bool pieceAddedSuccess = gameBoard->addPiece(row, col, playerTurn->getPlayingPiece());
            if (!pieceAddedSuccess)
            {
                cout << "Invalid Position! Try again.\n";
                continue; // ❗ Do not pop
            }
            else
            {
                players.pop_front(); // ✅ Only after valid move
                moveHistory.push(Move(row, col, playerTurn->getPlayingPiece()));
                players.push_back(playerTurn); // rotate turn
            }

            if (isThereWinner(row, col, playerTurn->getPlayingPiece()->getPieceType()))
            {
                gameBoard->printBoard();
                return playerTurn->getName();
            }
        }

        return "Draw";
    }
};
