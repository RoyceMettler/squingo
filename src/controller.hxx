#pragma once

#include <ge211.hxx>
#include <iostream>
#include "model.hxx"
#include "character.hxx"
#include "view.hxx"

// The main game class for Jump King
class Controller : public ge211::Abstract_game
{
public:

    /// CONSTRUCTOR ///
    // Constructs a game. There are no parameters.
    explicit Controller();

protected:

    /// CONTROLLER OPERATIONS CALLED BY GE211 ///

    // Draws the sprites in the world
    void draw(ge211::Sprite_set& set) override;

    // Sets the initial window dimensions. I hard-coded the world in this
    // game so these are always 768 x 576.
    View::Dimensions initial_window_dimensions() const override;

    // Sets the initial window title to "Jump King".
    std::string initial_window_title() const override;

    // Calls the on_frame function from the model every frame.
    void on_frame(double dt) override;

    // Calls various model functions when keys are pressed down. This game
    // utilizes the left and right arrow keys and the space bar. r is used
    // to restart the game. q is used to quit the game.
    void on_key_down(ge211::Key) override;

    // Calls various model functions when keys are lifted.
    void on_key_up(ge211::Key) override;

    // Calls model functions when keys are pressed.
    void on_key(ge211::Key) override;

private:

    /// PRIVATE MEMBER VARIABLES ///

    // The model referenced by the controller
    Model model_;

    // The view referenced by the controller
    View view_;
};
