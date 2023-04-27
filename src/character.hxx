#pragma once

#include <iostream>
#include <ge211.hxx>
#include "object.hxx"

// Encapsulates the character in the world and its associated
// functions that define its interaction with objects in the world

/// HELPFUL TYPE ALIASES ///
using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;
using Dimensions = ge211::Dims<double>;
using Block = ge211::Rect<int>;

// The character in the world
class Character
{
public:

    // Defines the current state of the character. It can either be
    // on an object, charging up a jump, or in the air.
    enum class Charstate
    {
        On_object,
        Start_Jumping,
        Jumping,
    };

    /// CONSTRUCTOR ///
    // Constructs a character. This is only done once, when the game
    // is launched, so it doesn't need to follow any specific parameters
    // apart from setting the member variables manually in the associated
    // .cxx file.
    explicit Character();

    ///////////////////////////////
    /// PUBLIC MEMBER FUNCTIONS ///
    ///////////////////////////////

        /// Character Collision Booleans ///

    // Determines whether the center of the character hits the top
    // of the screen window.
    bool hits_top() const;

    // Determines whether the center of the character hits the bottom
    // of the screen window.
    bool hits_bottom() const;

    // Determines whether any edge of the character hits any edge
    // of an object and remains true if any part of the character
    // is inside any part of the object. The model calls it by
    // itself, but it also doubles as a helper function for every
    // other object-interaction boolean in this class. Neat!
    bool hits_object(Object const&) const;

    // Determines whether the right edge of the character hits
    // the left edge of an object.
    bool hits_left_of_object(Object const&) const;

    // Determines whether the left edge of the character hits
    // the right edge of an object.
    bool hits_right_of_object(Object const&) const;

    // Determines whether the bottom edge of the character hits
    // the top edge of an object.
    bool hits_top_of_object(Object const&) const;

    // Determines whether the top edge of the character hits
    // the bottom edge of an object.
    bool hits_bottom_of_object(Object const&) const;

    // Determines whether the bottom right corner of the character
    // hits the hypotenuse of a northwest-oriented triangular object
    // or whether the bottom left corner of a character hits the
    // hypotenuse of a northeast-oriented triangular object.
    bool hits_upwards_slant(Triangular_Object const&) const;

    // Determines whether the top right corner of the character hits
    // the hypotenuse of a southwest-oriented triangular object or
    // whether the top left corner of the character hits the hypotenuse
    // of a southeast-oriented triangular object.
    bool hits_downwards_slant(Triangular_Object const&) const;

    // Determines whether a character hits the goalpost. Same definition as
    // hits_object.
    bool hits_goalpost(Goalpost const&) const;

        /// Basic Character Positions ///

    // The top-left corner of the character    .
    Position top_left() const;

        /// Character Positions Relative to Objects ///

    // Maintains x, sets y so that character is sitting on an object.
    Position on_block(Object const&) const;

    // Sets x so that character is to the left of an object, maintains y.
    Position left_of_block(Object const&) const;

    // Sets x so that character is to the right of an object, maintains y.
    Position right_of_block(Object const&) const;

    // Maintains x, sets y so that character is directly blow an object.
    Position below_block(Object const&) const;

    // Sets x and y so that the bottom-left corner of the character is
    // diagonally above the hypotenuse of a northeast-oriented object
    // relative to where the character hit the hypotenuse of that object.
    Position on_slant_northeast(Triangular_Object const&) const;

    // Sets x and y so that the bottom-right corner of the character is
    // diagonally above the hypotenuse of a northwest-oriented object
    // relative to where the character hit the hypotenuse of that object.
    Position on_slant_northwest(Triangular_Object const&) const;

    // Sets x and y so that the top-left corner of the character is
    // diagonally below the hypotenuse of a southeast-oriented object
    // relative to where the character hit the hypotenuse of that object.
    Position on_slant_southeast(Triangular_Object const&) const;

    // Sets x and y so that the top-right corner of the character is
    // diagonally below the hypotenuse of a southwest-oriented object
    // relative to where the character hit the hypotenuse of that object.
    Position on_slant_southwest(Triangular_Object const&) const;

        /// Character copier relative to framerate ///

    // Creates a new instance of a character and sets its position to its
    // change over time according to its velocity and the framerate
    Character next(double dtx, double dty) const;

    ///////////////////////
    /// GETTERS/SETTERS ///
    ///////////////////////

    // Returns the value of private bool walking_left_.
    bool get_walking_left() const;

    // Returns the value of private bool walking_right_.
    bool get_walking_right() const;

    // Returns the value of private bool wants_to_jump_.
    bool get_wants_to_jump() const;

    // Returns the value of private charstate charstate_.
    Charstate get_charstate() const;

    // Returns the value of private position center_.
    Position get_center() const;

    // Returns the value of private dimensions dimensions_.
    Dimensions get_dimensions() const;

    // Returns the value of private velocity velocity_.
    Velocity get_velocity() const;

    // Sets the value of private bool walking_left_ to an input.
    void set_walking_left(bool);

    // Sets the value of private bool walking_right_ to an input.
    void set_walking_right(bool);

    // Sets the value of private bool wants_to_jump_ to an input.
    void set_wants_to_jump(bool);

    // Sets the value of private charstate charstate_ to an input.
    void set_charstate(Charstate);

    // Sets the value of private position position_ to an input.
    void set_center(Position);

    // Sets the value of private velocity velocity_ to an input.
    void set_velocity(Velocity);

    // Sets the value of the width of private velocity velocity_ to an input.
    void set_velocity_width(float);

    // Sets the value of the height of private velocity velocity_ to an input.
    void set_velocity_height(float);

    // Scales the width of private velocity velocity_ by an input.
    void scale_velocity_width(float);

    // Scales the height of private velocity velocity_ by an input.
    void scale_velocity_height(float);

    // Increases the height of private velocity velocity_ by an input.
    void add_to_velocity_height(float);

private:

    ////////////////////////////////
    /// PRIVATE MEMBER VARIABLES ///
    ////////////////////////////////

    // Whether the character is walking to the left.
    bool walking_left_;

    // Whether the character is walking to the right.
    bool walking_right_;

    // Whether the character wants to jump. This is for if they are in
    // the air but the player has the space bar held down. The character
    // will start the jump animation upon landing on a block.
    bool wants_to_jump_;

    // The state of the character: on a block, charging up a jump, or midair.
    Charstate charstate_;

    // The position of the center of the character.
    Position center_;

    // The dimensions of the character.
    Dimensions dimensions_;

    // The velocity of the character.
    Velocity velocity_;
};