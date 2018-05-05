#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include "PieceView.h"
#include "WayPoint.h"
#include "ChessBoard.h"
class BoardView : public QWidget
{
    Q_OBJECT
public:
    explicit BoardView(QWidget *parent = nullptr);
    static const int HEIGHT = 11 * (PieceView::SIZE);
    static const int WIDTH = 10* (PieceView::SIZE);
signals:

public slots:
    void onPieceViewClicked(PieceView *pieceView);
    void onWayPointClicked(WayPoint *wayPoint);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private:
    void drawBackground(QPainter &painter, const QBrush &brush);
    void createWayPoints();
    void refreshBoard();


    const int V_LINE_COUNT = 9;
    const int H_LINE_COUNT = 10;
    QList<WayPoint*> _wayPoints;
    QList<PieceView*> _pieceViews;

    ChessBoard* _board;

    bool TryShowWinner();
};

#endif // BOARDVIEW_H
