cmake_minimum_required(VERSION 4.2)
project(ringame)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED)

add_executable(ringame main.cpp
        core/ringbuffer.cpp
        core/ringbuffer.h
        core/random.h
        core/uuid.h
        gameplay/gamecontext.h
        gameplay/gamecontext.cpp
        gameplay/iplayer.h
        gameplay/card.h
        gameplay/ieffect.h
        gameplay/impl/humanplayer.cpp
        gameplay/impl/humanplayer.h
        gameplay/effects/performplayerturneffect.cpp
        gameplay/effects/performplayerturneffect.h
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
        gameplay/effects/milldiscardstealeffect.cpp
        gameplay/effects/milldiscardstealeffect.h
        gameplay/effects/spawnminionseffect.cpp
        gameplay/effects/spawnminionseffect.h
        gameplay/ecardresolutionbehavior.h
        gameplay/effects/spawntrapeffect.cpp
        engine/appstate.cpp
        engine/appstate.h
        gameplay/registry.cpp
        gameplay/registry.h
        gameplay/card.cpp
        gameplay/library.h
)

target_link_libraries(ringame PRIVATE SDL3::SDL3)