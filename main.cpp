#include <iostream>

#include "core/ringbuffer.h"
#include <cassert>

#include "gameplay/impl/cardbase.h"
#include "gameplay/gamecontext.h"
#include "gameplay/effects/doubletotalstrengtheffect.h"
#include "gameplay/effects/milldiscardeffect.h"
#include "gameplay/effects/onemoreturneffect.h"
#include "gameplay/effects/reduceenemystrengtheffect.h"
#include "gameplay/impl/humanplayer.h"

int main() {

    // REQUIREMENTS:
    // 2 players
    // card game
    // cards have strength
    // turns happen one after the other
    // cards are drawn from decks and they get resolved (strength added to total player strength)
    // game ends when the decks are both empty (if one ends up empty before, that player skips turns)
    // the winner is the person with the larger strength total
    // terminal application

    // INTERPRETATION:
    // the game itself is a ring buffer
    // into the ring buffer, we add different effects that resolve and change stuff
    //    (including adding new things into the buffer)
    // some of these come from the game (draw and resolve), and some come from the cards (strength up)

    GameContext gameContext{2};

    gameContext.AddPlayer(new HumanPlayer("A", {
        new CardBase("Double Trouble", 1, new DoubleTotalStrengthEffect()),
        new CardBase("Cutpurse", 1, new ReduceEnemyStrengthEffect()),
    }));

    gameContext.AddPlayer(new HumanPlayer("B", {
        new CardBase("Chrono", 2, new OneMoreTurnEffect()),
        new CardBase("Graverobber", 5, new MillDiscardEffect()) }));

    gameContext.Run();

    return 0;
}
