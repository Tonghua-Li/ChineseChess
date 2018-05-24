#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "IBoard.h"
#include "Shuai.h"

#include <QObject>
class ChessBoard : public QObject, public IBoard
{
    Q_OBJECT
public:
    explicit ChessBoard(QObject *parent = nullptr);
    ~ChessBoard();
    void reset();
    QList<ChessPiece *> chessPieces() const;
    void nextPlayer();
    bool canSelect(ChessPiece *piece) const;
    void select(ChessPiece *piece);
    bool isAttack(ChessPiece *piece) const;
    void attack(ChessPiece *a, ChessPiece *b);
    Player getWinner() const;
    Player getActivePlayer() const;
    Player getPlayer(int x, int y) const;
    bool isShuai(int x, int y) const;
    bool isCrossRiver(Player player, int y) const;
    void moveSelectedTo(const QPoint &pos);
    ChessPiece *getSelected() const;
    void onPieceClicked(ChessPiece *piece);
    int getPieceId(int x, int y) const;
    bool isInsidePalace(Player player,int x, int y) const;
signals:
    void chessPiecesChanged();
public slots:

private:
    ChessPiece *getPiece(int x, int y) const;
    QList<ChessPiece *> _chessPieces;

    Player _activePlayer;
    Shuai *_blackShuai;
    Shuai *_redShuai;
};

#endif // CHESSBOARD_H
