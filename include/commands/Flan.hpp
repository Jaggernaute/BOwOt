//
// Created by jaggernaute on 5/22/22.
//

#include "../../libs/DPP/include/dpp/dpp.h"
#include <random>

#ifndef BOWOT_FLAN_HPP
#define BOWOT_FLAN_HPP

auto flan(const dpp::interaction_create_t& event) -> void {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> dis(0, 100);
    int random = dis(gen);

    if (random == 69) event.reply("FLAMBY !");
    else event.reply("FLAAAAAAAAAAAAAAAAN !");
}

#endif // BOWOT_FLAN_HPP
