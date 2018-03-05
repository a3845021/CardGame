//
//  LayerStart.hpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#ifndef LayerStart_h
#define LayerStart_h

USING_NS_CC;

#include "cocos2d.h"

class LayerStart : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LayerStart);
    
    
    void easy(Ref* pSender);
    void hard(Ref* pSender);
    void veryhard(Ref* pSender);
    void quit(Ref* pSender);
    
    enum DEGREE
    {
      EASY = 5,HARD = 7,VERYHARD = 9
    };
    
};






#endif /* LayerStart_h */
