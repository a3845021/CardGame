//
//  LayerOver.cpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#include "LayerOver.h"
#include "LayerStart.h"

cocos2d::Scene* LayerOver::createScene(bool res)
{
    Scene *scene = Scene::create();
    LayerOver *over = LayerOver::create(res);
    scene->addChild(over);
    return scene;
}

LayerOver* LayerOver::create(bool res)
{
    LayerOver *pRet = new LayerOver;
    if (pRet && pRet->init(res)) {
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

void LayerOver::menuCloseCallback(cocos2d::Ref* pSender)
{
    Scene *scen = LayerStart::createScene();
    Director::getInstance()->replaceScene(scen);
}

bool LayerOver::init(bool res)
{
    if ( !Layer::init())
    {
        return false;
    }
    
    MenuItem *back = MenuItemFont::create("Restart",this,menu_selector(LayerOver::menuCloseCallback));
    
    if (res)
    {
        MenuItem *win = MenuItemFont::create("你赢了");
        Menu *menu = Menu::create(win,back, NULL);
        menu->alignItemsVerticallyWithPadding(20);
        this->addChild(menu);
        
    }
    else
    {
        MenuItem *lose= MenuItemFont::create("你输了,宝贝");
        Menu *menu = Menu::create(lose,back, NULL);
        menu->alignItemsVerticallyWithPadding(20);
        this->addChild(menu);
    }
    
    
    
    
    
    
    return true;
}






