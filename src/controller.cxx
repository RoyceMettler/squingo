#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

void Controller::on_key_down(ge211::Key key)
{
    if(model_.startscreen){
        if (key.code() == ' ') {
            model_.character.set_wants_to_jump(true);
        }
    }
    if(model_.live){
        if (key == ge211::Key::left()) {
            model_.character.set_walking_left(true);
        }

        if (key == ge211::Key::right()) {
            model_.character.set_walking_right(true);
        }

        if (key.code() == 'r') {
            model_.character.set_charstate(Character::Charstate::Jumping);
            if(!model_.win){
                model_.set_room(1);
            }
            model_.character.set_center({634, 556});
            model_.character.set_velocity({0, 0});
        }
        if (key.code() == 'p') {
            model_.character.set_charstate(Character::Charstate::Jumping);
            if(!model_.win){
                model_.set_room(5);
            }
            model_.character.set_center({280, 250});
            model_.character.set_velocity({0, 0});
        }
    }

    if (key.code() == 'q') {
        exit(0);
    }
}

void Controller::on_key_up(ge211::Key key)
{
    if(model_.startscreen) {
        if (key.code() == ' ') {
            model_.character.set_wants_to_jump(false);
        }
    }
    if(model_.live) {
        if (key == ge211::Key::left()) {
            model_.character.set_walking_left(false);
        }
        if (key == ge211::Key::right()) {
            model_.character.set_walking_right(false);
        }
    }
}

void Controller::on_key(ge211::Key key)
{
    if (key.code() == '\r') {
        if (!model_.live && model_.startscreen) {
            model_.live = true;
            model_.set_room(1);
            model_.character.set_center({634, 551});
            model_.character.set_velocity({0, 0});
            model_.character.set_charstate(Character::Charstate::Jumping);

        }
        if (!model_.live && !model_.startscreen) {
            model_.startscreen = true;
        }
    }

    if(!model_.live && model_.startscreen){
        if (key == ge211::Key::left()) {
            model_.set_gravity(model_.get_gravity() - 1);
        }
        if (key == ge211::Key::right()) {
            model_.set_gravity(model_.get_gravity() + 1);
        }
    }
}