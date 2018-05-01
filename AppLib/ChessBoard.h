#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"

#include <QObject>

class ChessBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<ChessPiece*> chessPieces READ getChessPieces NOTIFY chessPiecesChanged)
public:
    explicit ChessBoard(QObject *parent = nullptr);
    QList<ChessPiece*> getChessPieces () const { return _chessPieces; }

signals:
    void chessPiecesChanged();
public slots:

private:
     QList<ChessPiece*> _chessPieces;
};

#endif // CHESSBOARD_H
