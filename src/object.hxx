#pragma once

#include <ge211.hxx>
#include <iostream>

// Encapsulates the definitions of game objects in the world
// Objects can either be rectangular, right-triangular, or the end goal

/// HELPFUL TYPE ALIASES ///
using Position = ge211::Posn<float>;
using Dimensions = ge211::Dims<double>;
using Block = ge211::Rect<int>;

// Basic rectangular object in the world
class Object
{

public:

    /// CONSTRUCTOR ///

    // Constructs a rectangular object in the world with specified
    // position and dimensions
    Object(Position const& pos, Dimensions const& dims, int const& room);

    /// GETTERS/SETTERS ///

    // Getter for the block of this object, so ge211 block getter functions
    // like top_left() can be applied without changing the block
    Block get_block() const;

    // Getter for the room this object is in
    int get_room() const;

protected:

    /// PRIVATE MEMBER VARIABLES ///

    // Block to house the actual body of the object
    Block block_;

    // Which room this object is in
    int room_;
};

// Triangular object in the world.
// All triangular objects are right-triangles.
class Triangular_Object: public Object
{
public:

    // Defines which way the triangular object is facing.

    ///////////////////////////////////////////////////////////
    ///                                                     ///
    ///                     IMPORTANT:                      ///
    ///                                                     ///
    ///   The specified rotation is the direction of the    ///
    ///   OUTWARDS PERPENDICULAR VECTOR to the HYPOTENUSE   ///
    ///                                                     ///
    ///                      EXAMPLE:                       ///
    ///                                                     ///
    ///     ^                                               ///
    ///      \      X                                       ///
    ///       \   X X                                       ///
    ///         X   X         ==       NORTHWEST            ///
    ///       X     X                                       ///
    ///     X X X X X                                       ///
    ///                                                     ///
    ///////////////////////////////////////////////////////////

    enum class Rotation
    {
        Northeast,
        Northwest,
        Southeast,
        Southwest,
    };

    /// CONSTRUCTOR ///
    // Constructs a triangular object with specified position,
    // dimensions, and rotation
    Triangular_Object(Position const& pos, Dimensions const& dims, int
    const& room, Rotation const& rot);

    /// GETTERS/SETTERS ///
    // Getter for the rotation of this object.
    Rotation rotation() const;

private:
    /// PRIVATE MEMBER VARIABLES ///
    // Rotation of this object
    Rotation rotation_;
};

// Goalpost in the world. Identical to regular block class besides constructor.
class Goalpost : public Object
{
public:
    /// CONSTRUCTOR ///
    // Constructs a goalpost with specified position and dimensions
    Goalpost(Position const& pos, Dimensions const& dims, int const& room);
};