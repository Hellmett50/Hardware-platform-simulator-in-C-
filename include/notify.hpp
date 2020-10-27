#ifndef _NOTIFY_
#define _NOTIFY_

//----------RETURN MACRO---------------------
#define FILE_OPEN_SUCCESS 0
#define FILE_OPEN_FAILURE 1
#define FILE_CLOSE_SUCCESS 0
#define FILE_CLOSE_FAILURE 1
#define LOADING_SUCCESS 0
#define	LOADING_FAILURE 1

//----------COLORS AND NOTIFICATIONS-----------------
#define FOR_ERRORS      0x00
#define FOR_WARNINGS    0x01
#define FOR_INFOS       0x02

#define OFF       0x00
#define BOLD      0x01
#define BLINK     0x05

#define BLACK       30
#define RED         31
#define GREEN       32
#define YELLOW      33
#define BLUE        34
#define MAGENTA     35
#define CYAN        36
#define WHITE       37

#define STYLE_ERROR       BLINK
#define STYLE_WARNING     BOLD
#define STYLE_INFO        BOLD

#define COLOR_ERROR       RED
#define COLOR_WARNING     YELLOW
#define COLOR_INFO        GREEN

#define STYLE(purpose)\
  (purpose == FOR_ERRORS ? STYLE_ERROR :\
   (purpose == FOR_WARNINGS ? STYLE_WARNING : STYLE_INFO ))

#define COLOR(purpose)\
  (purpose == FOR_ERRORS ? COLOR_ERROR :\
   (purpose == FOR_WARNINGS ? COLOR_WARNING : COLOR_INFO ))

#define RESET_COLORS(on_stream)\
  fprintf( on_stream, "%c[%dm", 0x1B, 0 )

#define SET_COLORS(purpose, on_stream)\
  fprintf( on_stream, "%c[%d;%dm", 0x1B, STYLE(purpose), COLOR(purpose) )

#define WARNING_MSG(type, msg) do {\
    fprintf( stderr, "%c[%d;%dm", 0x1B, STYLE_WARNING, BLUE );\
    fprintf( stderr, "[WARNING::<%s>] ", type );\
    SET_COLORS(FOR_WARNINGS, stderr);\
    fprintf( stderr, "%s%s", msg, ".\n");\
    RESET_COLORS(stderr);\
} while(0)

#define ERROR_MSG(type, msg) do {\
    fprintf( stderr, "%c[%d;%dm", 0x1B, BOLD, COLOR_ERROR );\
    fprintf( stderr, "[ERROR::<%s>] ", type );\
    SET_COLORS(FOR_ERRORS, stderr);\
    fprintf( stderr, "%s%s", msg, ".\n");\
    RESET_COLORS(stderr);\
} while(0)


#endif
