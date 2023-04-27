#include "character.hxx"

Character::Character()
: walking_left_(false),
  walking_right_(false),
  wants_to_jump_(false),
  charstate_(Character::Charstate::Jumping),
  center_(634,556),
  dimensions_(30, 30),
  velocity_(0, 0)
{ }

bool
Character::hits_top() const
{
    if((Character::center_.y < 0)){
        return true;
    }
    return false;
}

bool
Character::hits_bottom() const
{
    if(Character::center_.y > 576){
        return true;
    }
    return false;
}

bool
Character::hits_object(Object const& object) const
{
    if ((Character::center_.x + (Character::dimensions_.width / 2) < object
            .get_block().top_left().x)
        || (Character::center_.x - (Character::dimensions_.width / 2) > object
            .get_block().bottom_right().x)){
        return false;
    }

    if ((top_left().y + dimensions_.height < object
            .get_block().top_left().y)
        || (top_left().y > object.get_block().bottom_right().y)){
        return false;
    }

    return true;
}

bool
Character::hits_left_of_object(Object const& object) const
{
    if(hits_object(object))
    {
        Object temp = Object({object.get_block().top_left()
                              .into<float>().x - dimensions_.into<float>()
                                      .width - 1,
                              object.get_block().top_left().into<float>().y},
                             {dimensions_.width,
                              object.get_block().dimensions()
                              .into<double>().height}, object.get_room());
        if(hits_object(temp)){
            return true;
        }
    }
    return false;
}

bool
Character::hits_right_of_object(Object const& object) const
{
    if(hits_object(object))
    {
        Object temp = Object({object.get_block().top_right()
                              .into<float>().x + 1,
                              object.get_block().top_left().into<float>().y},
                             {dimensions_.width,
                              object.get_block().dimensions()
                              .into<double>().height}, object.get_room());
        if(hits_object(temp)){
            return true;
        }
    }
    return false;
}

bool
Character::hits_top_of_object(Object const& object) const
{
    if(hits_object(object))
    {
        Object temp = Object({object.get_block().top_left()
                              .into<float>().x,
                              object.get_block().top_left().into<float>().y
                              - dimensions_.into<float>().height},
                             {object.get_block().dimensions()
                             .into<double>().width,dimensions_.height},
                             object.get_room());
        if (hits_object(temp)){
            return true;
        }
    }
    return false;
}

bool
Character::hits_bottom_of_object(Object const& object) const
{
    if(hits_object(object))
    {
        Object temp = Object({object.get_block().top_left()
                              .into<float>().x,
                              object.get_block().bottom_left()
                              .into<float>().y + 1},
                             {object.get_block().dimensions()
                             .into<double>().width,dimensions_
                                     .height}, object.get_room());
        if (hits_object(temp)){
            return true;
        }
    }
    return false;
}

bool
Character::hits_upwards_slant(Triangular_Object const& object) const
{
    if(hits_object(object)){
        switch (object.rotation()) {
        case Triangular_Object::Rotation::Northeast:
            if((center_.y + (dimensions_.height / 2) +
                ((object.get_block().center().x * 2) - top_left().x))
                >= (object.get_block().center().y +
                object.get_block().center().x))
            {
                return true;
            }
            return false;

        case Triangular_Object::Rotation::Northwest:
            if(((center_.y + (dimensions_.height / 2)) +
                (center_.x + (dimensions_.width / 2))) >=
               (object.get_block().center().y + object.get_block().center().x))
            {
                return true;
            }
            return false;
        default:
            return false;
        }
    } else {
        return false;
    }
}

bool
Character::hits_downwards_slant(Triangular_Object const& object) const
{
    if(hits_object(object)){
        switch (object.rotation()) {
        case Triangular_Object::Rotation::Southeast:
            if(((Character::center_.y - (Character::dimensions_.height / 2)) +
                (Character::center_.x - (Character::dimensions_.width / 2))) <=
               (object.get_block().center().y + object.get_block().center().x))
            {
                return true;
            }

            return false;
        case Triangular_Object::Rotation::Southwest:
            if( ( (Character::center_.y - (Character::dimensions_.height / 2)) -
                  (Character::center_.x + (Character::dimensions_.width / 2)))
                  <= (object.get_block().center().y -
                  object.get_block().center().x))
            {
                return true;
            }
            return false;

        default:
            return false;
        }
    } else {
        return false;
    }
}

bool Character::hits_goalpost(Goalpost const& goalpost) const
{
    if(Character::hits_object(goalpost)){
        return true;
    }
    return false;
}

Position
Character::top_left() const
{
    float x = center_.x - (dimensions_.width / 2);
    float y = center_.y - (dimensions_.height / 2);
    return{x, y};
}

Position
Character::on_block(Object const& object) const
{
    float x = center_.x;
    float y = object.get_block().top_left().y - (0.5 * dimensions_.height);
    return {x, y};
}

Position
Character::left_of_block(Object const& object) const
{
    float x = object.get_block().top_left().x - (0.5 * dimensions_.width);
    float y = center_.y;
    return{x, y};
}

Position
Character::right_of_block(Object const& object) const
{
    float x = object.get_block().top_right().x + (0.5 * dimensions_.width);
    float y = center_.y;
    return{x, y};
}

Position
Character::below_block(Object const& object) const
{
    float x = center_.x;
    float y = object.get_block().bottom_left().y + 1 +
            (0.5 * dimensions_.height);
    return {x, y};
}

Position
Character::on_slant_northeast(Triangular_Object const& object) const
{
    float char_pos_sum = (top_left().y + dimensions_.height - 1) +
            ((object.get_block().center().x * 2) - top_left().x);
    float obj_center_sum = object.get_block().center().y +
            object.get_block().center().x;
    float xydistance = (char_pos_sum - obj_center_sum) / 2;
    return{center_.x + xydistance + 1, center_.y - xydistance - 1};
}

Position
Character::on_slant_northwest(Triangular_Object const& object) const
{
    float char_pos_sum = top_left().y + top_left().x + dimensions_.width +
            dimensions_.height - 2;
    float obj_center_sum = object.get_block().center().y
            + object.get_block().center().x;
    float xydistance = (char_pos_sum - obj_center_sum) / 2;
    return{center_.x - xydistance - 1, center_.y - xydistance - 1};
}

Position
Character::on_slant_southeast(Triangular_Object const& object) const
{
    float char_pos_sum = top_left().y + top_left().x;
    float obj_center_sum = object.get_block().center().y
            + object.get_block().center().x;
    float xydistance = (obj_center_sum - char_pos_sum) / 2;
    return{center_.x + xydistance + 1, center_.y + xydistance + 1};
}

Position
Character::on_slant_southwest(Triangular_Object const& object) const
{
    float char_pos_diff = top_left().y - (top_left().x + dimensions_.width - 1);
    float obj_center_diff = object.get_block().center().y
            - object.get_block().center().x;
    float xydistance = (obj_center_diff - char_pos_diff) / 2;
    return{center_.x - xydistance - 1, center_.y + xydistance + 1};
}

Character
Character::next(double dtx, double dty) const
{
    Character result(*this);
    result.center_.x += dtx * result.velocity_.width;
    result.center_.y += dty * result.velocity_.height;
    return result;
}

bool
Character::get_walking_left() const
{
    return walking_left_;
}

bool
Character::get_walking_right() const
{
    return walking_right_;
}

bool
Character::get_wants_to_jump() const
{
    return wants_to_jump_;
}

Character::Charstate
Character::get_charstate() const
{
    return charstate_;
}

Position
Character::get_center() const
{
    return center_;
}

Dimensions
Character::get_dimensions() const
{
    return dimensions_;
}

Velocity
Character::get_velocity() const
{
    return velocity_;
}

void
Character::set_walking_left(bool set)
{
    walking_left_ = set;
}

void
Character::set_walking_right(bool set)
{
    walking_right_ = set;
}

void
Character::set_wants_to_jump(bool set)
{
    wants_to_jump_ = set;
}

void
Character::set_charstate(Charstate set)
{
    charstate_ = set;
}

void
Character::set_center(Position set)
{
    center_ = set;
}

void
Character::set_velocity(Velocity set)
{
    velocity_ = set;
}

void
Character::set_velocity_width(float set)
{
    velocity_.width = set;
}

void
Character::set_velocity_height(float set)
{
    velocity_.height = set;
}

void
Character::scale_velocity_width(float set)
{
    velocity_.width = velocity_.width * set;
}

void
Character::scale_velocity_height(float set)
{
    velocity_.height = velocity_.height * set;
}

void Character::add_to_velocity_height(float set)
{
    velocity_.height = velocity_.height + set;
}