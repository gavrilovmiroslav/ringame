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
        gameplay/impl/cardbase.cpp
        gameplay/impl/cardbase.h
        gameplay/effects/strengthupeffect.cpp
        gameplay/effects/strengthupeffect.h
        gameplay/effects/gameoverifemptyeffect.cpp
        gameplay/effects/gameoverifemptyeffect.h
        gameplay/effects/doubletotalstrengtheffect.cpp
        gameplay/effects/doubletotalstrengtheffect.h
        gameplay/effects/onemoreturneffect.cpp
        gameplay/effects/onemoreturneffect.h
        gameplay/effects/reduceenemystrengtheffect.cpp
        gameplay/effects/reduceenemystrengtheffect.h
        gameplay/effects/milldiscardeffect.cpp
        gameplay/effects/milldiscardeffect.h
)
