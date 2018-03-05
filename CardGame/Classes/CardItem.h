//
//  CardItem.hpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#ifndef CardItem_h
#define CardItem_h




USING_NS_CC;

#include "cocos2d.h"

class CardItem : public cocos2d::Sprite
{
public:
    
    LabelTTF *ttf;
    Sprite *bg;
    
    
    static CardItem* create(int idx);
    
    virtual bool init(int idx);
    
    void showWhite();
    void showText();
    
    CC_SYNTHESIZE(int, _index, Index);
    
};





#endif /* CardItem_h */
