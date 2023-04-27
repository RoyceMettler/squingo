#pragma once

#include "model.hxx"
#include <ge211.hxx>

class Model;

struct View
{
public:

    /// HELPFUL TYPE ALIASES ///
    using Dimensions = ge211::Dims<int>;
    using Position = ge211::Posn<int>;

    /// CONSTRUCTOR ///
    // Constructs a new view given a model as an input
    explicit View(Model const& model);

    /// PUBLIC MEMBER FUNCTIONS ///

    // Sets the initial window dimensions of the screen to be 768 x 512.
    Dimensions initial_window_dimensions() const;

    // Sets the initial window title of the screen to be "Squingo"
    std::string initial_window_title() const;

    // Draws the state of the game each frame based on the model.
    void draw(ge211::Sprite_set& set);

private:

    /// PRIVATE HELPER FUNCTIONS ///


    // Sets the background to be correct based on the room the character is
    // currently in.
    void draw_background_(ge211::Sprite_set&) const;

    // Sets the character sprite to one of its possible eight versions
    // depending on what the character is doing.
    void draw_character_(ge211::Sprite_set&, Position) const;

    // Draws the victory screen when the player has won the game
    void draw_start_screen_(ge211::Sprite_set&) const;

    // Draws the gravity selection screen
    void draw_gravity_screen_(ge211::Sprite_set&);

    // Draws the character in the gravity selection screen.
    void draw_character_gravity_screen_(ge211::Sprite_set&, Position) const;

    // Draws the victory screen when the player has won the game
    void draw_victory_screen_(ge211::Sprite_set&);

    // Helper function for draw_victory_screen_. Draws the character in the
    // screen.
    void draw_character_victory_screen_(ge211::Sprite_set&, Position) const;

    /// PRIVATE VARIABLES ///

    // The model to be referenced by the view.
    Model const& model_;

    /// GAME SPRITES ///

    // A vector to be populated with the sprite for each rectangular object
    // based on the list of objects passed to the view by the model.
    std::vector<ge211::Rectangle_sprite> object_sprites_;

    // A bunch of static sprites that are all populated with images in the
    // "Resources" file when the view is constructed.
    ge211::Image_sprite const triangular_object_northwest_;
    ge211::Image_sprite const triangular_object_northeast_;
    ge211::Image_sprite const triangular_object_southwest_;
    ge211::Image_sprite const triangular_object_southeast_;
    ge211::Image_sprite const idle_sprite_right_;
    ge211::Image_sprite const walking_sprite_frame_one_right_;
    ge211::Image_sprite const walking_sprite_frame_two_right_;
    ge211::Image_sprite const start_jumping_sprite_;
    ge211::Image_sprite const jumping_sprite_positive_right_;
    ge211::Image_sprite const jumping_sprite_negative_right_;
    ge211::Image_sprite const hit_sprite_right_;
    ge211::Image_sprite const fell_sprite_right_;
    ge211::Image_sprite const background_room_1_;
    ge211::Image_sprite const background_room_2_;
    ge211::Image_sprite const background_room_3_;
    ge211::Image_sprite const background_room_4_;
    ge211::Image_sprite const background_room_5_;
    ge211::Image_sprite const background_end_screen_;
    ge211::Image_sprite const goalpost_sprite_;
    ge211::Font const font_;
    ge211::Text_sprite const start_screen_; // Squingo
    ge211::Text_sprite const start_screen_2_; // Help squingo get to the
    // spaceship.
    ge211::Text_sprite const start_screen_3_; // Good luck!
    ge211::Text_sprite const start_screen_4_; // controls:
    ge211::Text_sprite const start_screen_5_; // Arrow keys = Move left/right
    ge211::Text_sprite const start_screen_6_; // Hold space bar = charge jump
    ge211::Text_sprite const start_screen_7_; // Release space bar = jump
    ge211::Text_sprite const start_screen_8_; // Release space bar + arrow
    ge211::Text_sprite const start_screen_9_; // key = jump left/right
    ge211::Text_sprite const start_screen_10_; // R = restart
    ge211::Text_sprite const start_screen_11_; // Press enter to begin!
    ge211::Text_sprite const gravity_screen_1_; // Set gravity
    ge211::Text_sprite const gravity_screen_2_; // Use the arrow
    ge211::Text_sprite const gravity_screen_3_; // keys to change
    ge211::Text_sprite const gravity_screen_4_; // the gravity until
    ge211::Text_sprite const gravity_screen_5_; // Squingo can jump
    ge211::Text_sprite const gravity_screen_6_; // above the line.
    ge211::Text_sprite const gravity_screen_7_; // Or just change it to
    ge211::Text_sprite const gravity_screen_8_; // whatever you want I guess
    ge211::Text_sprite const gravity_screen_9_; // Gravity:
    ge211::Text_sprite gravity_screen_10_; // gravity in int format
    ge211::Rectangle_sprite const gravity_screen_11_;
    ge211::Rectangle_sprite const gravity_screen_12_;
    ge211::Text_sprite const gravity_screen_13_; // Press enter to continue.
    ge211::Text_sprite const end_screen_; // You win!
    ge211::Text_sprite const end_screen_2_; // Thanks for playing
    ge211::Text_sprite const end_screen_3_; // Total jumps:
    ge211::Text_sprite const end_screen_4_; // Total falls:
    ge211::Text_sprite end_screen_5_; // total jumps in int format
    ge211::Text_sprite end_screen_6_; // total falls in int format


};
