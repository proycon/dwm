/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Source Code Pro for Powerline:size=9", "FontAwesome:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#282828";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#a89984";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#4d6e4e";
static const char col_activeborder[]      = "#8fb1a4";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray1, col_cyan,  col_activeborder  },
};

/* tagging */
static const char *tags[] = { "1:", "2:", "3:", "4:", "5:", "6", "7:", "8:", "9", "10: ", "11" };
static const int permontag[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,       1 << 4,       0,           0,          0,        -1 },
	{ "Inkscape",     NULL,       NULL,       1 << 4,       0,           0,          0,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 2,       0,           0,          0,        -1 },
	{ "Menu",     NULL,       NULL,       0,            1,           0,          0,        -1 },
	{ "Lxappearance",     NULL,       NULL,       0,            1,    0,          0,               -1 },
	{ "Lightdm-gtk-greeter-settings",     NULL,       NULL,       0,            1,     0,          0,              -1 },
	{ "mpv",     NULL,       NULL,       0,            1,     0,          0,              -1 },
	{ "st",      NULL,     NULL,           0,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     NULL,           0,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mail",         1,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "newsboat",         1 << 5,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "vim",         1 << 1,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mhysa",         1 << 3,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "rocinante",         1 << 3,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp01",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp02",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp03",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp04",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp05",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp06",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp07",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp08",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp09",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp10",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp11",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "mlp12",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "anaproy",         1 << 7,         0,          1,          -1,        -1 },
	{ "Alacritty",      NULL,     "anaproy2",         1 << 7,         0,          1,          -1,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ "",      centeredmaster },
	{ "",      bstack },
	{ "",      bstackhoriz },
	{ "",    tstack },
	{ "",      tstackhoriz },
	{ NULL,       NULL },
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
static const char *scratchpadcmd[] = { "st","-t",scratchpadname,"-g","120x34","-e","/home/proycon/bin/tm",scratchpadname, NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,      spawn,          {.v = dmenucmd } },
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
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_z,      focusmonnum,        {.i = 1 } },
	{ MODKEY,                       XK_x,      focusmonnum,        {.i = 0 } },
	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_apostrophe,  cyclelayout,      {0} },
	{ MODKEY|ShiftMask,             XK_apostrophe,  togglefloating, {0} },
	{ MODKEY,                       XK_backslash,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_comma,  setgaps,        {.i = -3 } },
	{ MODKEY|ShiftMask,             XK_comma,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_period,  setgaps,        {.i = +3 } },
	{ MODKEY|ShiftMask,             XK_period,  setgaps,        {.i = +9  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9) //left monitor desktop 1
	TAGKEYS(                        XK_minus,                 10) //left monitor desktop 2
	TAGKEYS(                        XK_equal,                  8) //alias for last desktop on right monitor
	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,           {0} },
    { ALTKEY,                       XK_F8, spawn, SHCMD("fcitx && play ~/dotfiles/media/key.wav") },
    { ALTKEY,                       XK_F9, spawn, SHCMD("killall fcitx; setxkbmap proylatin && play ~/dotfiles/media/key.wav") },
    { ALTKEY,                       XK_F10, spawn, SHCMD("killall fcitx; setxkbmap proyeo && play ~/dotfiles/media/key.wav") },
    { ALTKEY|ShiftMask,             XK_F10, spawn, SHCMD("killall fcitx; setxkbmap proyel && play ~/dotfiles/media/key.wav") },
    { ALTKEY,                       XK_F11, spawn, SHCMD("killall fcitx; setxkbmap proyru && play ~/dotfiles/media/key.wav") },
    { ALTKEY,                       XK_F12, spawn, SHCMD("killall fcitx; setxkbmap proyar && play ~/dotfiles/media/key.wav") },
    { ALTKEY|ShiftMask,             XK_F12, spawn, SHCMD("killall fcitx; setxkbmap proylogic && play ~/dotfiles/media/key.wav") },
	{ MODKEY,						XK_F1, spawn, SHCMD("alacritty --working-directory ~ -t mail -e ssh -Y -A -t anaproy.nl ~/bin/tm_alot") },
	{ MODKEY,						XK_F2, spawn, SHCMD("alacritty --working-directory ~ -t vim -e ~/bin/tm nvim") },
	{ ALTKEY,						XK_F2, spawn, SHCMD("~/bin/lala") }, /* start music */
	{ ALTKEY|ShiftMask,				XK_F2, spawn, SHCMD("killall snapclient; mpc stop") }, /* stop music */
	{ MODKEY,						XK_F3, spawn, SHCMD("~/dotfiles/homecommand.sh") },
	{ ALTKEY,						XK_F3, spawn, SHCMD("~/dotfiles/homecommand.sh mute") },
	{ ALTKEY,						XK_F5, spawn, SHCMD("~/dotfiles/emojiselect") }, /* select emoji */
	{ MODKEY,						XK_F4, spawn, SHCMD("scrot && play ~/dotfiles/media/shutter.wav") }, /* screenshot */
	{ MODKEY|ShiftMask,				XK_F4, spawn, SHCMD("scrot --focused && play ~/dotfiles/media/shutter.wav") }, /* screenshot */
	{ MODKEY,						XK_F5, spawn, SHCMD("~/dotfiles/opensxiv.sh") }, /* gallery */
	{ MODKEY|ShiftMask,				XK_F5, spawn, SHCMD("~/dotfiles/openinstagram.sh") }, /* instagram gallery */
	{ MODKEY,						XK_F6, spawn, SHCMD("alacritty --working-directory ~ -t newsboat -e newsboat") }, /* RSS reader */
	{ MODKEY,						XK_F7, spawn, SHCMD("alacritty --working-directory ~ -t ncmpcpp -e ncmpcpp") }, /* Music browser */
	{ MODKEY,                       XK_y, spawn, SHCMD("alacritty --working-directory ~ -t youtube -e ytfzf -t") },
	{ MODKEY|ShiftMask,             XK_y, spawn, SHCMD("alacritty --working-directory ~ -t youtube -e ytfzf -t -H") },
	{ MODKEY,						XK_F8, spawn, SHCMD("picom -f") }, /* start compositor */
	{ MODKEY|ShiftMask,				XK_F8, spawn, SHCMD("killall picom") }, /* stop compositor */
	{ MODKEY,						XK_Escape, spawn, SHCMD("~/dotfiles/lock.sh") }, /* lock screen */
	{ MODKEY|ShiftMask,				XK_Escape, spawn, SHCMD("~/dotfiles/suspend.sh") }, /* lock screen */
	{ MODKEY,   	    			XK_slash, spawn, SHCMD("~/dotfiles/timetracker.sh") },
	{ MODKEY|ShiftMask,    			XK_slash, spawn, SHCMD("~/dotfiles/timetracker.sh 15") },
	{ MODKEY|ControlMask|ShiftMask, XK_slash, spawn, SHCMD("~/dotfiles/timetracker.sh 60") },
	{ MODKEY,						XK_w, spawn, SHCMD("~/dotfiles/buku-dmenu") },
	{ MODKEY,						XK_u, spawn, SHCMD("~/dotfiles/dmenu-files.sh /nettmp -t") },
	{ MODKEY,						XK_o, spawn, SHCMD("~/dotfiles/dmenu-files.sh /home/proycon -t") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD("alacritty --working-directory ~ -t ncmpcpp -e ncmpcpp") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 5 && play ~/dotfiles/media/key.wav") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 5 && play ~/dotfiles/media/key.wav") },
	{ 0, XF86XK_AudioMute,	spawn,		SHCMD("pamixer -t && play ~/dotfiles/media/key.wav") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("~/dotfiles/bright_down.sh") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("~/dotfiles/bright_up.sh") },
	{ MODKEY, XK_F12,	spawn,		SHCMD("pamixer --allow-boost -i 5 && play ~/dotfiles/media/key.wav") },
	{ MODKEY, XK_F11,	spawn,		SHCMD("pamixer --allow-boost -d 5 && play ~/dotfiles/media/key.wav") },
	{ MODKEY, XK_F10,	spawn,		SHCMD("pamixer -t && play ~/dotfiles/media/key.wav") },
	{ MODKEY, XK_F9,	spawn,		SHCMD("mpc next") },
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

