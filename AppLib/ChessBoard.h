#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "IBoard.h"

#include <QObject>
class ChessBoard : public QObject, public IBoard
{
    Q_OBJECT
public:
    explicit ChessBoard(QObject *parent = nullptr);
    ~ChessBoard();
    QList<ChessPiece *> chessPieces() const;
    void nextPlayer();
    bool canSelect(ChessPiece *piece) const;
    Player getActivePlayer() const;
    Player getPieceOn(int x, int y) const;
signals:
    void chessPiecesChanged();
public slots:

private:
    QList<ChessPiece *> _chessPieces;

    Player _activePlayer;


};

#endif // CHESSBOARD_H
