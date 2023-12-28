/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Input event codes
 *
 *    *** IMPORTANT ***
 * This file is not only included from C-code but also from devicetree source
 * files. As such this file MUST only contain comments and defines.
 *
 * Copyright (c) 1999-2002 Vojtech Pavlik
 * Copyright (c) 2015 Hans de Goede <hdegoede@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */
#ifndef _INPUT_EVENT_CODES_H
#define _INPUT_EVENT_CODES_H

/*
 * Device properties and quirks
 */

#define INPUT_PROP_POINTER		0x00	/* needs a pointer */
#define INPUT_PROP_DIRECT		0x01	/* direct input devices */
#define INPUT_PROP_BUTTONPAD		0x02	/* has button(s) under pad */
#define INPUT_PROP_SEMI_MT		0x03	/* touch rectangle only */
#define INPUT_PROP_TOPBUTTONPAD		0x04	/* softbuttons at top of pad */
#define INPUT_PROP_POINTING_STICK	0x05	/* is a pointing stick */
#define INPUT_PROP_ACCELEROMETER	0x06	/* has accelerometer */

#define INPUT_PROP_MAX			0x1f
#define INPUT_PROP_CNT			(INPUT_PROP_MAX + 1)

/*
 * Event types
 */

#define EV_SYN			0x00
#define EV_KEY			0x01
#define EV_REL			0x02
#define EV_ABS			0x03
#define EV_MSC			0x04
#define EV_SW			0x05
#define EV_LED			0x11
#define EV_SND			0x12
#define EV_REP			0x14
#define EV_FF			0x15
#define EV_PWR			0x16
#define EV_FF_STATUS		0x17
#define EV_MAX			0x1f
#define EV_CNT			(EV_MAX+1)

/*
 * Synchronization events.
 */

#define SYN_REPORT		0
#define SYN_CONFIG		1
#define SYN_MT_REPORT		2
#define SYN_DROPPED		3
#define SYN_MAX			0xf
#define SYN_CNT			(SYN_MAX+1)

/*
 * Keys and buttons
 *
 * Most of the keys/buttons are modeled after USB HUT 1.12
 * (see http://www.usb.org/developers/hidpage).
 * Abbreviations in the comments:
 * AC - Application Control
 * AL - Application Launch Button
 * SC - System Control
 */

#define PH_KEY_RESERVED		0
#define PH_KEY_ESC			1
#define PH_KEY_1			2
#define PH_KEY_2			3
#define PH_KEY_3			4
#define PH_KEY_4			5
#define PH_KEY_5			6
#define PH_KEY_6			7
#define PH_KEY_7			8
#define PH_KEY_8			9
#define PH_KEY_9			10
#define PH_KEY_0			11
#define PH_KEY_MINUS		12
#define PH_KEY_EQUAL		13
#define PH_KEY_BACKSPACE		14
#define PH_KEY_TAB			15
#define PH_KEY_Q			16
#define PH_KEY_W			17
#define PH_KEY_E			18
#define PH_KEY_R			19
#define PH_KEY_T			20
#define PH_KEY_Y			21
#define PH_KEY_U			22
#define PH_KEY_I			23
#define PH_KEY_O			24
#define PH_KEY_P			25
#define PH_KEY_LEFTBRACE		26
#define PH_KEY_RIGHTBRACE		27
#define PH_KEY_ENTER		28
#define PH_KEY_LEFTCTRL		29
#define PH_KEY_A			30
#define PH_KEY_S			31
#define PH_KEY_D			32
#define PH_KEY_F			33
#define PH_KEY_G			34
#define PH_KEY_H			35
#define PH_KEY_J			36
#define PH_KEY_K			37
#define PH_KEY_L			38
#define PH_KEY_SEMICOLON		39
#define PH_KEY_APOSTROPHE		40
#define PH_KEY_GRAVE		41
#define PH_KEY_LEFTSHIFT		42
#define PH_KEY_BACKSLASH		43
#define PH_KEY_Z			44
#define PH_KEY_X			45
#define PH_KEY_C			46
#define PH_KEY_V			47
#define PH_KEY_B			48
#define PH_KEY_N			49
#define PH_KEY_M			50
#define PH_KEY_COMMA		51
#define PH_KEY_DOT			52
#define PH_KEY_SLASH		53
#define PH_KEY_RIGHTSHIFT		54
#define PH_KEY_KPASTERISK		55
#define PH_KEY_LEFTALT		56
#define PH_KEY_SPACE		57
#define PH_KEY_CAPSLOCK		58
#define PH_KEY_F1			59
#define PH_KEY_F2			60
#define PH_KEY_F3			61
#define PH_KEY_F4			62
#define PH_KEY_F5			63
#define PH_KEY_F6			64
#define PH_KEY_F7			65
#define PH_KEY_F8			66
#define PH_KEY_F9			67
#define PH_KEY_F10			68
#define PH_KEY_NUMLOCK		69
#define PH_KEY_SCROLLLOCK		70
#define PH_KEY_KP7			71
#define PH_KEY_KP8			72
#define PH_KEY_KP9			73
#define PH_KEY_KPMINUS		74
#define PH_KEY_KP4			75
#define PH_KEY_KP5			76
#define PH_KEY_KP6			77
#define PH_KEY_KPPLUS		78
#define PH_KEY_KP1			79
#define PH_KEY_KP2			80
#define PH_KEY_KP3			81
#define PH_KEY_KP0			82
#define PH_KEY_KPDOT		83

#define PH_KEY_ZENKAKUHANKAKU	85
#define PH_KEY_102ND		86
#define PH_KEY_F11			87
#define PH_KEY_F12			88
#define PH_KEY_RO			89
#define PH_KEY_KATAKANA		90
#define PH_KEY_HIRAGANA		91
#define PH_KEY_HENKAN		92
#define PH_KEY_KATAKANAHIRAGANA	93
#define PH_KEY_MUHENKAN		94
#define PH_KEY_KPJPCOMMA		95
#define PH_KEY_KPENTER		96
#define PH_KEY_RIGHTCTRL		97
#define PH_KEY_KPSLASH		98
#define PH_KEY_SYSRQ		99
#define PH_KEY_RIGHTALT		100
#define PH_KEY_LINEFEED		101
#define PH_KEY_HOME		102
#define PH_KEY_UP			103
#define PH_KEY_PAGEUP		104
#define PH_KEY_LEFT		105
#define PH_KEY_RIGHT		106
#define PH_KEY_END			107
#define PH_KEY_DOWN		108
#define PH_KEY_PAGEDOWN		109
#define PH_KEY_INSERT		110
#define PH_KEY_DELETE		111
#define PH_KEY_MACRO		112
#define PH_KEY_MUTE		113
#define PH_KEY_VOLUMEDOWN		114
#define PH_KEY_VOLUMEUP		115
#define PH_KEY_POWER		116	/* SC System Power Down */
#define PH_KEY_KPEQUAL		117
#define PH_KEY_KPPLUSMINUS		118
#define PH_KEY_PAUSE		119
#define PH_KEY_SCALE		120	/* AL Compiz Scale (Expose) */

#define PH_KEY_KPCOMMA		121
#define PH_KEY_HANGEUL		122
#define PH_KEY_HANGUEL		KEY_HANGEUL
#define PH_KEY_HANJA		123
#define PH_KEY_YEN			124
#define PH_KEY_LEFTMETA		125
#define PH_KEY_RIGHTMETA		126
#define PH_KEY_COMPOSE		127

#define PH_KEY_STOP		128	/* AC Stop */
#define PH_KEY_AGAIN		129
#define PH_KEY_PROPS		130	/* AC Properties */
#define PH_KEY_UNDO		131	/* AC Undo */
#define PH_KEY_FRONT		132
#define PH_KEY_COPY		133	/* AC Copy */
#define PH_KEY_OPEN		134	/* AC Open */
#define PH_KEY_PASTE		135	/* AC Paste */
#define PH_KEY_FIND		136	/* AC Search */
#define PH_KEY_CUT			137	/* AC Cut */
#define PH_KEY_HELP		138	/* AL Integrated Help Center */
#define PH_KEY_MENU		139	/* Menu (show menu) */
#define PH_KEY_CALC		140	/* AL Calculator */
#define PH_KEY_SETUP		141
#define PH_KEY_SLEEP		142	/* SC System Sleep */
#define PH_KEY_WAKEUP		143	/* System Wake Up */
#define PH_KEY_FILE		144	/* AL Local Machine Browser */
#define PH_KEY_SENDFILE		145
#define PH_KEY_DELETEFILE		146
#define PH_KEY_XFER		147
#define PH_KEY_PROG1		148
#define PH_KEY_PROG2		149
#define PH_KEY_WWW			150	/* AL Internet Browser */
#define PH_KEY_MSDOS		151
#define PH_KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
#define PH_KEY_SCREENLOCK		KEY_COFFEE
#define PH_KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
#define PH_KEY_DIRECTION		KEY_ROTATE_DISPLAY
#define PH_KEY_CYCLEWINDOWS	154
#define PH_KEY_MAIL		155
#define PH_KEY_BOOKMARKS		156	/* AC Bookmarks */
#define PH_KEY_COMPUTER		157
#define PH_KEY_BACK		158	/* AC Back */
#define PH_KEY_FORWARD		159	/* AC Forward */
#define PH_KEY_CLOSECD		160
#define PH_KEY_EJECTCD		161
#define PH_KEY_EJECTCLOSECD	162
#define PH_KEY_NEXTSONG		163
#define PH_KEY_PLAYPAUSE		164
#define PH_KEY_PREVIOUSSONG	165
#define PH_KEY_STOPCD		166
#define PH_KEY_RECORD		167
#define PH_KEY_REWIND		168
#define PH_KEY_PHONE		169	/* Media Select Telephone */
#define PH_KEY_ISO			170
#define PH_KEY_CONFIG		171	/* AL Consumer Control Configuration */
#define PH_KEY_HOMEPAGE		172	/* AC Home */
#define PH_KEY_REFRESH		173	/* AC Refresh */
#define PH_KEY_EXIT		174	/* AC Exit */
#define PH_KEY_MOVE		175
#define PH_KEY_EDIT		176
#define PH_KEY_SCROLLUP		177
#define PH_KEY_SCROLLDOWN		178
#define PH_KEY_KPLEFTPAREN		179
#define PH_KEY_KPRIGHTPAREN	180
#define PH_KEY_NEW			181	/* AC New */
#define PH_KEY_REDO		182	/* AC Redo/Repeat */

#define PH_KEY_F13			183
#define PH_KEY_F14			184
#define PH_KEY_F15			185
#define PH_KEY_F16			186
#define PH_KEY_F17			187
#define PH_KEY_F18			188
#define PH_KEY_F19			189
#define PH_KEY_F20			190
#define PH_KEY_F21			191
#define PH_KEY_F22			192
#define PH_KEY_F23			193
#define PH_KEY_F24			194

#define PH_KEY_PLAYCD		200
#define PH_KEY_PAUSECD		201
#define PH_KEY_PROG3		202
#define PH_KEY_PROG4		203
#define PH_KEY_ALL_APPLICATIONS	204	/* AC Desktop Show All Applications */
#define PH_KEY_DASHBOARD		KEY_ALL_APPLICATIONS
#define PH_KEY_SUSPEND		205
#define PH_KEY_CLOSE		206	/* AC Close */
#define PH_KEY_PLAY		207
#define PH_KEY_FASTFORWARD		208
#define PH_KEY_BASSBOOST		209
#define PH_KEY_PRINT		210	/* AC Print */
#define PH_KEY_HP			211
#define PH_KEY_CAMERA		212
#define PH_KEY_SOUND		213
#define PH_KEY_QUESTION		214
#define PH_KEY_EMAIL		215
#define PH_KEY_CHAT		216
#define PH_KEY_SEARCH		217
#define PH_KEY_CONNECT		218
#define PH_KEY_FINANCE		219	/* AL Checkbook/Finance */
#define PH_KEY_SPORT		220
#define PH_KEY_SHOP		221
#define PH_KEY_ALTERASE		222
#define PH_KEY_CANCEL		223	/* AC Cancel */
#define PH_KEY_BRIGHTNESSDOWN	224
#define PH_KEY_BRIGHTNESSUP	225
#define PH_KEY_MEDIA		226

#define PH_KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
					   outputs (Monitor/LCD/TV-out/etc) */
#define PH_KEY_KBDILLUMTOGGLE	228
#define PH_KEY_KBDILLUMDOWN	229
#define PH_KEY_KBDILLUMUP		230

#define PH_KEY_SEND		231	/* AC Send */
#define PH_KEY_REPLY		232	/* AC Reply */
#define PH_KEY_FORWARDMAIL		233	/* AC Forward Msg */
#define PH_KEY_SAVE		234	/* AC Save */
#define PH_KEY_DOCUMENTS		235

#define PH_KEY_BATTERY		236

#define PH_KEY_BLUETOOTH		237
#define PH_KEY_WLAN		238
#define PH_KEY_UWB			239

#define PH_KEY_UNKNOWN		240

#define PH_KEY_VIDEO_NEXT		241	/* drive next video source */
#define PH_KEY_VIDEO_PREV		242	/* drive previous video source */
#define PH_KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
#define PH_KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
					  brightness control is off,
					  rely on ambient */
#define PH_KEY_BRIGHTNESS_ZERO	KEY_BRIGHTNESS_AUTO
#define PH_KEY_DISPLAY_OFF		245	/* display device to off state */

#define PH_KEY_WWAN		246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
#define PH_KEY_WIMAX		KEY_WWAN
#define PH_KEY_RFKILL		247	/* Key that controls all radios */

#define PH_KEY_MICMUTE		248	/* Mute / unmute the microphone */

/* Code 255 is reserved for special needs of AT keyboard driver */

#define BTN_MISC		0x100
#define BTN_0			0x100
#define BTN_1			0x101
#define BTN_2			0x102
#define BTN_3			0x103
#define BTN_4			0x104
#define BTN_5			0x105
#define BTN_6			0x106
#define BTN_7			0x107
#define BTN_8			0x108
#define BTN_9			0x109

#define BTN_MOUSE		0x110
#define BTN_LEFT		0x110
#define BTN_RIGHT		0x111
#define BTN_MIDDLE		0x112
#define BTN_SIDE		0x113
#define BTN_EXTRA		0x114
#define BTN_FORWARD		0x115
#define BTN_BACK		0x116
#define BTN_TASK		0x117

#define BTN_JOYSTICK		0x120
#define BTN_TRIGGER		0x120
#define BTN_THUMB		0x121
#define BTN_THUMB2		0x122
#define BTN_TOP			0x123
#define BTN_TOP2		0x124
#define BTN_PINKIE		0x125
#define BTN_BASE		0x126
#define BTN_BASE2		0x127
#define BTN_BASE3		0x128
#define BTN_BASE4		0x129
#define BTN_BASE5		0x12a
#define BTN_BASE6		0x12b
#define BTN_DEAD		0x12f

#define BTN_GAMEPAD		0x130
#define BTN_SOUTH		0x130
#define BTN_A			BTN_SOUTH
#define BTN_EAST		0x131
#define BTN_B			BTN_EAST
#define BTN_C			0x132
#define BTN_NORTH		0x133
#define BTN_X			BTN_NORTH
#define BTN_WEST		0x134
#define BTN_Y			BTN_WEST
#define BTN_Z			0x135
#define BTN_TL			0x136
#define BTN_TR			0x137
#define BTN_TL2			0x138
#define BTN_TR2			0x139
#define BTN_SELECT		0x13a
#define BTN_START		0x13b
#define BTN_MODE		0x13c
#define BTN_THUMBL		0x13d
#define BTN_THUMBR		0x13e

#define BTN_DIGI		0x140
#define BTN_TOOL_PEN		0x140
#define BTN_TOOL_RUBBER		0x141
#define BTN_TOOL_BRUSH		0x142
#define BTN_TOOL_PENCIL		0x143
#define BTN_TOOL_AIRBRUSH	0x144
#define BTN_TOOL_FINGER		0x145
#define BTN_TOOL_MOUSE		0x146
#define BTN_TOOL_LENS		0x147
#define BTN_TOOL_QUINTTAP	0x148	/* Five fingers on trackpad */
#define BTN_STYLUS3		0x149
#define BTN_TOUCH		0x14a
#define BTN_STYLUS		0x14b
#define BTN_STYLUS2		0x14c
#define BTN_TOOL_DOUBLETAP	0x14d
#define BTN_TOOL_TRIPLETAP	0x14e
#define BTN_TOOL_QUADTAP	0x14f	/* Four fingers on trackpad */

#define BTN_WHEEL		0x150
#define BTN_GEAR_DOWN		0x150
#define BTN_GEAR_UP		0x151

#define PH_KEY_OK			0x160
#define PH_KEY_SELECT		0x161
#define PH_KEY_GOTO		0x162
#define PH_KEY_CLEAR		0x163
#define PH_KEY_POWER2		0x164
#define PH_KEY_OPTION		0x165
#define PH_KEY_INFO		0x166	/* AL OEM Features/Tips/Tutorial */
#define PH_KEY_TIME		0x167
#define PH_KEY_VENDOR		0x168
#define PH_KEY_ARCHIVE		0x169
#define PH_KEY_PROGRAM		0x16a	/* Media Select Program Guide */
#define PH_KEY_CHANNEL		0x16b
#define PH_KEY_FAVORITES		0x16c
#define PH_KEY_EPG			0x16d
#define PH_KEY_PVR			0x16e	/* Media Select Home */
#define PH_KEY_MHP			0x16f
#define PH_KEY_LANGUAGE		0x170
#define PH_KEY_TITLE		0x171
#define PH_KEY_SUBTITLE		0x172
#define PH_KEY_ANGLE		0x173
#define PH_KEY_FULL_SCREEN		0x174	/* AC View Toggle */
#define PH_KEY_ZOOM		KEY_FULL_SCREEN
#define PH_KEY_MODE		0x175
#define PH_KEY_KEYBOARD		0x176
#define PH_KEY_ASPECT_RATIO	0x177	/* HUTRR37: Aspect */
#define PH_KEY_SCREEN		KEY_ASPECT_RATIO
#define PH_KEY_PC			0x178	/* Media Select Computer */
#define PH_KEY_TV			0x179	/* Media Select TV */
#define PH_KEY_TV2			0x17a	/* Media Select Cable */
#define PH_KEY_VCR			0x17b	/* Media Select VCR */
#define PH_KEY_VCR2		0x17c	/* VCR Plus */
#define PH_KEY_SAT			0x17d	/* Media Select Satellite */
#define PH_KEY_SAT2		0x17e
#define PH_KEY_CD			0x17f	/* Media Select CD */
#define PH_KEY_TAPE		0x180	/* Media Select Tape */
#define PH_KEY_RADIO		0x181
#define PH_KEY_TUNER		0x182	/* Media Select Tuner */
#define PH_KEY_PLAYER		0x183
#define PH_KEY_TEXT		0x184
#define PH_KEY_DVD			0x185	/* Media Select DVD */
#define PH_KEY_AUX			0x186
#define PH_KEY_MP3			0x187
#define PH_KEY_AUDIO		0x188	/* AL Audio Browser */
#define PH_KEY_VIDEO		0x189	/* AL Movie Browser */
#define PH_KEY_DIRECTORY		0x18a
#define PH_KEY_LIST		0x18b
#define PH_KEY_MEMO		0x18c	/* Media Select Messages */
#define PH_KEY_CALENDAR		0x18d
#define PH_KEY_RED			0x18e
#define PH_KEY_GREEN		0x18f
#define PH_KEY_YELLOW		0x190
#define PH_KEY_BLUE		0x191
#define PH_KEY_CHANNELUP		0x192	/* Channel Increment */
#define PH_KEY_CHANNELDOWN		0x193	/* Channel Decrement */
#define PH_KEY_FIRST		0x194
#define PH_KEY_LAST		0x195	/* Recall Last */
#define PH_KEY_AB			0x196
#define PH_KEY_NEXT		0x197
#define PH_KEY_RESTART		0x198
#define PH_KEY_SLOW		0x199
#define PH_KEY_SHUFFLE		0x19a
#define PH_KEY_BREAK		0x19b
#define PH_KEY_PREVIOUS		0x19c
#define PH_KEY_DIGITS		0x19d
#define PH_KEY_TEEN		0x19e
#define PH_KEY_TWEN		0x19f
#define PH_KEY_VIDEOPHONE		0x1a0	/* Media Select Video Phone */
#define PH_KEY_GAMES		0x1a1	/* Media Select Games */
#define PH_KEY_ZOOMIN		0x1a2	/* AC Zoom In */
#define PH_KEY_ZOOMOUT		0x1a3	/* AC Zoom Out */
#define PH_KEY_ZOOMRESET		0x1a4	/* AC Zoom */
#define PH_KEY_WORDPROCESSOR	0x1a5	/* AL Word Processor */
#define PH_KEY_EDITOR		0x1a6	/* AL Text Editor */
#define PH_KEY_SPREADSHEET		0x1a7	/* AL Spreadsheet */
#define PH_KEY_GRAPHICSEDITOR	0x1a8	/* AL Graphics Editor */
#define PH_KEY_PRESENTATION	0x1a9	/* AL Presentation App */
#define PH_KEY_DATABASE		0x1aa	/* AL Database App */
#define PH_KEY_NEWS		0x1ab	/* AL Newsreader */
#define PH_KEY_VOICEMAIL		0x1ac	/* AL Voicemail */
#define PH_KEY_ADDRESSBOOK		0x1ad	/* AL Contacts/Address Book */
#define PH_KEY_MESSENGER		0x1ae	/* AL Instant Messaging */
#define PH_KEY_DISPLAYTOGGLE	0x1af	/* Turn display (LCD) on and off */
#define PH_KEY_BRIGHTNESS_TOGGLE	KEY_DISPLAYTOGGLE
#define PH_KEY_SPELLCHECK		0x1b0   /* AL Spell Check */
#define PH_KEY_LOGOFF		0x1b1   /* AL Logoff */

#define PH_KEY_DOLLAR		0x1b2
#define PH_KEY_EURO		0x1b3

#define PH_KEY_FRAMEBACK		0x1b4	/* Consumer - transport controls */
#define PH_KEY_FRAMEFORWARD	0x1b5
#define PH_KEY_CONTEXT_MENU	0x1b6	/* GenDesc - system context menu */
#define PH_KEY_MEDIA_REPEAT	0x1b7	/* Consumer - transport control */
#define PH_KEY_10CHANNELSUP	0x1b8	/* 10 channels up (10+) */
#define PH_KEY_10CHANNELSDOWN	0x1b9	/* 10 channels down (10-) */
#define PH_KEY_IMAGES		0x1ba	/* AL Image Browser */
#define PH_KEY_NOTIFICATION_CENTER	0x1bc	/* Show/hide the notification center */
#define PH_KEY_PICKUP_PHONE	0x1bd	/* Answer incoming call */
#define PH_KEY_HANGUP_PHONE	0x1be	/* Decline incoming call */

#define PH_KEY_DEL_EOL		0x1c0
#define PH_KEY_DEL_EOS		0x1c1
#define PH_KEY_INS_LINE		0x1c2
#define PH_KEY_DEL_LINE		0x1c3

#define PH_KEY_FN			0x1d0
#define PH_KEY_FN_ESC		0x1d1
#define PH_KEY_FN_F1		0x1d2
#define PH_KEY_FN_F2		0x1d3
#define PH_KEY_FN_F3		0x1d4
#define PH_KEY_FN_F4		0x1d5
#define PH_KEY_FN_F5		0x1d6
#define PH_KEY_FN_F6		0x1d7
#define PH_KEY_FN_F7		0x1d8
#define PH_KEY_FN_F8		0x1d9
#define PH_KEY_FN_F9		0x1da
#define PH_KEY_FN_F10		0x1db
#define PH_KEY_FN_F11		0x1dc
#define PH_KEY_FN_F12		0x1dd
#define PH_KEY_FN_1		0x1de
#define PH_KEY_FN_2		0x1df
#define PH_KEY_FN_D		0x1e0
#define PH_KEY_FN_E		0x1e1
#define PH_KEY_FN_F		0x1e2
#define PH_KEY_FN_S		0x1e3
#define PH_KEY_FN_B		0x1e4
#define PH_KEY_FN_RIGHT_SHIFT	0x1e5

#define PH_KEY_BRL_DOT1		0x1f1
#define PH_KEY_BRL_DOT2		0x1f2
#define PH_KEY_BRL_DOT3		0x1f3
#define PH_KEY_BRL_DOT4		0x1f4
#define PH_KEY_BRL_DOT5		0x1f5
#define PH_KEY_BRL_DOT6		0x1f6
#define PH_KEY_BRL_DOT7		0x1f7
#define PH_KEY_BRL_DOT8		0x1f8
#define PH_KEY_BRL_DOT9		0x1f9
#define PH_KEY_BRL_DOT10		0x1fa

#define PH_KEY_NUMERIC_0		0x200	/* used by phones, remote controls, */
#define PH_KEY_NUMERIC_1		0x201	/* and other keypads */
#define PH_KEY_NUMERIC_2		0x202
#define PH_KEY_NUMERIC_3		0x203
#define PH_KEY_NUMERIC_4		0x204
#define PH_KEY_NUMERIC_5		0x205
#define PH_KEY_NUMERIC_6		0x206
#define PH_KEY_NUMERIC_7		0x207
#define PH_KEY_NUMERIC_8		0x208
#define PH_KEY_NUMERIC_9		0x209
#define PH_KEY_NUMERIC_STAR	0x20a
#define PH_KEY_NUMERIC_POUND	0x20b
#define PH_KEY_NUMERIC_A		0x20c	/* Phone key A - HUT Telephony 0xb9 */
#define PH_KEY_NUMERIC_B		0x20d
#define PH_KEY_NUMERIC_C		0x20e
#define PH_KEY_NUMERIC_D		0x20f

#define PH_KEY_CAMERA_FOCUS	0x210
#define PH_KEY_WPS_BUTTON		0x211	/* WiFi Protected Setup key */

#define PH_KEY_TOUCHPAD_TOGGLE	0x212	/* Request switch touchpad on or off */
#define PH_KEY_TOUCHPAD_ON		0x213
#define PH_KEY_TOUCHPAD_OFF	0x214

#define PH_KEY_CAMERA_ZOOMIN	0x215
#define PH_KEY_CAMERA_ZOOMOUT	0x216
#define PH_KEY_CAMERA_UP		0x217
#define PH_KEY_CAMERA_DOWN		0x218
#define PH_KEY_CAMERA_LEFT		0x219
#define PH_KEY_CAMERA_RIGHT	0x21a

#define PH_KEY_ATTENDANT_ON	0x21b
#define PH_KEY_ATTENDANT_OFF	0x21c
#define PH_KEY_ATTENDANT_TOGGLE	0x21d	/* Attendant call on or off */
#define PH_KEY_LIGHTS_TOGGLE	0x21e	/* Reading light on or off */

#define BTN_DPAD_UP		0x220
#define BTN_DPAD_DOWN		0x221
#define BTN_DPAD_LEFT		0x222
#define BTN_DPAD_RIGHT		0x223

#define PH_KEY_ALS_TOGGLE		0x230	/* Ambient light sensor */
#define PH_KEY_ROTATE_LOCK_TOGGLE	0x231	/* Display rotation lock */

#define PH_KEY_BUTTONCONFIG		0x240	/* AL Button Configuration */
#define PH_KEY_TASKMANAGER		0x241	/* AL Task/Project Manager */
#define PH_KEY_JOURNAL		0x242	/* AL Log/Journal/Timecard */
#define PH_KEY_CONTROLPANEL		0x243	/* AL Control Panel */
#define PH_KEY_APPSELECT		0x244	/* AL Select Task/Application */
#define PH_KEY_SCREENSAVER		0x245	/* AL Screen Saver */
#define PH_KEY_VOICECOMMAND		0x246	/* Listening Voice Command */
#define PH_KEY_ASSISTANT		0x247	/* AL Context-aware desktop assistant */
#define PH_KEY_KBD_LAYOUT_NEXT	0x248	/* AC Next Keyboard Layout Select */
#define PH_KEY_EMOJI_PICKER	0x249	/* Show/hide emoji picker (HUTRR101) */
#define PH_KEY_DICTATE		0x24a	/* Start or Stop Voice Dictation Session (HUTRR99) */

#define PH_KEY_BRIGHTNESS_MIN		0x250	/* Set Brightness to Minimum */
#define PH_KEY_BRIGHTNESS_MAX		0x251	/* Set Brightness to Maximum */

#define PH_KEY_KBDINPUTASSIST_PREV		0x260
#define PH_KEY_KBDINPUTASSIST_NEXT		0x261
#define PH_KEY_KBDINPUTASSIST_PREVGROUP		0x262
#define PH_KEY_KBDINPUTASSIST_NEXTGROUP		0x263
#define PH_KEY_KBDINPUTASSIST_ACCEPT		0x264
#define PH_KEY_KBDINPUTASSIST_CANCEL		0x265

/* Diagonal movement keys */
#define PH_KEY_RIGHT_UP			0x266
#define PH_KEY_RIGHT_DOWN			0x267
#define PH_KEY_LEFT_UP			0x268
#define PH_KEY_LEFT_DOWN			0x269

#define PH_KEY_ROOT_MENU			0x26a /* Show Device's Root Menu */
/* Show Top Menu of the Media (e.g. DVD) */
#define PH_KEY_MEDIA_TOP_MENU		0x26b
#define PH_KEY_NUMERIC_11			0x26c
#define PH_KEY_NUMERIC_12			0x26d
/*
 * Toggle Audio Description: refers to an audio service that helps blind and
 * visually impaired consumers understand the action in a program. Note: in
 * some countries this is referred to as "Video Description".
 */
#define PH_KEY_AUDIO_DESC			0x26e
#define PH_KEY_3D_MODE			0x26f
#define PH_KEY_NEXT_FAVORITE		0x270
#define PH_KEY_STOP_RECORD			0x271
#define PH_KEY_PAUSE_RECORD		0x272
#define PH_KEY_VOD				0x273 /* Video on Demand */
#define PH_KEY_UNMUTE			0x274
#define PH_KEY_FASTREVERSE			0x275
#define PH_KEY_SLOWREVERSE			0x276
/*
 * Control a data application associated with the currently viewed channel,
 * e.g. teletext or data broadcast application (MHEG, MHP, HbbTV, etc.)
 */
#define PH_KEY_DATA			0x277
#define PH_KEY_ONSCREEN_KEYBOARD		0x278
/* Electronic privacy screen control */
#define PH_KEY_PRIVACY_SCREEN_TOGGLE	0x279

/* Select an area of screen to be copied */
#define PH_KEY_SELECTIVE_SCREENSHOT	0x27a

/*
 * Some keyboards have keys which do not have a defined meaning, these keys
 * are intended to be programmed / bound to macros by the user. For most
 * keyboards with these macro-keys the key-sequence to inject, or action to
 * take, is all handled by software on the host side. So from the kernel's
 * point of view these are just normal keys.
 *
 * The KEY_MACRO# codes below are intended for such keys, which may be labeled
 * e.g. G1-G18, or S1 - S30. The KEY_MACRO# codes MUST NOT be used for keys
 * where the marking on the key does indicate a defined meaning / purpose.
 *
 * The KEY_MACRO# codes MUST also NOT be used as fallback for when no existing
 * KEY_FOO define matches the marking / purpose. In this case a new KEY_FOO
 * define MUST be added.
 */
#define PH_KEY_MACRO1			0x290
#define PH_KEY_MACRO2			0x291
#define PH_KEY_MACRO3			0x292
#define PH_KEY_MACRO4			0x293
#define PH_KEY_MACRO5			0x294
#define PH_KEY_MACRO6			0x295
#define PH_KEY_MACRO7			0x296
#define PH_KEY_MACRO8			0x297
#define PH_KEY_MACRO9			0x298
#define PH_KEY_MACRO10			0x299
#define PH_KEY_MACRO11			0x29a
#define PH_KEY_MACRO12			0x29b
#define PH_KEY_MACRO13			0x29c
#define PH_KEY_MACRO14			0x29d
#define PH_KEY_MACRO15			0x29e
#define PH_KEY_MACRO16			0x29f
#define PH_KEY_MACRO17			0x2a0
#define PH_KEY_MACRO18			0x2a1
#define PH_KEY_MACRO19			0x2a2
#define PH_KEY_MACRO20			0x2a3
#define PH_KEY_MACRO21			0x2a4
#define PH_KEY_MACRO22			0x2a5
#define PH_KEY_MACRO23			0x2a6
#define PH_KEY_MACRO24			0x2a7
#define PH_KEY_MACRO25			0x2a8
#define PH_KEY_MACRO26			0x2a9
#define PH_KEY_MACRO27			0x2aa
#define PH_KEY_MACRO28			0x2ab
#define PH_KEY_MACRO29			0x2ac
#define PH_KEY_MACRO30			0x2ad

/*
 * Some keyboards with the macro-keys described above have some extra keys
 * for controlling the host-side software responsible for the macro handling:
 * -A macro recording start/stop key. Note that not all keyboards which emit
 *  KEY_MACRO_RECORD_START will also emit KEY_MACRO_RECORD_STOP if
 *  KEY_MACRO_RECORD_STOP is not advertised, then KEY_MACRO_RECORD_START
 *  should be interpreted as a recording start/stop toggle;
 * -Keys for switching between different macro (pre)sets, either a key for
 *  cycling through the configured presets or keys to directly select a preset.
 */
#define PH_KEY_MACRO_RECORD_START		0x2b0
#define PH_KEY_MACRO_RECORD_STOP		0x2b1
#define PH_KEY_MACRO_PRESET_CYCLE		0x2b2
#define PH_KEY_MACRO_PRESET1		0x2b3
#define PH_KEY_MACRO_PRESET2		0x2b4
#define PH_KEY_MACRO_PRESET3		0x2b5

/*
 * Some keyboards have a buildin LCD panel where the contents are controlled
 * by the host. Often these have a number of keys directly below the LCD
 * intended for controlling a menu shown on the LCD. These keys often don't
 * have any labeling so we just name them KEY_KBD_LCD_MENU#
 */
#define PH_KEY_KBD_LCD_MENU1		0x2b8
#define PH_KEY_KBD_LCD_MENU2		0x2b9
#define PH_KEY_KBD_LCD_MENU3		0x2ba
#define PH_KEY_KBD_LCD_MENU4		0x2bb
#define PH_KEY_KBD_LCD_MENU5		0x2bc

#define BTN_TRIGGER_HAPPY		0x2c0
#define BTN_TRIGGER_HAPPY1		0x2c0
#define BTN_TRIGGER_HAPPY2		0x2c1
#define BTN_TRIGGER_HAPPY3		0x2c2
#define BTN_TRIGGER_HAPPY4		0x2c3
#define BTN_TRIGGER_HAPPY5		0x2c4
#define BTN_TRIGGER_HAPPY6		0x2c5
#define BTN_TRIGGER_HAPPY7		0x2c6
#define BTN_TRIGGER_HAPPY8		0x2c7
#define BTN_TRIGGER_HAPPY9		0x2c8
#define BTN_TRIGGER_HAPPY10		0x2c9
#define BTN_TRIGGER_HAPPY11		0x2ca
#define BTN_TRIGGER_HAPPY12		0x2cb
#define BTN_TRIGGER_HAPPY13		0x2cc
#define BTN_TRIGGER_HAPPY14		0x2cd
#define BTN_TRIGGER_HAPPY15		0x2ce
#define BTN_TRIGGER_HAPPY16		0x2cf
#define BTN_TRIGGER_HAPPY17		0x2d0
#define BTN_TRIGGER_HAPPY18		0x2d1
#define BTN_TRIGGER_HAPPY19		0x2d2
#define BTN_TRIGGER_HAPPY20		0x2d3
#define BTN_TRIGGER_HAPPY21		0x2d4
#define BTN_TRIGGER_HAPPY22		0x2d5
#define BTN_TRIGGER_HAPPY23		0x2d6
#define BTN_TRIGGER_HAPPY24		0x2d7
#define BTN_TRIGGER_HAPPY25		0x2d8
#define BTN_TRIGGER_HAPPY26		0x2d9
#define BTN_TRIGGER_HAPPY27		0x2da
#define BTN_TRIGGER_HAPPY28		0x2db
#define BTN_TRIGGER_HAPPY29		0x2dc
#define BTN_TRIGGER_HAPPY30		0x2dd
#define BTN_TRIGGER_HAPPY31		0x2de
#define BTN_TRIGGER_HAPPY32		0x2df
#define BTN_TRIGGER_HAPPY33		0x2e0
#define BTN_TRIGGER_HAPPY34		0x2e1
#define BTN_TRIGGER_HAPPY35		0x2e2
#define BTN_TRIGGER_HAPPY36		0x2e3
#define BTN_TRIGGER_HAPPY37		0x2e4
#define BTN_TRIGGER_HAPPY38		0x2e5
#define BTN_TRIGGER_HAPPY39		0x2e6
#define BTN_TRIGGER_HAPPY40		0x2e7

/* We avoid low common keys in module aliases so they don't get huge. */
#define PH_KEY_MIN_INTERESTING	KEY_MUTE
#define PH_KEY_MAX			0x2ff
#define PH_KEY_CNT			(KEY_MAX+1)

/*
 * Relative axes
 */

#define REL_X			0x00
#define REL_Y			0x01
#define REL_Z			0x02
#define REL_RX			0x03
#define REL_RY			0x04
#define REL_RZ			0x05
#define REL_HWHEEL		0x06
#define REL_DIAL		0x07
#define REL_WHEEL		0x08
#define REL_MISC		0x09
/*
 * 0x0a is reserved and should not be used in input drivers.
 * It was used by HID as REL_MISC+1 and userspace needs to detect if
 * the next REL_* event is correct or is just REL_MISC + n.
 * We define here REL_RESERVED so userspace can rely on it and detect
 * the situation described above.
 */
#define REL_RESERVED		0x0a
#define REL_WHEEL_HI_RES	0x0b
#define REL_HWHEEL_HI_RES	0x0c
#define REL_MAX			0x0f
#define REL_CNT			(REL_MAX+1)

/*
 * Absolute axes
 */

#define ABS_X			0x00
#define ABS_Y			0x01
#define ABS_Z			0x02
#define ABS_RX			0x03
#define ABS_RY			0x04
#define ABS_RZ			0x05
#define ABS_THROTTLE		0x06
#define ABS_RUDDER		0x07
#define ABS_WHEEL		0x08
#define ABS_GAS			0x09
#define ABS_BRAKE		0x0a
#define ABS_HAT0X		0x10
#define ABS_HAT0Y		0x11
#define ABS_HAT1X		0x12
#define ABS_HAT1Y		0x13
#define ABS_HAT2X		0x14
#define ABS_HAT2Y		0x15
#define ABS_HAT3X		0x16
#define ABS_HAT3Y		0x17
#define ABS_PRESSURE		0x18
#define ABS_DISTANCE		0x19
#define ABS_TILT_X		0x1a
#define ABS_TILT_Y		0x1b
#define ABS_TOOL_WIDTH		0x1c

#define ABS_VOLUME		0x20

#define ABS_MISC		0x28

/*
 * 0x2e is reserved and should not be used in input drivers.
 * It was used by HID as ABS_MISC+6 and userspace needs to detect if
 * the next ABS_* event is correct or is just ABS_MISC + n.
 * We define here ABS_RESERVED so userspace can rely on it and detect
 * the situation described above.
 */
#define ABS_RESERVED		0x2e

#define ABS_MT_SLOT		0x2f	/* MT slot being modified */
#define ABS_MT_TOUCH_MAJOR	0x30	/* Major axis of touching ellipse */
#define ABS_MT_TOUCH_MINOR	0x31	/* Minor axis (omit if circular) */
#define ABS_MT_WIDTH_MAJOR	0x32	/* Major axis of approaching ellipse */
#define ABS_MT_WIDTH_MINOR	0x33	/* Minor axis (omit if circular) */
#define ABS_MT_ORIENTATION	0x34	/* Ellipse orientation */
#define ABS_MT_POSITION_X	0x35	/* Center X touch position */
#define ABS_MT_POSITION_Y	0x36	/* Center Y touch position */
#define ABS_MT_TOOL_TYPE	0x37	/* Type of touching device */
#define ABS_MT_BLOB_ID		0x38	/* Group a set of packets as a blob */
#define ABS_MT_TRACKING_ID	0x39	/* Unique ID of initiated contact */
#define ABS_MT_PRESSURE		0x3a	/* Pressure on contact area */
#define ABS_MT_DISTANCE		0x3b	/* Contact hover distance */
#define ABS_MT_TOOL_X		0x3c	/* Center X tool position */
#define ABS_MT_TOOL_Y		0x3d	/* Center Y tool position */


#define ABS_MAX			0x3f
#define ABS_CNT			(ABS_MAX+1)

/*
 * Switch events
 */

#define SW_LID			0x00  /* set = lid shut */
#define SW_TABLET_MODE		0x01  /* set = tablet mode */
#define SW_HEADPHONE_INSERT	0x02  /* set = inserted */
#define SW_RFKILL_ALL		0x03  /* rfkill master switch, type "any"
					 set = radio enabled */
#define SW_RADIO		SW_RFKILL_ALL	/* deprecated */
#define SW_MICROPHONE_INSERT	0x04  /* set = inserted */
#define SW_DOCK			0x05  /* set = plugged into dock */
#define SW_LINEOUT_INSERT	0x06  /* set = inserted */
#define SW_JACK_PHYSICAL_INSERT 0x07  /* set = mechanical switch set */
#define SW_VIDEOOUT_INSERT	0x08  /* set = inserted */
#define SW_CAMERA_LENS_COVER	0x09  /* set = lens covered */
#define SW_KEYPAD_SLIDE		0x0a  /* set = keypad slide out */
#define SW_FRONT_PROXIMITY	0x0b  /* set = front proximity sensor active */
#define SW_ROTATE_LOCK		0x0c  /* set = rotate locked/disabled */
#define SW_LINEIN_INSERT	0x0d  /* set = inserted */
#define SW_MUTE_DEVICE		0x0e  /* set = device disabled */
#define SW_PEN_INSERTED		0x0f  /* set = pen inserted */
#define SW_MACHINE_COVER	0x10  /* set = cover closed */
#define SW_MAX			0x10
#define SW_CNT			(SW_MAX+1)

/*
 * Misc events
 */

#define MSC_SERIAL		0x00
#define MSC_PULSELED		0x01
#define MSC_GESTURE		0x02
#define MSC_RAW			0x03
#define MSC_SCAN		0x04
#define MSC_TIMESTAMP		0x05
#define MSC_MAX			0x07
#define MSC_CNT			(MSC_MAX+1)

/*
 * LEDs
 */

#define LED_NUML		0x00
#define LED_CAPSL		0x01
#define LED_SCROLLL		0x02
#define LED_COMPOSE		0x03
#define LED_KANA		0x04
#define LED_SLEEP		0x05
#define LED_SUSPEND		0x06
#define LED_MUTE		0x07
#define LED_MISC		0x08
#define LED_MAIL		0x09
#define LED_CHARGING		0x0a
#define LED_MAX			0x0f
#define LED_CNT			(LED_MAX+1)

/*
 * Autorepeat values
 */

#define REP_DELAY		0x00
#define REP_PERIOD		0x01
#define REP_MAX			0x01
#define REP_CNT			(REP_MAX+1)

/*
 * Sounds
 */

#define SND_CLICK		0x00
#define SND_BELL		0x01
#define SND_TONE		0x02
#define SND_MAX			0x07
#define SND_CNT			(SND_MAX+1)

#endif
