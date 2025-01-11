# How-add-Discord-pressence-to-cocos2d-x-4.0 
In this repository you can see a basic implementation of how to add discord presences in cocos2d-x 4.0

In order to create discord presences in cocos2d-x, you must first download discord game sdk, then add the x86 libraries in your cocos2d-x project, then configure the path to the libraries in your visual studio, add the discord_game_sdk.h together with your project code, then copy all the discord cpp files into your code as well.

Also, you must configure in discord developer portal an application so that the discord API can connect to the code, copy the client id and paste it where it says YOUR_CLIENT_ID, then you can put the name of your project and logo. In your scene, it does not matter which one you call DiscordPressence as it is in CustomScene so that it works, compile and in your discord activity it should appear.

# NOTE
For cocos2d-x 4.0, I recommend you to download Discord game SDK 2.5.6 to avoid any error when compiling. ```

# Example 

```cpp
bool CustomScene::init() {
    if (!Scene::init()) return false;

    cocos2d::Size vs = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    if (DiscordPressence::getInstance()->init()) {
        DiscordPressence::getInstance()->updatePressence("Loading...", "My game is starting!");
    }

    cocos2d::Sprite* mySpr = cocos2d::Sprite::create("mySpr.png");
    mySpr->setPosition(cocos2d::Vec2(vs.width / 2, vs.height / 2));
    addChild(mySpr);
    return true;
}

void CustomScene::update(float dt) {
    DiscordPressence::getInstance()->tick();
}
```
# UPDATE

I have updated this because I noticed that when you changed scenes, the core would close before being able to update the presence. With this change I made that problem is history, just use the 'updatePressence' and 'tick' methods I gave you when you go to change scenes and your presence does it too.

In case I notice more bugs and if I manage to add more features, I will update this repository :)

By Urafael
