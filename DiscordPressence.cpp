#include "DiscordPressence.h"

DiscordPressence::DiscordPressence() : core( nullptr )
{ }

DiscordPressence::~DiscordPressence()
{
    // shutdown();
}

DiscordPressence* DiscordPressence::getInstance()
{
    static DiscordPressence instance;
    return &instance;
}

bool DiscordPressence::init()
{
    if (core) {
        CCLOG( "Discord already initialized." );
        return true;
    }
    // Here you can add your discord client ID, first create an application in discord developer portal, after OAuth2 and you can show your client id, copy and pste on 'YOUR_CLIENT_ID'
    discord::Result result = discord::Core::Create( YOUR_CLIENT_ID, DiscordCreateFlags_Default, &core );

    if (result == discord::Result::Ok) {
        CCLOG( "Discord initialized successfully" );
        return true;
    }
    else {
        CCLOG( "Failed to initialize Discord: %d", static_cast<int>(result) );
        return false;
    }
}

void DiscordPressence::updatePresence( const std::string& state, const std::string& details )
{
    if (!core) {
        CCLOG( "Discord core is not initialized." );
        return;
    }

    auto& activityManager = core->ActivityManager();
    discord::Activity activity{ };
    activity.SetState( state.c_str() );
    activity.SetDetails( details.c_str() );
    activity.GetAssets().SetLargeImage( "your_game_logo" ); // in discord dev portal add your game icon, in the rout application->Rich Pressence->art assets
    activity.GetAssets().SetLargeText( "your_game_name" ); // your name application

    activityManager.UpdateActivity( activity, []( discord::Result result ) {
        if (result == discord::Result::Ok) {
            CCLOG( "Discord presence updated successfully" );
        }
        else {
            CCLOG( "Failed to update Discord presence: %d", static_cast<int>(result) );
        }
    } );
}

void DiscordPressence::shutdown()
{
    if (core) {
        core = nullptr;
        CCLOG( "Discord core shutdown successfully" );
    }
}

void DiscordPressence::tick()
{
    if (core) {
        core->RunCallbacks();
    }
}
                 
