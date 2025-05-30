#ifndef GUARD_FISHING_GAME_ABILITY_MODIFIERS_H
#define GUARD_FISHING_GAME_ABILITY_MODIFIERS_H

#include "constants/abilities.h"

struct FishAbilityModifier
{
    u16 ability;
    s16 effectAmount;
    u16 operand;
    u16 effectType;
    u16 happensWhen;
    bool8 hasMoreEffects;
};

// Possible values for happensWhen
#define FG_HAPPENS_ALWAYS                       (1 << 0)
#define FG_HAPPENS_ON_START                     (1 << 1)
#define FG_HAPPENS_WHEN_FISH_INSIDE_BAR         (1 << 2)
#define FG_HAPPENS_WHEN_FISH_OUTSIDE_BAR        (1 << 3)
#define FG_HAPPENS_WHEN_TREASURE_INSIDE_BAR     (1 << 4)
#define FG_HAPPENS_WHEN_TREASURE_OUTSIDE_BAR    (1 << 5)

// Ability effect types
#define FG_EFFECT_BAR_SIZE                      (1 << 6) // Width of the fishing bar.
#define FG_EFFECT_FISH_SPEED                    (1 << 7) // Speed a fish travels during a movement.
#define FG_EFFECT_FISH_MOVE_DELAY               (1 << 8) // Delay between fish movements.
#define FG_EFFECT_FISH_MOVE_DISTANCE            (1 << 9) // How far a fish will travel in a movement.
#define FG_EFFECT_SCORE_INCREASE                (1 << 10) // How much the score will increase by every frame.
#define FG_EFFECT_SCORE_DECREASE                (1 << 11) // How much the score will decrease every frame.

// Operands for ability modifiers
#define FG_ADD                                  (1 << 12)
#define FG_SUBTRACT                             (1 << 13)
#define FG_MULTIPLY                             (1 << 14)
#define FG_DIVIDE                               (1 << 15)

static const struct FishAbilityModifier sAbilityEffects[] = 
{
    {0},
/*
    {
        .ability = ,
        .happensWhen = ,
        .effectType = ,
        .operand = ,
        .effectAmount = ,
        .hasMoreEffects = 
    },
*/
    {
        .ability = ABILITY_STICKY_HOLD,
        .happensWhen = FG_HAPPENS_WHEN_FISH_INSIDE_BAR,
        .effectType = FG_EFFECT_FISH_SPEED,
        .operand = FG_SUBTRACT,
        .effectAmount = 2,
        .hasMoreEffects = TRUE
    },
    {
        .ability = ABILITY_STICKY_HOLD,
        .happensWhen = FG_HAPPENS_ON_START,
        .effectType = FG_EFFECT_BAR_SIZE,
        .operand = FG_ADD,
        .effectAmount = 8,
        .hasMoreEffects = FALSE
    }
};

#endif // GUARD_FISHING_GAME_ABILITY_MODIFIERS_H
