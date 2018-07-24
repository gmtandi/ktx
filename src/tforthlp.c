
#include "g_local.h"

void TeamFortress_Alias (const char *halias, int himpulse1, int himpulse2)
{

	stuffcmd (PROG_TO_EDICT( self->s.v.owner ), "alias %s \"impulse %d", halias, himpulse1);
	if ((himpulse2 != 0))
	{
		stuffcmd (PROG_TO_EDICT( self->s.v.owner ), ";wait; impulse %d",himpulse2);
	}
	stuffcmd (PROG_TO_EDICT( self->s.v.owner ), "\"\n");
}

void TeamFortres_Aliases()
{
		G_centerprint (PROG_TO_EDICT( self->s.v.owner ),  "Hue Team Fortress v1.45\nhttp://github.com/gmtandi/huetf\n");
		G_centerprint (PROG_TO_EDICT( self->s.v.owner ),  "binding aliases...\n");
/*		TeamFortress_Alias ("primeone", 150, 0);
		TeamFortress_Alias ("primetwo", 151, 0);
		TeamFortress_Alias ("throwgren", 152, 0);
		TeamFortress_Alias ("+gren1", 150, 0);
		TeamFortress_Alias ("+gren2", 151, 0);
		TeamFortress_Alias ("-gren1", 152, 0);
		TeamFortress_Alias ("-gren2", 152, 0);*/
}
