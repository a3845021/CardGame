//
//  LayerGame.hpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#ifndef LayerGame_h
#define LayerGame_h


using namespace std;
USING_NS_CC;

#include "cocos2d.h"

class LayerGame : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int degree);
    static LayerGame* create(int degree);
    virtual bool init(int degree);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    

    
    void getAllPoint();
    void getAvaliblePoint();
    void addCard();
    
    void showCardAllBack();
    
    
    PointArray *allPoints;
    vector<int> vec;
    Array *allCards;
    
    // 创建一个变量和get，set方法
    CC_SYNTHESIZE(int, _degree, Degree);
    CC_SYNTHESIZE(int, _clickStart, ClickStart);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
};








#endif /* LayerGame_h */
