#ifndef GUARD_POKERIDE_H
#define GUARD_POKERIDE_H

#if !OW_POKEMON_OBJECT_EVENTS
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for PokeRide to work."
#endif

void PokeRide_Init();
void SavePokeRideData(struct PokeRide *pokeRide);
void LoadPokeRideData(struct PokeRide *pokeRide);
void ClearPokeRideData(void);

void GetOnOffPokeRide();
bool8 PokeRide_ProcessInput();
bool8 PokeRide_IsActiveObject(u8 objectEventId);
void PokeRide_ResetSprites();

void PokeRide_OnObjectEventMovement(u8 objectEventId);

void PokeRide_OnWarp();

u8 PokeRide_GetMonSpriteId(struct ObjectEvent* objectEvent);

bool8 PokeRide_IsValidRideSpecies(u16 species);
bool8 PokeRide_IsValidRideClimbSpecies(u16 species);
bool8 PokeRide_IsValidRideSwimSpecies(u16 species);
bool8 PokeRide_IsValidRideFlySpecies(u16 species);

bool8 PokeRide_CanRideInvJumpLedge();
bool8 PokeRide_CanRideSwim();
bool8 PokeRide_CanRideFly();

bool8 PokeRide_IsRideActive();
bool8 PokeRide_IsRideSwimming();
bool8 PokeRide_IsRideFlying();
bool8 PokeRide_IsRideCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);

void MovePlayerOnPokeRide(u8 direction, u16 newKeys, u16 heldKeys);

#endif //GUARD_POKERIDE_H
