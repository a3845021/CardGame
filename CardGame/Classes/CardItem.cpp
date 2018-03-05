//
//  CardItem.cpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#include "CardItem.h"



//static __TYPE__* create() \
//{ \
//    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
//    if (pRet && pRet->init()) \
//    { \
//        pRet->autorelease(); \
//        return pRet; \
//    } \
//    else \
//    { \
//        delete pRet; \
//        pRet = nullptr; \
//        return nullptr; \
//    } \
//}

CardItem* CardItem::create(int idx)
{
    CardItem *pRet = new CardItem;
    if (pRet && pRet->init(idx)) {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
    
}

bool CardItem::init(int idx)
{
    if ( !Sprite::init())
    {
        return false;
    }
    
    

    setIndex(idx);
    
    setContentSize(Size(80, 80));
    setAnchorPoint(Vec2(0, 0));
    CCString *str = CCString::createWithFormat("%d", idx);
    ttf = LabelTTF::create(str->getCString(), "Courier New", 30);
    ttf->setPosition(Vec2(40, 40));
    addChild(ttf);
    
    bg = Sprite::create();
    bg->setColor(Color3B(255, 255, 255));
    bg->setPosition(Vec2(40, 40));
    bg->setTextureRect(Rect(0, 0, 77, 77));
    addChild(bg);
    
    
    
    
    
    return true;
}

void CardItem::showWhite()
{
    ttf->setVisible(false);
    bg->setVisible(true);
}
void CardItem::showText()
{
    ttf->setVisible(true);
    bg->setVisible(false);
}








