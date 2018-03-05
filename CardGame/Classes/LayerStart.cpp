//
//  LayerStart.cpp
//  CardGame
//
//  Created by Apple on 2018/3/2.
//

#include "LayerStart.h"
#include "LayerGame.h"

USING_NS_CC;

Scene* LayerStart::createScene()
{
    Scene *secen = Scene::create();
    LayerStart *start = LayerStart::create();
    secen->addChild(start);
    return secen;
}



// on "init" you need to initialize your instance
bool LayerStart::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    MenuItem *easyItem = MenuItemFont::create("easy", this,menu_selector(LayerStart::easy));
    MenuItem *hardItem = MenuItemFont::create("hard", this,menu_selector(LayerStart::hard));
    MenuItem *veryhadrItem = MenuItemFont::create("veryhard", this,menu_selector(LayerStart::veryhard));
    MenuItem *quitItem = MenuItemFont::create("quit", this,menu_selector(LayerStart::quit));
    Menu *menu = Menu::create(easyItem,hardItem,veryhadrItem,quitItem, NULL);
    menu->alignItemsVerticallyWithPadding(20);
    addChild(menu);
    
    
    
    
    
    return true;
    
    
}

void LayerStart::easy(Ref* pSender)
{
    Scene *game = LayerGame::createScene(EASY);
    Director::getInstance()->replaceScene(game);
}
void LayerStart::hard(Ref* pSender)
{
    Scene *game = LayerGame::createScene(HARD);
    Director::getInstance()->replaceScene(game);
}
void LayerStart::veryhard(Ref* pSender)
{
    Scene *game = LayerGame::createScene(VERYHARD);
    Director::getInstance()->replaceScene(game);
}
void LayerStart::quit(Ref* pSender)
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
