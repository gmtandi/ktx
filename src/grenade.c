#include "g_local.h"

void TeamFortress_PrimeGrenade () 
{
                G_sprint ( self, 2,  "Grenade primed... HueTF 0wns :D \n");
}

void TeamFortress_GrenadePrimed()
{
        sound (self, CHAN_WEAPON, "weapons/ax1.wav", 1, ATTN_NORM);
/*        KickPlayer (-1, user);

        newmis = spawn ();
        newmis.owner = user;
        newmis.movetype = enter;
        newmis.solid = 2;
        newmis.classname = "grenade";
        makevectors (user.v_angle);
        if (user.deadflag)
        {
                newmis.velocity = '0 0 200';
        }
        else
        {
                if (user.v_angle_x)
                {
                        newmis.velocity = ((((v_forward * 600) + (v_up * 200)) + ((crandom () * v_right) * enter)) + ((crandom () * v_up) * enter));
                }
                else
                {
                        newmis.velocity = aim (user, 10000);
                        newmis.velocity = (newmis.velocity * 600);
                        newmis.velocity_z = 200;
                }
        }
        newmis.angles = vectoangles (newmis.velocity);
        newmis.think = SUB_Null;
        newmis.nextthink = self.heat;
        if ((self.weapon == 1))
        {
                newmis.touch = NormalGrenadeTouch;
                newmis.think = NormalGrenadeExplode;
                newmis.skin = 0;
                newmis.avelocity = '300 300 300';
                setmodel (newmis, "progs/hgren2.mdl");
        }
        else
        {
                if ((self.weapon == 2))
                {
                        newmis.touch = ConcussionGrenadeTouch;
                        newmis.think = ConcussionGrenadeExplode;
                        newmis.skin = 1;
                        newmis.avelocity = '300 300 300';
                        setmodel (newmis, "progs/hgren2.mdl");
                }

                // impact grenade
                else  if ((self.weapon == 11))
                {
                        newmis.weapon = 11;
                        newmis.touch = ConcussionGrenadeTouch;
                        newmis.think = ConcussionGrenadeExplode;
                        newmis.skin = 1;
                        newmis.avelocity = '300 300 300';
                        setmodel (newmis, "progs/hgren2.mdl");
                }

                else
                {
                        if ((self.weapon == 3))
                        {
                                newmis.touch = NailGrenadeTouch;
                                newmis.think = NailGrenadeExplode;
                                newmis.skin = 1;
                                newmis.avelocity = '0 300 0';
                                setmodel (newmis, "progs/biggren.mdl");
                        }
                        else
                        {
                                if ((self.weapon == 4))
                                {
                                        newmis.touch = MirvGrenadeTouch;
                                        newmis.think = MirvGrenadeExplode;
                                        newmis.skin = 0;
                                        newmis.avelocity = '0 300 0';
                                        setmodel (newmis, "progs/biggren.mdl");
                                }
                                else
                                {
                                        if ((self.weapon == 5))
                                        {
                                                newmis.touch = NapalmGrenadeTouch;
                                                newmis.think = NapalmGrenadeExplode;
                                                newmis.skin = 2;
                                                newmis.avelocity = '0 300 0';
                                                setmodel (newmis, "progs/biggren.mdl");
                                        }
                                        else
                                        {
                                                if ((self.weapon == 6))
                                                {
                                                        newmis.touch = FlareGrenadeTouch;
                                                        newmis.weapon = self.team_no;
                                                        newmis.think = FlareGrenadeExplode;
                                                        newmis.skin = 1;
                                                        newmis.avelocity = '300 300 300';
                                                        newmis.mdl = "flare";
                                                        setmodel (newmis, "progs/flare.mdl");
                                                }
                                                else
                                                {
                                                        if ((self.weapon == 7))
                                                        {
                                                                newmis.touch = GasGrenadeTouch;
                                                                newmis.think = GasGrenadeExplode;
                                                                newmis.skin = 3;
                                                                newmis.avelocity = '300 300 300';
                                                                setmodel (newmis, "progs/grenade2.mdl");
                                                        }
                                                        else
                                                        {
                                                                if ((self.weapon == 8))
                                                                {
                                                                        newmis.touch = EMPGrenadeTouch;
                                                                        newmis.think = EMPGrenadeExplode;
                                                                        newmis.skin = 4;
                                                                        newmis.avelocity = '300 300 300';
                                                                        setmodel (newmis, "progs/grenade2.mdl");
                                                                }
                                                                else
                                                                {
                                                                        if ((self.weapon == enter))
                                                                        {
                                                                                newmis.touch = CanisterTouch;
                                                                                newmis.think = ScatterCaltrops;
                                                                                newmis.skin = 0;
                                                                                newmis.avelocity = '0 0 0';
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        setsize (newmis, '0 0 0', '0 0 0');
        setorigin (newmis, user.origin);
        oldself = self;
        self = self.owner;
        self = oldself;
        dremove (self);
};
*/
}

/*

void GrenadeExplode()
{
        if ( self->voided )
        {
                return;
        }
        self->voided = 1;

        FixQuad(PROG_TO_EDICT( self->s.v.owner ));

	T_RadiusDamage( self, PROG_TO_EDICT( self->s.v.owner ), 120, world, dtGL );

        WriteByte( MSG_MULTICAST, SVC_TEMPENTITY );
        WriteByte( MSG_MULTICAST, TE_EXPLOSION );
        WriteCoord( MSG_MULTICAST, self->s.v.origin[0] );
        WriteCoord( MSG_MULTICAST, self->s.v.origin[1] );
        WriteCoord( MSG_MULTICAST, self->s.v.origin[2] );
        trap_multicast( PASSVEC3( self->s.v.origin ), MULTICAST_PHS );

        ent_remove( self );
}

void GrenadeTouch()
{
        if ( other == PROG_TO_EDICT( self->s.v.owner ) )
                return;         // don't explode on owner
        
        // can't touch/damage others in race
        if ( isRACE()
        && ( other->ct == ctPlayer )
        && ( other != PROG_TO_EDICT( self->s.v.owner ) ) )
                return;

        if ( other->s.v.takedamage )
        {
                if ( other->ct == ctPlayer )
                {
                        WS_Mark( PROG_TO_EDICT( self->s.v.owner ), wpGL );
                        PROG_TO_EDICT( self->s.v.owner )->ps.wpn[wpGL].hits++;
                }
        }

        if ( other->s.v.takedamage == DAMAGE_AIM )
        {
                GrenadeExplode();
                return;
        }
        sound( self, CHAN_WEAPON, "weapons/bounce.wav", 1, ATTN_NORM ); // bounce sound
        if ( self->s.v.velocity[0] == 0 && self->s.v.velocity[1] == 0 && self->s.v.velocity[2] == 0 )
                VectorClear( self->s.v.avelocity );
}*/

/*
================
W_FireGrenade
================
*/

/*
void W_FireGrenade()
{
        float r1 = crandom(), r2 = crandom();
        vec3_t ang;
        WS_Mark( self, wpGL );

        self->ps.wpn[wpGL].attacks++;

    if ( match_in_progress == 2 )
                if (deathmatch != 4 && !k_bloodfest)
                {
                        self->s.v.currentammo = self->s.v.ammo_rockets = self->s.v.ammo_rockets - 1;
                        AmmoUsed (self);
                }

        sound( self, CHAN_WEAPON, "weapons/grenade.wav", 1, ATTN_NORM );

        g_globalvars.msg_entity = EDICT_TO_PROG( self );

        WriteByte( MSG_ONE, SVC_SMALLKICK );

        newmis = spawn();
        g_globalvars.newmis = EDICT_TO_PROG( newmis );
        newmis->voided = 0;
        newmis->s.v.owner = EDICT_TO_PROG( self );
        newmis->s.v.movetype = MOVETYPE_BOUNCE;
        newmis->isMissile = true;
        newmis->s.v.solid = SOLID_BBOX;
        newmis->classname = "grenade";

// set newmis speed     

        VectorCopy(self->s.v.v_angle, ang);


        // limit pitch in case the server allows pitch angles < -70,
        // so that grenades still go straight up and not behind
        if (ang[PITCH] < -70)
                ang[PITCH] = -70;

        trap_makevectors( ang );

        // Yawnmode: disable randomness in grenade aim
        // - Molgrum
        if ( k_yawnmode )
                r1 = r2 = 0;

        newmis->s.v.velocity[0] =
            g_globalvars.v_forward[0] * 600 + g_globalvars.v_up[0] * 200 +
            r1 * g_globalvars.v_right[0] * 10 +
            r2 * g_globalvars.v_up[0]    * 10;
        newmis->s.v.velocity[1] =
            g_globalvars.v_forward[1] * 600 + g_globalvars.v_up[1] * 200 +
            r1 * g_globalvars.v_right[1] * 10 +
            r2 * g_globalvars.v_up[1]    * 10;
        newmis->s.v.velocity[2] =
            g_globalvars.v_forward[2] * 600 + g_globalvars.v_up[2] * 200 +
            r1 * g_globalvars.v_right[2] * 10 +
            r2 * g_globalvars.v_up[0]    * 10;

        SetVector( newmis->s.v.avelocity, 300, 300, 300 );
// newmis.avelocity = '300 300 300';

        vectoangles( newmis->s.v.velocity, newmis->s.v.angles );

        newmis->touch = ( func_t ) GrenadeTouch;
        newmis->s.v.nextthink = g_globalvars.time + 2.5;
        newmis->think = ( func_t ) GrenadeExplode;

        if ( deathmatch == 4 && cvar("k_dmm4_gren_mode") )
                newmis->think = ( func_t ) SUB_Remove;

        setmodel( newmis, "progs/grenade.mdl" );
        setsize( newmis, 0, 0, 0, 0, 0, 0 );
        setorigin( newmis, PASSVEC3( self->s.v.origin ) );

#ifdef BOT_SUPPORT
        BotsGrenadeSpawned (newmis);
#endif
}

*/




/*

void () GrenadeTimer =
{
        self.heat = self.heat - 1;
        self.nextthink = time + 1;
        self.owner.StatusGrenTime = self.heat;

        if (!self.heat)
        {
                dremove(self);
        }
};

void () RemoveGrenadeTimers =
{
        local entity te = find(world, classname, "gtimer");
        while (te != world)
        {
                if (te.owner == self)
                        dremove(te);
                te = find(te, classname, "gtimer");
        }
};
void () TeamFortress_PrimeGrenade =
{
        local float gtype;
        local string gs;
        local string ptime;
        local entity tGrenade;
        local entity timer;

        if ((self.playerclass == 11))
        {
                return;
        }
        if (((self.tfstate & 1) || (self.tfstate & 1024)))
        {
                return;
        }
        if ((self.impulse == 150))
        {
                gtype = self.tp_grenades_1;
                if ((self.tp_grenades_1 == 2))
                {
                        gs = "Concussion grenade";
                }
                else
                {
                        if ((self.tp_grenades_1 == 3))
                        {
                                gs = "Nail grenade";
                        }
                        else
                        {
                                if ((self.tp_grenades_1 == 4))
                                {
                                        gs = "Mirv grenade";
                                }
                                else
                                {
                               }
                                else
                                {
                                        if ((self.tp_grenades_1 == 5))
                                        {
                                                gs = "Napalm grenade";
                                        }
                                        else
                                        {
                                                if ((self.tp_grenades_1 == 6))
                                                {
                                                        gs = "Flare";
                                                }
                                                else
                                                {
                                                        if ((self.tp_grenades_1 == 7))
                                                        {
                                                                gs = "Gas grenade";
                                                        }
                                                        else
                                                        {
                                                                if ((self.tp_grenades_1 == 8))
                                                                {
                                                                        gs = "EMP grenade";
                                                                }
                                                                else
                                                                {
                                                                        if ((self.tp_grenades_1 == enter))
                                                                        {
                                                                                gs = "Caltrop canister";
                                                                        }


                                                                        else
                                                                                if ((self.tp_grenades_1 == 11))
                                                                                gs = "Impact Grenade";

                                                                        else
                                                                        {
                                                                                gs = "Grenade";
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                if ((self.no_grenades_1 > 0))
                {
                        if (!practice)
                        {
                                self.no_grenades_1 = (self.no_grenades_1 - 1);
                        }
                        if ((gtype == 6))
                        {
                                newmis = spawn ();
                                newmis.owner = self;
                                newmis.movetype = 6;
                                newmis.solid = 2;
                                newmis.classname = "grenade";
                                makevectors (self.v_angle);
                                newmis.velocity = ((v_forward * 600) + (v_up * 25));
                                newmis.velocity = (newmis.velocity * 700);
                                newmis.angles = vectoangles (newmis.velocity);
                                newmis.weapon = self.team_no;
                                newmis.think = FlareGrenadeExplode;
                                newmis.nextthink = (time + 0.8);
                                newmis.touch = FlareGrenadeTouch;
                                newmis.skin = 1;
                                newmis.mdl = "flare";
                                setmodel (newmis, "progs/flare.mdl");
                                setsize (newmis, '0 0 0', '0 0 0');
                                setorigin (newmis, self.origin);
                                return;
                        }
                        if ((gtype == 10))
                        {
                                ptime = ftos (0.5);
                                sprint (self, 2, "Opening ");
                                sprint (self, 2, gs);
                                sprint (self, 2, "...\n");
                        }
                        else
                        {
                                ptime = ftos (3);
                                sprint (self, 2, gs);
                                sprint (self, 2, " primed, ");
                                sprint (self, 2, ptime);
                                sprint (self, 2, " seconds...\n");
                        }
                }
                else
                {
                        }
                }
                else
                {
                        sprint (self, 2, "No ");
                        sprint (self, 2, gs);
                        sprint (self, 2, "s left.\n");
                        return;
                }
        }
        if ((self.impulse == 151))
        {
                gtype = self.tp_grenades_2;
                if ((self.tp_grenades_2 == 2))
                {
                        gs = "Concussion grenade";
                }
                else
                {
                        if ((self.tp_grenades_2 == 3))
                        {
                                gs = "Nail grenade";
                        }
                        else
                        {
                                if ((self.tp_grenades_2 == 4))
                                {
                                        gs = "Mirv grenade";
                                }
                                else
                                {
                                        if ((self.tp_grenades_2 == 5))
                                        {
                                                gs = "Napalm grenade";
                                                gs = "Napalm grenade";
                                        }
                                        else
                                        {
                                                if ((self.tp_grenades_2 == 6))
                                                {
                                                        gs = "Flare";
                                                }
                                                else
                                                {
                                                        if ((self.tp_grenades_2 == 7))
                                                        {
                                                                gs = "Gas grenade";
                                                        }
                                                        else
                                                        {
                                                                if ((self.tp_grenades_2 == 8))
                                                                {
                                                                        gs = "EMP grenade";
                                                                }
                                                                else
                                                                {
                                                                        gs = "Grenade";
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                if ((self.no_grenades_2 > 0))
                if ((self.no_grenades_2 > 0))
                {
                        if (!practice)
                        {
                                self.no_grenades_2 = (self.no_grenades_2 - 1);
                        }
                        if ((gtype == 6))
                        {
                                newmis = spawn ();
                                newmis.owner = self;
                                newmis.movetype = 6;
                                newmis.solid = 2;
                                newmis.classname = "grenade";
                                makevectors (self.v_angle);
                                if (self.v_angle_x)
                                {
                                        newmis.velocity = ((v_forward * 1200) + (v_up * 200));
                                }
                                else
                                {
                                        newmis.velocity = aim (self, 10000);
                                        newmis.velocity = (newmis.velocity * 1200);
                                        newmis.velocity_z = _K;
                                }
                                newmis.angles = vectoangles (newmis.velocity);
                                newmis.weapon = self.team_no;
                                newmis.think = FlareGrenadeExplode;
                                newmis.nextthink = (time + 0.8);
                                newmis.touch = FlareGrenadeTouch;
                                newmis.skin = 1;
                                newmis.mdl = "flare";

                                setmodel (newmis, "progs/flare.mdl");
                                setsize (newmis, '0 0 0', '0 0 0');
                                setorigin (newmis, self.origin);
                                return;
                        }
                        if ((gtype == enter))
                        {
                                ptime = ftos (0.5);
                                sprint (self, 2, "Opening ");
                                sprint (self, 2, gs);
                                sprint (self, 2, "...\n");
                        }
                        else
                        {
                                ptime = ftos (3);
                                sprint (self, 2, gs);
                                sprint (self, 2, " primed, ");
                                sprint (self, 2, ptime);
                                sprint (self, 2, " seconds...\n");
                        }
                }
                else
                {
                        sprint (self, 2, "No ");
                        sprint (self, 2, gs);
                        sprint (self, 2, "s left.\n");
                        return;
                }
        }
        self.tfstate = (self.tfstate | 1);
        tGrenade = spawn ();
        tGrenade.owner = self;
        tGrenade.weapon = gtype;
        tGrenade.classname = "timer";
        tGrenade.impulse = self.impulse;
        tGrenade.nextthink = (time + 0.8);
        if (gtype == GR_TYPE_CALTROP)
        {
                tGrenade.heat = ((time + 0.5) + 0.5);
        }
        else
        {
                tGrenade.heat = ((time + 3) + 0.8);

                RemoveGrenadeTimers();

                local float grensound = stof(infokey(self, "grensound"));
                if (grentimers == 1)
                {
                        timer = spawn();
                        timer.nextthink = time + 0.8;
                        timer.think = GrenadeTimer;
                        timer.heat = 4;
                        timer.owner = self;
                        timer.classname = "gtimer";
                        if (grensound == 1)
                        {
                                stuffcmd(self, "play grentimer\n");
                        }
                }
                                stuffcmd(self, "play grentimer\n");
                        }
                }

        }

        tGrenade.think = TeamFortress_GrenadePrimed;
};

void () TeamFortress_GrenadePrimed =
{
        local entity user;
        local entity oldself;

        user = self.owner;
        if ((!(user.tfstate & 1024) && !user.deadflag))
        {
                self.nextthink = (time + 0.1);
                if (!self.think)
                {
                        dremove (self);
                }
                if ((time > self.heat) && (self.weapon != GR_TYPE_CALTROP))
                {
                        TeamFortress_ExplodePerson (self);
                }
                return;
        }
        if (!(user.tfstate & 1))
        {
                dprint ("GrenadePrimed logic error\n");
        }
        user.tfstate = (user.tfstate - (user.tfstate & 1));
        user.tfstate = (user.tfstate - (user.tfstate & 1024));
        sound (user, 1, "weapons/ax1.wav", 1, 1);
        KickPlayer (-1, user);
        newmis = spawn ();
        newmis.owner = user;
        newmis.movetype = enter;
        newmis.solid = 2;
        newmis.classname = "grenade";
        makevectors (user.v_angle);
        if (user.deadflag)
        {
                newmis.velocity = '0 0 200';
        }
        else
        {
                if (user.v_angle_x)
                {
                        newmis.velocity = ((((v_forward * 600) + (v_up * 200)) + ((crandom () * v_right) * enter)) + ((crandom () * v_up) * enter));
                }
                else
                {
                        newmis.velocity = aim (user, 10000);
                        newmis.velocity = (newmis.velocity * 600);
                        newmis.velocity_z = 200;
                }
        }
        newmis.angles = vectoangles (newmis.velocity);
        newmis.think = SUB_Null;
        newmis.nextthink = self.heat;
        if ((self.weapon == 1))

*/
