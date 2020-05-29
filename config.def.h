/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#282828";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#a89984";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#98971a";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Menu",     NULL,       NULL,       0,            1,           -1 },
	{ "Lxappearance",     NULL,       NULL,       0,            1,           -1 },
	{ "Lightdm-gtk-greeter-settings",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
};

/* key definitions */
#define MODKEY Mod4Mask /* super */
#define ALTKEY Mod1Mask /* alt */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD|ShiftMask, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-font", "Source Code Pro for Powerline 16", "-combi-modi", "window,drun,run", "-show", "combi", "-modi","combi", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "urxvt","-name",scratchpadname,"-e","/home/proycon/bin/tm",scratchpadname, NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_apostrophe,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_a,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
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
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,           {0} },
    { ALTKEY,                       XK_F8, spawn, SHCMD("fcitx") },
    { ALTKEY,                       XK_F9, spawn, SHCMD("killall fcitx || setxkbmap proylatin") },
    { ALTKEY,                       XK_F10, spawn, SHCMD("killall fcitx || setxkbmap proyeo") },
    { ALTKEY|ShiftMask,             XK_F10, spawn, SHCMD("killall fcitx || setxkbmap proyel") },
    { ALTKEY,                       XK_F11, spawn, SHCMD("killall fcitx || setxkbmap proyru") },
    { ALTKEY,                       XK_F12, spawn, SHCMD("killall fcitx || setxkbmap proyar") },
    { ALTKEY|ShiftMask,             XK_F12, spawn, SHCMD("killall fcitx || setxkbmap proylogic") },
	{ MODKEY,						XK_F1, spawn, SHCMD("alacritty --working-directory ~ -t mail -e ssh -Y -A -t anaproy.nl ~/tm_alot") },
	{ MODKEY,						XK_F2, spawn, SHCMD("alacritty --working-directory ~ -t vim -e ~/bin/tm nvim") },
	{ ALTKEY,						XK_F2, spawn, SHCMD("~/bin/lala") }, /* start music */
	{ ALTKEY|ShiftMask,				XK_F2, spawn, SHCMD("killall mplayer; mpc stop") }, /* stop music */
	{ MODKEY,						XK_F3, spawn, SHCMD("$BROWSER") },
	{ ALTKEY,						XK_F5, spawn, SHCMD("~/dotfiles/emojiselect.sh") }, /* select emoji */
	{ MODKEY,						XK_F5, spawn, SHCMD("~/dotfiles/opensxiv.sh") }, /* gallery */
	{ MODKEY|ShiftMask,				XK_F5, spawn, SHCMD("~/dotfiles/openinstagram.sh") }, /* instagram gallery */
	{ MODKEY,						XK_F6, spawn, SHCMD("alacritty --working-directory ~ -t newsboat -e newsboat") }, /* RSS reader */
	{ MODKEY,						XK_F7, spawn, SHCMD("alacritty --working-directory ~ -t ncmpcpp -e ncmpcpp") }, /* Music browser */
	{ MODKEY,						XK_F12, spawn, SHCMD("picom -cC -z -r 3 -l 2 -t 2 -f") }, /* start compositor */
	{ MODKEY|ShiftMask,				XK_F12, spawn, SHCMD("killall picom") }, /* stop compositor */
	{ MODKEY,						XK_Escape, spawn, SHCMD("~/dotfiles/lock.sh") }, /* lock screen */
	{ MODKEY|ShiftMask,				XK_Escape, spawn, SHCMD("~/dotfiles/suspend.sh") }, /* lock screen */
    { ALTKEY,                       XK_F4,  spawn, SHCMD("pkill -f notifyclient.py") }, /* restart notifyclient */
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD("alacritty --working-directory ~ -t ncmpcpp -e ncmpcpp") },
	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("paactl set-sink-volume 0 +5%") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pactl set-sink-volume 0 -5%") },
	{ 0, XF86XK_AudioMute,	spawn,		SHCMD("pactl set-sink-mute 0 toggle") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("~/dotfiles/bright_down.sh") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("~/dotfiles/bright_up.sh") },
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
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

