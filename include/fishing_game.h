#ifndef GUARD_FISHING_GAME_H
#define GUARD_FISHING_GAME_H

#define FISH_ICON_WIDTH             12
#define FISH_ICON_START_X           36
#define FISH_ICON_MIN_X             26
#define FISH_ICON_MAX_X             ((FISHING_AREA_WIDTH - (FISH_ICON_WIDTH + 4)) * 10)
//#define FISH_ICON_AREA_MIDDLE      (((FISH_ICON_MAX_X - FISH_ICON_MIN_X) / 2) + FISH_ICON_MIN_X)

#define FISHING_BAR_Y               93
#define FISHING_BAR_START_X         51
#define FISHING_BAR_WIDTH           64 // Cannot be below 33 or above 64.
#define FISHING_BAR_WIDTH_ADJUST    (64 - FISHING_BAR_WIDTH)
#define FISHING_AREA_WIDTH          202
#define FISHING_BAR_BOUNCINESS      1.3 // The greater the number, the less the bar will bounce when it hits the left side.
#define POSITION_ADJUSTMENT         10
#define FISHING_BAR_MAX_SPEED       50  // The greater the number, the faster the bar is allowed to go.
#define BAR_SPEED_MODIFIER          (FISHING_BAR_MAX_SPEED / (FISHING_BAR_MAX_SPEED / 2.0)) // The greater the number value, the slower the bar changes speed. (Decimals are encouraged, as a little goes a long way.)
#define FISHING_BAR_MAX             ((FISHING_AREA_WIDTH - FISHING_BAR_WIDTH) * 10)

#define STARTING_SCORE              10  // Must be divisible by SCORE_INTERVAL.
#define SCORE_MAX                   1920 // Must be divisible by SCORE_AREA_WIDTH.
#define SCORE_AREA_WIDTH            192
#define SCORE_AREA_OFFSET           8
#define SCORE_INTERVAL              (SCORE_MAX / SCORE_AREA_WIDTH)
#define SCORE_SECTION_INIT_X        ((STARTING_SCORE / SCORE_INTERVAL) - SCORE_AREA_OFFSET)
#define SCORE_SECTION_INIT_Y        80
#define SCORE_SECTION_WIDTH         64
#define NUM_COLOR_INTERVALS         64
#define SCORE_COLOR_INTERVAL        (SCORE_AREA_WIDTH / NUM_COLOR_INTERVALS)
#define STARTING_COLOR_INTERVAL     ((STARTING_SCORE / SCORE_INTERVAL) / SCORE_COLOR_INTERVAL)

#define FISH_DIR_LEFT               0
#define FISH_DIR_RIGHT              1

#define SCORE_RIGHT                 0
#define SCORE_MIDDLE                1
#define SCORE_LEFT                  2

enum {
    FISH_SPEED,
    FISH_SPEED_VARIABILITY,
    FISH_MOVE_DELAY,
    FISH_DELAY_VARIABILITY,
    FISH_DISTANCE,
    FISH_DIST_VARIABILITY
};

void CB2_InitFishingGame(void);

#endif // GUARD_FISHING_GAME_H
