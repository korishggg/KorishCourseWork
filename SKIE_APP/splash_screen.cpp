#include "splash_screen.hpp"

#include <cstring>

#include <SFML/Graphics.hpp>

Splash_screen::Splash_screen( Game * game, std::string name )
    : Visible_game_object( game, name ),
      m_is_finished( false )
{}

void Splash_screen::Show( char const * image ) {
    if( strcmp( image, "" ) == 0 ) {
        Load( "/Users/korish/Desktop/SKIE-APP/SKIE_APP/SKIE_APP/images/splash_screen.png" );
    } else {
        Load( image );
    }
}

bool Splash_screen::Is_finished() {
    return m_is_finished;
}

void Splash_screen::Update() {
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ) {
        m_is_finished = true;
    }
}

void Splash_screen::Update( sf::Time elapsed_time ) {
    Update();
}
