#include "../libs/DPP/include/dpp/dpp.h"
#include "../libs/cpp-dotenv/include/dotenv.h"

#include "../include/commands/Flan.hpp"

#define UNUSED(expr) (void)(expr)
#define COMMAND event.command.get_command_name()

using namespace dotenv;

const dpp::snowflake MY_GUILD_ID = 957713533813006447;

auto main() -> int {

    std::string env_path = "../resources/.env";
    auto& dotenv = env;
    env.load_dotenv(env_path);
    dpp::cluster bot(env["TOKEN"], dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_interaction_create([=](const dpp::interaction_create_t& event) {
        if (COMMAND == "ping") {
            event.reply("pong");
        } else if (COMMAND == "flan") {
            flan(event);
        }
    });

    bot.on_ready([&bot](const dpp::ready_t&  event) {
        UNUSED(event);
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(
                dpp::slashcommand("ping",
                                  "Ping pong!",
                                  bot.me.id),
                MY_GUILD_ID
            );
            bot.guild_command_create(
                dpp::slashcommand("flan",
                                  "FLAAAAAAAAAAAAAAAAN !",
                                  bot.me.id),
                MY_GUILD_ID
            );
        }
    });

    bot.start(false);
}