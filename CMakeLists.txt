cmake_minimum_required(VERSION 4.2)
project(ringame)

set(CMAKE_CXX_STANDARD 23)

add_executable(ringame main.cpp
        core/ringbuffer.cpp
        core/ringbuffer.h
        gameplay/gamecontext.h
        gameplay/gamecontext.cpp
        gameplay/iplayer.h
        gameplay/icard.h
        gameplay/ieffect.h
        gameplay/impl/humanplayer.cpp
        gameplay/impl/humanplayer.h
        gameplay/effects/performplayerturneffect.cpp
        gameplay/effects/performplayerturneffect.h
        gameplay/cardbase.cpp
        gameplay/cardbase.h
        gameplay/effects/strengthupeffect.cpp
        gameplay/effects/strengthupeffect.h
        gameplay/effects/gameoverifemptyeffect.cpp
        gameplay/effects/gameoverifemptyeffect.h
)
