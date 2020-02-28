/*************************************************************/
/* LOG-OUT UTILITES                                          */
/*                                                           */
/* (c) Mashkin S.V.                                          */
/*************************************************************/

#ifndef MYLOG_H
#define MYLOG_H

#define MYLOG_ENABLED 0 //0=disable, 1=enable debugging

#if MYLOG_ENABLED==1

    #define MYLOG_USER(mess...)   \
            do{                   \
              printf("USE: ");    \
              printf(mess);       \
              printf("\n");       \
            }while(0)

    #define MYLOG_ERROR(mess...)  \
            do{                   \
              printf("ERR: ");    \
              printf(mess);       \
              printf("\n");       \
            }while(0)


    #define MYLOG_WARNING(mess...)\
            do{                   \
              printf("WAR: ");    \
              printf(mess);       \
              printf("\n");       \
            }while(0)

    #define MYLOG_DEBUG(mess...)  \
            do{                   \
              printf("DEB: ");    \
              printf(mess);       \
              printf("\n");       \
            }while(0)

    #define MYLOG_MESSAGE(mess...)
    #define MYLOG_GOD(mess...)

    #define MYLOG_TRACE(mess...)  \
            do{                   \
              printf("TRA: ");    \
              printf(mess);       \
              printf("\n");       \
            }while(0)

    #define MYLOG_STATE(mess...)
    #define MYLOG_REALTIME(mess...)

#else

    #define MYLOG_USER(mess...)
    #define MYLOG_ERROR(mess...)
    #define MYLOG_WARNING(mess...)
    #define MYLOG_DEBUG(mess...)
    #define MYLOG_MESSAGE(mess...)
    #define MYLOG_GOD(mess...)
    #define MYLOG_TRACE(mess...)
    #define MYLOG_STATE(mess...)
    #define MYLOG_REALTIME(mess...)

#endif

#endif //MYLOG_H


