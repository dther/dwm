/* See LICENSE file for copyright and license details. */ 
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;	/* gaps for A E S T H E T I C */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char statussep         = ';';      /* status bar separator */
static const char *fonts[]          = { "Siji:size=10", "xos4 Terminus:size=10" };
static const char dmenufont[]       = "xos4 Terminus:size=10";
static char color0[]                = "#222222";
static char color1[]                = "#222222";
static char color2[]                = "#222222";
static char color3[]                = "#222222";
static char color4[]                = "#222222";
static char color5[]                = "#222222";
static char color6[]                = "#222222";
static char color7[]                = "#bbbbbb";
static char color8[]                = "#444444";
static char color9[]                = "#222222";
static char color10[]               = "#005577";
static char color11[]               = "#222222";
static char color12[]               = "#222222";
static char color13[]               = "#222222";
static char color14[]               = "#222222";
static char color15[]               = "#eeeeee";
/* Some colours that don't change. Used for errors/warnings and the like. */
//static char colorred[]              = "#ff0000";
//static char coloryellow[]           = "#ffff00";
//static char colorgreen[]            = "#00ff00";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { color7, color0, color8 },
       [SchemeSel]  = { color15,  color9,  color10 },
       //[SchemeOk]   = { colorgreen, color0, color10 },
       //[SchemeWarn] = { coloryellow, color0, color10 },
       //[SchemeUrgent] = { colorred, color0, color10 },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     	       instance   	title      	    tags mask     isfloating   isterminal   noswallow   monitor */
	{ "krita",		        NULL,      	NULL,         	1 << 4,       0,           0,           0,          -1 },
	{ "MyPaint",		    NULL,      	NULL,           1 << 4,       0,           0,           0,          -1 },
	{ "tabbed",	   "tabbed-surf",	    NULL,  	        1 << 1,       0,           0,           0,          -1 },
	{ "Pale moon",		    NULL,	    NULL,  	        1 << 1,       0,           0,           -1,         -1 },
	{ "discord",		    NULL,      	NULL,   	    1 << 2,       0,           0,           0,          -1 },
	{ "Zathura",		    NULL,      	NULL,   	    1 << 3,       0,           0,           0,          -1 },
	{ NULL,        "libreoffice",   	NULL,   	    1 << 3,       0,           0,           0,          -1 },
    { "cool-retro-term",    NULL,       NULL,           1 << 0,       0,           1,           -1,         -1 },
	{ "St",                 "st",   	"st",   	    1 << 0,       0,           1,           -1,         -1 },
	{ "St",                 "st",       "ranger",   	1 << 5,       0,           1,           -1,         -1 },
	{ "St",                 "st",       "Vim",   	    1 << 0,       0,           1,           -1,         -1 },
	{ "St",                 "st",       "tmux",   	    1 << 0,       0,           1,           0,          -1 },
	{ "St",                 "st", "Thinkvantage Bind",       0,       1,           1,           0,          -1 },
    { "mpv",                NULL,       NULL,           1 << 3,       0,           0,           0,          -1 },
    { "Inkscape",           NULL,       NULL,           1 << 4,       0,           0,           0,          -1 },
    { "OpenSCAD",           NULL,       NULL,           1 << 4,       0,           0,           0,          -1 },
    { "cura",               NULL,       NULL,           1 << 4,       0,           0,           0,          -1 },
    { "Steam",              NULL,       NULL,           1 << 6,       1,           0,           0,          -1 },
    { "Steam",              "Steam",   "Steam",         1 << 6,       0,           0,           0,          -1 },
    { "pico8",              "pico8",    NULL,           1 << 6,       0,           0,           0,          -1 },
    { "Lutris",             NULL,       NULL,           1 << 6,       0,           0,           0,          -1 },
	{ "Emacs",              NULL,       NULL,           1 << 0,       0,           0,           0,          -1 },
    { "Cellwriter",         NULL,       NULL,           1 << 8,       1,           0,           0,          -1 },
    { "Wpg",                NULL,       NULL,           1 << 8,       1,           0,           0,          -1 },
    { NULL,                 NULL,       "Event Tester",      0,       1,           0,           1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define HOLDKEY XK_Super_L // key held to create alt tags

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", color0, "-nf", color7, "-sb", color10, "-sf", color15, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", "-e", "tmux-scratchpad", NULL };
static const char *networkmancmd[] = { "networkmanager_dmenu", "-m", dmenumon, "-fn", dmenufont, "-nb", color0, "-nf", color7, "-sb", color10, "-sf", color15, NULL };
#define THINKV_PATH "/home/dther/bin/thinkvantage" //path to script bound to thinkvantage
static const char *bindcmd[] = { "st", "-t", "Thinkvantage Bind", "-g", "120x34", "-e", "vim", THINKV_PATH, NULL};
static const char *mpctogglecmd[] = { "mpc", "toggle", NULL };
static const char *mpcstopcmd[] = { "mpc", "stop", NULL };
static const char *mpcnextcmd[] = { "mpc", "next", NULL };
static const char *mpcprevcmd[] = { "mpc", "prev", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
    { 0,                            HOLDKEY,   showalttag,       {0} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_n,      spawn,          {.v = networkmancmd} },
    { MODKEY,                       XK_q,      spawn,          {.v = bindcmd} },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,			            XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0 } },
    { MODKEY,                       XK_Up,     spawn,          {.v = mpcstopcmd} },
    { MODKEY,                       XK_Down,   spawn,          {.v = mpctogglecmd} },
    { MODKEY,                       XK_Left,   spawn,          {.v = mpcprevcmd} },
    { MODKEY,                       XK_Right,  spawn,          {.v = mpcnextcmd} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button3,        view,           {0} },
	{ ClkTagBar,            0,              Button1,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

