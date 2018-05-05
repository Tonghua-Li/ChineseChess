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
    void select(ChessPiece *piece);
    bool isAttack(ChessPiece* piece) const;
    void attack(ChessPiece *a, ChessPiece *b);
    Player getActivePlayer() const;
    Player getPieceOn(int x, int y) const;
    void moveSelectedTo(const QPoint &pos);
    ChessPiece* getSelected() const;
    void onPieceClicked(ChessPiece *piece);
signals:
    void chessPiecesChanged();
public slots:

private:
    ChessPiece *getPiece(int x, int y) const;
    QList<ChessPiece *> _chessPieces;

    Player _activePlayer;


};

#endif // CHESSBOARD_H
