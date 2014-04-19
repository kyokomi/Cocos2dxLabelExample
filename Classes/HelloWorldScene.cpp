#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    

    const int fontSize = 80;
    
    // デフォルトっぽいの
    TTFConfig ttfConfig("fonts/Marker Felt.ttf", fontSize, GlyphCollection::DYNAMIC);
    auto labelTest = Label::createWithTTF(ttfConfig, "hoge hoge");
    labelTest->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    this->addChild(labelTest);
    
    const int height = labelTest->getContentSize().height * 1.5;
    
    // 文字と文字の間隔
    TTFConfig ttfConfigOutLine(ttfConfig);
    ttfConfigOutLine.outlineSize = 4;
    auto labelTestOutLine = Label::createWithTTF(ttfConfigOutLine, "hoge hoge");
    labelTestOutLine->setPosition(Point(labelTest->getPosition() - Point(0, height)));
    this->addChild(labelTestOutLine);
    
    // 影
    auto labelTestShadow = Label::createWithTTF(ttfConfig, "hoge hoge");
    labelTestShadow->setPosition(Point(labelTestOutLine->getPosition() - Point(0, height)));
    labelTestShadow->setColor(Color3B::RED);
    labelTestShadow->enableShadow(Color4B(255,255,255,128), Size(4, -4));
    this->addChild(labelTestShadow);
    
    // エフェクト（outlineと併用できない）
    TTFConfig ttfConfigEffect(ttfConfig);
    ttfConfigEffect.distanceFieldEnabled = true;
    auto labelTestEffect = Label::createWithTTF(ttfConfigEffect, "hoge hoge");
    labelTestEffect->setPosition(Point(labelTestShadow->getPosition() - Point(0, height)));
    labelTestEffect->setColor(Color3B::WHITE);
    labelTestEffect->enableGlow(Color4B::RED);
    this->addChild(labelTestEffect);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
