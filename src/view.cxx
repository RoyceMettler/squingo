#include "view.hxx"
#include <string>

static ge211::Color const object_color {60, 60, 60};
static ge211::Color const white {255, 253, 170};

View::View(Model const& model)
        : model_(model),
          triangular_object_northwest_("Triangular_Object_Northwest.png"),
          triangular_object_northeast_("Triangular_Object_Northeast.png"),
          triangular_object_southwest_("Triangular_Object_Southwest.png"),
          triangular_object_southeast_("Triangular_Object_Southeast.png"),
          idle_sprite_right_("idle_sprite_right.png"),
          walking_sprite_frame_one_right_("walking_sprite_frame_one_right.png"),
          walking_sprite_frame_two_right_("walking_sprite_frame_two_right.png"),
          start_jumping_sprite_("start_jumping_sprite.png"),
          jumping_sprite_positive_right_("jumping_sprite_positive_right.png"),
          jumping_sprite_negative_right_("jumping_sprite_negative_right.png"),
          hit_sprite_right_("hit_sprite_right.png"),
          fell_sprite_right_("fell_sprite_right.png"),
          background_room_1_("bg_room_1.png"),
          background_room_2_("bg_room_2.png"),
          background_room_3_("bg_room_3.png"),
          background_room_4_("bg_room_4.png"),
          background_room_5_("bg_room_5.png"),
          background_end_screen_("bg_end_screen.png"),
          goalpost_sprite_("Goalpost.png"),
          font_("8514fix.fon", 200),
          start_screen_("Squingo", font_),
          start_screen_2_("Help Squingo get to the spaceship.", font_),
          start_screen_3_("P = Cheat to the end.", font_),
          start_screen_4_("Controls:", font_),
          start_screen_5_("Arrow keys = Move left or right.", font_),
          start_screen_6_("Hold space bar = Charge a jump.", font_),
          start_screen_7_("Release space bar = Jump.", font_),
          start_screen_8_("Release space bar + arrow key =", font_),
          start_screen_9_("Jump left or right.", font_),
          start_screen_10_("R = Restart.", font_),
          start_screen_11_("Good luck! Press enter to begin.", font_),
          gravity_screen_1_("Set Gravity", font_),
          gravity_screen_2_("Use the arrow", font_),
          gravity_screen_3_("keys to change", font_),
          gravity_screen_4_("the gravity until", font_),
          gravity_screen_5_("Squingo can jump", font_),
          gravity_screen_6_("above the line.", font_),
          gravity_screen_7_("Or just change it to whatever",
          font_),
          gravity_screen_8_("you want I guess.", font_),
          gravity_screen_9_("Gravity:", font_),
          gravity_screen_10_("11", font_),
          gravity_screen_11_({70, 30}, object_color),
          gravity_screen_12_({70, 10}, white),
          gravity_screen_13_("Press enter to continue.", font_),
          end_screen_("You Win!", font_),
          end_screen_2_("Thanks for playing!", font_),
          end_screen_3_("Total Jumps:", font_),
          end_screen_4_("Total Falls:", font_),
          end_screen_5_("0", font_),
          end_screen_6_("0", font_)
{
    for(size_t i = 0; i < model_.objects.size(); i++){
        object_sprites_.push_back(ge211::Rectangle_sprite(model_.objects[i]
        .get_block().dimensions(), object_color));
    }
}

void
View::draw(ge211::Sprite_set& set)
{
    if(!model_.live && !model_.startscreen){
        draw_start_screen_(set);
    }
    if(!model_.live && model_.startscreen){
        draw_gravity_screen_(set);
        draw_character_gravity_screen_(
                set,model_.character.top_left().into<int>());
    }
    if(model_.get_room() == 5){
        set.add_sprite(goalpost_sprite_, {500, 100}, 15,
                       ge211::Transform{}.scale(0.1));
    }
    if(model_.win){
        draw_victory_screen_(set);
        draw_character_victory_screen_(set, {400, 230});
    }
    draw_character_(set, model_.character.top_left().into<int>());
    draw_background_(set);
    for(size_t i = 0; i < object_sprites_.size(); i++){
        if(model_.objects[i].get_room() == model_.get_room()){
            set.add_sprite(object_sprites_[i], model_.objects[i]
                    .get_block().top_left());
        }
    }
    for(size_t i = 0; i < model_.triangular_objects.size(); i++){
        if(model_.triangular_objects[i].get_room() == model_.get_room()){
            float temp = model_.triangular_objects[i].get_block().width * 0.01;
            switch(model_.triangular_objects[i].rotation()) {
            case Triangular_Object::Rotation::Northeast:
                set.add_sprite(
                        triangular_object_northeast_,
                        model_.triangular_objects[i].get_block().top_left(),
                        0,
                        ge211::Transform{}.scale(temp));
                break;
            case Triangular_Object::Rotation::Northwest:
                set.add_sprite(
                        triangular_object_northwest_,
                        model_.triangular_objects[i].get_block().top_left(),
                        0,
                        ge211::Transform{}.scale(temp));
                break;
            case Triangular_Object::Rotation::Southeast:
                set.add_sprite(
                        triangular_object_southeast_,
                        model_.triangular_objects[i].get_block().top_left(),
                        0,
                        ge211::Transform{}.scale(temp));
                break;
            case Triangular_Object::Rotation::Southwest:
                set.add_sprite(
                        triangular_object_southwest_,
                        model_.triangular_objects[i].get_block().top_left(),
                        0,
                        ge211::Transform{}.scale(temp));
                break;
            default:
                break;
            }
        }
    }
}

void View::draw_background_(ge211::Sprite_set& set) const
{
    switch(model_.get_room()){
    case 1:
        set.add_sprite(background_room_1_, {0, 0}, -1);
        break;
    case 2:
        set.add_sprite(background_room_2_, {0, 0}, -1);
        break;
    case 3:
        set.add_sprite(background_room_3_, {0, 0}, -1);
        break;
    case 4:
        set.add_sprite(background_room_4_, {0, 0}, -1);
        break;
    case 5:
        set.add_sprite(background_room_5_, {0, 0}, -1);
        break;
    default:
        break;
    }
}

void View::draw_character_(ge211::Sprite_set& set, Position pos)
const
{
    switch(model_.character.get_charstate()){
    case Character::Charstate::On_object:
        if((model_.character.get_walking_left() && model_.character
        .get_walking_right()) || (!model_.character.get_walking_left() &&
        !model_.character.get_walking_right()))
        {
            if(model_.get_animation_state()){
                if(model_.get_fall_distance() > 350){
                    set.add_sprite(fell_sprite_right_, pos, 8);
                } else {
                    set.add_sprite(idle_sprite_right_, pos, 8);
                }
            } else {
                if (model_.get_fall_distance() > 350) {
                    set.add_sprite(fell_sprite_right_, pos, 8,
                                   ge211::Transform{}.flip_h());
                } else {
                    set.add_sprite(idle_sprite_right_, pos, 8,
                               ge211::Transform {}.flip_h());
                }
            }
        }
        if(model_.character.get_walking_left() && !model_.character
        .get_walking_right())
        {
            if(model_.get_duration() < 15){
                set.add_sprite(walking_sprite_frame_one_right_, pos, 8,
                               ge211::Transform{}.flip_h());
            } else {
                set.add_sprite(walking_sprite_frame_two_right_, pos, 8,
                               ge211::Transform{}.flip_h());
            }
        }
        if(!model_.character.get_walking_left() && model_.character
                                                         .get_walking_right())
        {
            if(model_.get_duration() < 15){
                set.add_sprite(walking_sprite_frame_one_right_, pos, 8);
            } else {
                set.add_sprite(walking_sprite_frame_two_right_, pos, 8);
            }
        }
        break;
    case Character::Charstate::Start_Jumping:
        set.add_sprite(start_jumping_sprite_, pos, 8);
        break;
    case Character::Charstate::Jumping:
        if(model_.get_animation_state()){
            if(!model_.get_hit_object_while_jumping()){
                if(model_.character.get_velocity().height <= 0)
                {
                    set.add_sprite(jumping_sprite_positive_right_, pos, 8);
                } else {
                    set.add_sprite(jumping_sprite_negative_right_, pos, 8);
                }
            } else {
                set.add_sprite(hit_sprite_right_, pos, 8);
            }
        } else {
            if(!model_.get_hit_object_while_jumping()){
                if(model_.character.get_velocity().height <= 0)
                {
                    set.add_sprite(jumping_sprite_positive_right_, pos, 8,
                                   ge211::Transform{}.flip_h());
                } else {
                    set.add_sprite(jumping_sprite_negative_right_, pos, 8,
                                   ge211::Transform{}.flip_h());
                }
            } else {
                set.add_sprite(hit_sprite_right_, pos, 8,
                               ge211::Transform{}.flip_h());
            }
        }
        break;
    }
}

void
View::draw_start_screen_(ge211::Sprite_set& set) const
{
    set.add_sprite(background_end_screen_, {0, 0}, 12);
    set.add_sprite(idle_sprite_right_, {400, 230}, 20,
                   ge211::Transform{}.scale(10));
    set.add_sprite(start_screen_, {215, 30}, 13,
                   ge211::Transform{}.scale(5));
    set.add_sprite(start_screen_2_, {195, 150}, 13,
                   ge211::Transform{}.scale(1.2));
    set.add_sprite(start_screen_4_, {100, 210}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(start_screen_5_, {30, 270}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_6_, {30, 310}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_7_, {30, 350}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_8_, {30, 390}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_9_, {30, 415}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_10_, {30, 455}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_3_, {30, 495}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(start_screen_11_, {30, 535}, 13,
                   ge211::Transform{}.scale(1));
}

void
View::draw_gravity_screen_(ge211::Sprite_set& set)
{
    set.add_sprite(background_end_screen_, {0, 0}, 12);
    set.add_sprite(gravity_screen_1_, {110, 30}, 13,
                   ge211::Transform{}.scale(5));
    set.add_sprite(gravity_screen_2_, {48, 150}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(gravity_screen_3_, {50, 190}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(gravity_screen_4_, {47, 230}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(gravity_screen_5_, {48, 270}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(gravity_screen_6_, {48, 310}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(gravity_screen_7_, {48, 385}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(gravity_screen_8_, {48, 410}, 13,
                   ge211::Transform{}.scale(1));
    set.add_sprite(gravity_screen_9_, {48, 450}, 13,
                   ge211::Transform{}.scale(3));
    set.add_sprite(gravity_screen_11_, {525, 495}, 13);
    set.add_sprite(gravity_screen_12_, {525, 300}, 13);
    set.add_sprite(gravity_screen_13_, {48, 535}, 13);
    ge211::Text_sprite::Builder builder(font_);
    builder << model_.get_gravity();
    gravity_screen_10_.reconfigure(builder);
    set.add_sprite(gravity_screen_10_, {295, 453}, 13,
                   ge211::Transform{}.scale(3));
}

void
View::draw_character_gravity_screen_(ge211::Sprite_set& set, Position pos) const
{
    switch(model_.character.get_charstate()){
    case Character::Charstate::On_object:
        set.add_sprite(idle_sprite_right_, {545, pos.y - 70}, 15);
        break;
    case Character::Charstate::Start_Jumping:
        set.add_sprite(start_jumping_sprite_, {545, pos.y - 70}, 15);
        break;
    case Character::Charstate::Jumping:
        if(model_.character.get_velocity().height <= 0)
        {
            set.add_sprite(jumping_sprite_positive_right_,
                           {545, pos.y - 70}, 15);
        } else {
            set.add_sprite(jumping_sprite_negative_right_,
                           {545, pos.y - 70}, 15);
        }
        break;
    }
}

void
View::draw_victory_screen_(ge211::Sprite_set& set)
{
    ge211::Text_sprite::Builder builder(font_);
    builder << model_.get_jump_count();
    end_screen_5_.reconfigure(builder);
    ge211::Text_sprite::Builder builder2(font_);
    builder2 << model_.get_fall_count();
    end_screen_6_.reconfigure(builder2);
    set.add_sprite(end_screen_, {190, 30}, 13,
                   ge211::Transform{}.scale(5));
    set.add_sprite(end_screen_2_, {195, 130}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(end_screen_3_, {100, 300}, 13,
                   ge211::Transform{}.scale(1.6));
    set.add_sprite(end_screen_5_, {100, 330}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(end_screen_4_, {100, 400}, 13,
                   ge211::Transform{}.scale(1.6));
    set.add_sprite(end_screen_6_, {100, 430}, 13,
                   ge211::Transform{}.scale(2));
    set.add_sprite(background_end_screen_, {0, 0}, 12);
}

void
View::draw_character_victory_screen_(ge211::Sprite_set& set, Position pos) const
{
    switch(model_.character.get_charstate()){
    case Character::Charstate::On_object:
        set.add_sprite(idle_sprite_right_, pos, 20,
                       ge211::Transform{}.scale(10));
        break;
    case Character::Charstate::Start_Jumping:
        set.add_sprite(start_jumping_sprite_, pos, 20,
                       ge211::Transform{}.scale(10));
        break;
    case Character::Charstate::Jumping:
        if(model_.character.get_velocity().height <= 0)
        {
            set.add_sprite(
                    jumping_sprite_positive_right_, pos, 20,
                    ge211::Transform{}.scale(10));
        } else {
            set.add_sprite(
                    idle_sprite_right_, pos, 20,
                    ge211::Transform{}.scale(10));
                }
        break;
    }
}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return {768, 576};
}

std::string View::initial_window_title() const
{
    return "Squingo";
}
