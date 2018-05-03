#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "IBoard.h"

#include <QObject>
#include <QtQml/qqmllist.h>

class ChessBoard : public QObject, public IBoard
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<ChessPiece> chessPieces READ getChessPieces NOTIFY chessPiecesChanged)
public:
    explicit ChessBoard(QObject *parent = nullptr);

    QQmlListProperty<ChessPiece> getChessPieces () {
        return QQmlListProperty<ChessPiece>(this, _chessPieces);
    }

signals:
    void chessPiecesChanged();
public slots:

private:
     QList<ChessPiece*> _chessPieces;

     // IBoard interface
public:
     bool HasChessPiece(int x, int y) const{return true;}
};

#endif // CHESSBOARD_H
