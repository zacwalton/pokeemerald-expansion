#ifndef GUARD_FLDEFF_H
#define GUARD_FLDEFF_H

// cut
bool8 SetUpFieldMove_Cut(void);
bool8 FldEff_UseCutOnGrass(void);
bool8 FldEff_UseCutOnTree(void);
bool8 FldEff_CutGrass(void);
void FixLongGrassMetatilesWindowTop(s16 x, s16 y);
void FixLongGrassMetatilesWindowBottom(s16 x, s16 y);

extern const struct SpritePalette gSpritePalette_CutGrass;
extern struct MapPosition gPlayerFacingPosition;

// escalator
void StartEscalator(bool8 goingUp);
void StopEscalator(void);
bool8 IsEscalatorMoving(void);

// soft-boiled
bool8 SetUpFieldMove_SoftBoiled(void);
void Task_TryUseSoftboiledOnPartyMon(u8 taskId);
void ChooseMonForSoftboiled(u8 taskId);

// flash
//Pack flash values into VAR - moveTint:6; followerTint:6; shadowStrength:4
#define VAR_FLASH_TRACKER_PACKED VAR_FLASH_TRACKER

#define GET_SHADOW_STRENGTH(val)     ((val) & 0xF)
#define GET_FOLLOWER_TINT(val)       (((val) >> 4) & 0x3F)
#define GET_MOVE_TINT(val)           (((val) >> 10) & 0x3F)

#define SET_SHADOW_STRENGTH(val, x)  ((val) = ((val) & ~0x000F) | ((x) & 0xF))
#define SET_FOLLOWER_TINT(val, x)    ((val) = ((val) & ~0x03F0) | (((x) & 0x3F) << 4))
#define SET_MOVE_TINT(val, x)        ((val) = ((val) & ~0xFC00) | (((x) & 0x3F) << 10))

bool8 SetUpFieldMove_Flash(void);
void CB2_DoChangeMap(void);
bool8 GetMapPairFadeToType(u8 _fromType, u8 _toType);
bool8 GetMapPairFadeFromType(u8 _fromType, u8 _toType);
void UpdateFlashTint(void);
void UpdateFlashStrength(void);
void UpdateFlashRadiusOnStep(void);

// strength
bool8 SetUpFieldMove_Strength(void);
bool8 FldEff_UseStrength(void);

// sweet scent
bool8 SetUpFieldMove_SweetScent(void);
bool8 FldEff_SweetScent(void);
void StartSweetScentFieldEffect(void);

// teleport
bool8 SetUpFieldMove_Teleport(void);
bool8 FldEff_UseTeleport(void);

// dig
bool8 SetUpFieldMove_Dig(void);
bool8 FldEff_UseDig(void);

// rock smash
bool8 CheckObjectGraphicsInFrontOfPlayer(u16 graphicsId);
u8 CreateFieldMoveTask(void);
bool8 SetUpFieldMove_RockSmash(void);
bool8 FldEff_UseRockSmash(void);

// headbutt
bool8 FldEff_UseHeadbutt(void);
bool8 SetUpFieldMove_Headbutt(void);
// Whirlpool
bool8 FldEff_UseWhirlpool(void);
bool8 SetUpFieldMove_Whirlpool(void);
// Lava Plume
bool8 FldEff_UseLava(void);
bool8 SetUpFieldMove_Lava(void);
// Sludge Wave
bool8 FldEff_UseSludge(void);
bool8 SetUpFieldMove_Sludge(void);
// Douse
bool8 SetUpFieldMove_Douse(void);
bool8 FldEff_UseDouse(void);

// defog
bool8 SetUpFieldMove_Defog(void);
bool8 FldEff_Defog(void);

#endif // GUARD_FLDEFF_H
