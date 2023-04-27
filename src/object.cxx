#include "object.hxx"

Object::Object(Position const& pos, Dimensions const& dims, int const& room)
: block_(pos.x, pos.y, dims.width, dims.height),
  room_(room)

{ }

Block
Object::get_block() const
{
    return block_;
}

int
Object::get_room() const
{
    return room_;
}

Triangular_Object::Triangular_Object(Position const& pos, Dimensions const&
dims, int const& room, Triangular_Object::Rotation const& rot)
: Object(pos, dims, room), rotation_(rot)
{ }

Triangular_Object::Rotation Triangular_Object::rotation() const
{
    return rotation_;
}

Goalpost::Goalpost(Position const& pos, Dimensions const& dims, int const& room)
: Object(pos, dims, room)
{ }

