#include "DiscordPressence.h"

DiscordPressence::DiscordPressence() : core(nullptr){}

DiscordPressence::~DiscordPressence() {
  shutdown();
}

DiscordPressence* DiscordPressence::getInstance(){
  static DiscordPressence instance;
  return &instance;
}

bool DiscordPressence::init(){

	uint64_t flags = static_cast<uint64_t>(discord::CreateFlags::NoRequireDiscord);

     // Here you can add your Discord client ID, where discord developer portal / Applications
	discord::Result result = discord::Core::Create( YOUR_CLIENT_ID, flags, &core);

	if (result == discord::Result::Ok){
		CCLOG( "Discord initialized succesfully" );
		return true;
	} else {
	   CCLOG("Failed to initialized Discord: %d", result);
	   return false;
	}
}

void DiscordPressence::updatePressence(const std::string& state, const std::string& details) {
	 if (!core) return;

   auto& activityManager = core->ActivityManager();
   discord::Activity activity{};
   activity.SetState(state.c_str());
   activity.SetDetails(details.c_str());
   activity.GetAssets().SetLargeImage("your_logo"); // Here you can add your game logo, from Discord developer portal / Applications / Rich Pressence / Art assets
   activity.GetAssets().SetLargeText("your_game_name"); // Add your game name

   activityManager.UpdateActivity(activity, [](discord::Result result) {
   	 if (result == discord::Result::Ok)	{
	   CCLOG("Discord presence updated succesfully");
	 } else {
	   CCLOG("Failed to update Discord pressence: %d", static_cast<int>(result));
	 }
   });

}

void DiscordPressence::shutdown() {
  if (core) {
   delete core;
   core = nullptr;
   CCLOG("Discord core shutdown succesfully");
  }
}

void DiscordPressence::tick() {
  if(core) {
   core->RunCallbacks();
  }
}