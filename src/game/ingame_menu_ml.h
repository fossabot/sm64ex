#ifndef INGAME_MENU_ML_H
#define INGAME_MENU_ML_H

#include "types.h"

#define ASCII_TO_DIALOG(asc)                                       \
    (((asc) >= '0' && (asc) <= '9') ? ((asc) - '0') :              \
     ((asc) >= 'A' && (asc) <= 'Z') ? ((asc) - 'A' + 0x0A) :       \
     ((asc) >= 'a' && (asc) <= 'z') ? ((asc) - 'a' + 0x24) : 0x00)


#define MENU_MTX_PUSH   1
#define MENU_MTX_NOPUSH 2

#define MENU_SCROLL_VERTICAL   1
#define MENU_SCROLL_HORIZONTAL 2

// Japanese File Select uses an unique table
// to print specific Japanese HUD chars
#define HUD_LUT_JPMENU 1
#define HUD_LUT_GLOBAL 2

// For file select JP HUD difference
#ifdef VERSION_JP
#define HUD_LUT_DIFF HUD_LUT_JPMENU
#else
#define HUD_LUT_DIFF HUD_LUT_GLOBAL
#endif

#define RENDER_PAUSE_SCREEN       1
#define RENDER_COURSE_DONE_SCREEN 2


extern s8 gDialogCourseActNum;
extern s8 gHudFlash;

struct DialogEntry
{
 /*0x00*/ u32 unused;
 /*0x04*/ s8 linesPerBox;
 /*0x06*/ s16 leftOffset;
 /*0x08*/ s16 width;
 /*0x0C*/ const u8 *str;
};

// EU only
enum HudSpecialHUDChars {
    HUD_CHAR_A_UMLAUT = 0x3A,
    HUD_CHAR_O_UMLAUT = 0x3B,
    HUD_CHAR_U_UMLAUT = 0x3C
};

enum SpecialFontChars {
    GLOBAL_CHAR_SPACE = 0x9E,
    GLOBAR_CHAR_TERMINATOR = 0xFF
};

// definitions for some of the special characters defined in charmap_ml.txt
enum DialogSpecialChars {
    DIALOG_CHAR_LOWER_A_GRAVE = 0x68,      // 'a' grave
    DIALOG_CHAR_LOWER_A_CIRCUMFLEX = 0x69, // 'a' circumflex
    DIALOG_CHAR_LOWER_A_UMLAUT = 0x6A,     // 'a' umlaut
    DIALOG_CHAR_LOWER_A_ACUTE = 0x6B,      // 'a' acute
    DIALOG_CHAR_UPPER_A_GRAVE = 0x6C,      // 'A' grave
    DIALOG_CHAR_UPPER_A_CIRCUMFLEX = 0x6D, // 'A' circumflex
    DIALOG_CHAR_UPPER_A_UMLAUT = 0x6E,     // 'A' umlaut
    DIALOG_CHAR_UPPER_A_ACUTE = 0x6F,      // 'A' acute
    DIALOG_CHAR_LOWER_E_GRAVE = 0x70,      // 'e' grave
    DIALOG_CHAR_LOWER_E_CIRCUMFLEX = 0x71, // 'e' circumflex
    DIALOG_CHAR_LOWER_E_UMLAUT = 0x72,     // 'e' umlaut
    DIALOG_CHAR_LOWER_E_ACUTE = 0x73,      // 'e' acute
    DIALOG_CHAR_UPPER_E_GRAVE = 0x74,      // 'E' grave
    DIALOG_CHAR_UPPER_E_CIRCUMFLEX = 0x75, // 'E' circumflex
    DIALOG_CHAR_UPPER_E_UMLAUT = 0x76,     // 'E' umlaut
    DIALOG_CHAR_UPPER_E_ACUTE = 0x77,      // 'E' acute
    DIALOG_CHAR_LOWER_U_GRAVE = 0x78,      // 'u' grave
    DIALOG_CHAR_LOWER_U_CIRCUMFLEX = 0x79, // 'u' circumflex
    DIALOG_CHAR_LOWER_U_UMLAUT = 0x7A,     // 'u' umlaut
    DIALOG_CHAR_LOWER_U_ACUTE = 0x7B,      // 'u' acute
    DIALOG_CHAR_UPPER_U_GRAVE = 0x7C,      // 'U' grave
    DIALOG_CHAR_UPPER_U_CIRCUMFLEX = 0x7D, // 'U' circumflex
    DIALOG_CHAR_UPPER_U_UMLAUT = 0x7E,     // 'U' umlaut
    DIALOG_CHAR_UPPER_U_ACUTE = 0x7F,      // 'U' acute
    DIALOG_CHAR_LOWER_O_GRAVE = 0x80,      // 'o' grave
    DIALOG_CHAR_LOWER_O_CIRCUMFLEX = 0x81, // 'o' circumflex
    DIALOG_CHAR_LOWER_O_UMLAUT = 0x82,     // 'o' umlaut
    DIALOG_CHAR_LOWER_O_ACUTE = 0x83,      // 'o' acute
    DIALOG_CHAR_UPPER_O_GRAVE = 0x84,      // 'O' grave
    DIALOG_CHAR_UPPER_O_CIRCUMFLEX = 0x85, // 'O' circumflex
    DIALOG_CHAR_UPPER_O_UMLAUT = 0x86,     // 'O' umlaut
    DIALOG_CHAR_UPPER_O_ACUTE = 0x87,      // 'O' acute
    DIALOG_CHAR_LOWER_I_GRAVE = 0x88,      // 'i' grave
    DIALOG_CHAR_LOWER_I_CIRCUMFLEX = 0x89, // 'i' circumflex
    DIALOG_CHAR_LOWER_I_UMLAUT = 0x8A,     // 'i' umlaut
    DIALOG_CHAR_LOWER_I_ACUTE = 0x8B,      // 'i' acute
    DIALOG_CHAR_UPPER_I_GRAVE = 0x8C,      // 'I' grave
    DIALOG_CHAR_UPPER_I_CIRCUMFLEX = 0x8D, // 'I' circumflex
    DIALOG_CHAR_UPPER_I_UMLAUT = 0x8E,     // 'I' umlaut
    DIALOG_CHAR_UPPER_I_ACUTE = 0x8F,      // 'I' acute
    DIALOG_CHAR_LOWER_N_TILDE = 0x90,      // 'n' with tilde
    DIALOG_CHAR_UPPER_N_TILDE = 0x91,      // 'N' with tilde
    DIALOG_CHAR_UPSIDE_DOWN_EXCLAMATION_MARK = 0x92, // ¡
    DIALOG_CHAR_UPSIDE_DOWN_QUESTION_MARK = 0x93, // ¿
    DIALOG_CHAR_I_NO_DIA = 0x2C,           // 'i' without diacritic
    DIALOG_CHAR_DOUBLE_LOW_QUOTE = 0x97,   // German opening quotation mark
    DIALOG_CHAR_SLASH = 0x65,
    DIALOG_CHAR_MULTI_THE = 0x66, // 'the'
    DIALOG_CHAR_MULTI_YOU = 0x67, // 'you'
    DIALOG_CHAR_PERIOD = 0x3F,
    DIALOG_CHAR_COMMA = 0x5A,
    DIALOG_CHAR_SPACE = 0x40,
    DIALOG_CHAR_STAR_COUNT = 0x42, // number of stars
    DIALOG_CHAR_UMLAUT = 0xE9,
    DIALOG_CHAR_DAKUTEN = 0x4A,
    DIALOG_CHAR_PERIOD_OR_HANDAKUTEN = 0x4B,
    DIALOG_CHAR_STAR_FILLED = 0x54,
    DIALOG_CHAR_STAR_OPEN = 0x57,
    DIALOG_CHAR_NEWLINE = 0xFE,
    DIALOG_CHAR_TERMINATOR = 0xFF
};

extern s32 gDialogResponse;
extern u16 gDialogColorFadeTimer;
extern s8 gLastDialogLineNum;
extern s32 gDialogVariable;
extern u16 gDialogTextAlpha;
extern s16 gCutsceneMsgXOffset;
extern s16 gCutsceneMsgYOffset;
extern s8 gRedCoinsCollected;

extern void create_dl_identity_matrix(void);
extern void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z);
extern void create_dl_ortho_matrix(void);
extern void print_generic_string(s16 x, s16 y, const u8 *str);
extern void print_hud_lut_string(s8 fontLut, s16 x, s16 y, const u8 *str);
extern void print_menu_generic_string(s16 x, s16 y, const u8 *str);
extern void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex);
#if defined(VERSION_US) || defined(VERSION_EU)
extern s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, f32 scale);
#endif
#if defined(VERSION_JP) || defined(VERSION_EU)
#ifdef VERSION_JP
// remap JP get_str_x_pos_from_center() calls to get_str_x_pos_from_center_scale()
#define get_str_x_pos_from_center get_str_x_pos_from_center_scale
#endif
extern s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale);
#endif
extern void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileNum, s8 courseNum, s16 x, s16 y);
extern void int_to_str(s32 num, u8 *dst);
extern s16 get_dialog_id(void);
extern void create_dialog_box(s16 dialog);
extern void create_dialog_box_with_var(s16 dialog, s32 dialogVar);
extern void create_dialog_inverted_box(s16 dialog);
extern void create_dialog_box_with_response(s16 dialog);
extern void reset_dialog_render_state(void);
extern void set_menu_mode(s16 mode);
extern void reset_cutscene_msg_fade(void);
extern void dl_rgba16_begin_cutscene_msg_fade(void);
extern void dl_rgba16_stop_cutscene_msg_fade(void);
extern void print_credits_str_ascii(s16 x, s16 y, const char *str);
extern void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration);
extern void do_cutscene_handler(void);
extern void render_hud_cannon_reticle(void);
extern void reset_red_coins_collected(void);
extern s16 render_menus_and_dialogs(void);

#endif /* INGAME_MENU_H */
