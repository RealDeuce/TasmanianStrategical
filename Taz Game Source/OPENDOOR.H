/*          ษออออออออออออออออออออออออออออออออออออออออออออออออออออป
 *          บ   ฺฤฤฤฤฤฟ                                          บ
 *          บ   ณ     ณฺฤฤฤฤฟฺฤฤฤฟฺฤฤฟ                           บ
 *          บ   ณ     ณณ    ณรฤฤฤูณ  ณ                           บ
 *          บ   ภฤฤฤฤฤูรฤฤฤฤูภฤฤฤ ณ  รฤฤฤฤฟ                      บ
 *          บ          ณ             ณ    ณฺฤฤฤฟฺฤฤฤฟฺฤฤฤ ฺฤฤ    บ
 *          บ                        ณ    ณณ   ณณ   ณณ    ภฤฤฟ   บ
 *          บ                        ภฤฤฤฤูภฤฤฤูภฤฤฤูณ     ฤฤู   บ
 *          บ                    ฤฤฤฤฤฤฤฤฤฤฤฤ                    บ
 *          บ      Door Programming Toolkit - Version 4.00       บ
 *          ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ
 *       (C) Copyright 1991, 1992 by Brian Pirie. All Rights Reserved.
 */


#ifndef OPENDOOR_H                              /* Only parse OPENDOOR.H once */
#define OPENDOOR_H



                                              /* OPENDOORS GLOBAL DEFINITIONS */
                                              /* ---------------------------- */

#ifdef __cplusplus                 /* Compiler-dependant function definitions */
#define FUNCDEF extern "C"
#else
#define FUNCDEF
#endif



extern char od_registered_to[36];            /* Program information variables */
extern unsigned long od_registration_key;
extern char od_program_name[40];



#define FALSE 0                               /* Boolean constant definitions */
#define TRUE !FALSE
#define MAYBE 2



extern char default_path[60];                 /* Default search path variable */



                                /* OPENDOORS DOORDRIVER FUNCTIONS DEFINITIONS */
                                /* ------------------------------------------ */

FUNCDEF int          od_carrier(void);    /* OpenDoors door driver functions */
FUNCDEF void         od_clear_keybuffer(void);
FUNCDEF void         od_clr_line(void);
FUNCDEF void         od_clr_scr(void);
FUNCDEF void         od_disp(char *buffer, int size, char local_echo);
FUNCDEF void         od_disp_str(char *string);
FUNCDEF int          od_draw_box(char left, char top, char right, char bottom);
FUNCDEF unsigned int od_edit_str(char *input_string, char *format_string,
                                 int row, int col, unsigned char normal_colour,
                                 unsigned char highlight_colour,
                                 char character, unsigned int flags);
FUNCDEF void         od_emulate(register char in_char);
FUNCDEF void         od_exit(int errorlevel, char term_call);
FUNCDEF int          od_get_key(int wait);
FUNCDEF void         od_init(void);
FUNCDEF void         od_input_str(char *string, int max_len,
                                  unsigned char minchar, unsigned char maxchar);
FUNCDEF void         od_kernal(void);
FUNCDEF int          od_list_files(char *directory);
FUNCDEF void         od_page(void);
FUNCDEF void         od_printf(char *format, ...);
FUNCDEF void         od_putch(int character);
FUNCDEF void         od_repeat(char value, unsigned char times);
FUNCDEF int          od_send_file(char *filename);
FUNCDEF void         od_set_attrib(int colour);
#define              od_set_colour(x, y) od_set_attrib(x|(y<<4))
FUNCDEF void         od_set_cursor(int row, int col);
FUNCDEF void         od_set_statusline(char setting);
FUNCDEF int          od_spawn(char *command_line);




#define EDIT_FLAG_NORMAL          0x0000               /* od_edit_str() flags */
#define EDIT_FLAG_NO_REDRAW       0x0001
#define EDIT_FLAG_FIELD_MODE      0x0002
#define EDIT_FLAG_EDIT_STRING     0x0004
#define EDIT_FLAG_STRICT_INPUT    0x0008
#define EDIT_FLAG_PASSWORD_MODE   0x0010
#define EDIT_FLAG_ALLOW_CANCEL    0x0020
#define EDIT_FLAG_FILL_STRING     0x0040
#define EDIT_FLAG_AUTO_ENTER      0x0080
#define EDIT_FLAG_AUTO_DELETE     0x0100
#define EDIT_FLAG_KEEP_BLANK      0x0200
#define EDIT_FLAG_PERMALITERAL    0x0400



#define EDIT_RETURN_ERROR         0            /* od_edit_str() return values */
#define EDIT_RETURN_CANCEL        1
#define EDIT_RETURN_ACCEPT        2
#define EDIT_RETURN_PREVIOUS      3
#define EDIT_RETURN_NEXT          4



#define STATUS_NORMAL      1                /* OpenDoors status line settings */
#define STATUS_NONE        10
#define STATUS_HELP        9
#define STATUS_USER1       2
#define STATUS_USER2       3
#define STATUS_USER3       5
#define STATUS_USER4       6
#define STATUS_SYSTEM      4



#define D_BLACK    0                          /* OpenDoors colour definitions */
#define D_BLUE     1
#define D_GREEN    2
#define D_CYAN     3
#define D_RED      4
#define D_MAGENTA  5
#define D_BROWN    6
#define D_GREY     7
#define L_BLACK    8
#define L_BLUE     9
#define L_GREEN    10
#define L_CYAN     11
#define L_RED      12
#define L_MAGENTA  13
#define L_YELLOW   14
#define L_WHITE    15
#define B_BLACK    L_BLACK
#define B_BLUE     L_BLUE
#define B_GREEN    L_GREEN
#define B_CYAN     L_CYAN
#define B_RED      L_RED
#define B_MAGENTA  L_MAGENTA
#define B_BROWN    L_YELLOW
#define B_GREY     L_WHITE



                                    /* OPENDOORS DOORDRIVER CONTROL STRUCTURE */
                                    /* -------------------------------------- */

struct _od_control                 /* OpenDoors door driver control structure */
   {
   char          info_path[60];          /* Location of door information file */


   char          port;                                   /* Modem information */
   unsigned int  baud;


   char          system_name[40];                 /* Caller & BBS information */
   char          sysop_name[40];
   long          system_calls;
   char          system_last_caller[36];
   char          timelog_start_date[9];
   int           timelog_busyperhour[24];
   int           timelog_busyperday[7];

   char          user_name[36];
   char          user_location[26];
   char          user_password[16];
   char          user_dataphone[13];
   char          user_homephone[13];
   char          user_lasttime[6];
   char          user_lastdate[9];
   char          user_attribute;
   char          user_flags[4];
   unsigned int  user_net_credit;
   unsigned int  user_pending;
   unsigned int  user_messages;
   unsigned int  user_lastread;
   unsigned int  user_security;
   unsigned int  user_numcalls;
   unsigned int  user_uploads;
   unsigned int  user_downloads;
   unsigned int  user_upk;
   unsigned int  user_downk;
   unsigned int  user_todayk;
   unsigned int  user_time_used;
   unsigned int  user_screen_length;
   char          user_last_pwdchange;
   char          user_attrib2;
   unsigned char user_group;
   unsigned int  user_xi_record;

   char          event_status;
   char          event_starttime[6];
   char          event_errorlevel;
   char          event_days;
   char          event_force;
   char          event_last_run[9];

   char          user_netmailentered;
   char          user_echomailentered;
   char          user_logintime[6];
   char          user_logindate[9];
   int           user_timelimit;
   long          user_loginsec;
   long          user_credit;
   unsigned int  user_num;
   int           user_readthru;
   int           user_numpages;
   int           user_downlimit;
   char          user_timeofcreation[6];
   char          user_logonpassword[16];
   char          user_wantchat;
   char          user_ansi;

   int           user_deducted_time;
   char          user_menustack[50][9];
   char          user_menustackpointer;
   char          user_handle[36];
   char          user_comment[81];
   char          user_firstcall[9];
   char          user_combinedrecord[25];
   char          user_birthday[9];
   char          user_subdate[9];
   unsigned char user_screenwidth;
   unsigned char user_msg_area;
   unsigned char user_file_area;
   unsigned char user_language;
   unsigned char user_date_format;
   char          user_forward_to[36];
   char          user_error_free;
   char          sysop_next;
   char          user_emsi_session;
   char          user_emsi_crtdef[41];
   char          user_emsi_protocols[41];
   char          user_emsi_capabilities[41];
   char          user_emsi_requests[41];
   char          user_emsi_software[41];
   unsigned char user_hold_attr1;
   unsigned char user_hold_attr2;
   unsigned char user_hold_len;

   char          user_reasonforchat[78];
   char          user_callsign[12];
   char          user_sex;
   char          user_avatar;


   char          od_info_type;            /* Door information file statistics */
   char          od_extended_info;
   char          od_ra_info;
   char          od_rbbs_node;


   char          od_okaytopage;                              /* Door settings */
   int           od_pagestartmin;
   int           od_pageendmin;
   char          od_user_keyboard_on;


   char          od_box_chars[6];        /* OpenDoors customization variables */
   char          od_colour_char;
   char          od_clear_on_exit;
   unsigned char od_disable;
   int           od_inactivity;
   int           od_last_hot;
   char          od_list_pause;
   char          od_list_stop;
   char          od_nocopyright;
   char          od_noexit;
   char          od_page_len;
   char          od_status_on;

   void          (*od_before_exit)(void);            /* Custom function hooks */
   void          (*od_cbefore_chat)(void);
   void          (*od_cafter_chat)(void);
   void          (*od_cbefore_shell)(void);
   void          (*od_cafter_shell)(void);


   unsigned int  key_chat;           /* OpenDoors function key customizations */   unsigned int        key_dosshell;
   unsigned int  key_drop2bbs;
   unsigned int  key_hangup;
   unsigned int  key_keyboardoff;
   unsigned int  key_lesstime;
   unsigned int  key_lockout;
   unsigned int  key_moretime;
   unsigned int  key_status[8];
   unsigned int  key_sysopnext;

   char          od_num_keys;                     /* Additional function keys */
   int           od_hot_key[16];


   char *         od_after_chat;           /* OpenDoors prompt customizations */
   char *         od_after_shell;
   char *         od_before_chat;
   char *         od_before_shell;
   char *         od_chat_reason;
   char *         od_continue;
   char *         od_help_text;
   char *         od_help_text2;
   char *         od_inactivity_timeout;
   char *         od_inactivity_warning;
   char *         od_month[12];
   char *         od_no_keyboard;
   char *         od_no_sysop;
   char *         od_no_response;
   char *         od_no_time;
   char *         od_offline;
   char *         od_paging;
   char *         od_press_key;
   char *         od_status_line[15];
   char *         od_sysop_next;
   char *         od_time_left;
   char *         od_time_warning;
   char *         od_want_chat;


   char          od_chat_colour1;          /* OpenDoors colour customizations */
   char          od_chat_colour2;
   char          od_list_comment_col;
   char          od_list_name_col;
   char          od_list_offline_col;
   char          od_list_size_col;
   char          od_list_title_col;
   };

extern struct _od_control od_control;         /* od_control external variable */

#define DORINFO1         0                     /* Door information file types */
#define EXITINFO         1
#define RA1EXITINFO      2
#define CHAINTXT         3
#define SFDOORSDAT       4
#define CALLINFO         5
#define DOORSYS_GAP      6
#define DOORSYS_DRWY     7
#define QBBS275EXITINFO  8

#define DIS_INFOFILE        0x01                    /* Function disable flags */
#define DIS_CARRIERDETECT   0x02
#define DIS_TIMEOUT         0x04

#define ES_DELETED 0                                 /* Event status settings */
#define ES_ENABLED 1
#define ES_DISABLED 2



                                                 /* OLD VERSION COMPATIBILITY */
                                                 /* ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ */

#define key_help                       key_status[6]
#define key_nohelp                     key_status[0]
#define od_chat_color1                 od_chat_colour1
#define od_chat_color2                 od_chat_colour2
#define od_set_color(x, y)             od_set_attrib(x|(y<<4))
#define user_credit                    user_net_credit
#define caller_netmailentered          user_netmailentered
#define caller_echomailentered         user_echomailentered
#define caller_logintime               user_logintime
#define caller_logindate               user_logindate
#define caller_timelimit               user_timelimit
#define caller_loginsec                user_loginsec
#define caller_credit                  user_credit
#define caller_userrecord              user_num
#define caller_readthru                user_readthru
#define caller_numpages                user_numpages
#define caller_downlimit               user_downlimit
#define caller_timeofcreation          user_timeofcreation
#define caller_logonpassword           user_logonpassword
#define caller_wantchat                user_wantchat
#define caller_ansi                    user_ansi
#define ra_deducted_time               user_deducted_time
#define ra_menustack                   user_menustack
#define ra_menustackpointer            user_menustackpointer
#define ra_userhandle                  user_handle
#define ra_comment                     user_comment
#define ra_firstcall                   user_firstcall
#define ra_combinedrecord              user_combinedrecord
#define ra_birthday                    user_birthday
#define ra_subdate                     user_subdate
#define ra_screenwidth                 user_screenwidth
#define ra_msg_area                    user_msg_area
#define ra_file_area                   user_file_area
#define ra_language                    user_language
#define ra_date_format                 user_date_format
#define ra_forward_to                  user_forward_to
#define ra_error_free                  user_error_free
#define ra_sysop_next                  sysop_next
#define ra_emsi_session                user_emsi_session
#define ra_emsi_crtdef                 user_emsi_crtdef
#define ra_emsi_protocols              user_emsi_protocols
#define ra_emsi_capabilities           user_emsi_capabilities
#define ra_emsi_requests               user_emsi_requests
#define ra_emsi_software               user_emsi_software
#define ra_hold_attr1                  user_hold_attr1
#define ra_hold_attr2                  user_hold_attr2
#define ra_hold_len                    user_hold_len
#define caller_usernum                 user_num
#define caller_callsign                user_callsign
#define caller_sex                     user_sex
#define od_avatar                      user_avatar
#define B_YELLOW                       L_YELLOW
#define B_WHITE                        L_WHITE
#endif
