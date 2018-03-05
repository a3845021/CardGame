//
//  LayerGame.cpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#include "LayerGame.h"
#include "CardItem.h"
#include "time.h"
#include "stdlib.h"
#include "LayerOver.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"

//USING_NS_CC_EXT;

using namespace CocosDenshion;

USING_NS_CC;

Scene* LayerGame::createScene(int degree)
{
    Scene *secen = Scene::create();
    LayerGame *start = LayerGame::create(degree);
    secen->addChild(start);
    return secen;
}

LayerGame* LayerGame::create(int degree)
{
    LayerGame *pRet = new LayerGame;
    if (pRet && pRet->init(degree)) {
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

// on "init" you need to initialize your instance
bool LayerGame::init(int degree)
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }


    SimpleAudioEngine::getInstance()->preloadEffect("click.wav");
    
    
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
    
    
    setClickStart(0);
    
    setDegree(degree);
    getAllPoint();
    getAvaliblePoint();
    addCard();
    
    return true;
}


void LayerGame::showCardAllBack()
{
    Object *obj;
    CCARRAY_FOREACH(allCards, obj)
    {
        CardItem *item = (CardItem *)obj;
        item->showWhite();
    }
}


bool LayerGame::onTouchBegan(Touch *touch, Event *unused_event)
{
    for (int i = 0; i < allCards->count(); i++) {
        if (((CardItem *)allCards->objectAtIndex(i))->getBoundingBox().containsPoint(touch->getLocation())){
            
            showCardAllBack();
            SimpleAudioEngine::getInstance()->playEffect("click.wav");
        
            if (getClickStart() == ((CardItem *)allCards->objectAtIndex(i))->getIndex())
            {
                ((CardItem *)allCards->objectAtIndex(i))->removeFromParentAndCleanup(true);
                allCards->removeObjectAtIndex(i);
                if (allCards->count() == 0) {
                    
                    Scene *over = LayerOver::createScene(true);
                    Director::getInstance()->replaceScene(over);
                    CCLOG("U win Game");
                }
                
             
            }
            else
            {
                Scene *over = LayerOver::createScene(false);
                Director::getInstance()->replaceScene(over);
                CCLOG("U lose Game");
            }
            
            _clickStart++;
        }
    }
    return true;
}

void LayerGame::addCard()
{
    
    allCards = Array::create();
    allCards->retain();
    
    for (int i = 0; i < getDegree(); i++) {
        CardItem *item = CardItem::create(i);
        item->setPosition(allPoints->getControlPointAtIndex(vec[i]));
        addChild(item);
        item->showText();
        allCards->addObject(item);
    }
    
    
}

void LayerGame::getAllPoint()
{
    allPoints = PointArray::create(60);
    allPoints->retain();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            allPoints->addControlPoint(Vec2(80 * i, 80 * j));
        }
    }
}


void LayerGame::getAvaliblePoint()
{
    srand(time(NULL));
    while (1) {
        int idx = rand() % 60;
        Vector<int>::iterator itr = vec.begin();
        for (;itr != vec.end(); ++itr) {
            if (*itr == idx) {
                break;
            }
        }
        if (itr == vec.end()) {
            vec.push_back(idx);
            if (vec.size() == getDegree()) {
                break;
            }
        }
    }
}








