#ifndef CHESSPIECE_H
#define CHESSPIECE_H

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
signals:
    void positionChanged();
public slots:

private:
    QPoint _position;
};

#endif // CHESSPIECE_H
