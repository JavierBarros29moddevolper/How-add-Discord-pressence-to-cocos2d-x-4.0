#ifndef __DISCORDPRESSENCE_H__
#define __DISCORDPRESSENCE_H__

#include "discord_game_sdk.h"
#include "discord/discord.h"
#include "cocos2d.h"

class DiscordPressence {
private:
	DiscordPressence();
	~DiscordPressence();
public:
	discord::Core* core; 
	static DiscordPressence* getInstance();
   bool init();
   void updatePressence(const std::string& state = "Playing", const std::string& details = "");
   void shutdown();
   void tick();
};


#endif // !__DISCORDPRESSENCE_H__
