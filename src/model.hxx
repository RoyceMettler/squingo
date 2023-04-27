#pragma once

#include <ge211.hxx>
#include <iostream>
#include "character.hxx"
#include "object.hxx"

// Represents the state of the game squingo
class Model
{
public:
    /// CONSTRUCTOR ///
    // Constructs a model. The objects are placed manually by me within the
    // model source file.
    explicit Model();

    /// PUBLIC VARIABLES ///
    // These variables are accessed by the controller and the view, so they
    // are public.

    // The vector of all rectangular objects in the world
    std::vector<Object> objects;

    // The vector of all triangular objects in the world
    std::vector<Triangular_Object> triangular_objects;

    // The goalpost in the world
    Goalpost goalpost = Goalpost({500, 100}, {92, 93}, 5);

    // The character in the world
    Character character;

    // Whether the player has won the game
    bool win = false;

    // Whether the game is live
    bool live = false;

    // Whether the start screen is on screen 1 or screen 2 (1 = false, 2 = true)
    bool startscreen = false;

    /// PUBLIC MEMBER FUNCTIONS ///

    // Updates the state of the game every frame according to a TON of rules.
    // Check the definition in the source file for a full breakdown of each
    // rule.
    void on_frame(double dt);

    // Makes the character jump.
    void jump();

    /// GETTERS / SETTERS ///

    // Returns the value of the private int room_.
    int get_room() const;

    // Sets the value of the private int room_ to an input.
    void set_room(int set);

    // Returns the value of the private int duration_.
    int get_duration() const;

    // Returns the value of the private int fall_distance_.
    int get_fall_distance() const;

    // Returns the value of the private bool animation_state_.
    bool get_animation_state() const;

    // Returns the value of the private bool hit_object_while_jumping_.
    bool get_hit_object_while_jumping() const;

    // Returns the jump count at the end of the game.
    int get_jump_count() const;

    // Returns the fall count at the end of the game.
    int get_fall_count() const;

    // Gets the private int gravity_
    int get_gravity() const;

    // Sets the private int gravity_
    void set_gravity(int set);

private:

    /// PRIVATE HELPER FUNCTIONS FOR ON_FRAME()///

    // Helper function for on_frame().
    // Tracks how many objects the character is currently touching.
    // Necessary to determine when the player hits an object while
    // walking, in which case their movement is halted.
    void track_object_collision_();

    // Helper function for on_frame().
    // Tracks which room the player is currently in. Also places player at
    // the bottom of the next room if they reach the top, and at the top of
    // the previous room if they fall through the bottom.
    // Necessary to determine which objects should be loaded into the world
    // and to ensure the player is in the correct room.
    void track_room_();

    // Helper function for on_frame().
    // Tracks the duration for which the player has been walking in a
    // direction, so the view knows when to update the character walking sprite.
    void track_duration();

    // Helper function for on_frame().
    // Tracks the distance the player fell during a jump.
    void track_fall_distance();

    // Helper function for on_frame().
    // Tracks whether a player walks off a block while moving to the left.
    // If so, causes the player to fall off the block.
    void fall_off_object_left_();

    // Helper function for on_frame().
    // Tracks whether a player walks off a block while moving to the right.
    // If so, causes the player to fall off the block.
    void fall_off_object_right_();

    // Helper function for on_frame().
    // Called at the beginning of every frame. Resets the value of
    // object_collision_ to 0 and hit_object_while_walking to false.
    // Necessary because the character would get stuck in place indefinitely
    // when they walked into an object before I implemented this.
    void reset_();

    // Helper function for on_frame().
    // Called every frame that a player is jumping (has the character state
    // jumping). Determines what happens when a player hits a rectangular
    // object in the world. If they hit it from the side, they ricochet off
    // and their x-velocity is cut in half. If they hit it from the bottom,
    // they ricochet downwards and their x-velocity is cut in half. If they
    // hit it from the top, they land on it and their state is set to on_object.
    // Also handles some bugs I encountered when the character would hit the
    // corner of an object and not know whether to ricochet off the side or
    // to land on/ricochet off the bottom.
    void object_behavior_();

    // Helper function for on_frame().
    // Called every frame that a player is jumping (has the character state
    // jumping). Determines what happens when a player hits a triangular
    // object in the world.
    //
    // If they hit it from the non-hypotenuse side, the object is treated as
    // rectangular and the rules from object_behavior_() are applied.
    //
    // If they hit it on the hypotenuse and the triangular object is facing
    // up (it is either northwest or northeast), they begin to slide up or
    // down it according to the velocity with which they hit it. This is done
    // via projecting their velocity vector onto the vector of the slope of
    // the object. Once they slide all the way off it, they retain their new
    // velocities and are midair once more.
    //
    // If they hit it on the hypotenuse and it faces downwards (it is either
    // southwest or southeast), they ricochet diagonally downwards off of it
    // depending on the velocity vector with which they hit it.
    //
    // Also handles the same bugs as described in object_behavior_().
    void triangular_object_behavior_();

    /// PRIVATE HELPER FUNCTIONS FOR OBJECT_BEHAVIOR_() ///

    // Helper function for object_behavior_().
    // Sets the character's position to be that of them landing on top of
    // an object if object_behavior() determines they do so. Sets their state
    // to on_object and resets their velocity.
    void put_character_on_object_(Object const&);

    // Helper function for object_behavior_().
    // Reflects a character off the bottom of an object and adjusts their
    // velocity according to the description in object_behavior_().
    void reflect_character_down_(Object const&);

    // Helper function for object_behavior_().
    // Reflects a character off the left side of an object and adjusts their
    // velocity according to the description in object_behavior_().
    void reflect_character_left_(Object const&);

    // Helper function for object_behavior_().
    // Reflects a character off the right side of an object and adjusts their
    // velocity according to the description in object_behavior_().
    void reflect_character_right_(Object const&);

    /// PRIVATE MEMBER VARIABLES ///

    // The charge with which the character jumps. It increases every frame
    // they charge up their jump until the player releases the space bar or
    // it hits 2, at which point the character jumps with that amount of force.
    double charge_ = 0;

    // Whether a character has run into an object while walking, because if
    // they did their movement should be halted.
    bool hit_object_while_walking_ = false;

    // The amount of objects a player is hitting at any given time.
    int object_collision_ = 0;

    // The grace period the player has between lifting the left arrow key and
    // lifting the space bar in which they will still jump in that direction.
    // I implemented this because sometimes I would release the arrow key
    // slightly before the space bar and I'd jump straight up, which was
    // annoying. This makes the controls a lot smoother.
    int jumping_left_grace_period_ = 0;

    // The grace period the player has between lifting the right arrow key and
    // lifting the space bar in which they will still jump in that direction.
    // I implemented this because sometimes I would release the arrow key
    // slightly before the space bar and I'd jump straight up, which was
    // annoying. This makes the controls a lot smoother.
    int jumping_right_grace_period_ = 0;

    // The current room the player is in.
    int room_ = 6;

    // Duration that handles character walking animation.
    int duration_ = 0;

    // "helper" int for fall_distance_ that remembers where the player
    // started their jump from.
    int jump_initial_y = 556;

    // "helper" int for fall_distance_ that knows whether the fall count has
    // been incremented by one already.
    bool updated_fall_count_already_ = false;

    // Fall distance that determines whether the character has been in the air
    // long enough that they pretty likely didn't make the jump they wanted
    // to and fell down.
    int fall_distance_ = 0;

    // Bool that tracks which way the character sprite should face. True =
    // right, false = left.
    bool animation_state_ = true;

    // Bool that tracks whether a character has hit an object yet while
    // jumping. Necessary for character sprite animation.
    bool hit_object_while_jumping_ = false;

    // The number of jumps the player has done over the course of the game,
    // to be displayed on the end screen.
    int jump_count_ = 0;

    // The number of falls the player has taken over the course of the game,
    // to be displayed on the end screen.
    int fall_count_ = 0;

    // Added this after turning it in. For some reason the gravity would
    // sometimes be altered based on I think how fast the computer running
    // the game is ??? ge211 moment.
    int gravity_ = 11;

};
