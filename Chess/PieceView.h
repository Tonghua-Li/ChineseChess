#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QWidget>
#include "ChessPiece.h"
class PieceView : public QWidget
{
    Q_OBJECT
public:
    static const int SIZE = 60;
    explicit PieceView(QWidget *parent, ChessPiece *piece);
    ChessPiece *piece() const;

signals:
    void selected(PieceView *view);
public slots:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    const int PADDING = 5;
    ChessPiece* _piece;
    QBrush _defaultBrush;
    QBrush _currentBrush;
    void select();
    void unselect();
    void movePosition(const QPoint &pos);
};

#endif // PIECEVIEW_H
