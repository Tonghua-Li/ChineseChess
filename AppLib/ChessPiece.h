#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "IBoard.h"

#include "Player.h"
#include <QObject>
#include <QPoint>

class ChessPiece : public QObject
{
    Q_OBJECT
public:
    explicit ChessPiece(QObject *parent, Player player, const QString &letter);
    QPoint position() const { return _position; }
    void setPosition(const QPoint &position) { _position = position; }
    void setPosition(int x, int y);
    Player player() const { return _player; }
    QString letter() const { return _letter; }
    virtual bool canMoveTo(const IBoard *board, int x, int y) const = 0;

signals:
    void positionChanged();
public slots:

protected:
    QPoint _position;
    Player _player;
    QString _letter;
};

#endif // CHESSPIECE_H
