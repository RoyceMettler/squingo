#include "model.hxx"
#include <cmath>

Model::Model() :
character()
{
    /// ROOM 1 ///
    // Floor & Sides
    objects.push_back(Object({0, 566}, {768, 10}, 1));
    objects.push_back(Object({758, 0}, {10, 576}, 1));
    objects.push_back(Object({0, 0}, {10, 576}, 1));

    // Room 1 objects
    objects.push_back(Object({0, 430}, {160, 136}, 1));
    objects.push_back(Object({160, 470}, {40, 96}, 1));
    objects.push_back(Object({360, 500}, {130, 66}, 1));
    objects.push_back(Object({350, 510}, {10, 56}, 1));
    objects.push_back(Object({490, 510}, {10, 56}, 1));
    objects.push_back(Object({100, 220}, {100, 20}, 1));
    objects.push_back(Object({380, 210}, {150, 40}, 1));
    objects.push_back(Object({0, 0}, {450, 30}, 1));
    objects.push_back(Object({708, 0}, {50, 300}, 1));

    // Room 1 triangular objects
    triangular_objects.push_back(Triangular_Object(
            {10, 30}, {80, 80}, 1,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
           {10, 350}, {80, 80}, 1,
           Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {160, 430}, {40, 40}, 1,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {200, 546}, {20, 20}, 1,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {500, 546}, {20, 20}, 1,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {330, 546}, {20, 20}, 1,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {738, 546}, {20, 20}, 1,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {350, 500}, {10, 10}, 1,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {490, 500}, {10, 10}, 1,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {350, 30}, {50, 50}, 1,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {400, 30}, {50, 50}, 1,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {708, 300}, {50, 50}, 1,
            Triangular_Object::Rotation::Southwest));

    /// ROOM 2 ///
    // Sides
    objects.push_back(Object({758, 0}, {10, 576}, 2));
    objects.push_back(Object({0, 0}, {10, 576}, 2));

    // Room 2 objects
    objects.push_back(Object({708, 566}, {50, 10}, 2));
    objects.push_back(Object({0, 566}, {400, 10}, 2));
    objects.push_back(Object({400, 410}, {40, 166}, 2));
    objects.push_back(Object({400, 0}, {40, 320}, 2));
    objects.push_back(Object({360, 0}, {40, 280}, 2));
    objects.push_back(Object({360, 450}, {40, 126}, 2));
    objects.push_back(Object({115, 450}, {120, 20}, 2));
    objects.push_back(Object({145, 100}, {60, 350}, 2));
    objects.push_back(Object({115, 340}, {30, 10}, 2));
    objects.push_back(Object({115, 200}, {30, 10}, 2));
    objects.push_back(Object({115, 80}, {120, 20}, 2));
    objects.push_back(Object({10, 0}, {255, 10}, 2));
    objects.push_back(Object({330, 170}, {30, 10}, 2));
    objects.push_back(Object({718, 440}, {40, 10}, 2));
    objects.push_back(Object({718, 90}, {40, 10}, 2));

    // Room 2 triangular objects
    triangular_objects.push_back(Triangular_Object(
            {440, 410}, {40, 40}, 2,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {360, 410}, {40, 40}, 2,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {440, 450}, {40, 40}, 2,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {360, 280}, {40, 40}, 2,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {115, 420}, {30, 30}, 2,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {205, 420}, {30, 30}, 2,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {115, 350}, {30, 30}, 2,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {115, 210}, {30, 30}, 2,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {115, 100}, {30, 30}, 2,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {330, 180}, {30, 30}, 2,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {205, 100}, {30, 30}, 2,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {10, 526}, {40, 40}, 2,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {320, 526}, {40, 40}, 2,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {718, 400}, {40, 40}, 2,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {718, 100}, {40, 40}, 2,
            Triangular_Object::Rotation::Southwest));

    /// ROOM 3 ///
    // Sides
    objects.push_back(Object({758, 0}, {10, 576}, 3));
    objects.push_back(Object({0, 0}, {10, 576}, 3));

    // Room 3 objects
    objects.push_back(Object({0, 566}, {265, 10}, 3));
    objects.push_back(Object({10, 370}, {40, 10}, 3));
    objects.push_back(Object({430, 470}, {30, 10}, 3));
    objects.push_back(Object({390, 500}, {20, 76}, 3));
    objects.push_back(Object({410, 320}, {20, 356}, 3));
    objects.push_back(Object({728, 310}, {30, 10}, 3));
    objects.push_back(Object({504, 200}, {150, 30}, 3));
    objects.push_back(Object({474, 110}, {30, 90}, 3));
    objects.push_back(Object({654, 210}, {10, 10}, 3));
    objects.push_back(Object({180, 30}, {10, 40}, 3));
    objects.push_back(Object({170, 70}, {30, 10}, 3));
    objects.push_back(Object({444, 100}, {60, 10}, 3));

    // Room 3 triangular objects
    triangular_objects.push_back(Triangular_Object(
            {10, 526}, {40, 40}, 3,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {360, 546}, {30, 30}, 3,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {390, 480}, {20, 20}, 3,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {10, 380}, {40, 40}, 3,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {430, 480}, {30, 30}, 3,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {728, 320}, {30, 30}, 3,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {654, 200}, {10, 10}, 3,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {654, 220}, {10, 10}, 3,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {474, 200}, {30, 30}, 3,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {504, 190}, {10, 10}, 3,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {170, 60}, {10, 10}, 3,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {190, 60}, {10, 10}, 3,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {444, 110}, {30, 30}, 3,
            Triangular_Object::Rotation::Southwest));

    /// ROOM 4 ///
    // Sides
    objects.push_back(Object({758, 0}, {10, 576}, 4));
    objects.push_back(Object({0, 0}, {10, 576}, 4));

    // Room 4 Objects
    objects.push_back(Object({10, 500}, {40, 10}, 4));
    objects.push_back(Object({100, 300}, {80, 20}, 4));
    objects.push_back(Object({100, 60}, {80, 20}, 4));
    objects.push_back(Object({410, 130}, {20, 270}, 4));
    objects.push_back(Object({430, 240}, {100, 20}, 4));
    objects.push_back(Object({738, 95}, {20, 5}, 4));

    // Room 4 Triangular Objects
    triangular_objects.push_back(Triangular_Object(
            {10, 510}, {40, 40}, 4,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {380, 80}, {50, 50}, 4,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {380, 400}, {50, 50}, 4,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {430, 190}, {50, 50}, 4,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {430, 260}, {50, 50}, 4,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {380, 130}, {30, 30}, 4,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {380, 370}, {30, 30}, 4,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {738, 100}, {20, 20}, 4,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {100, 320}, {40, 40}, 4,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {140, 320}, {40, 40}, 4,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {100, 80}, {40, 40}, 4,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {140, 80}, {40, 40}, 4,
            Triangular_Object::Rotation::Southeast));

    /// ROOM 5 ///
    // Sides
    objects.push_back(Object({758, 0}, {10, 576}, 5));
    objects.push_back(Object({0, 0}, {10, 576}, 5));

    // Room 5 Objects
    objects.push_back(Object({550, 500}, {80, 20}, 5));
    objects.push_back(Object({10, 480}, {20, 5}, 5));
    objects.push_back(Object({270, 300}, {10, 100}, 5));
    objects.push_back(Object({250, 340}, {20, 20}, 5));
    objects.push_back(Object({280, 340}, {20, 20}, 5));

    // Room 5 Triangular Objects
    triangular_objects.push_back(Triangular_Object(
            {550, 520}, {40, 40}, 5,
            Triangular_Object::Rotation::Southwest));
    triangular_objects.push_back(Triangular_Object(
            {590, 520}, {40, 40}, 5,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {10, 485}, {20, 20}, 5,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {250, 320}, {20, 20}, 5,
            Triangular_Object::Rotation::Northwest));
    triangular_objects.push_back(Triangular_Object(
            {280, 320}, {20, 20}, 5,
            Triangular_Object::Rotation::Northeast));
    triangular_objects.push_back(Triangular_Object(
            {280, 360}, {20, 20}, 5,
            Triangular_Object::Rotation::Southeast));
    triangular_objects.push_back(Triangular_Object(
            {250, 360}, {20, 20}, 5,
            Triangular_Object::Rotation::Southwest));

    /// ROOM 6 (where the player is teleported when they win) ///
    // Floor & Sides
    objects.push_back(Object({0, 566}, {768, 10}, 6));
    objects.push_back(Object({758, 0}, {10, 576}, 6));
    objects.push_back(Object({0, 0}, {10, 576}, 6));
    objects.push_back(Object({0, 0}, {768, 70}, 6));

}

void
Model::on_frame(double dt)
{
    if(room_ < 1){
        character.set_charstate(Character::Charstate::Jumping);
        character.set_center({634, 556});
        character.set_velocity({0, 0});
        fall_count_++;
    }
    if(room_ == 5 && character.hits_goalpost(goalpost))
    {
        win = true;
        room_ = 6;
        character.set_center({349, 556});
    }
    // This function is run every frame.
    // First, the values of object_collision_ and hit_object_while_walking
    // are reset.
    reset_();

    // Then, they are repopulated with the new data for this frame.
    track_object_collision_();

    // room_ is set to the current room the player is in because the player
    // should only be able to interact with objects in that room.
    track_room_();

    // I had found that sometimes I would lift the arrow key slightly
    // before the space bar when trying to jump in a direction and I'd end up
    // jumping straight upwards, which was annoying. I implemented this grace
    // period system to give the player some leeway in lifting the arrow key
    // before the space bar and still jumping in the direction they want to.
    // It makes the controls of the game a lot smoother.

    // If the left or right key is pressed, the grace period is set back 20
    // frames. If not, it counts down over 20 frames and if it hits zero, the
    // game officially registers the respective arrow key as not pressed.
    if(character.get_walking_left()){
        jumping_left_grace_period_ = 20;
    }
    if(jumping_left_grace_period_ > 0){
        jumping_left_grace_period_--;
    }
    if(character.get_walking_right()){
        jumping_right_grace_period_ = 20;
    }
    if(jumping_right_grace_period_ > 0){
        jumping_right_grace_period_--;
    }

    // Now the function is split into a switch statement depending on the
    // current state of the character.

    switch(character.get_charstate()) {
    case Character::Charstate::On_object:
        track_fall_distance();
        if(fall_distance_ > 350 && !updated_fall_count_already_)
        {
            fall_count_++;
            updated_fall_count_already_ = true;
        }
        hit_object_while_jumping_ = false;
        // If the character is on an object and presses space, they will
        // start jumping.
        if(character.get_wants_to_jump()){
            character.set_charstate(Character::Charstate::Start_Jumping);
            break;
        }

        // If a character is walking both left and right, they don't move.
        if(character.get_walking_left() && character.get_walking_right()){
            duration_ = 0;
            fall_distance_ = 0;
            jump_initial_y = character.get_center().y;
            updated_fall_count_already_ = false;
            character = character.next(0, 0);
        }

        // If a character is not walking left or right, they don't move.
        if(!character.get_walking_left() && !character.get_walking_right()){
            duration_ = 0;
            character = character.next(0, 0);
        }

        // If a character is walking left, first see if they walk off the
        // object in which case they fall off. Then, see if they hit any
        // objects while walking, in which case prevent them from walking
        // left anymore. If they don't hit any, they keep walking left.
        if(character.get_walking_left() && !character.get_walking_right()){
            animation_state_ = false;
            fall_distance_ = 0;
            updated_fall_count_already_ = false;
            jump_initial_y = character.get_center().y;
            track_duration();
            fall_off_object_left_();
            bool has_hit = false;
            if(hit_object_while_walking_){
                for(size_t i = 0; i < objects.size(); i++){
                    if(objects[i].get_room() == room_ &&
                    character.hits_right_of_object(objects[i])){
                        character.set_center(character.
                        right_of_block(objects[i]));
                        has_hit = true;
                        character = character.next(0, 0);
                        break;
                    }
                }
                for(size_t i = 0; i < triangular_objects.size(); i++){
                    if(triangular_objects[i].get_room() == room_ &&
                    character.hits_right_of_object(triangular_objects[i])
                    &&(character.top_left().y + (character.get_dimensions()
                    .height - 1)) >= triangular_objects[i].get_block()
                    .top_left().y){
                        character.set_center(character.
                        right_of_block(triangular_objects[i]));
                        has_hit = true;
                        character = character.next(0, 0);
                        break;
                    }
                }
            }
            if(!has_hit){
                character = character.next(-dt, 0);
            }
        }

        // If a character is walking right, first see if they walk off the
        // object in which case they fall off. Then, see if they hit any
        // objects while walking, in which case prevent them from walking
        // right anymore. If they don't hit any, they keep walking right.
        if(!character.get_walking_left() && character.get_walking_right()){
            animation_state_ = true;
            fall_distance_ = 0;
            updated_fall_count_already_ = false;
            jump_initial_y = character.get_center().y;
            track_duration();
            fall_off_object_right_();
            bool has_hit = false;
            if(hit_object_while_walking_){
                for(size_t i = 0; i < objects.size(); i++)
                {
                    if(objects[i].get_room() == room_ &&
                    character.hits_left_of_object(objects[i]))
                    {
                        character.set_center(character.
                        left_of_block(objects[i]));
                        has_hit = true;
                        character = character.next(0, 0);
                        break;
                    }
                }
                for(size_t i = 0; i < triangular_objects.size(); i++)
                {
                    if(triangular_objects[i].get_room() == room_ &&
                    character.hits_left_of_object(triangular_objects[i])
                    && (character.top_left().y + (character.get_dimensions()
                    .height - 1)) >= triangular_objects[i].get_block()
                    .top_left().y)
                    {
                        character.set_center(character.
                        left_of_block(triangular_objects[i]));
                        has_hit = true;
                        character = character.next(0, 0);
                        break;
                    }
                }
            }
            if(!has_hit){
                character = character.next(dt, 0);
            }
        }
        break;

    case Character::Charstate::Start_Jumping:
        // If a character is winding up their jump, preemptively set their x
        // velocity to 400 since jumping x velocity is larger than walking x
        // velocity. Also prevent them from moving. Every frame, increase the
        // charge until it reaches two or until the player lets go of the
        // space bar. Call jump() when that happens.
        fall_distance_ = 0;
        updated_fall_count_already_ = false;
        jump_initial_y = character.get_center().y;
        character.set_velocity_width(400);
        character = character.next(0, 0);
        charge_ = charge_ + (0.0025 * gravity_);
        if((charge_ >= 2) || !character.get_wants_to_jump()){
            jump();
            break;
        }
        break;

    case Character::Charstate::Jumping:
        // If a character is jumping, add 12 to their y velocity simulating
        // them being affected by a gravitational constant of 12. Then keep
        // them moving in the direction they were heading. See if they hit
        // any objects and adjust their position and velocity accordingly.
        character.add_to_velocity_height(gravity_);
        character = character.next(dt, dt);
        object_behavior_();
        triangular_object_behavior_();
        if(character.hits_top()){
            jump_initial_y = jump_initial_y + 576;
        }
        if(character.hits_bottom()){
            jump_initial_y = jump_initial_y - 576;
        }
    default:
        break;
    }
}

void
Model::jump()
{
    if(!win){
        jump_count_++;
    }
    jump_initial_y = character.get_center().y;
    character.set_charstate(Character::Charstate::Jumping);
    character.scale_velocity_height(-charge_);
    if((jumping_left_grace_period_ == 0 && jumping_right_grace_period_ == 0)
    || (jumping_left_grace_period_ > 0 && jumping_right_grace_period_ > 0))
    {
        if(object_collision_ == 2){
            if(animation_state_){
                character.set_center({character.get_center().x - 1,
                                      character.get_center().y});
            } else {
                character.set_center({character.get_center().x + 1,
                                      character.get_center().y});
            }
        }
        character.set_velocity_width(0);
    }
    if(jumping_left_grace_period_ == 0 && jumping_right_grace_period_ > 0)
    {
        animation_state_ = true;
    }
    if(jumping_left_grace_period_ > 0 && jumping_right_grace_period_ == 0)
    {
        animation_state_ = false;
        character.scale_velocity_width(-1);
    }

}

int
Model::get_room() const
{
    return room_;
}

void
Model::set_room(int set)
{
    room_ = set;
}

int
Model::get_duration() const
{
    return duration_;
}

int
Model::get_fall_distance() const
{
    return fall_distance_;
}

bool
Model::get_animation_state() const
{
    return animation_state_;
}

bool
Model::get_hit_object_while_jumping() const
{
    return hit_object_while_jumping_;
}

int
Model::get_jump_count() const
{
    return jump_count_;
}

int
Model::get_fall_count() const
{
    return fall_count_;
}

int
Model::get_gravity() const
{
    return gravity_;
}

void
Model::set_gravity(int set)
{
    gravity_ = set;
}

void
Model::track_object_collision_()
{
    int sum = 0;
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i].get_room() == room_ && character.hits_object
        (objects[i])) {
            sum++;
        }
    }
    for (size_t i = 0; i < triangular_objects.size(); i++) {
        if(triangular_objects[i].get_room() == room_ &&
        character.hits_object(triangular_objects[i]) &&
        (character.top_left().y + (character.get_dimensions()
        .height - 1)) >= triangular_objects[i].get_block()
        .top_left().y){
            sum++;
        }
    }
    object_collision_ = sum;
    if(sum == 2){
        hit_object_while_walking_ = true;
    }
    if(sum != 2){
        hit_object_while_walking_ = false;
    }
}

void
Model::track_room_()
{
    if(character.hits_top()){
        room_++;
        character.set_center({character.get_center().x, 576});
    }
    if(character.hits_bottom()){
        room_--;
        character.set_center({character.get_center().x, 0});
    }
}

void
Model::track_duration()
{
    duration_ += 1;
    if (duration_ >= 30) {
        duration_ = 0;
    }
}

void
Model::track_fall_distance()
{
    fall_distance_ = character.get_center().y - jump_initial_y;
}

void
Model::fall_off_object_left_()
{
    if(object_collision_ == 0){
        jump_initial_y = character.get_center().y;
        character.set_velocity_height(0);
        character.scale_velocity_width(-0.75);
        character.set_charstate(Character::Charstate::Jumping);
    }
}

void
Model::fall_off_object_right_()
{
    if(object_collision_ == 0){
        jump_initial_y = character.get_center().y;
        character.set_velocity_height(0);
        character.scale_velocity_width(0.75);
        character.set_charstate(Character::Charstate::Jumping);
    }
}

void
Model::reset_()
{
    object_collision_ = 0;
    hit_object_while_walking_ = false;
}

void
Model::object_behavior_()
{
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i].get_room() == room_) {
            if(character.hits_object(objects[i])){
                hit_object_while_jumping_ = true;
            }
            if (character.hits_top_of_object(objects[i]) && character
                    .hits_right_of_object(objects[i])) {
                if (((character.top_left().y +
                character.get_dimensions().height - 5) >=
                     objects[i].get_block().top_left().y))
                {
                    reflect_character_right_(objects[i]);
                    break;
                } else {
                    put_character_on_object_(objects[i]);
                    break;
                }
            }

            if (character.hits_top_of_object(objects[i]) && character
                    .hits_left_of_object(objects[i])) {
                if (((character.top_left().y + character.get_dimensions()
                        .height - 5) >=
                     objects[i].get_block().top_left().y)) {
                    reflect_character_left_(objects[i]);
                    break;
                } else {
                    put_character_on_object_(objects[i]);
                    break;
                }
            }

            if (character.hits_bottom_of_object(objects[i]) && character
                    .hits_right_of_object(objects[i])) {
                if (((character.top_left().y + 5) <=
                     objects[i].get_block().bottom_left().y)) {
                    reflect_character_right_(objects[i]);
                    break;
                } else {
                    reflect_character_down_(objects[i]);
                    break;
                }
            }

            if (character.hits_bottom_of_object(objects[i]) && character
                    .hits_left_of_object(objects[i])) {
                if (((character.top_left().y + 5) <=
                     objects[i].get_block().bottom_left().y)) {
                    reflect_character_left_(objects[i]);
                    break;
                } else {
                    reflect_character_down_(objects[i]);
                    break;
                }
            }

            if (character.hits_left_of_object(objects[i])) {
                reflect_character_left_(objects[i]);
                break;
            }
            if (character.hits_right_of_object(objects[i])) {
                reflect_character_right_(objects[i]);
                break;
            }
            if (character.hits_top_of_object(objects[i])) {
                put_character_on_object_(objects[i]);
                break;
            }
            if (character.hits_bottom_of_object(objects[i])) {
                reflect_character_down_(objects[i]);
                break;
            }
        }
    }
}

void
Model::triangular_object_behavior_()
{
    for(size_t i = 0; i < triangular_objects.size(); i++) {
        if ((triangular_objects[i].get_room() == room_) &&
        character.hits_object(triangular_objects[i]))
        {
            bool hit_yet = false;
            switch (triangular_objects[i].rotation()) {
            case Triangular_Object::Rotation::Northeast:
                for(size_t j = 0; j < objects.size(); j++){
                    if(objects[j].get_room() == room_ && character
                    .hits_top_of_object(objects[j]))
                    {
                        hit_yet = true;
                        break;
                    }
                    if(objects[j].get_room() == room_ &&
                    character.hits_right_of_object(objects[j]))
                    {
                        hit_yet = true;
                        reflect_character_right_(objects[j]);
                        break;
                    }
                }
                if(!hit_yet){
                    if (character.hits_bottom_of_object(triangular_objects[i])
                    && character.hits_left_of_object(triangular_objects[i])){
                        if (((character.top_left().y + 5) <=
                        triangular_objects[i].get_block().bottom_left().y)){
                            hit_object_while_jumping_ = true;
                            reflect_character_left_(triangular_objects[i]);
                            break;
                        } else {
                            hit_object_while_jumping_ = true;
                            reflect_character_down_(triangular_objects[i]);
                            break;
                        }
                    }
                    if (character.hits_bottom_of_object(triangular_objects[i])){
                        hit_object_while_jumping_ = true;
                        reflect_character_down_(triangular_objects[i]);
                        break;
                    }
                    if (character.hits_left_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        reflect_character_left_(triangular_objects[i]);
                        break;
                    }

                    if (character.hits_upwards_slant(triangular_objects[i]))
                    {
                        hit_object_while_jumping_ = true;
                        character.set_center(character.on_slant_northeast(
                                triangular_objects[i]));
                        float proj = ((character.get_velocity().width
                                       + character.get_velocity().height) / 2);
                        character.set_velocity({proj, proj});
                    }
                }
                break;
            case Triangular_Object::Rotation::Northwest:
                for(size_t j = 0; j < objects.size(); j++){
                    if(objects[j].get_room() == room_ && character
                            .hits_top_of_object(objects[j]))
                    {
                        hit_yet = true;
                        break;
                    }
                    if(objects[j].get_room() == room_ &&
                       character.hits_left_of_object(objects[j]))
                    {
                        hit_yet = true;
                        reflect_character_left_(objects[j]);
                        break;
                    }
                }
                if(!hit_yet){
                    if (character.hits_bottom_of_object(triangular_objects[i])&&
                        character.hits_right_of_object(triangular_objects[i])){
                        if (((character.top_left().y + 5) <=
                        triangular_objects[i].get_block().bottom_left().y)){
                            hit_object_while_jumping_ = true;
                            reflect_character_right_(triangular_objects[i]);
                            break;
                        } else {
                            hit_object_while_jumping_ = true;
                            reflect_character_down_(triangular_objects[i]);
                            break;
                        }
                    }
                    if (character.hits_bottom_of_object(triangular_objects[i])){
                        hit_object_while_jumping_ = true;
                        reflect_character_down_(triangular_objects[i]);
                        break;
                    }
                    if (character.hits_right_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        reflect_character_right_(triangular_objects[i]);
                        break;
                    }
                    if (character.hits_upwards_slant(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        character.set_center(character.
                        on_slant_northwest(triangular_objects[i]));
                        float proj = (character.get_velocity().width
                                + (character.get_velocity().height * -1))/ 2;
                        character.set_velocity_width(proj);
                        character.set_velocity_height(proj * -1);
                    }
                }
                break;
            case Triangular_Object::Rotation::Southeast:
                for(size_t j = 0; j < objects.size(); j++){
                    if(objects[j].get_room() == room_ && character
                            .hits_top_of_object(objects[j]))
                    {
                        hit_yet = true;
                        break;
                    }
                    if(objects[j].get_room() == room_ &&
                       character.hits_right_of_object(objects[j]))
                    {
                        hit_yet = true;
                        reflect_character_right_(objects[j]);
                        break;
                    }
                }
                if(!hit_yet){
                    if (character.hits_top_of_object(triangular_objects[i]) &&
                        character.hits_left_of_object(triangular_objects[i])) {
                        if (((character.top_left().y +
                        character.get_dimensions().height - 5) >=
                        triangular_objects[i].get_block().top_left().y)) {
                            hit_object_while_jumping_ = true;
                            reflect_character_left_(triangular_objects[i]);
                            break;
                        } else {
                            hit_object_while_jumping_ = true;
                            put_character_on_object_(triangular_objects[i]);
                            break;
                        }
                    }
                    if (character.hits_top_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        put_character_on_object_(triangular_objects[i]);
                        break;
                    }
                    if (character.hits_left_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        reflect_character_left_(triangular_objects[i]);
                        break;
                    }
                    if (character.hits_downwards_slant(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        character.set_center(character
                        .on_slant_southeast(triangular_objects[i]));
                        if (character.get_velocity().width == 0) {
                            character.set_velocity({200, -20});
                        } else {
                            if (character.get_velocity().width > 0) {
                                character.scale_velocity_width(0.5);
                                character.set_velocity_height(-20);
                            }
                            if (character.get_velocity().width < 0) {
                                character.scale_velocity_width(-0.25);
                                character.set_velocity_height(-20);
                            }
                        }
                    }
                }
                break;
            case Triangular_Object::Rotation::Southwest:
                for(size_t j = 0; j < objects.size(); j++){
                    if(objects[j].get_room() == room_ && character
                            .hits_top_of_object(objects[j]))
                    {
                        hit_yet = true;
                        break;
                    }
                    if(objects[j].get_room() == room_ &&
                       character.hits_left_of_object(objects[j]))
                    {
                        hit_yet = true;
                        reflect_character_left_(objects[j]);
                        break;
                    }
                }
                if(!hit_yet){
                    if (character.hits_top_of_object(triangular_objects[i]) &&
                        character.hits_right_of_object(triangular_objects[i])) {
                        if (((character.top_left().y +character.get_dimensions()
                        .height - 5) >= triangular_objects[i].get_block()
                        .top_left().y)) {
                            hit_object_while_jumping_ = true;
                            reflect_character_right_(triangular_objects[i]);
                            break;
                        } else {
                            hit_object_while_jumping_ = true;
                            put_character_on_object_(triangular_objects[i]);
                            break;
                        }
                    }

                    if (character.hits_top_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        put_character_on_object_(triangular_objects[i]);
                        break;
                    }

                    if (character.hits_right_of_object(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        reflect_character_right_(triangular_objects[i]);
                        break;
                    }

                    if (character.hits_downwards_slant(triangular_objects[i])) {
                        hit_object_while_jumping_ = true;
                        character.set_center(character
                        .on_slant_southwest(triangular_objects[i]));
                        if (character.get_velocity().width == 0) {
                            character.set_velocity({-200, -20});
                        } else {
                            if (character.get_velocity().width < 0) {
                                character.scale_velocity_width(0.5);
                                character.set_velocity_height(-20);
                            }
                            if (character.get_velocity().width > 0) {
                                character.scale_velocity_width(-0.25);
                                character.set_velocity_height(-20);
                            }
                        }
                    }
                }
                break;
            }
        }
    }
}

void
Model::put_character_on_object_(Object const& object)
{
    character.set_center(character.on_block(object));
    character.set_velocity({250, 400});
    character.set_charstate(Character::Charstate::On_object);
    charge_ = 0;
}

void
Model::reflect_character_down_(Object const& object)
{
    character.set_center(character.below_block(object));
    character.scale_velocity_width(0.5);
    character.set_velocity_height(-20);
}

void
Model::reflect_character_left_(Object const& object)
{
    character.set_center(character.left_of_block(object));
    character.scale_velocity_width(-0.5);
}

void
Model::reflect_character_right_(Object const& object)
{
    character.set_center(character.right_of_block(object));
    character.scale_velocity_width(-0.5);
}
