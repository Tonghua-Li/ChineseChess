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
signals:
    void chessPiecesChanged();
public slots:

private:
    QList<ChessPiece *> _chessPieces;

    // IBoard interface
public:
    int hasPieceOn(int x, int y) const;

};

#endif // CHESSBOARD_H
