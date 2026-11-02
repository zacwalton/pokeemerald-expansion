static const struct PokeRideInfo sPokeRideInfo[NUM_SPECIES] =
{
    [SPECIES_VENUSAUR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-10,
                .playerY=-3,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CHARIZARD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BLASTOISE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-8,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PIDGEOT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_FEAROW] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-10,
                .monX=2,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ARBOK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_NIDOQUEEN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NIDOKING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PARASECT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DUGTRIO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PRIMEAPE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCANINE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_POLIWRATH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ALAKAZAM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MACHAMP] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_VICTREEBEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TENTACRUEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOLEM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAPIDASH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SLOWBRO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DODRIO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DEWGONG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MUK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ONIX] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=7,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ELECTRODE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WEEZING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=3,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_RHYDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KANGASKHAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SEAKING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_STARMIE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAUROS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GYARADOS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-11,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LAPRAS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=8,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AERODACTYL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SNORLAX] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARTICUNO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=5,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZAPDOS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=7,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MOLTRES] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-8,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_DRAGONITE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MEGANIUM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TYPHLOSION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-5,
                .monX=5,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FERALIGATR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NOCTOWL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-9,
                .monX=6,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ARIADOS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-6,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CROBAT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_LANTURN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_POLITOED] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_QUAGSIRE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SLOWKING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WOBBUFFET] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GIRAFARIG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FORRETRESS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_STEELIX] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=-1,
                .playerY=-17,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-17,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-15,
                .monX=3,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GRANBULL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_URSARING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MAGCARGO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PILOSWINE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_OCTILLERY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MANTINE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SKARMORY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=6,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_HOUNDOOM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=1,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KINGDRA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=5,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_DONPHAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_STANTLER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAIKOU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ENTEI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SUICUNE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TYRANITAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LUGIA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=3,
                .monY=-11,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_HO_OH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=-10,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-13,
                .monX=4,
                .monY=-10,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SCEPTILE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BLAZIKEN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SWAMPERT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LUDICOLO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SHIFTRY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SWELLOW] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PELIPPER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-7,
                .monX=5,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WAILORD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-9,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-11,
                .monX=1,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_VILEPLUME] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-3,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CLOYSTER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-7,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_EXEGGUTOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FURRET] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SCIZOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HERACROSS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-3,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MIGHTYENA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LINOONE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=2,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=1,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CLAYDOL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TORKOAL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WHISCASH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CRAWDAUNT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MILOTIC] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=3,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SHARPEDO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-8,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FLYGON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_HARIYAMA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=5,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MANECTRIC] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CAMERUPT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WALREIN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GLALIE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-3,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GRUMPIG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ALTARIA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-6,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SLAKING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-5,
                .monX=5,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SWALOT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TROPIUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_EXPLOUD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ABSOL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SEVIPER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RELICANTH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AGGRON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SALAMENCE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=1,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_METAGROSS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-9,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGIROCK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGICE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGISTEEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KYOGRE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=-11,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-10,
                .monX=2,
                .monY=-9,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GROUDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=-11,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-14,
                .monX=0,
                .monY=-11,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-15,
                .monX=2,
                .monY=-10,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAYQUAZA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-19,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-23,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-17,
                .monX=0,
                .monY=-11,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LATIAS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-10,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LATIOS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TORTERRA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_INFERNAPE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_EMPOLEON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_STARAPTOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=4,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_BIBAREL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LUXRAY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAMPARDOS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BASTIODON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FLOATZEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GASTRODON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=5,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AMBIPOM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRIFBLIM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-12,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HONCHKROW] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-3,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BRONZONG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GARCHOMP] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HIPPOWDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRAPION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ABOMASNOW] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MAGNEZONE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LICKILICKY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RHYPERIOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TANGROWTH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ELECTIVIRE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MAGMORTAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-3,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TOGEKISS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=2,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_YANMEGA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MAMOSWINE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PROBOPASS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DUSKNOIR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DIALGA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=1,
                .monY=-12,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PALKIA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-14,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-18,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=3,
                .playerY=-22,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HEATRAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=1,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGIGIGAS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-18,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-20,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-20,
                .monX=3,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GIRATINA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-18,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-21,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=3,
                .playerY=-19,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CRESSELIA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DARKRAI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCEUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-15,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-14,
                .monX=1,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SERPERIOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=1,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_EMBOAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SAMUROTT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_STOUTLAND] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_UNFEZANT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZEBSTRIKA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GIGALITH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CONKELDURR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_EXCADRILL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SEISMITOAD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SCOLIPEDE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KROOKODILE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DARMANITAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CRUSTLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=4,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SIGILYPH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=4,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_COFAGRIGUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CARRACOSTA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCHEOPS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=1,
                .monY=-2,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GARBODOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZOROARK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOTHITELLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REUNICLUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=2,
                .playerY=-7,
                .monX=2,
                .monY=-17,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=-18,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_VANILLUXE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SAWSBUCK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ESCAVALIER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-9,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AMOONGUSS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-18,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_JELLICENT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-12,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ALOMOMOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-9,
                .monX=1,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GALVANTULA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FERROTHORN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=1,
                .playerY=-4,
                .monX=1,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KLINKLANG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=2,
                .playerY=-1,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-7,
                .monX=5,
                .monY=-13,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_EELEKTROSS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BEHEEYEM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CHANDELURE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HAXORUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-13,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BEARTIC] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CRYOGONAL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ACCELGOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=1,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRUDDIGON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=2,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOLURK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BOUFFALANT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BRAVIARY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MANDIBUZZ] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=1,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_HYDREIGON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-11,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_VOLCARONA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_COBALION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TERRAKION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_VIRIZION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-9,
                .monX=1,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TORNADUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_THUNDURUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RESHIRAM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=1,
                .monY=-7,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-10,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZEKROM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=3,
                .playerY=-17,
                .monX=0,
                .monY=-11,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_LANDORUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KYUREM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=1,
                .playerY=-13,
                .monX=-1,
                .monY=-3,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=2,
                .monY=-10,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=5,
                .playerY=-12,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KELDEO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GENESECT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CHESNAUGHT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DIGGERSBY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TALONFLAME] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=4,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_PYROAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FLORGES] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOGOAT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PANGORO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FURFROU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MALAMAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BARBARACLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRAGALGE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CLAWITZER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=3,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-12,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TYRANTRUM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AURORUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HAWLUCHA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOODRA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TREVENANT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOURGEIST] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AVALUGG] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NOIVERN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_XERNEAS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-15,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=2,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_YVELTAL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=1,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZYGARDE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=4,
                .monY=-14,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_VOLCANION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DECIDUEYE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_INCINEROAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PRIMARINA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TOUCANNON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=-1,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_VIKAVOLT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=-3,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CRABOMINABLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LYCANROC] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TOXAPEX] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MUDSDALE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARAQUANID] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BEWEAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ORANGURU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PASSIMIAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOLISOPOD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PALOSSAND] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TYPE_NULL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SILVALLY] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TURTONATOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BRUXISH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRAMPA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DHELMISE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-13,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KOMMO_O] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAPU_KOKO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_TAPU_LELE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAPU_BULU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAPU_FINI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SOLGALEO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LUNALA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_NIHILEGO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BUZZWOLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_PHEROMOSA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=1,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_XURKITREE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CELESTEELA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GUZZLORD] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NECROZMA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_NAGANADEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-10,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_STAKATAKA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZERAORA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MELMETAL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RILLABOOM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_CINDERACE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GREEDENT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-10,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CORVIKNIGHT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ORBEETLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-9,
                .playerY=-15,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_THIEVUL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DUBWOOL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DREDNAW] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_COALOSSAL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FLAPPLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_APPLETUN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SANDACONDA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BARRASKEWDA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CENTISKORCH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-4,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GRAPPLOCT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HATTERENE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=1,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GRIMMSNARL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_OBSTAGOON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RUNERIGUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-10,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FALINKS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FROSMOTH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_COPPERAJAH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRACOZOLT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCTOZOLT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRACOVISH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCTOVISH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DURALUDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DRAGAPULT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-16,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-19,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-20,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZACIAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZAMAZENTA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ETERNATUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-15,
                .monX=0,
                .monY=-9,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-16,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_URSHIFU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZARUDE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGIELEKI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_REGIDRAGO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GLASTRIER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SPECTRIER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WYRDEER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KLEAVOR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_URSALUNA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BASCULEGION] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=2,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SNEASLER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_OVERQWIL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-12,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ENAMORUS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=2,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAICHU_ALOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DUGTRIO_ALOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOLEM_ALOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MUK_ALOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_EXEGGUTOR_ALOLA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-28,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=1,
                .playerY=-29,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-27,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAPIDASH_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SLOWBRO_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WEEZING_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=3,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ARTICUNO_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-9,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZAPDOS_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_MOLTRES_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SLOWKING_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DARMANITAN_GALAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCANINE_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ELECTRODE_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TYPHLOSION_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-7,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SAMUROTT_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LILLIGANT_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZOROARK_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BRAVIARY_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GOODRA_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_AVALUGG_HISUI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GASTRODON_EAST] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DIALGA_ORIGIN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-11,
                .monX=2,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_PALKIA_ORIGIN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-20,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-25,
                .monX=0,
                .monY=-17,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=3,
                .playerY=-25,
                .monX=1,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GIRATINA_ORIGIN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=-10,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-15,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=1,
                .monY=-12,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZYGARDE_COMPLETE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-13,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_HOOPA_UNBOUND] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-11,
                .monX=5,
                .monY=-15,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_LYCANROC_MIDNIGHT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_LYCANROC_DUSK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NECROZMA_DUSK_MANE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-11,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_NECROZMA_DAWN_WINGS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_ZACIAN_CROWNED] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ZAMAZENTA_CROWNED] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_URSHIFU_RAPID_STRIKE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=4,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BASCULEGION_F] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=-1,
                .monY=3,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_SKELEDIRGE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=0,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARBOLIVA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_GARGANACL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-12,
                .monX=4,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_BELLIBOLT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-2,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KILOWATTREL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=-1,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-9,
                .monX=0,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MABOSSTIFF] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TOEDSCRUEL] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-14,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_KLAWF] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ESPATHRA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-12,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_WUGTRIO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-5,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BOMBIRDIER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_REVAVROOM] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_CYCLIZAR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HOUNDSTONE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-11,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CETITAN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_VELUZA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DONDOZO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-3,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=0,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=0,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ANNIHILAPE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_CLODSIRE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FARIGIRAF] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=0,
                .monX=0,
                .monY=-12,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=2,
                .monX=0,
                .monY=-9,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=0,
                .monX=1,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GREAT_TUSK] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-8,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BRUTE_BONNET] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-13,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_FLUTTER_MANE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-4,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SLITHER_WING] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_SANDY_SHOCKS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-10,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_IRON_TREADS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_IRON_HANDS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=3,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_IRON_JUGULIS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-8,
                .monX=2,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_IRON_MOTH] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=2,
                .monY=-1,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_IRON_THORNS] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-6,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_BAXCALIBUR] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WO_CHIEN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_CHIEN_PAO] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-4,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TING_LU] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-7,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ROARING_MOON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-4,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_KORAIDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-17,
                .monX=0,
                .monY=-15,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-13,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-6,
                .playerY=-16,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_MIRAIDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB | POKERIDE_FLAG_CAN_SWIM | POKERIDE_FLAG_CAN_FLY,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-12,
                .monX=2,
                .monY=-14,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-13,
                .monX=-2,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-11,
                .monX=0,
                .monY=-14,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_TAUROS_PALDEA_COMBAT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-1,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAUROS_PALDEA_BLAZE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_TAUROS_PALDEA_AQUA] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_WALKING_WAKE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-5,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_IRON_LEAVES] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_OKIDOGI] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=-1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-7,
                .monX=1,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
        }
    },
    [SPECIES_URSALUNA_BLOODMOON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-11,
                .monX=2,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_ARCHALUDON] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-5,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_HYDRAPPLE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-4,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-7,
                .monX=3,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_GOUGING_FIRE] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-7,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-6,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-6,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_RAGING_BOLT] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=1,
                .playerY=-11,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-11,
                .monX=0,
                .monY=-16,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-11,
                .monX=4,
                .monY=-16,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_IRON_BOULDER] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-10,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-2,
                .playerY=-10,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
    [SPECIES_IRON_CROWN] =
    {
        .flags = POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB,
        .spriteInfo =
        {
            [POKERIDE_SPRITE_UP] =
            {
                .playerX=0,
                .playerY=-9,
                .monX=0,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
            [POKERIDE_SPRITE_DOWN] =
            {
                .playerX=0,
                .playerY=-8,
                .monX=0,
                .monY=0,
                .playerRendersInFront=FALSE,
            },
            [POKERIDE_SPRITE_SIDE] =
            {
                .playerX=-3,
                .playerY=-8,
                .monX=1,
                .monY=0,
                .playerRendersInFront=TRUE,
            },
        }
    },
};
