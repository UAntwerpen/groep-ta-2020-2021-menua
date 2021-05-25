//
// Created by Menua on 28/02/2021.
//

#include "State.h"

void State::set_title(string new_title) {
    this->state_title = new_title;
}

string State::get_title() {
    return this->state_title;
}

void State::set_finalstate(bool value) {
    this->final_state = value;
}

bool State::get_finalstate() const {
    return this->final_state;
}

void State::set_startstate(bool value) {
    this->start_state = value;
}

bool State::get_startstate() const {
    return this->start_state;
}








