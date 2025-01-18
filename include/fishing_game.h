#ifndef GUARD_FISHING_GAME_H
#define GUARD_FISHING_GAME_H

// Fishing Bar
#define FISHING_BAR_WIDTH           40   // The width of the fishing bar in number of pixels. Cannot be below 33 or above 64.
#define FISHING_BAR_MAX_SPEED       50   // The greater the number, the faster the bar is allowed to go.
#define FISHING_BAR_BOUNCINESS      1.3  // The greater the number, the less the bar will bounce when it hits the left side. (Decimals are encouraged, as a little goes a long way.)
#define BAR_SPEED_MODIFIER          (FISHING_BAR_MAX_SPEED / (FISHING_BAR_MAX_SPEED / 2.0)) // The greater the number value (the 2.0), the slower the bar changes speed. (Decimals are encouraged, as a little goes a long way.)

#define FISHING_AREA_WIDTH          202  // The width of the total fishing bar area in number of pixels.
#define FISHING_BAR_Y               102
#define FISHING_BAR_START_X         35
#define FISHING_BAR_SEGMENT_WIDTH   32
#define FISHING_BAR_WIDTH_ADJUST    (FISHING_BAR_WIDTH - FISHING_BAR_SEGMENT_WIDTH) // Adjustment for the fishing bar width.
#define POSITION_ADJUSTMENT         10   // Multiplier to make values larger so decimal places are retained.
#define FISHING_BAR_MAX             ((FISHING_AREA_WIDTH - FISHING_BAR_WIDTH) * POSITION_ADJUSTMENT)

// Score Meter
#define STARTING_SCORE              300  // The number of points you already have when the game starts.
#define SCORE_INCREASE              3    // The score increases by this many point every frame while the fish is within the bar.
#define SCORE_DECREASE              5    // The score decreases by this many point every frame while the fish is outside the bar.
#define SCORE_MAX                   1920 // The number of points required to win. Must be divisible by SCORE_AREA_WIDTH.

#define SCORE_AREA_WIDTH            192  // The width of the total score meter area in number of pixels.
#define SCORE_AREA_OFFSET           24   // Position of the left edge of the score area.
#define SCORE_BAR_OFFSET            ((SCORE_SECTION_WIDTH / 2) - SCORE_AREA_OFFSET) // Sets the score position in relation to SCORE_AREA_OFFSET.
#define SCORE_INTERVAL              (SCORE_MAX / SCORE_AREA_WIDTH)
#define SCORE_SECTION_INIT_X        ((STARTING_SCORE / SCORE_INTERVAL) - SCORE_BAR_OFFSET)
#define SCORE_SECTION_INIT_Y        80
#define SCORE_SECTION_WIDTH         64   // The width of one score meter section sprite in number of pixels.
#define NUM_SCORE_SECTIONS          (SCORE_AREA_WIDTH / SCORE_SECTION_WIDTH)
#define NUM_COLOR_INTERVALS         64
#define SCORE_COLOR_INTERVAL        (SCORE_AREA_WIDTH / NUM_COLOR_INTERVALS)
#define SCORE_THIRD_SIZE            (SCORE_AREA_WIDTH / 3)

// Pokemon Icon
#define FISH_FIRST_MOVE_DELAY       0.8 // Number of seconds before the fish will make its first movement.
#define FISH_ICON_HITBOX_WIDTH      12

#define FISH_ICON_WIDTH             32
#define FISH_ICON_Y                 99
#define FISH_ICON_START_X           36
#define FISH_ICON_MIN_X             26
#define FISH_ICON_MAX_X             ((FISHING_AREA_WIDTH - ((FISH_ICON_WIDTH / 2) + 4)) * POSITION_ADJUSTMENT)

// Perfect
#define PERFECT_SPRITE_WIDTH        32
#define PERFECT_X                   ((FISHING_BAR_START_X + FISHING_AREA_WIDTH) - PERFECT_SPRITE_WIDTH)
#define PERFECT_Y                   SCORE_SECTION_INIT_Y


enum {
    FISH_SPEED,
    FISH_SPEED_VARIABILITY,
    FISH_MOVE_DELAY,
    FISH_DELAY_VARIABILITY,
    FISH_DISTANCE,
    FISH_DIST_VARIABILITY
};

enum {
    SCORE_METER,
    FISHING_BAR,
    FISHING_BAR_RIGHT,
    PERFECT
};

#define FISH_DIR_LEFT               0
#define FISH_DIR_RIGHT              1

#define SCORE_RIGHT                 0
#define SCORE_MIDDLE                1
#define SCORE_LEFT                  2

void CB2_InitFishingGame(void);

#endif // GUARD_FISHING_GAME_H
