/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 8;  /* snap pixel, def=32 */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps               = 0;   /* 1 means no outer gap when there is only one window */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const char buttonbar[]            = "≋";
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char font[]                 = "monospace 12";
static char dmenufont[]                  = "monospace:size=12";

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#4d4d4d";
static char selbordercolor[]             = "#4d4d4d";
static char selfloatcolor[]              = "#4d4d4d";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#4d4d4d";
static char titleselbordercolor[]        = "#4d4d4d";
static char titleselfloatcolor[]         = "#4d4d4d";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#4d4d4d";
static char tagsselbordercolor[]         = "#4d4d4d";
static char tagsselfloatcolor[]          = "#4d4d4d";

static char hidfgcolor[]                 = "#4d4d4d";
static char hidbgcolor[]                 = "#222222";
static char hidbordercolor[]             = "#4d4d4d";
static char hidfloatcolor[]              = "#f76e0c";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHid]          = { hidfgcolor,       hidbgcolor,       hidbordercolor,       hidfloatcolor },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};


static const char *layoutmenu_cmd = "layoutmenu.sh";

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "200x60", "-e", "ranger", NULL };
const char *spcmd3[] = {"st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
//const char *spcmd4[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
   {"spranger",    spcmd2},
   {"spcalc",      spcmd3},
//   {"keepassxc",   spcmd4},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
/*
static const Rule rules[] = {
	 * xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype

	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
};
*/

static const Rule rules[] = {
    // xprop(1):
    //    WM_CLASS(STRING) = instance, class
    //    WM_NAME(STRING) = title
    //    WM_WINDOW_ROLE(STRING) = role
    //
    // class      role      instance    title      wtype  tags mask    isfloating   isterminal  noswallow  monitor
    { "Gimp",     NULL,     NULL,       NULL,      NULL,   0,           1,           0,          0,         -1 },
    { "Firefox",  NULL,     NULL,       NULL,      NULL,   1 << 8,      0,           0,          0,         -1 },
    { "St",       NULL,     NULL,       NULL,      NULL,   0,           0,           1,          0,         -1 },
    { NULL,       NULL,     NULL,  "Event Tester", NULL,   0,           0,           0,          1,         -1 },   // xev
    { NULL,       NULL,     "spterm",   NULL,      NULL,   SPTAG(0),    1,           1,          0,         -1 },
    { NULL,       NULL,     "spfm",     NULL,      NULL,   SPTAG(1),    1,           1,          0,         -1 },
    { NULL,       NULL,     "spcalc",   NULL,      NULL,   SPTAG(2),    1,           1,          0,         -1 },
};

static const MonitorRule monrules[] = {
    /* monitor  tag   layout  mfact  nmaster  showbar  topbar */
//    {  -1,      -1,   0,      -1,    -1,      -1,      -1     }, // default
//    {   1,      -1,   0,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
    {   0,       1,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#1 : default
    {   0,       2,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#2 : default
    {   0,       3,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#3 : default
    {   0,       4,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#4 : default
    {   0,       5,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#5 : default
    {   0,       6,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#6 : default
    {   0,       7,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#7 : default
    {   0,       8,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#8 : default
    {   0,       9,   0,      -1,    -1,      -1,      -1     }, // mon#0 tag#9 : default
    {   0,       0,   9,      -1,    -1,      -1,      -1     }, // mon#0 tag#0 : grid layout (#9) - nice for winview

    {   1,       1,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#1 : default
    {   1,       2,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#2 : default
    {   1,       3,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#3 : default
    {   1,       4,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#4 : default
    {   1,       5,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#5 : default
    {   1,       6,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#6 : default
    {   1,       7,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#7 : default
    {   1,       8,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#8 : default
    {   1,       9,   0,      -1,    -1,      -1,      -1     }, // mon#1 tag#9 : default
    {   1,       0,   9,      -1,    -1,      -1,      -1     }, // mon#1 tag#0 : grid layout (#9) - nice for winview
};


/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,       0,     BAR_ALIGN_LEFT,   width_stbutton,          draw_stbutton,          click_stbutton,          "statusbutton" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{  0,       0,     BAR_ALIGN_RIGHT,  width_status,            draw_status,            click_statuscmd,         "status" },
//	{ -1,       0,     BAR_ALIGN_RIGHT,  width_status,            draw_status,            click_statuscmd,         "status" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, -SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "|||",      flextile,         { -1, -1, -SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "[D]",      flextile,         { -1, -1, -SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ NULL,       NULL,             {0} },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      tagprevmon,     {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};
static const char *termcmd[]  = { "st", NULL };
static const char *instantswitchcmd[] = {"rofi", "-show", "window", "-show-icons", "-kb-row-down", "Alt+Tab,Down", "-kb-row-up", "Alt+Ctrl+Tab,Up", "-kb-accept-entry", "!Alt_L,!Alt+Tab,Return", "-me-select-entry", "", "-me-accept-entry", "MousePrimary", NULL};

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
//static const char *statuscmds[] = { "notify-send Mouse$BUTTON" };
//static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

/*
static const char* firefoxcmd[] = {"firefox", NULL};
static Key on_empty_keys[] = {
	// modifier key            function                argument
	{ 0,        XK_f,          spawn,                  {.v = firefoxcmd } },
};
*/
/*
static Key keys[] = {
	// modifier                     key            function                argument
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_s,          swapfocus,              {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_j,          inplacerotate,          {.i = +1} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_k,          inplacerotate,          {.i = -1} },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
	{ MODKEY|Mod4Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
	{ MODKEY|Mod4Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
	{ MODKEY|Mod4Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
	{ MODKEY|Mod4Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ShiftMask,             XK_Tab,        shiftview,              { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_backslash,  shiftview,              { .i = +1 } },
	{ MODKEY|Mod4Mask,              XK_Tab,        shiftviewclients,       { .i = -1 } },
	{ MODKEY|Mod4Mask,              XK_backslash,  shiftviewclients,       { .i = +1 } },
	{ MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
	{ MODKEY,                       XK_o,          winview,                {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   // flextile, 1 = layout axis
	{ MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   // flextile, 2 = master axis
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   // flextile, 3 = stack axis
	{ MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   // flextile, 4 = secondary stack axis
	{ MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   // flextile, 1 = layout axis
	{ MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   // flextile, 2 = master axis
	{ MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   // flextile, 3 = stack axis
	{ MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   // flextile, 4 = secondary stack axis
	{ MODKEY|ControlMask,           XK_Return,     mirrorlayout,           {0} },          // flextile, flip master and stack areas
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
	{ MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },
	{ MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_comma,      tagallmon,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_period,     tagallmon,              {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_comma,      tagswapmon,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_period,     tagswapmon,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};
*/

#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier                     key            function                argument */
    TAGKEYS(                        XK_1,                                  0)
    TAGKEYS(                        XK_2,                                  1)
    TAGKEYS(                        XK_3,                                  2)
    TAGKEYS(                        XK_4,                                  3)
    TAGKEYS(                        XK_5,                                  4)
    TAGKEYS(                        XK_6,                                  5)
    TAGKEYS(                        XK_7,                                  6)
    TAGKEYS(                        XK_8,                                  7)
    TAGKEYS(                        XK_9,                                  8)

    { Mod1Mask,                     XK_Tab,        spawn,                  {.v = instantswitchcmd } },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },

    { MODKEY,                       XK_F1,         spawn,                  SHCMD("dmenushortcut") },
    { MODKEY|ShiftMask,             XK_F1,         spawn,                  SHCMD("randman") },
    { MODKEY,                       XK_F2,         spawn,                  SHCMD("showman") },
    { MODKEY|ShiftMask,             XK_F2,         quit,                   {1} },    // restart = sighup
    { MODKEY|ControlMask|ShiftMask, XK_F2,         quit,                   {0} },    // quit = sigterm
    { MODKEY,                       XK_F3,         spawn,                  SHCMD("displayselect") },
    { MODKEY,                       XK_F5,         xrdb,                   {.v = NULL } },

    { MODKEY,                       XK_Tab,        view,                   {0} },
    //{ MODKEY,                       XK_grave,      spawn,                  SHCMD("dmenuunicode") },

    { MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },
    { MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
    { MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },

    { MODKEY|ShiftMask,             XK_BackSpace,  spawn,                  SHCMD("sysact") },
    { MODKEY,                       XK_Insert,     spawn,                  SHCMD("showclip") },
    { ShiftMask,                    XK_Print,      spawn,                  SHCMD("maimpick") },
    { MODKEY,                       XK_Page_Up,    shiftviewclients,       {.i =  1 } },
    { MODKEY,                       XK_Page_Down,  shiftviewclients,       {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Page_Up,    shiftview,              {.i =  1 } },
    { MODKEY|ShiftMask,             XK_Page_Down,  shiftview,              {.i = -1 } },
    { MODKEY,                       XK_minus,      spawn,                  SHCMD("pulsemixer --change-volume -5 ; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,             XK_minus,      spawn,                  SHCMD("pulsemixer --change-volume -1 ; kill -44 $(pidof dwmblocks)") },
    { MODKEY,                       XK_equal,      spawn,                  SHCMD("pulsemixer --change-volume +5 ; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,             XK_equal,      spawn,                  SHCMD("pulsemixer --change-volume +1 ; kill -44 $(pidof dwmblocks)") },

    { MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_Return,     togglescratch,          {.ui = 0 } },
    { MODKEY|ControlMask,           XK_Return,     togglescratch,          {.ui = 1 } },
    { MODKEY,                       XK_comma,      spawn,                  SHCMD("mpc prev ; kill -45 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,             XK_comma,      spawn,                  SHCMD("mpc seek 0% ; kill -45 $(pidof dwmblocks)") },
    { MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
    { MODKEY,                       XK_period,     spawn,                  SHCMD("mpc next ; kill -45 $(pidof dwmblocks)") },
    { MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
    { MODKEY,                       XK_space,      zoom,                   {0} },
    { MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
    { MODKEY|ControlMask,           XK_space,      setlayout,              {0} },

    { MODKEY,                       XK_backslash,  focusmon,               {.i = +1 } },  // TODO
    { MODKEY,                       XK_apostrophe, tagswapmon,             {.i = +1 } },
    { MODKEY,                       XK_semicolon,  tagmon,                 {.i = +1 } },  // TODO
    { MODKEY|ShiftMask,             XK_apostrophe, tagallmon,              {.i = +1 } },

    { MODKEY,                       XK_Left,       focusmon,               {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Left,       tagmon,                 {.i = -1 } },
    { MODKEY,                       XK_Right,      focusmon,               {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Right,      tagmon,                 {.i = +1 } },

    { MODKEY|ShiftMask,             XK_a,          spawn,                  SHCMD("st -e pulsemixer ; kill -44 $(pidof dwmblocks)") },
    { MODKEY,                       XK_b,          togglebar,              {0} },
    { MODKEY,                       XK_c,          spawn,                  SHCMD("gpass") },
    { MODKEY|ShiftMask,             XK_c,          togglescratch,          {.ui = 2 } },
    { MODKEY,                       XK_d,          spawn,                  {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_d,          togglegaps,             {0} },
    { MODKEY,                       XK_f,          togglefullscreen,       {0} },
    { MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },
    { MODKEY,                       XK_h,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
    { MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
    { MODKEY|ShiftMask,             XK_i,          incnmaster,             {.i = -1 } },
    { MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
    { MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
    { MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
    { MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
    { MODKEY,                       XK_l,          setmfact,               {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
    //{ MODKEY,                       XK_m,          spawn,                  SHCMD("pamixer -t; pkill -RTMIN+10 dwmblocks") },
    { MODKEY,                       XK_m,          spawn,                  SHCMD("pulsemixer --toggle-mute ; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,             XK_m,          spawn,                  SHCMD("st -e ncmpcpp") },
    { MODKEY,                       XK_o,          winview,                {0} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
    { MODKEY,                       XK_p,          spawn,                  SHCMD("mpc toggle; kill -45 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,             XK_p,          spawn,                  SHCMD("mpc pause ; pauseallmpv") },
    { MODKEY|ShiftMask,             XK_q,          killclient,             {0} },
    { MODKEY|ShiftMask,             XK_r,          mirrorlayout,           {0} },         /* flextile, flip master and stack areas */
    { MODKEY,                       XK_s,          swapfocus,              {.i = -1 } },
    { MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
    { MODKEY,                       XK_w,          spawn,                  SHCMD("$BROWSER") },
    //{ MODKEY|ShiftMask,             XK_w,          spawn,                  SHCMD("chromium --force-device-scale-factor=2 --disable-field-trial-config") },
    { MODKEY|ShiftMask,             XK_w,          spawn,                  SHCMD("chromium --autoplay-policy=user-required --disable-field-trial-config") },
    { MODKEY|ShiftMask,             XK_x,          spawn,                  SHCMD("slock & mpc pause ; pauseallmpv") },
    { MODKEY,                       XK_a,          spawn,                  SHCMD("instant") },
    { MODKEY,                       XK_z,          incrgaps,               {.i = +1 } },
    { MODKEY|ShiftMask,             XK_z,          incrgaps,               {.i = -1 } },

    // TODO
    { MODKEY,                       XK_q,          setlayout,              {.v = &layouts[0]} },
    //{ MODKEY,                       XK_a,          setlayout,              {.v = &layouts[1]} },
    { MODKEY,                       XK_y,          setlayout,              {.v = &layouts[2]} },

    // resize/move floating window
    { MODKEY|Mod1Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
    { MODKEY|Mod1Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
    { MODKEY|Mod1Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
    { MODKEY|Mod1Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },

    //------- not important keys...  --> remove ?
    { MODKEY|Mod1Mask|ShiftMask,    XK_j,          inplacerotate,          {.i = +1} },
    { MODKEY|Mod1Mask|ShiftMask,    XK_k,          inplacerotate,          {.i = -1} },
    { MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
    { MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },

    // rotate axis
    { MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
    { MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
    { MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
    { MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */

    { MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
    { MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
    { MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
    { MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */

    // TODO  -- Laptop
    { 0, XF86XK_AudioMute,           spawn,        SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioRaiseVolume,    spawn,        SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioLowerVolume,    spawn,        SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioPrev,           spawn,        SHCMD("mpc prev") },
    { 0, XF86XK_AudioNext,           spawn,        SHCMD("mpc next") },
    { 0, XF86XK_AudioPause,          spawn,        SHCMD("mpc pause") },
    { 0, XF86XK_AudioPlay,           spawn,        SHCMD("mpc play") },
    { 0, XF86XK_AudioStop,           spawn,        SHCMD("mpc stop") },
    { 0, XF86XK_AudioRewind,         spawn,        SHCMD("mpc seek -10") },
    { 0, XF86XK_AudioForward,        spawn,        SHCMD("mpc seek +10") },
    { 0, XF86XK_AudioMedia,          spawn,        SHCMD("st -e ncmpcpp") },
    { 0, XF86XK_PowerOff,            spawn,        SHCMD("sysact") },
    { 0, XF86XK_Calculator,          spawn,        SHCMD("st -e bc -l") },
    { 0, XF86XK_Sleep,               spawn,        SHCMD("sudo -A zzz") },
    { 0, XF86XK_WWW,                 spawn,        SHCMD("$BROWSER") },
    { 0, XF86XK_DOS,                 spawn,        SHCMD("st") },
    { 0, XF86XK_ScreenSaver,         spawn,        SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
    { 0, XF86XK_TaskPane,            spawn,        SHCMD("st -e htop") },
    { 0, XF86XK_Mail,                spawn,        SHCMD("st -e neomutt") },
    { 0, XF86XK_MyComputer,          spawn,        SHCMD("st -e lf /") },
    { 0, XF86XK_Battery,             spawn,        SHCMD("") },
    { 0, XF86XK_Launch1,             spawn,        SHCMD("xset dpms force off") },
    { 0, XF86XK_TouchpadToggle,      spawn,        SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOff,         spawn,        SHCMD("synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOn,          spawn,        SHCMD("synclient TouchpadOff=0") },
    { 0, XF86XK_MonBrightnessUp,     spawn,        SHCMD("xbacklight -inc 15") },
    { 0, XF86XK_MonBrightnessDown,   spawn,        SHCMD("xbacklight -dec 15") },

    //---- inner/outer gaps:  not needed!
    /*
    { MODKEY|Mod1Mask,              XK_i,          incrigaps,              {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_o,          incrogaps,              {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_6,          incrihgaps,             {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_7,          incrivgaps,             {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_8,          incrohgaps,             {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_9,          incrovgaps,             {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
    */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
/*
static Button buttons[] = {
	// click                event mask           button          function        argument
	{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenucmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	// placemouse options, choose which feels more natural:
	//    0 - tiled position is relative to mouse cursor
	//    1 - tiled postiion is relative to window center
	//    2 - mouse pointer warps to window center
	//
	{ ClkClientWin,         MODKEY|ControlMask,  Button1,        placemouse,     {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};
*/
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask           button          function        argument */
  	{ ClkButton,        	0,	              	 Button1,	     spawn,		     SHCMD("xmenu.sh") },
  	{ ClkButton,        	0,	              	 Button2,	     spawn,		     SHCMD("dmenuunicode") },
    { ClkButton,		    0,		             Button3,	     spawn,		     {.v = dmenucmd } },

	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
    { ClkWinTitle,          0,                   Button2,        zoom,           {0} },
    { ClkWinTitle,          0,                   Button3,        showhideclient, {0} },

    { ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        layoutmenu,     {0} },
    //{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },

    { ClkStatusText,        0,                   Button1,        sigdwmblocks,   {.i = 1 } },
    { ClkStatusText,        0,                   Button2,        sigdwmblocks,   {.i = 2 } },
    { ClkStatusText,        0,                   Button3,        sigdwmblocks,   {.i = 3 } },
    { ClkStatusText,        0,                   Button4,        sigdwmblocks,   {.i = 4 } },
    { ClkStatusText,        0,                   Button5,        sigdwmblocks,   {.i = 5 } },
    { ClkStatusText,        ShiftMask,           Button1,        sigdwmblocks,   {.i = 6 } },

    { ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|ControlMask,  Button1,        placemouse,     {.i = 1} },
    { ClkClientWin,         MODKEY|Mod1Mask,     Button1,        tagmon,         {.i = +1} },
    { ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
    { ClkClientWin,         MODKEY,              Button4,        incrgaps,       {.i = +1} },
    { ClkClientWin,         MODKEY,              Button5,        incrgaps,       {.i = -1} },
//    { ClkClientWin,         MODKEY,              Button7,        tagmon,         {.i = -1} },

    { ClkTagBar,            0,                   Button1,        view,           {0} },
    { ClkTagBar,            0,                   Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
    { ClkTagBar,            0,                   Button4,        shiftview,      {.i = -1} },
    { ClkTagBar,            0,                   Button5,        shiftview,      {.i = 1} },

    { ClkRootWin,           0,                   Button2,        togglebar,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "swapfocus",               swapfocus },
	{ "inplacerotate",           inplacerotate },
	{ "incnstack",               incnstack },
	{ "rotatelayoutaxis",        rotatelayoutaxis },
	{ "setlayoutaxisex",         setlayoutaxisex },
	{ "mirrorlayout",            mirrorlayout },
	{ "setcfact",                setcfact },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "shiftview",               shiftview },
	{ "shiftviewclients",        shiftviewclients },
	{ "togglesticky",            togglesticky },
	{ "cyclelayout",             cyclelayout },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "tagallmon",               tagallmon },
	{ "tagswapmon",              tagswapmon},
	{ "togglefullscreen",        togglefullscreen },
	{ "fullscreen",              fullscreen },
	{ "togglescratch",           togglescratch },
	{ "killclient",              killclient },
	{ "winview",                 winview },
	{ "xrdb",                    xrdb },
	{ "tagnextmonex",            tagnextmonex },
	{ "tagprevmonex",            tagprevmonex },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};
