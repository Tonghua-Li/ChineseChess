#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "IBoard.h"

#include <QObject>
#include <QPoint>

class ChessPiece : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_INVOKABLE bool canMoveTo(int x, int y);
public:
    explicit ChessPiece(QObject *parent = nullptr);
    QPoint getPosition() const {return _position;}
    void setPosition(const QPoint &position) {_position = position;}
    virtual bool CanMoveTo(const IBoard *board, int x, int y) const;
signals:
    void positionChanged();
public slots:

protected:
    QPoint _position;
};

#endif // CHESSPIECE_H
