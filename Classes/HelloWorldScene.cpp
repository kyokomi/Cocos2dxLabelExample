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

    const int fontSize = 80;
    
    // デフォルトで入ってるMarker Felt.ttfフォントの設定を作る
    TTFConfig ttfConfig("fonts/Marker Felt.ttf",
                        fontSize,
                        GlyphCollection::DYNAMIC);
    // 1. 普通にTTFフォントを使って表示
    auto label = Label::createWithTTF(ttfConfig, "hoge hoge");
    label->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    this->addChild(label);
    
    const int height = label->getContentSize().height * 1.5;
    
    // 2. 文字と文字の間隔を設定（アウトライン）
    TTFConfig ttfConfigOutLine(ttfConfig);
    // 文字の間隔を指定（フォントサイズの幅っぽい）
    ttfConfigOutLine.outlineSize = 4;
    auto labelOutLine = Label::createWithTTF(ttfConfigOutLine, "hoge hoge");
    labelOutLine->setPosition(Point(label->getPosition() - Point(0, height)));
    this->addChild(labelOutLine);
    
    // 3. 文字に影をつける（x=4, y=-4の位置に影を置く）
    auto labelShadow = Label::createWithTTF(ttfConfig, "hoge hoge");
    labelShadow->setPosition(Point(labelOutLine->getPosition() - Point(0, height)));
    labelShadow->setColor(Color3B::RED);
    // 半透明の影を（x = 4, y = -4）の位置へ指定
    labelShadow->enableShadow(Color4B(255,255,255,128), Size(4, -4));
    this->addChild(labelShadow);
    
    // 4. エフェクト表示（アウトラインと併用できないので注意）
    TTFConfig ttfConfigEffect(ttfConfig);
    // エフェクト有効（_useDistanceField = distanceFieldEnabled;されます）
    ttfConfigEffect.distanceFieldEnabled = true;
    auto labelEffect = Label::createWithTTF(ttfConfigEffect, "hoge hoge");
    labelEffect->setPosition(Point(labelShadow->getPosition() - Point(0, height)));
    // エフェクトの色を指定
    labelEffect->enableGlow(Color4B::RED);
    this->addChild(labelEffect);
    
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
