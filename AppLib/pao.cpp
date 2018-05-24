#include "pao.h"
#include<math.h>

Pao::Pao(QObject *parent, Player player, int x, int y)
    : ChessPiece(parent, player, "泡", x, y,4)
{}

bool Pao::canMoveTo(const IBoard *board, int x, int y) const
{
    auto currentX = _position.x();
    auto currentY = _position.y();
    auto player = this->player();
    auto destplayer=board->getPlayer(x,y);
    if (destplayer==player) {
        return false;
    }
    if(currentX!=x && currentY!=y){return false;}
    if(abs(currentX-x)+abs(currentY-y)<=1){return false;}
    int cnt=0;
    if(currentX==x){
        int startY=std::min(currentY,y)+1;
        int endY=std::max(currentY,y);
        cnt=0;
        for(int i=startY;i<endY;++i){
            if(board->getPlayer(x,i)!=Player::None){
                ++cnt;
            }
        }
    }
    else{
        int startX=std::min(currentX,x)+1;
        int endX=std::max(currentX,x);
        cnt=0;
        for(int i=startX;i<endX;++i){
            if(board->getPlayer(i,y)!=Player::None){
                ++cnt;
            }
        }
    }
    if(cnt==1){return destplayer!=Player::None;}
    if(cnt==0){return destplayer==Player::None;}
    return false;
}
