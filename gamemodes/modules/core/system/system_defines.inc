//#define function:%0(%1) forward %0(%1); public %0(%1)
#define    function:%0(%1)	forward %0(%1); public %0(%1)

#if defined BCRYPT_COST
    #undef BCRYPT_COST
    #define BCRYPT_COST     12
#else
    #define BCRYPT_COST     12
#endif

#if defined MAX_PLAYERS
    #undef MAX_PLAYERS
    #define MAX_PLAYERS     20
#else
    #define MAX_PLAYERS     20
#endif
#define MAX_CHARACTERS      3

#define INVALID_VALUE       -255

//#define isnull(%0) ((!(%0[0])) ? (true) : (false))