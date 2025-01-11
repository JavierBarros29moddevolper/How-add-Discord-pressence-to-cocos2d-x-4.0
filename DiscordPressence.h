#ifndef __DISCORDPRESSENCE_H__
#define __DISCORDPRESSENCE_H__

#include "discord_game_sdk.h"
#include "Discord/discord.h"
#include "Discord/core.h"
#include "CCConsole.h"
#include <string>

class DiscordPressence
{
private:
    DiscordPressence();
    ~DiscordPressence();

    discord::Core* core;

public:
    static DiscordPressence* getInstance();
    bool init();
    void updatePresence( const std::string& state = "Playing", const std::string& details = "" );
    void shutdown();
    void tick();
};

#endif // __DISCORDPRESSENCE_H__
