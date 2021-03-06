#include "moving_game_object.hpp"
#include "moving_game_object_manager.hpp"

Moving_game_object_manager::Moving_game_object_manager()
    : m_focused_object_y( 0 )
{}

Moving_game_object_manager::~Moving_game_object_manager() {

}

Moving_game_object_manager  g_moving_game_object_manager;

// static
void Moving_game_object_manager::Initialize( Game * game ) {
    g_moving_game_object_manager.m_game = game;
}

// static
Moving_game_object_manager *    Moving_game_object_manager::Instance() {
    return &g_moving_game_object_manager;
}

Game * Moving_game_object_manager::Game_instance() {
    return m_game;
}

void Moving_game_object_manager::Register_object( Moving_game_object * object ) {
    m_objects.push_back( object );
}

void Moving_game_object_manager::Deregister_object( Moving_game_object * object ) {
    for( std::vector< Moving_game_object * >::iterator object_it = m_objects.begin();
         object_it != m_objects.end();
         ++object_it )
    {
        if( object == *object_it ) {
            m_objects.erase( object_it );
            break;
        }
    }
}

void Moving_game_object_manager::Set_focused_object(Moving_game_object * focus_object ) {
    m_focused_object = focus_object;
}

void Moving_game_object_manager::Set_focused_object_y( unsigned int focused_object_y ) {
    m_focused_object_y = focused_object_y;
}

Moving_game_object const * Moving_game_object_manager::Get_focused_object() const {
    return const_cast< Moving_game_object const * >( m_focused_object );
}

void Moving_game_object_manager::Handle_object_move( Moving_game_object * object,
                                                     float x,
                                                     float y ) {
    if( object == m_focused_object ) {
        object->Set_position( object->Get_position().x, m_focused_object_y );
        for( std::vector< Moving_game_object * >::iterator it = m_objects.begin();
             it != m_objects.end();
             ++it )
        {
            if( *it != object ) {
                (*it)->Move( 0, -y, false );
            }
        }
    }
}
