#include "Bing.h"

Bing::Bing(QObject *parent, Player player, int x, int y):
    ChessPiece(parent, player, "兵", x, y)
{

}

bool Bing::canMoveTo(const IBoard *board, int x, int y) const
{
    auto player = this->player();
    auto destPlayer=board->getPlayer(x, y);
    auto currentX = _position.x();
    auto currentY = _position.y();
    bool passRiver=isPassRiver(currentY);
    if(destPlayer==player){
        return false;
    }
    if(!passRiver){
        if(currentX!=x){return false;}
        if(abs(currentY-y)!=1){return false;}
        return isForward(y);
    }
    else{
        if(currentY==y){
            return abs(currentX-x)==1;
        }
        else{
            if(abs(currentY-y)!=1){return false;}
            if(currentX!=x){return false;}
            return isForward(y);
        }
    }
    return false;
}
