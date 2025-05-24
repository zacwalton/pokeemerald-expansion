#include "global.h"
#include "frontier_util.h"
#include "battle_setup.h"
#include "clock.h"
#include "data.h"
#include "event_data.h"
#include "field_door.h"
#include "field_effect.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "move.h"
#include "mystery_event_script.h"
#include "palette.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "script_movement.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "malloc.h"
#include "gba/isagbprint.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/event_bg.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

struct HarvestableTileMapping
{
	u16 harvestableTile;
	u16 collectedTile;
	bool16 isImpassable;
};

static const struct HarvestableTileMapping sHarvestableTileMap[] = {
	// Plain Gras
	{ METATILE_Hoenn_Summer_BALM_GRASS,  					METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_BALM_LARGE_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_MUSHROOM_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_MUSHROOM_LARGE_GRASS,  			METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_KINGSLEAF_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_VIVICHOKE_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_STONE_GRASS,  					METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_WOOD_GRASS,  					METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_LEEK_GRASS,  					METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_LIMESTONE_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_REDSTONE_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_GREENSTONE_GRASS,  				METATILE_General_Grass,							FALSE },
	{ METATILE_Hoenn_Summer_GOLDSTONE_GRASS,  				METATILE_General_Grass,							FALSE },
	
	// Grass Mountain Top
	{ METATILE_Hoenn_Summer_BALM_TOP,  						METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_BALM_LARGE_TOP,  				METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_MUSHROOM_TOP,  					METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_MUSHROOM_LARGE_TOP,  			METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_KINGSLEAF_TOP,  				METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_VIVICHOKE_TOP,  				METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_STONE_TOP,  					METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_WOOD_TOP,  						METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	{ METATILE_Hoenn_Summer_LEEK_TOP,  						METATILE_Hoenn_Summer_MountainTop_Grass,		FALSE },
	
	// Grass Mountain Top Left
    { METATILE_Hoenn_Summer_BALM_TOPLEFT, 					METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_TOPLEFT, 			METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_TOPLEFT, 				METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_TOPLEFT, 		METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_TOPLEFT, 				METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_TOPLEFT, 				METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_STONE_TOPLEFT, 					METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_WOOD_TOPLEFT, 					METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },
    { METATILE_Hoenn_Summer_LEEK_TOPLEFT, 					METATILE_Hoenn_Summer_MountainTopLeft_Grass,	FALSE },

    // Grass Mountain Top Right
    { METATILE_Hoenn_Summer_BALM_TOPRIGHT, 					METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_TOPRIGHT, 			METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_TOPRIGHT, 				METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_TOPRIGHT, 		METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_TOPRIGHT, 			METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_TOPRIGHT, 			METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_STONE_TOPRIGHT, 				METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_WOOD_TOPRIGHT, 					METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },
    { METATILE_Hoenn_Summer_LEEK_TOPRIGHT, 					METATILE_Hoenn_Summer_MountainTopRight_Grass,	FALSE },

    // Sand
    { METATILE_Hoenn_Summer_BALM_SAND, 						METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_SAND, 				METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_SAND, 					METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_SAND, 			METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_SAND, 				METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_SAND, 				METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_STONE_SAND, 					METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_WOOD_SAND, 						METATILE_Hoenn_Summer_Sand,						FALSE },
    { METATILE_Hoenn_Summer_LEEK_SAND, 						METATILE_Hoenn_Summer_Sand,						FALSE },

    // Rock
    { METATILE_Hoenn_Summer_BALM_ROCK, 						METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_ROCK, 				METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_ROCK, 					METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_ROCK, 			METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_ROCK, 				METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_ROCK, 				METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_STONE_ROCK, 					METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_WOOD_ROCK, 						METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },
    { METATILE_Hoenn_Summer_LEEK_ROCK, 						METATILE_Hoenn_Summer_Rock_Walkable,			FALSE },

    // Shallow Water
    { METATILE_Hoenn_Summer_BALM_WATER, 					METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_WATER, 				METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_WATER, 				METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_WATER, 			METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_WATER, 				METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_WATER, 				METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_STONE_WATER, 					METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_WOOD_WATER, 					METATILE_Hoenn_Summer_Water_Shallow,			FALSE },
    { METATILE_Hoenn_Summer_LEEK_WATER, 					METATILE_Hoenn_Summer_Water_Shallow,			FALSE },

    // Cliff
    { METATILE_Hoenn_Summer_BALM_LARGE_CLIFF, 				METATILE_Hoenn_Summer_Cliff,					TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_CLIFF, 			METATILE_Hoenn_Summer_Cliff,					TRUE },
    { METATILE_Hoenn_Summer_KINGSLEAF_CLIFF, 				METATILE_Hoenn_Summer_Cliff,					TRUE },

    // Grassy Cliff
    { METATILE_Hoenn_Summer_BALM_LARGE_GRASSCLIFF, 			METATILE_Hoenn_Summer_Cliff_Grass,				TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_GRASSCLIFF, 		METATILE_Hoenn_Summer_Cliff_Grass,				TRUE },
    { METATILE_Hoenn_Summer_KINGSLEAF_GRASSCLIFF, 			METATILE_Hoenn_Summer_Cliff_Grass,				TRUE },

    // Green Tree Left
    { METATILE_Hoenn_Summer_BALM_LARGE_GREENTREELEFT, 		METATILE_Hoenn_Summer_GreenTreeLeft,			TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_GREENTREELEFT, 	METATILE_Hoenn_Summer_GreenTreeLeft,			TRUE },

    // Green Tree Right
    { METATILE_Hoenn_Summer_BALM_LARGE_GREENTREERIGHT, 		METATILE_Hoenn_Summer_GreenTreeRight,			TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_GREENTREERIGHT, 	METATILE_Hoenn_Summer_GreenTreeRight,			TRUE },

    // Blue Tree Left
    { METATILE_Hoenn_Summer_BALM_LARGE_BLUETREELEFT, 		METATILE_Hoenn_Summer_BlueTreeLeft,				TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_BLUETREELEFT, 	METATILE_Hoenn_Summer_BlueTreeLeft,				TRUE },

    // Blue Tree Right
    { METATILE_Hoenn_Summer_BALM_LARGE_BLUETREERIGHT, 		METATILE_Hoenn_Summer_BlueTreeRight,			TRUE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_BLUETREERIGHT, 	METATILE_Hoenn_Summer_BlueTreeRight,			TRUE },
		
    // Chalk Cliff
    { METATILE_Hoenn_Summer_BALM_CHALK, 					METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_CHALK, 				METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_CHALK, 				METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_CHALK, 			METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_CHALK, 				METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_CHALK, 				METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_STONE_CHALK, 					METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_WOOD_CHALK, 					METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_LEEK_CHALK, 					METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_LIMESTONE_CHALK, 				METATILE_Hoenn_Summer_ChalkCliff_Walkable,		FALSE },

    // Volcanic Cliff
    { METATILE_Hoenn_Summer_BALM_VOLCANIC, 					METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_VOLCANIC, 			METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_VOLCANIC, 				METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_VOLCANIC, 		METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_VOLCANIC, 			METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_VOLCANIC, 			METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_STONE_VOLCANIC, 				METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_WOOD_VOLCANIC, 					METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_LEEK_VOLCANIC, 					METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_REDSTONE_VOLCANIC, 				METATILE_Hoenn_Summer_VolcanicCliff_Walkable,	FALSE },

    // Emerald Cliff
    { METATILE_Hoenn_Summer_BALM_EMERALD, 					METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_EMERALD, 			METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_EMERALD, 				METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_EMERALD, 		METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_EMERALD, 				METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_EMERALD, 				METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_STONE_EMERALD, 					METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_WOOD_EMERALD, 					METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_LEEK_EMERALD, 					METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },
    { METATILE_Hoenn_Summer_GREENSTONE_EMERALD, 			METATILE_Hoenn_Summer_EmeraldCliff_Walkable,	FALSE },

    // Gold Cliff
    { METATILE_Hoenn_Summer_BALM_GOLD, 						METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_BALM_LARGE_GOLD, 				METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_GOLD, 					METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_MUSHROOM_LARGE_GOLD, 			METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_KINGSLEAF_GOLD, 				METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_VIVICHOKE_GOLD, 				METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_STONE_GOLD, 					METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_WOOD_GOLD, 						METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_LEEK_GOLD, 						METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
    { METATILE_Hoenn_Summer_GOLDSTONE_GOLD, 				METATILE_Hoenn_Summer_GoldCliff_Walkable,		FALSE },
};

void SetHarvestedMetatile(u16 x, u16 y, u16 metatileId)
{
	u32 i;
    for (i = 0; i < ARRAY_COUNT(sHarvestableTileMap); i++)
	{
		if (metatileId == sHarvestableTileMap[i].harvestableTile)
		{
			if (!sHarvestableTileMap[i].isImpassable)
				MapGridSetMetatileIdAt(x, y, sHarvestableTileMap[i].collectedTile);
			else 
				MapGridSetMetatileIdAt(x, y, sHarvestableTileMap[i].collectedTile | MAPGRID_COLLISION_MASK);
		break;
		}
	}
}

void SetHarvestableItemPresentAtCoords(const struct MapEvents *events)
{
    u8 bgEventCount = events->bgEventCount;
    const struct BgEvent *bgEvent = events->bgEvents;
    int i;
	
    for (i = 0; i < bgEventCount; i++)
    {
        if (bgEvent[i].kind == BG_EVENT_HARVESTABLE_ITEM)
        {
			u16 x = bgEvent[i].x + MAP_OFFSET;
			u16 y = bgEvent[i].y + MAP_OFFSET;
            if (FlagGet(bgEvent[i].bgUnion.harvestableItem.harvestFlag + FLAGS_BASE))
			{
                SetHarvestedMetatile(x, y, MapGridGetMetatileIdAt(x, y));
			}
        }
    };
}

/*
bool8 ScrCmd_setmetatileateatbgeventid(struct ScriptContext *ctx)
{
	u16 localId = VarGet(ScriptReadHalfword(ctx));
    u16 x, y;
	GetBgEventPosition(&x, &y, localId);
    u16 metatileId;
    bool16 isImpassable;
	s32 previousMetatileId = MapGridGetMetatileIdAt(x, y);

    x += MAP_OFFSET;
    y += MAP_OFFSET;
	
	SetHarvestedMetatile(x, y, MapGridGetMetatileIdAt(x, y));
    return FALSE;
}


static bool8 IsHiddenItemPresentInConnection(const struct MapConnection *connection, int x, int y)
{
    s16 connectionX, connectionY;
    struct MapHeader const *const connectionHeader = GetMapHeaderFromConnection(connection);

// To convert our x/y into coordinates that are relative to the connected map, we must:
//  - Subtract the virtual offset used for the border buffer (MAP_OFFSET).
//  - Subtract the horizontal offset between North/South connections, or the vertical offset for East/West
//  - Account for map size. (0,0) is in the NW corner of our map, so when looking North/West we have to add the height/width of the connected map,
//     and when looking South/East we have to subtract the height/width of our current map.
#define localX (x - MAP_OFFSET)
#define localY (y - MAP_OFFSET)
    switch (connection->direction)
    {
    case CONNECTION_NORTH:
        connectionX = localX - connection->offset;
        connectionY = connectionHeader->mapLayout->height + localY;
        break;
    case CONNECTION_SOUTH:
        connectionX = localX - connection->offset;
        connectionY = localY - gMapHeader.mapLayout->height;
        break;
    case CONNECTION_WEST:
        connectionX = connectionHeader->mapLayout->width + localX;
        connectionY = localY - connection->offset;
        break;
    case CONNECTION_EAST:
        connectionX = localX - gMapHeader.mapLayout->width;
        connectionY = localY - connection->offset;
        break;
    default:
        return FALSE;
    }
    return IsHiddenItemPresentAtCoords(connectionHeader->events, connectionX, connectionY);
}

#undef localX
#undef localY
*/
