//
//  LayerOver.hpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#ifndef LayerOver_h
#define LayerOver_h



USING_NS_CC;

#include "cocos2d.h"

class LayerOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(bool res);
    static LayerOver* create(bool res);
    virtual bool init(bool res);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
};



#endif /* LayerOver_h */
