/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include <vector>
    #include <cstdio>
    #include <fstream>
    #include "SymbolTable.h"
    #include "ASTNode.h"

    using namespace std;

    extern int yylex();
    extern int yylineno;
    extern FILE* yyin;
    void yyerror(const char *s);

    SymbolTable* currentScope = nullptr;
    std::vector<std::pair<string, string>> currentParams;
    std::ofstream tableFile("tables.txt");

#line 92 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_VAL = 3,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 4,                  /* FLOAT_VAL  */
  YYSYMBOL_STRING_VAL = 5,                 /* STRING_VAL  */
  YYSYMBOL_BOOL_VAL = 6,                   /* BOOL_VAL  */
  YYSYMBOL_CHAR_VAL = 7,                   /* CHAR_VAL  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_TYPE_INT = 9,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_BOOL = 10,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_CHAR = 11,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_FLOAT = 12,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_STRING = 13,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_VOID = 14,                 /* TYPE_VOID  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 16,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 17,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 18,                 /* PROTECTED  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_MAIN = 31,                      /* MAIN  */
  YYSYMBOL_PRINT = 32,                     /* PRINT  */
  YYSYMBOL_TRUE = 33,                      /* TRUE  */
  YYSYMBOL_FALSE = 34,                     /* FALSE  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_INC = 36,                       /* INC  */
  YYSYMBOL_DEC = 37,                       /* DEC  */
  YYSYMBOL_ADD_ASSIGN = 38,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 39,                /* SUB_ASSIGN  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NEQ = 44,                       /* NEQ  */
  YYSYMBOL_LT = 45,                        /* LT  */
  YYSYMBOL_GT = 46,                        /* GT  */
  YYSYMBOL_LE = 47,                        /* LE  */
  YYSYMBOL_GE = 48,                        /* GE  */
  YYSYMBOL_PLUS = 49,                      /* PLUS  */
  YYSYMBOL_MINUS = 50,                     /* MINUS  */
  YYSYMBOL_MUL = 51,                       /* MUL  */
  YYSYMBOL_DIV = 52,                       /* DIV  */
  YYSYMBOL_MOD = 53,                       /* MOD  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 56,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 57,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 58,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 59,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 60,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 61,                     /* COMMA  */
  YYSYMBOL_DOT = 62,                       /* DOT  */
  YYSYMBOL_COLON = 63,                     /* COLON  */
  YYSYMBOL_TILDE = 64,                     /* TILDE  */
  YYSYMBOL_ARROW = 65,                     /* ARROW  */
  YYSYMBOL_AMPER = 66,                     /* AMPER  */
  YYSYMBOL_DECL = 67,                      /* DECL  */
  YYSYMBOL_AS = 68,                        /* AS  */
  YYSYMBOL_UNLESS = 69,                    /* UNLESS  */
  YYSYMBOL_REPEAT = 70,                    /* REPEAT  */
  YYSYMBOL_SWAP = 71,                      /* SWAP  */
  YYSYMBOL_CHANCE = 72,                    /* CHANCE  */
  YYSYMBOL_POWER = 73,                     /* POWER  */
  YYSYMBOL_REPEAT_STR = 74,                /* REPEAT_STR  */
  YYSYMBOL_RANDOM = 75,                    /* RANDOM  */
  YYSYMBOL_COMP = 76,                      /* COMP  */
  YYSYMBOL_APPROX = 77,                    /* APPROX  */
  YYSYMBOL_LOWER_THAN_ELSE = 78,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_program = 80,                   /* program  */
  YYSYMBOL_81_1 = 81,                      /* $@1  */
  YYSYMBOL_global_decl_list = 82,          /* global_decl_list  */
  YYSYMBOL_global_item = 83,               /* global_item  */
  YYSYMBOL_primitive_type = 84,            /* primitive_type  */
  YYSYMBOL_ptr_list = 85,                  /* ptr_list  */
  YYSYMBOL_var_type = 86,                  /* var_type  */
  YYSYMBOL_return_type = 87,               /* return_type  */
  YYSYMBOL_var_declaration = 88,           /* var_declaration  */
  YYSYMBOL_array_init_list = 89,           /* array_init_list  */
  YYSYMBOL_variable = 90,                  /* variable  */
  YYSYMBOL_complex_variable = 91,          /* complex_variable  */
  YYSYMBOL_semicolon_expression = 92,      /* semicolon_expression  */
  YYSYMBOL_boolean_expression = 93,        /* boolean_expression  */
  YYSYMBOL_non_semicolon_expression = 94,  /* non_semicolon_expression  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_arg_list = 96,                  /* arg_list  */
  YYSYMBOL_args = 97,                      /* args  */
  YYSYMBOL_func_decl = 98,                 /* func_decl  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_100_3 = 100,                    /* $@3  */
  YYSYMBOL_param_list = 101,               /* param_list  */
  YYSYMBOL_param = 102,                    /* param  */
  YYSYMBOL_class_decl = 103,               /* class_decl  */
  YYSYMBOL_104_4 = 104,                    /* $@4  */
  YYSYMBOL_inheritance_spec = 105,         /* inheritance_spec  */
  YYSYMBOL_class_body = 106,               /* class_body  */
  YYSYMBOL_class_member_list = 107,        /* class_member_list  */
  YYSYMBOL_class_member = 108,             /* class_member  */
  YYSYMBOL_access_modifier = 109,          /* access_modifier  */
  YYSYMBOL_constructor_decl = 110,         /* constructor_decl  */
  YYSYMBOL_111_5 = 111,                    /* $@5  */
  YYSYMBOL_112_6 = 112,                    /* $@6  */
  YYSYMBOL_destructor_decl = 113,          /* destructor_decl  */
  YYSYMBOL_main_function = 114,            /* main_function  */
  YYSYMBOL_115_7 = 115,                    /* $@7  */
  YYSYMBOL_statement_list = 116,           /* statement_list  */
  YYSYMBOL_full_statement_list = 117,      /* full_statement_list  */
  YYSYMBOL_statement_or_decl = 118,        /* statement_or_decl  */
  YYSYMBOL_statement = 119,                /* statement  */
  YYSYMBOL_print_statement = 120,          /* print_statement  */
  YYSYMBOL_return_statement = 121,         /* return_statement  */
  YYSYMBOL_break_continue_statement = 122, /* break_continue_statement  */
  YYSYMBOL_block = 123,                    /* block  */
  YYSYMBOL_if_statement = 124,             /* if_statement  */
  YYSYMBOL_switch_statement = 125,         /* switch_statement  */
  YYSYMBOL_case_list = 126,                /* case_list  */
  YYSYMBOL_case_item = 127,                /* case_item  */
  YYSYMBOL_while_statement = 128,          /* while_statement  */
  YYSYMBOL_do_statement = 129,             /* do_statement  */
  YYSYMBOL_for_statement = 130,            /* for_statement  */
  YYSYMBOL_for_init = 131,                 /* for_init  */
  YYSYMBOL_for_cond = 132,                 /* for_cond  */
  YYSYMBOL_for_step = 133                  /* for_step  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    85,   100,   101,   104,   105,   106,   113,
     114,   115,   116,   117,   120,   121,   124,   125,   126,   127,
     130,   131,   132,   140,   150,   169,   178,   206,   222,   227,
     233,   242,   261,   264,   288,   289,   294,   297,   315,   316,
     317,   318,   319,   320,   323,   332,   341,   350,   359,   368,
     377,   386,   395,   404,   405,   408,   409,   418,   427,   436,
     445,   455,   464,   473,   479,   489,   499,   510,   520,   531,
     577,   578,   580,   581,   582,   583,   586,   587,   590,   591,
     594,   600,   613,   618,   612,   635,   636,   637,   640,   649,
     648,   673,   674,   677,   678,   681,   682,   685,   686,   687,
     688,   689,   692,   692,   692,   695,   699,   694,   712,   722,
     721,   756,   764,   770,   775,   784,   789,   790,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   803,   805,   846,
     847,   848,   850,   852,   855,   857,   858,   861,   862,   865,
     877,   878,   881,   884,   885,   887,   892,   898,   901,   904,
     910,   911,   914,   915,   918,   919
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_VAL", "FLOAT_VAL",
  "STRING_VAL", "BOOL_VAL", "CHAR_VAL", "ID", "TYPE_INT", "TYPE_BOOL",
  "TYPE_CHAR", "TYPE_FLOAT", "TYPE_STRING", "TYPE_VOID", "CLASS", "PUBLIC",
  "PRIVATE", "PROTECTED", "CONST", "IF", "SWITCH", "CASE", "DEFAULT",
  "ELSE", "WHILE", "FOR", "DO", "RETURN", "BREAK", "CONTINUE", "MAIN",
  "PRINT", "TRUE", "FALSE", "ASSIGN", "INC", "DEC", "ADD_ASSIGN",
  "SUB_ASSIGN", "AND", "OR", "NOT", "EQ", "NEQ", "LT", "GT", "LE", "GE",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "COLON",
  "TILDE", "ARROW", "AMPER", "DECL", "AS", "UNLESS", "REPEAT", "SWAP",
  "CHANCE", "POWER", "REPEAT_STR", "RANDOM", "COMP", "APPROX",
  "LOWER_THAN_ELSE", "$accept", "program", "$@1", "global_decl_list",
  "global_item", "primitive_type", "ptr_list", "var_type", "return_type",
  "var_declaration", "array_init_list", "variable", "complex_variable",
  "semicolon_expression", "boolean_expression", "non_semicolon_expression",
  "expression", "arg_list", "args", "func_decl", "$@2", "$@3",
  "param_list", "param", "class_decl", "$@4", "inheritance_spec",
  "class_body", "class_member_list", "class_member", "access_modifier",
  "constructor_decl", "$@5", "$@6", "destructor_decl", "main_function",
  "$@7", "statement_list", "full_statement_list", "statement_or_decl",
  "statement", "print_statement", "return_statement",
  "break_continue_statement", "block", "if_statement", "switch_statement",
  "case_list", "case_item", "while_statement", "do_statement",
  "for_statement", "for_init", "for_cond", "for_step", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-219)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-153)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -219,    21,  -219,  -219,    -7,    18,   -38,    -3,  -219,  -219,
    -219,  -219,  -219,   -22,    42,   -31,     9,   109,  -219,    31,
    -219,    98,   205,    48,  -219,  -219,  -219,    96,    63,   205,
      53,    71,   107,  -219,  -219,  -219,  -219,  -219,   107,   -21,
     105,  -219,    27,   141,   175,   -19,  -219,   118,  -219,   136,
     136,   568,  -219,   181,   139,   186,   189,  -219,  -219,   142,
      27,  -219,   137,  -219,  -219,   568,   133,   134,    53,   205,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,    54,    54,
     568,   568,    54,   568,   568,    54,   531,  -219,  -219,  -219,
    -219,   595,  -219,  -219,   149,   160,  -219,  -219,   613,   205,
     197,  -219,   -11,   102,   102,  -219,  -219,   102,   651,  -219,
     102,   568,  -219,  -219,   568,   568,   568,   568,   218,   219,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,  -219,   568,   568,   568,   568,   568,   172,
      53,   183,  -219,  -219,  -219,   107,  -219,   187,   188,  -219,
    -219,   870,   870,   870,   870,   190,   185,   670,  -219,  -219,
      95,   884,   919,   919,   903,   903,   903,   903,    55,    55,
     169,   169,   169,   169,    58,    55,   919,   919,  -219,    41,
     191,   136,  -219,   568,  -219,   568,  -219,   204,   192,  -219,
    -219,    -6,   870,   870,   195,   198,   199,   200,   528,   568,
    -219,  -219,   202,  -219,  -219,  -219,   243,   203,   208,   209,
     211,  -219,   944,   210,  -219,   212,   217,   221,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   259,   313,   222,   568,   568,
     568,   568,    32,   233,   870,   568,   367,   -36,   568,   568,
      54,   568,   568,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,   870,   213,   870,   708,   214,   117,
    -219,   223,   236,   724,  -219,   762,   778,   101,   816,   237,
     421,   528,   238,   528,   568,   568,  -219,   241,   241,    54,
     241,   239,  -219,   235,  -219,  -219,   240,   242,   246,  -219,
    -219,   119,  -219,  -219,   528,    -5,    32,   244,   245,  -219,
     568,   230,  -219,  -219,  -219,   248,  -219,  -219,   832,  -219,
     528,  -219,   475,  -219,   475
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,     0,     0,     0,     4,     6,
       7,     8,     3,    92,     0,     0,     0,     0,    89,     0,
      82,     0,     0,     0,   102,   103,   104,     0,     0,     0,
      87,     0,    18,    10,     9,    12,    11,    13,    16,     0,
       0,    91,    94,     0,     0,     0,    86,     0,    14,    19,
      17,     0,    23,     0,     0,     0,     0,    98,    99,     0,
      93,    96,     0,   100,   101,     0,     0,     0,     0,     0,
      15,    72,    73,    74,    75,    31,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    32,    76,    55,
      77,     0,   109,   105,     0,     0,    95,    97,     0,     0,
       0,    85,     0,    42,    43,    52,    61,    36,     0,    62,
      63,     0,    40,    41,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      87,     0,    90,    27,    88,    21,    20,     0,     0,    25,
      71,    37,    38,    39,    81,     0,    78,     0,    33,    34,
      45,    44,    46,    47,    48,    49,    50,    51,    56,    57,
      58,    59,    60,    66,    67,    65,    68,    64,   113,     0,
       0,    22,    83,    30,    69,     0,    35,     0,     0,   113,
     115,     0,    29,    80,     0,     0,     0,     0,     0,   136,
     137,   138,     0,   113,   110,   126,     0,     0,     0,     0,
       0,   112,     0,     0,   111,     0,     0,     0,   125,   118,
     122,   119,   121,   120,   106,     0,     0,     0,     0,     0,
       0,     0,   151,     0,   135,     0,     0,     0,     0,     0,
       0,     0,    79,   133,   127,   123,   124,   115,   108,    84,
     116,   114,   117,    26,    28,    55,     0,     0,    55,     0,
     150,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,   134,     0,     0,     0,
       0,     0,   107,   140,   144,   147,    77,     0,    55,   130,
     129,     0,   131,   128,     0,     0,   155,     0,     0,   141,
       0,     0,   142,   143,   154,     0,   148,   132,     0,   113,
       0,   113,   146,   149,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,  -219,  -219,  -219,   -32,   -10,  -219,    -4,
    -219,   -75,  -219,  -178,  -218,    24,   -50,    64,  -219,   303,
    -219,  -219,   168,   249,  -219,  -219,  -219,  -219,  -219,   251,
     292,  -219,  -219,  -219,  -219,  -219,  -219,  -187,    65,  -219,
    -173,  -219,  -219,  -219,  -163,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     4,     8,    38,    49,    39,   147,   211,
     191,    86,    87,    88,    89,    90,   256,   155,   156,    58,
      30,   190,    45,    46,    11,    28,    18,    59,    60,    61,
      62,    63,   140,   247,    64,    12,   139,   187,   226,   251,
     214,   215,   216,   217,   218,   219,   220,   295,   303,   221,
     222,   223,   261,   287,   305
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    91,   225,   103,   104,    15,    50,   107,     5,   213,
     110,   255,     6,   258,    51,    98,   236,   300,   301,    43,
     213,     3,    21,    20,   148,   233,    13,    21,    16,    14,
     105,   106,    22,   108,   109,    54,    67,    22,    57,    52,
      75,    17,    68,    24,    25,    26,     6,   213,   213,   149,
      19,   227,   302,   252,   260,   228,    57,   288,   213,   102,
       7,   151,    75,    23,   152,   153,   154,   157,    78,    79,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    82,   173,   174,   175,   176,   177,   144,
     146,    55,   213,   213,    56,   213,   188,   252,   283,    29,
     285,    31,    68,    40,    41,    82,   130,   131,   132,   130,
     131,   132,   212,   181,   289,   290,   213,   292,   304,    42,
      44,   299,   312,   212,   314,    24,    25,    26,   134,   135,
      47,   134,   213,   192,   213,   193,   213,   313,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   234,
     212,   212,   111,   112,   113,   114,   115,   259,    48,   117,
     117,   212,   279,   118,   118,   267,   119,   119,   134,   135,
     136,   137,   138,    53,   298,   117,    65,   117,   254,   118,
     257,   118,   119,    66,   119,   263,    69,    70,   265,   266,
      92,   268,   154,    93,    94,   212,   212,    15,   212,    95,
      97,    99,   100,   141,   291,    32,    33,    34,    35,    36,
      37,   145,    75,    32,    33,    34,    35,    36,    37,   212,
     142,   259,   250,     6,   194,   195,   158,   159,   178,   196,
     197,   198,   199,   200,   201,   212,   202,   212,   180,   212,
      78,    79,   134,   182,   183,   184,   185,   189,   224,   229,
     308,   237,   230,   231,   232,    82,   235,   238,   262,   294,
     203,   204,   239,   240,   205,   241,   250,    75,   271,   273,
     243,   206,   244,   207,   208,   209,   210,   245,     6,   194,
     195,   246,   253,   274,   196,   197,   198,   199,   200,   201,
     275,   202,   281,   309,   284,    78,    79,   203,   286,   293,
    -152,   297,   296,   310,   306,   307,   269,    10,   179,    27,
      82,    96,   270,     0,     0,   203,   248,   101,     0,   205,
       0,    75,     0,     0,     0,     0,   206,     0,   207,   208,
     209,   210,     6,   194,   195,     0,     0,     0,   196,   197,
     198,   199,   200,   201,     0,   202,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,   203,
     249,     0,     0,   205,     0,    75,     0,     0,     0,     0,
     206,     0,   207,   208,   209,   210,     6,   194,   195,     0,
       0,     0,   196,   197,   198,   199,   200,   201,     0,   202,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,   203,   264,     0,     0,   205,     0,    75,
       0,     0,     0,     0,   206,     0,   207,   208,   209,   210,
       6,   194,   195,     0,     0,     0,   196,   197,   198,   199,
     200,   201,     0,   202,     0,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,   203,   282,     0,
       0,   205,     0,    75,     0,     0,     0,     0,   206,     0,
     207,   208,   209,   210,     6,   194,   195,     0,     0,     0,
     196,   197,   198,   199,   200,   201,     0,   202,     0,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,   203,     0,     0,     0,   205,    75,     0,     0,     0,
       0,     0,   206,     0,   207,   208,   209,   210,   194,   195,
       0,     0,     0,   196,   197,   198,   199,   200,   201,     0,
     202,     0,     0,     0,    78,    79,   111,   112,   113,   114,
     115,    71,    72,    73,     0,    74,    75,     0,     0,    82,
       0,     0,     0,     0,   203,   116,     0,     0,   205,   117,
       0,     0,     0,   118,     0,     0,   119,   207,   208,   209,
     210,    76,    77,     0,    78,    79,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,    85,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,     0,     0,   120,   121,   133,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   134,   135,
     136,   137,   138,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,   150,     0,     0,     0,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   134,   135,   136,   137,   138,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   272,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   276,
       0,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,   277,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   278,     0,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   280,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,     0,     0,   134,
     135,   136,   137,   138,     0,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   120,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,  -153,  -153,
    -153,  -153,   128,   129,   130,   131,   132,   134,   135,   136,
     137,   138,  -153,  -153,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,   134,   135,   136,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,  -153,  -153,     0,   242,     0,
       0,     0,   117,     0,     0,     0,   118,     0,     0,   119
};

static const yytype_int16 yycheck[] =
{
       4,    51,   189,    78,    79,     8,    38,    82,    15,   187,
      85,   229,    19,   231,    35,    65,   203,    22,    23,    29,
     198,     0,    58,    54,    35,   198,     8,    58,    31,    67,
      80,    81,    68,    83,    84,     8,    55,    68,    42,    60,
       8,    63,    61,    16,    17,    18,    19,   225,   226,    60,
       8,    57,    57,   226,   232,    61,    60,   275,   236,    69,
      67,   111,     8,    54,   114,   115,   116,   117,    36,    37,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    51,   134,   135,   136,   137,   138,    99,
     100,    64,   270,   271,    67,   273,    55,   270,   271,    68,
     273,     3,    61,    55,     8,    51,    51,    52,    53,    51,
      52,    53,   187,   145,   277,   278,   294,   280,   296,    56,
      67,   294,   309,   198,   311,    16,    17,    18,    73,    74,
      59,    73,   310,   183,   312,   185,   314,   310,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   199,
     225,   226,    35,    36,    37,    38,    39,   232,    51,    58,
      58,   236,    61,    62,    62,   240,    65,    65,    73,    74,
      75,    76,    77,    68,    55,    58,    35,    58,   228,    62,
     230,    62,    65,     8,    65,   235,    68,    51,   238,   239,
       9,   241,   242,    54,     8,   270,   271,     8,   273,    57,
      63,    68,    68,    54,   279,     8,     9,    10,    11,    12,
      13,    14,     8,     8,     9,    10,    11,    12,    13,   294,
      60,   296,   226,    19,    20,    21,     8,     8,    56,    25,
      26,    27,    28,    29,    30,   310,    32,   312,    55,   314,
      36,    37,    73,    56,    56,    55,    61,    56,    56,    54,
     300,     8,    54,    54,    54,    51,    54,    54,    25,    24,
      56,    57,    54,    54,    60,    54,   270,     8,    55,    55,
      60,    67,    60,    69,    70,    71,    72,    60,    19,    20,
      21,    60,    60,    60,    25,    26,    27,    28,    29,    30,
      54,    32,    55,    63,    56,    36,    37,    56,   274,    60,
      60,    55,    60,    55,    60,    60,   242,     4,   140,    17,
      51,    60,   247,    -1,    -1,    56,    57,    68,    -1,    60,
      -1,     8,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    72,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    60,    -1,     8,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    72,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    56,    57,    -1,    -1,    60,    -1,     8,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    72,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    56,    57,    -1,
      -1,    60,    -1,     8,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    72,    19,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,     8,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    35,    36,    37,    38,
      39,     3,     4,     5,    -1,     7,     8,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    56,    54,    -1,    -1,    60,    58,
      -1,    -1,    -1,    62,    -1,    -1,    65,    69,    70,    71,
      72,    33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    40,    41,    60,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    73,    74,
      75,    76,    77,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    73,    74,    75,    76,    77,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    40,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    40,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    73,    74,    75,
      76,    77,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    73,    74,    75,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    54,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,    81,     0,    82,    15,    19,    67,    83,    88,
      98,   103,   114,     8,    67,     8,    31,    63,   105,     8,
      54,    58,    68,    54,    16,    17,    18,   109,   104,    68,
      99,     3,     8,     9,    10,    11,    12,    13,    84,    86,
      55,     8,    56,    86,    67,   101,   102,    59,    51,    85,
      85,    35,    60,    68,     8,    64,    67,    88,    98,   106,
     107,   108,   109,   110,   113,    35,     8,    55,    61,    68,
      51,     3,     4,     5,     7,     8,    33,    34,    36,    37,
      42,    50,    51,    54,    64,    66,    90,    91,    92,    93,
      94,    95,     9,    54,     8,    57,   108,    63,    95,    68,
      68,   102,    86,    90,    90,    95,    95,    90,    95,    95,
      90,    35,    36,    37,    38,    39,    54,    58,    62,    65,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    60,    73,    74,    75,    76,    77,   115,
     111,    54,    60,    60,    86,    14,    86,    87,    35,    60,
      55,    95,    95,    95,    95,    96,    97,    95,     8,     8,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    56,   101,
      55,    85,    56,    56,    55,    61,    59,   116,    55,    56,
     100,    89,    95,    95,    20,    21,    25,    26,    27,    28,
      29,    30,    32,    56,    57,    60,    67,    69,    70,    71,
      72,    88,    90,    92,   119,   120,   121,   122,   123,   124,
     125,   128,   129,   130,    56,   116,   117,    57,    61,    54,
      54,    54,    54,   119,    95,    54,   116,     8,    54,    54,
      54,    54,    54,    60,    60,    60,    60,   112,    57,    57,
      88,   118,   119,    60,    95,    93,    95,    95,    93,    90,
      92,   131,    25,    95,    57,    95,    95,    90,    95,    96,
     117,    55,    55,    55,    60,    54,    55,    55,    55,    61,
      55,    55,    57,   119,    56,   119,    94,   132,    93,   123,
     123,    90,   123,    60,    24,   126,    60,    55,    55,   119,
      22,    23,    57,   127,    92,   133,    60,    60,    95,    63,
      55,    63,   116,   119,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    81,    80,    82,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    99,   100,    98,   101,   101,   101,   102,   104,
     103,   105,   105,   106,   106,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   109,   111,   112,   110,   113,   115,
     114,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   121,   121,   122,   122,   123,
     124,   124,   125,   126,   126,   127,   127,   128,   129,   130,
     131,   131,   132,   132,   133,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     1,     2,     5,     7,     8,    12,     8,     3,     1,
       0,     1,     1,     3,     3,     4,     2,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     0,     0,    12,     3,     1,     0,     4,     0,
       8,     3,     0,     1,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     0,     9,     7,     0,
      10,     2,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     5,     5,
       5,     5,     7,     2,     4,     2,     1,     1,     1,     3,
       5,     7,     7,     2,     0,     4,     3,     5,     7,     9,
       1,     0,     1,     0,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 85 "parser.y"
        { 
            currentScope = new SymbolTable("Global"); 
        }
#line 1578 "parser.tab.cpp"
    break;

  case 3: /* program: $@1 global_decl_list main_function  */
#line 89 "parser.y"
        {
            if(currentScope) 
            {
                currentScope->Print(tableFile);
                delete currentScope; 
                currentScope = nullptr;
            }
            tableFile.close();
        }
#line 1592 "parser.tab.cpp"
    break;

  case 9: /* primitive_type: TYPE_BOOL  */
#line 113 "parser.y"
                             { (yyval.stringVal) = new string("bool"); }
#line 1598 "parser.tab.cpp"
    break;

  case 10: /* primitive_type: TYPE_INT  */
#line 114 "parser.y"
                             { (yyval.stringVal) = new string("int"); }
#line 1604 "parser.tab.cpp"
    break;

  case 11: /* primitive_type: TYPE_FLOAT  */
#line 115 "parser.y"
                             { (yyval.stringVal) = new string("float"); }
#line 1610 "parser.tab.cpp"
    break;

  case 12: /* primitive_type: TYPE_CHAR  */
#line 116 "parser.y"
                             { (yyval.stringVal) = new string("char"); }
#line 1616 "parser.tab.cpp"
    break;

  case 13: /* primitive_type: TYPE_STRING  */
#line 117 "parser.y"
                             { (yyval.stringVal) = new string("string"); }
#line 1622 "parser.tab.cpp"
    break;

  case 14: /* ptr_list: MUL  */
#line 120 "parser.y"
                        { (yyval.stringVal) = new string("*"); }
#line 1628 "parser.tab.cpp"
    break;

  case 15: /* ptr_list: ptr_list MUL  */
#line 121 "parser.y"
                        { (yyval.stringVal) = new string(*(yyvsp[-1].stringVal) + "*"); delete (yyvsp[-1].stringVal); }
#line 1634 "parser.tab.cpp"
    break;

  case 16: /* var_type: primitive_type  */
#line 124 "parser.y"
                           { (yyval.stringVal) = (yyvsp[0].stringVal); }
#line 1640 "parser.tab.cpp"
    break;

  case 17: /* var_type: primitive_type ptr_list  */
#line 125 "parser.y"
                                   { (yyval.stringVal) = new string(*(yyvsp[-1].stringVal) + *(yyvsp[0].stringVal)); delete (yyvsp[-1].stringVal); delete (yyvsp[0].stringVal); }
#line 1646 "parser.tab.cpp"
    break;

  case 18: /* var_type: ID  */
#line 126 "parser.y"
                           { (yyval.stringVal) = (yyvsp[0].stringVal); }
#line 1652 "parser.tab.cpp"
    break;

  case 19: /* var_type: ID ptr_list  */
#line 127 "parser.y"
                           { (yyval.stringVal) = new string(*(yyvsp[-1].stringVal) + *(yyvsp[0].stringVal)); delete (yyvsp[-1].stringVal); delete (yyvsp[0].stringVal); }
#line 1658 "parser.tab.cpp"
    break;

  case 20: /* return_type: var_type  */
#line 130 "parser.y"
                       { (yyval.stringVal) = (yyvsp[0].stringVal); }
#line 1664 "parser.tab.cpp"
    break;

  case 21: /* return_type: TYPE_VOID  */
#line 131 "parser.y"
                              { (yyval.stringVal) = new string("void"); }
#line 1670 "parser.tab.cpp"
    break;

  case 22: /* return_type: TYPE_VOID ptr_list  */
#line 132 "parser.y"
                                 { (yyval.stringVal) = new string("void" + *(yyvsp[0].stringVal)); delete (yyvsp[0].stringVal); }
#line 1676 "parser.tab.cpp"
    break;

  case 23: /* var_declaration: DECL ID AS var_type SEMICOLON  */
#line 141 "parser.y"
                { 
                    if(currentScope->symbols.find(*(yyvsp[-3].stringVal)) != currentScope->symbols.end()) {
                        string msg = "Eroare semantica: Variabila '" + *(yyvsp[-3].stringVal) + "' este deja definita in acest scope.";
                        yyerror(msg.c_str());
                    }
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*(yyvsp[-3].stringVal), *(yyvsp[-1].stringVal), "variable", scopeType));
                    delete (yyvsp[-3].stringVal); delete (yyvsp[-1].stringVal);
                }
#line 1690 "parser.tab.cpp"
    break;

  case 24: /* var_declaration: DECL ID AS var_type ASSIGN expression SEMICOLON  */
#line 151 "parser.y"
                {
                    if(currentScope->symbols.find(*(yyvsp[-5].stringVal)) != currentScope->symbols.end()) {
                        string msg = "Eroare semantica: Variabila '" + *(yyvsp[-5].stringVal) + "' este deja definita in acest scope.";
                        yyerror(msg.c_str());
                    }
                    if(*(yyvsp[-3].stringVal) != (yyvsp[-1].astNode)->nodeType && (yyvsp[-1].astNode)->nodeType != "error") {
                         string msg = "Eroare semantica: Tip incompatibil la initializarea variabilei '" + *(yyvsp[-5].stringVal) + "': asteptat '" + *(yyvsp[-3].stringVal) + "', primit '" + (yyvsp[-1].astNode)->nodeType + "'";
                         yyerror(msg.c_str());
                    }

                    string computedVal = (yyvsp[-1].astNode)->eval(currentScope).toString();
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    SymbolInfo s(*(yyvsp[-5].stringVal), *(yyvsp[-3].stringVal), "variable", scopeType + " initialized", computedVal);
                    s.hasValue = true;
                    currentScope->addSymbol(s);
                    
                    delete (yyvsp[-5].stringVal); delete (yyvsp[-3].stringVal); delete (yyvsp[-1].astNode);
                }
#line 1713 "parser.tab.cpp"
    break;

  case 25: /* var_declaration: DECL ID LBRACKET INT_VAL RBRACKET AS var_type SEMICOLON  */
#line 170 "parser.y"
                {
                    if(currentScope->symbols.find(*(yyvsp[-6].stringVal)) != currentScope->symbols.end()) 
                        yyerror("Redefinire vector.");
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*(yyvsp[-6].stringVal), *(yyvsp[-1].stringVal), "array", scopeType));

                    delete (yyvsp[-6].stringVal); delete (yyvsp[-4].stringVal); delete (yyvsp[-1].stringVal);
                }
#line 1726 "parser.tab.cpp"
    break;

  case 26: /* var_declaration: DECL ID LBRACKET INT_VAL RBRACKET AS var_type ASSIGN LBRACE array_init_list RBRACE SEMICOLON  */
#line 179 "parser.y"
                {
                    if(currentScope->symbols.find(*(yyvsp[-10].stringVal)) != currentScope->symbols.end())
                        yyerror("Redefinire vector.");

                    string declaredType = *(yyvsp[-5].stringVal);
                    if((yyvsp[-2].nodeList))
                    {
                        for(ASTNode* node : *(yyvsp[-2].nodeList))
                        {
                            if(node->nodeType != declaredType && node->nodeType != "error")
                            {
                                string msg = "Eroare semantica: Element de tip '" + node->nodeType + "' intr-un vector de tip '" + declaredType + "'";
                                yyerror(msg.c_str());
                            }
                        }
                    }
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*(yyvsp[-10].stringVal), declaredType, "array", scopeType + " with value"));

                    if((yyvsp[-2].nodeList)) 
                    {
                        for(auto n : *(yyvsp[-2].nodeList))
                            delete n;
                        delete (yyvsp[-2].nodeList);
                    }
                    delete (yyvsp[-10].stringVal); delete (yyvsp[-8].stringVal); delete (yyvsp[-5].stringVal);
                }
#line 1758 "parser.tab.cpp"
    break;

  case 27: /* var_declaration: CONST DECL ID AS var_type ASSIGN expression SEMICOLON  */
#line 207 "parser.y"
                {
                    if(currentScope->symbols.find(*(yyvsp[-5].stringVal)) != currentScope->symbols.end())
                        yyerror("Redefinire constanta.");
                    if(*(yyvsp[-3].stringVal) != (yyvsp[-1].astNode)->nodeType && (yyvsp[-1].astNode)->nodeType != "error")
                        yyerror("Tipuri incompatibile la const.");
                    string computedVal = (yyvsp[-1].astNode)->eval(currentScope).toString();
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    SymbolInfo s(*(yyvsp[-5].stringVal), "const " + *(yyvsp[-3].stringVal), "constant variable", scopeType, computedVal);
                    s.hasValue = true;
                    currentScope->addSymbol(s);

                    delete (yyvsp[-5].stringVal); delete (yyvsp[-3].stringVal); delete (yyvsp[-1].astNode);
                }
#line 1776 "parser.tab.cpp"
    break;

  case 28: /* array_init_list: array_init_list COMMA expression  */
#line 223 "parser.y"
                {
                    (yyval.nodeList)=(yyvsp[-2].nodeList);
                    (yyval.nodeList)->push_back((yyvsp[0].astNode));
                }
#line 1785 "parser.tab.cpp"
    break;

  case 29: /* array_init_list: expression  */
#line 228 "parser.y"
                { 
                    (yyval.nodeList)=new std::vector<ASTNode*>();
                    (yyval.nodeList)->push_back((yyvsp[0].astNode));
                }
#line 1794 "parser.tab.cpp"
    break;

  case 30: /* array_init_list: %empty  */
#line 233 "parser.y"
                {
                    (yyval.nodeList)=new std::vector<ASTNode*>();
                }
#line 1802 "parser.tab.cpp"
    break;

  case 31: /* variable: ID  */
#line 243 "parser.y"
        { 
            SymbolInfo* info = currentScope->lookup(*(yyvsp[0].stringVal));
            string t = "error";
            if(!info) {
                string msg = "Eroare semantica: Variabila '" + *(yyvsp[0].stringVal) + "' nu a fost declarata.";
                yyerror(msg.c_str());
            }
            else
            {
                t = info->type;
                if(t.find("const ") == 0) {
                    t = t.substr(6);
                }
            }
        
            (yyval.astNode)=new IdNode(*(yyvsp[0].stringVal), t);
            delete (yyvsp[0].stringVal);
        }
#line 1825 "parser.tab.cpp"
    break;

  case 32: /* variable: complex_variable  */
#line 261 "parser.y"
                           { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1831 "parser.tab.cpp"
    break;

  case 33: /* complex_variable: variable DOT ID  */
#line 265 "parser.y"
                 { 
                    IdNode* varNode = dynamic_cast<IdNode*>((yyvsp[-2].astNode));
                    string finalType = "error";
                    if (varNode)
                    {
                        SymbolInfo* objSym=currentScope->lookup(varNode->getName());
                        if (objSym)
                        {
                            string memType;
                            if(currentScope->checkClassMember(objSym->type, *(yyvsp[0].stringVal), memType))
                            {
                                finalType = memType;
                            }
                            else
                            {
                                string err = "Eroare semantica: Membrul '" + *(yyvsp[0].stringVal) + "' nu exista in definitia clasei '" + objSym->type + "'";
                                yyerror(err.c_str());
                            }
                        }
                    }
                    (yyval.astNode) = new OtherNode(finalType);
                    delete (yyvsp[-2].astNode); delete (yyvsp[0].stringVal); 
                 }
#line 1859 "parser.tab.cpp"
    break;

  case 34: /* complex_variable: variable ARROW ID  */
#line 288 "parser.y"
                                     { (yyval.astNode) = new OtherNode("ptr_field"); delete (yyvsp[-2].astNode); delete (yyvsp[0].stringVal); }
#line 1865 "parser.tab.cpp"
    break;

  case 35: /* complex_variable: variable LBRACKET expression RBRACKET  */
#line 290 "parser.y"
                 { 
                     (yyval.astNode) = new OtherNode((yyvsp[-3].astNode)->nodeType);
                     delete (yyvsp[-3].astNode); delete (yyvsp[-1].astNode);
                 }
#line 1874 "parser.tab.cpp"
    break;

  case 36: /* complex_variable: MUL variable  */
#line 294 "parser.y"
                                { (yyval.astNode) = new OtherNode("deref"); delete (yyvsp[0].astNode); }
#line 1880 "parser.tab.cpp"
    break;

  case 37: /* semicolon_expression: variable ASSIGN expression  */
#line 298 "parser.y"
                     { 
                        IdNode* id = dynamic_cast<IdNode*>((yyvsp[-2].astNode));
                        if(id)
                        {
                            if(id->nodeType != (yyvsp[0].astNode)->nodeType && id->nodeType != "error" && (yyvsp[0].astNode)->nodeType != "error")
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la atribuirea variabilei '" + id->getName() + "': asteptat '" + id->nodeType + "', primit '" + (yyvsp[0].astNode)->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            (yyval.astNode) = new AssignNode(id->getName(), (yyvsp[0].astNode), id->nodeType);
                        }
                        else
                        {
                            (yyval.astNode)=new OtherNode("complex_assign");
                        }
                        delete (yyvsp[-2].astNode);
                     }
#line 1902 "parser.tab.cpp"
    break;

  case 38: /* semicolon_expression: variable ADD_ASSIGN expression  */
#line 315 "parser.y"
                                                      { (yyval.astNode)=new OtherNode("add_assign"); delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);}
#line 1908 "parser.tab.cpp"
    break;

  case 39: /* semicolon_expression: variable SUB_ASSIGN expression  */
#line 316 "parser.y"
                                                      { (yyval.astNode)=new OtherNode("sub_assign"); delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);}
#line 1914 "parser.tab.cpp"
    break;

  case 40: /* semicolon_expression: variable INC  */
#line 317 "parser.y"
                                    { (yyval.astNode)=new OtherNode("inc_post"); delete (yyvsp[-1].astNode);}
#line 1920 "parser.tab.cpp"
    break;

  case 41: /* semicolon_expression: variable DEC  */
#line 318 "parser.y"
                                    { (yyval.astNode)=new OtherNode("dec_post"); delete (yyvsp[-1].astNode);}
#line 1926 "parser.tab.cpp"
    break;

  case 42: /* semicolon_expression: INC variable  */
#line 319 "parser.y"
                                    { (yyval.astNode)=new OtherNode("inc_pre"); delete (yyvsp[0].astNode); }
#line 1932 "parser.tab.cpp"
    break;

  case 43: /* semicolon_expression: DEC variable  */
#line 320 "parser.y"
                                    { (yyval.astNode)=new OtherNode("dec_pre"); delete (yyvsp[0].astNode); }
#line 1938 "parser.tab.cpp"
    break;

  case 44: /* boolean_expression: expression OR expression  */
#line 324 "parser.y"
                   { 
                        if((yyvsp[-2].astNode)->nodeType != "bool" || (yyvsp[0].astNode)->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'OR' asteapta operanzi 'bool', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "||", "bool");
                   }
#line 1951 "parser.tab.cpp"
    break;

  case 45: /* boolean_expression: expression AND expression  */
#line 333 "parser.y"
                   { 
                        if((yyvsp[-2].astNode)->nodeType != "bool" || (yyvsp[0].astNode)->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'AND' asteapta operanzi 'bool', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "&&", "bool");
                   }
#line 1964 "parser.tab.cpp"
    break;

  case 46: /* boolean_expression: expression EQ expression  */
#line 342 "parser.y"
                   { 
                        if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                        {
                            string msg = "Eroare semantica: Tipuri incompatibile la egalitate: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "==", "bool");
                   }
#line 1977 "parser.tab.cpp"
    break;

  case 47: /* boolean_expression: expression NEQ expression  */
#line 351 "parser.y"
                   { 
                       if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la neegalitate: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "!=", "bool");
                   }
#line 1990 "parser.tab.cpp"
    break;

  case 48: /* boolean_expression: expression LT expression  */
#line 360 "parser.y"
                   { 
                       if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (<): operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "<", "bool");
                   }
#line 2003 "parser.tab.cpp"
    break;

  case 49: /* boolean_expression: expression GT expression  */
#line 369 "parser.y"
                   { 
                       if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (>): operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), ">", "bool");
                   }
#line 2016 "parser.tab.cpp"
    break;

  case 50: /* boolean_expression: expression LE expression  */
#line 378 "parser.y"
                   { 
                       if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (<=): operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "<=", "bool");
                   }
#line 2029 "parser.tab.cpp"
    break;

  case 51: /* boolean_expression: expression GE expression  */
#line 387 "parser.y"
                   { 
                       if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (>=): operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), ">=", "bool");
                   }
#line 2042 "parser.tab.cpp"
    break;

  case 52: /* boolean_expression: NOT expression  */
#line 396 "parser.y"
                   { 
                        if((yyvsp[0].astNode)->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'NOT' se aplica doar expresiilor 'bool', primit '" + (yyvsp[0].astNode)->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        (yyval.astNode)=new UnaryNode((yyvsp[0].astNode), "!", "bool"); 
                   }
#line 2055 "parser.tab.cpp"
    break;

  case 53: /* boolean_expression: TRUE  */
#line 404 "parser.y"
                          { (yyval.astNode)=new LiteralNode("bool", "true"); }
#line 2061 "parser.tab.cpp"
    break;

  case 54: /* boolean_expression: FALSE  */
#line 405 "parser.y"
                           { (yyval.astNode)=new LiteralNode("bool", "false"); }
#line 2067 "parser.tab.cpp"
    break;

  case 55: /* non_semicolon_expression: boolean_expression  */
#line 408 "parser.y"
                                              { (yyval.astNode)=(yyvsp[0].astNode); }
#line 2073 "parser.tab.cpp"
    break;

  case 56: /* non_semicolon_expression: expression PLUS expression  */
#line 410 "parser.y"
                         { 
                            if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la adunare: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "+", (yyvsp[-2].astNode)->nodeType);
                         }
#line 2086 "parser.tab.cpp"
    break;

  case 57: /* non_semicolon_expression: expression MINUS expression  */
#line 419 "parser.y"
                         { 
                            if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la scadere: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "-", (yyvsp[-2].astNode)->nodeType);
                         }
#line 2099 "parser.tab.cpp"
    break;

  case 58: /* non_semicolon_expression: expression MUL expression  */
#line 428 "parser.y"
                         { 
                            if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la inmultire: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "*", (yyvsp[-2].astNode)->nodeType);
                         }
#line 2112 "parser.tab.cpp"
    break;

  case 59: /* non_semicolon_expression: expression DIV expression  */
#line 437 "parser.y"
                         { 
                            if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la impartire: operand stang '" + (yyvsp[-2].astNode)->nodeType + "' vs operand drept '" + (yyvsp[0].astNode)->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "/", (yyvsp[-2].astNode)->nodeType);
                         }
#line 2125 "parser.tab.cpp"
    break;

  case 60: /* non_semicolon_expression: expression MOD expression  */
#line 446 "parser.y"
                         { 
                             if((yyvsp[-2].astNode)->nodeType != "int" || (yyvsp[0].astNode)->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'MOD' necesita operanzi 'int', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                            }
                             (yyval.astNode)=new BinaryNode((yyvsp[-2].astNode), (yyvsp[0].astNode), "%", "int");
                         }
#line 2138 "parser.tab.cpp"
    break;

  case 61: /* non_semicolon_expression: MINUS expression  */
#line 456 "parser.y"
                         { 
                             if((yyvsp[0].astNode)->nodeType != "int" && (yyvsp[0].astNode)->nodeType != "float")
                             {
                                  string msg = "Eroare semantica: Operatorul unar '-' necesita 'int' sau 'float', dar a primit '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             (yyval.astNode)=new UnaryNode((yyvsp[0].astNode), "-", (yyvsp[0].astNode)->nodeType); 
                         }
#line 2151 "parser.tab.cpp"
    break;

  case 62: /* non_semicolon_expression: TILDE expression  */
#line 465 "parser.y"
                         { 
                             if((yyvsp[0].astNode)->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul '~' necesita 'int', dar a primit '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             (yyval.astNode)=new UnaryNode((yyvsp[0].astNode), "~", "int"); 
                         }
#line 2164 "parser.tab.cpp"
    break;

  case 63: /* non_semicolon_expression: AMPER variable  */
#line 474 "parser.y"
                         { 
                             (yyval.astNode)=new OtherNode("address_of"); 
                             delete (yyvsp[0].astNode); 
                         }
#line 2173 "parser.tab.cpp"
    break;

  case 64: /* non_semicolon_expression: expression APPROX expression  */
#line 480 "parser.y"
                         { 
                             if((yyvsp[-2].astNode)->nodeType != "float" || (yyvsp[0].astNode)->nodeType != "float")
                             {
                                  string msg = "Eroare semantica: Operatorul 'APPROX' (~=) necesita operanzi 'float', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);
                             (yyval.astNode)=new OtherNode("bool"); 
                         }
#line 2187 "parser.tab.cpp"
    break;

  case 65: /* non_semicolon_expression: expression RANDOM expression  */
#line 490 "parser.y"
                         { 
                             if((yyvsp[-2].astNode)->nodeType != "int" || (yyvsp[0].astNode)->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'RANDOM' (\?\?) necesita interval 'int', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);
                             (yyval.astNode)=new OtherNode("int"); 
                         }
#line 2201 "parser.tab.cpp"
    break;

  case 66: /* non_semicolon_expression: expression POWER expression  */
#line 500 "parser.y"
                         { 
                             if(((yyvsp[-2].astNode)->nodeType != "int" && (yyvsp[-2].astNode)->nodeType != "float") || ((yyvsp[0].astNode)->nodeType != "int" && (yyvsp[0].astNode)->nodeType != "float"))
                             {
                                  string msg = "Eroare semantica: Operatorul 'POWER' (**) necesita 'int' sau 'float', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             string resType = (yyvsp[-2].astNode)->nodeType;
                             delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);
                             (yyval.astNode)=new OtherNode(resType);
                         }
#line 2216 "parser.tab.cpp"
    break;

  case 67: /* non_semicolon_expression: expression REPEAT_STR expression  */
#line 511 "parser.y"
                         { 
                             if((yyvsp[-2].astNode)->nodeType != "string" || (yyvsp[0].astNode)->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'REPEAT_STR' (##) necesita 'string' si 'int', dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);
                             (yyval.astNode)=new OtherNode("string"); 
                         }
#line 2230 "parser.tab.cpp"
    break;

  case 68: /* non_semicolon_expression: expression COMP expression  */
#line 521 "parser.y"
                         { 
                             if((yyvsp[-2].astNode)->nodeType != (yyvsp[0].astNode)->nodeType)
                             {
                                  string msg = "Eroare semantica: Operatorul 'COMP' (<=>) necesita aceleasi tipuri, dar a primit '" + (yyvsp[-2].astNode)->nodeType + "' si '" + (yyvsp[0].astNode)->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete (yyvsp[-2].astNode); delete (yyvsp[0].astNode);
                             (yyval.astNode)=new OtherNode("int"); 
                         }
#line 2244 "parser.tab.cpp"
    break;

  case 69: /* non_semicolon_expression: variable LPAREN arg_list RPAREN  */
#line 532 "parser.y"
                         { 
                             IdNode* funcId = dynamic_cast<IdNode*>((yyvsp[-3].astNode));
                             string returnType = "error"; 

                             if(funcId)
                             {
                                 SymbolInfo* funcSym=currentScope->lookup(funcId->getName());
                                 if(!funcSym || funcSym->kind != "function")
                                 {
                                     string err = "Eroare semantica: Functia '" + funcId->getName() + "' nu este definita.";
                                     yyerror(err.c_str());
                                 } 
                                 else
                                 {
                                     returnType = funcSym->type;

                                     if(funcSym->parameters.size() != (yyvsp[-1].typeList)->size())
                                     {
                                         string err = "Eroare semantica: Numar incorect de parametri la apelul functiei '" + funcId->getName() + "'. Asteptat: " + to_string(funcSym->parameters.size()) + ", Primit: " + to_string((yyvsp[-1].typeList)->size());
                                         yyerror(err.c_str());
                                     }
                                     else
                                     {
                                         for(size_t i=0;i<funcSym->parameters.size(); ++i)
                                         {
                                             if(funcSym->parameters[i].second != (yyvsp[-1].typeList)->at(i))
                                             {
                                                 string err = "Eroare semantica: Tip incorect la parametrul " + to_string(i+1) + " al functiei '" + funcId->getName() + "': asteptat '" + funcSym->parameters[i].second + "', primit '" + (yyvsp[-1].typeList)->at(i) + "'";
                                                 yyerror(err.c_str());
                                             }
                                         }
                                     }
                                 }
                             }
                             else
                             {
                                 if((yyvsp[-3].astNode)->nodeType != "error") {
                                     returnType = (yyvsp[-3].astNode)->nodeType;
                                 }
                             }

                             delete (yyvsp[-1].typeList);
                             (yyval.astNode)=new OtherNode(returnType);
                             delete (yyvsp[-3].astNode); 
                          }
#line 2294 "parser.tab.cpp"
    break;

  case 70: /* non_semicolon_expression: variable  */
#line 577 "parser.y"
                                    { (yyval.astNode)=(yyvsp[0].astNode); }
#line 2300 "parser.tab.cpp"
    break;

  case 71: /* non_semicolon_expression: LPAREN expression RPAREN  */
#line 578 "parser.y"
                                                    { (yyval.astNode)=(yyvsp[-1].astNode); }
#line 2306 "parser.tab.cpp"
    break;

  case 72: /* non_semicolon_expression: INT_VAL  */
#line 580 "parser.y"
                                      { (yyval.astNode)=new LiteralNode("int", *(yyvsp[0].stringVal)); delete (yyvsp[0].stringVal); }
#line 2312 "parser.tab.cpp"
    break;

  case 73: /* non_semicolon_expression: FLOAT_VAL  */
#line 581 "parser.y"
                                      { (yyval.astNode)=new LiteralNode("float", *(yyvsp[0].stringVal)); delete (yyvsp[0].stringVal); }
#line 2318 "parser.tab.cpp"
    break;

  case 74: /* non_semicolon_expression: STRING_VAL  */
#line 582 "parser.y"
                                      { (yyval.astNode)=new LiteralNode("string", *(yyvsp[0].stringVal)); delete (yyvsp[0].stringVal); }
#line 2324 "parser.tab.cpp"
    break;

  case 75: /* non_semicolon_expression: CHAR_VAL  */
#line 583 "parser.y"
                                      { (yyval.astNode)=new LiteralNode("char", *(yyvsp[0].stringVal)); delete (yyvsp[0].stringVal); }
#line 2330 "parser.tab.cpp"
    break;

  case 76: /* expression: semicolon_expression  */
#line 586 "parser.y"
                                  { (yyval.astNode)=(yyvsp[0].astNode); }
#line 2336 "parser.tab.cpp"
    break;

  case 77: /* expression: non_semicolon_expression  */
#line 587 "parser.y"
                                      { (yyval.astNode)=(yyvsp[0].astNode); }
#line 2342 "parser.tab.cpp"
    break;

  case 78: /* arg_list: args  */
#line 590 "parser.y"
                { (yyval.typeList) = (yyvsp[0].typeList); }
#line 2348 "parser.tab.cpp"
    break;

  case 79: /* arg_list: %empty  */
#line 591 "parser.y"
           { (yyval.typeList) = new vector<string>(); }
#line 2354 "parser.tab.cpp"
    break;

  case 80: /* args: args COMMA expression  */
#line 595 "parser.y"
     { 
        (yyval.typeList) = (yyvsp[-2].typeList); 
        (yyval.typeList)->push_back((yyvsp[0].astNode)->nodeType);
        delete (yyvsp[0].astNode); 
     }
#line 2364 "parser.tab.cpp"
    break;

  case 81: /* args: expression  */
#line 601 "parser.y"
     { 
        (yyval.typeList) = new vector<string>(); 
        (yyval.typeList)->push_back((yyvsp[0].astNode)->nodeType);
        delete (yyvsp[0].astNode); 
     }
#line 2374 "parser.tab.cpp"
    break;

  case 82: /* $@2: %empty  */
#line 613 "parser.y"
          { 
             currentScope=new SymbolTable("function_" + *(yyvsp[-1].stringVal), currentScope);
             currentParams.clear();
          }
#line 2383 "parser.tab.cpp"
    break;

  case 83: /* $@3: %empty  */
#line 618 "parser.y"
          {
             SymbolInfo funcSymbol(*(yyvsp[-7].stringVal), *(yyvsp[-1].stringVal), "function");
             funcSymbol.parameters=currentParams;
             currentScope->parentScope->addSymbol(funcSymbol);
             currentParams.clear();
          }
#line 2394 "parser.tab.cpp"
    break;

  case 84: /* func_decl: DECL ID LPAREN $@2 param_list RPAREN AS return_type LBRACE $@3 full_statement_list RBRACE  */
#line 625 "parser.y"
          {
             currentScope->Print(tableFile);
             SymbolTable* parent=currentScope->parentScope;
             delete currentScope;
             currentScope=parent;
             if((yyvsp[-1].nodeList)) { for(auto n : *(yyvsp[-1].nodeList)) if(n) delete n; delete (yyvsp[-1].nodeList); }
             delete (yyvsp[-10].stringVal); delete (yyvsp[-4].stringVal);
          }
#line 2407 "parser.tab.cpp"
    break;

  case 88: /* param: DECL ID AS var_type  */
#line 641 "parser.y"
      {
          currentScope->addSymbol(SymbolInfo(*(yyvsp[-2].stringVal), *(yyvsp[0].stringVal), "parameter", "local"));
          currentParams.push_back(make_pair(*(yyvsp[-2].stringVal), *(yyvsp[0].stringVal)));
          delete (yyvsp[-2].stringVal); delete (yyvsp[0].stringVal);
      }
#line 2417 "parser.tab.cpp"
    break;

  case 89: /* $@4: %empty  */
#line 649 "parser.y"
           {
               SymbolInfo classSym(*(yyvsp[-1].stringVal), "class", "class");
               currentScope->addSymbol(classSym);

               SymbolTable* classScope = new SymbolTable("class_" + *(yyvsp[-1].stringVal), currentScope);

               SymbolInfo* storedSym = currentScope->lookup(*(yyvsp[-1].stringVal));
               if(storedSym)
               {
                   storedSym->classScope = classScope;
               }

               currentScope = classScope;
           }
#line 2436 "parser.tab.cpp"
    break;

  case 90: /* class_decl: CLASS ID inheritance_spec $@4 LBRACE class_body RBRACE SEMICOLON  */
#line 664 "parser.y"
           {
               currentScope->Print(tableFile);
               SymbolTable* parent = currentScope->parentScope;

               currentScope=parent;
               delete (yyvsp[-6].stringVal);
           }
#line 2448 "parser.tab.cpp"
    break;

  case 105: /* $@5: %empty  */
#line 695 "parser.y"
                 {
                    currentScope=new SymbolTable("constructor_" + *(yyvsp[-1].stringVal), currentScope);
                 }
#line 2456 "parser.tab.cpp"
    break;

  case 106: /* $@6: %empty  */
#line 699 "parser.y"
                 {
                    currentScope->parentScope->addSymbol(SymbolInfo(*(yyvsp[-5].stringVal), "constructor", "constructor"));
                 }
#line 2464 "parser.tab.cpp"
    break;

  case 107: /* constructor_decl: ID LPAREN $@5 param_list RPAREN LBRACE $@6 full_statement_list RBRACE  */
#line 703 "parser.y"
                 {
                    currentScope->Print(tableFile);
                    SymbolTable* parent=currentScope->parentScope;
                    delete currentScope;
                    currentScope=parent;
                    if((yyvsp[-1].nodeList)) { for(auto n : *(yyvsp[-1].nodeList)) if(n) delete n; delete (yyvsp[-1].nodeList); }
                 }
#line 2476 "parser.tab.cpp"
    break;

  case 108: /* destructor_decl: TILDE ID LPAREN RPAREN LBRACE statement_list RBRACE  */
#line 713 "parser.y"
                { 
                    SymbolInfo destr("~" + *(yyvsp[-5].stringVal), "void", "destructor", "class");
                    currentScope->addSymbol(destr);
                    if((yyvsp[-1].nodeList)) { for(auto n : *(yyvsp[-1].nodeList)) if(n) delete n; delete (yyvsp[-1].nodeList); }
                    delete (yyvsp[-5].stringVal); 
                }
#line 2487 "parser.tab.cpp"
    break;

  case 109: /* $@7: %empty  */
#line 722 "parser.y"
             {
                 currentScope->addSymbol(SymbolInfo("main", "int", "function"));
                 currentScope=new SymbolTable("function_main", currentScope);
             }
#line 2496 "parser.tab.cpp"
    break;

  case 110: /* main_function: DECL MAIN LPAREN RPAREN AS TYPE_INT $@7 LBRACE statement_list RBRACE  */
#line 727 "parser.y"
             {
                 currentScope->Print(tableFile);

                 if((yyvsp[-1].nodeList) != nullptr)
                 {
                     for(ASTNode* node : *(yyvsp[-1].nodeList))
                     {
                         if(node != nullptr)
                         {
                            node->eval(currentScope);
                         }
                     }

                     for(ASTNode* node : *(yyvsp[-1].nodeList))
                        if(node)
                            delete node;
                     delete (yyvsp[-1].nodeList);
                 }

                 SymbolTable* parent=currentScope->parentScope;
                 delete currentScope;
                 currentScope=parent;
             }
#line 2524 "parser.tab.cpp"
    break;

  case 111: /* statement_list: statement_list statement  */
#line 757 "parser.y"
               {
                   (yyval.nodeList)=(yyvsp[-1].nodeList);
                   if((yyvsp[0].astNode) != nullptr)
                   {
                       (yyval.nodeList)->push_back((yyvsp[0].astNode));
                   }
               }
#line 2536 "parser.tab.cpp"
    break;

  case 112: /* statement_list: statement_list var_declaration  */
#line 765 "parser.y"
               { 
                   yyerror("Eroare sintactica: Declaratiile de variabile nu sunt permise in acest bloc.");
                   (yyval.nodeList)=(yyvsp[-1].nodeList);
               }
#line 2545 "parser.tab.cpp"
    break;

  case 113: /* statement_list: %empty  */
#line 770 "parser.y"
               {
                   (yyval.nodeList)=new std::vector<ASTNode*>();
               }
#line 2553 "parser.tab.cpp"
    break;

  case 114: /* full_statement_list: full_statement_list statement_or_decl  */
#line 776 "parser.y"
                    {
                        (yyval.nodeList)=(yyvsp[-1].nodeList);
                        if((yyvsp[0].astNode) != nullptr)
                        {
                            (yyval.nodeList)->push_back((yyvsp[0].astNode));
                        }
                    }
#line 2565 "parser.tab.cpp"
    break;

  case 115: /* full_statement_list: %empty  */
#line 784 "parser.y"
                    {
                        (yyval.nodeList)=new std::vector<ASTNode*>();
                    }
#line 2573 "parser.tab.cpp"
    break;

  case 116: /* statement_or_decl: var_declaration  */
#line 789 "parser.y"
                                    { (yyval.astNode)=nullptr; }
#line 2579 "parser.tab.cpp"
    break;

  case 117: /* statement_or_decl: statement  */
#line 790 "parser.y"
                              { (yyval.astNode)=(yyvsp[0].astNode); }
#line 2585 "parser.tab.cpp"
    break;

  case 118: /* statement: if_statement  */
#line 793 "parser.y"
                         { (yyval.astNode)=nullptr; }
#line 2591 "parser.tab.cpp"
    break;

  case 119: /* statement: while_statement  */
#line 794 "parser.y"
                            { (yyval.astNode)=nullptr; }
#line 2597 "parser.tab.cpp"
    break;

  case 120: /* statement: for_statement  */
#line 795 "parser.y"
                          { (yyval.astNode)=nullptr; }
#line 2603 "parser.tab.cpp"
    break;

  case 121: /* statement: do_statement  */
#line 796 "parser.y"
                         { (yyval.astNode)=nullptr; }
#line 2609 "parser.tab.cpp"
    break;

  case 122: /* statement: switch_statement  */
#line 797 "parser.y"
                             { (yyval.astNode)=nullptr; }
#line 2615 "parser.tab.cpp"
    break;

  case 123: /* statement: return_statement SEMICOLON  */
#line 798 "parser.y"
                                       { (yyval.astNode)=nullptr; }
#line 2621 "parser.tab.cpp"
    break;

  case 124: /* statement: break_continue_statement SEMICOLON  */
#line 799 "parser.y"
                                               { (yyval.astNode)=nullptr; }
#line 2627 "parser.tab.cpp"
    break;

  case 125: /* statement: block  */
#line 800 "parser.y"
                  { (yyval.astNode)=nullptr; }
#line 2633 "parser.tab.cpp"
    break;

  case 126: /* statement: SEMICOLON  */
#line 801 "parser.y"
                      { (yyval.astNode)=nullptr; }
#line 2639 "parser.tab.cpp"
    break;

  case 127: /* statement: print_statement SEMICOLON  */
#line 803 "parser.y"
                                      { (yyval.astNode)=(yyvsp[-1].astNode); }
#line 2645 "parser.tab.cpp"
    break;

  case 128: /* statement: variable LPAREN arg_list RPAREN SEMICOLON  */
#line 806 "parser.y"
          { 
              IdNode* funcId = dynamic_cast<IdNode*>((yyvsp[-4].astNode));
              if(funcId)
              {
                  SymbolInfo* funcSym = currentScope->lookup(funcId->getName());
                  
                  if(!funcSym || funcSym->kind != "function")
                  {
                      string err = "Eroare semantica: Functia '" + funcId->getName() + "' nu este definita.";
                      yyerror(err.c_str());
                  } 
                  else
                  {
                      if(funcSym->parameters.size() != (yyvsp[-2].typeList)->size())
                      {
                          string err = "Eroare semantica: Numar incorect de parametri la apelul functiei '" + funcId->getName() + "'. Asteptat: " + to_string(funcSym->parameters.size()) + ", Primit: " + to_string((yyvsp[-2].typeList)->size());
                          yyerror(err.c_str());
                      }
                      else
                      {
                          for(size_t i=0; i<funcSym->parameters.size(); ++i)
                          {
                              string expectedType = funcSym->parameters[i].second;
                              string receivedType = (yyvsp[-2].typeList)->at(i);

                              if(expectedType != receivedType)
                              {
                                  string err = "Eroare semantica: Tip incorect la parametrul " + to_string(i+1) + " al functiei '" + funcId->getName() + "': asteptat '" + expectedType + "', primit '" + receivedType + "'";
                                  yyerror(err.c_str());
                              }
                          }
                      }
                  }
              }
              
              delete (yyvsp[-2].typeList); 
              delete (yyvsp[-4].astNode); 
              (yyval.astNode)=nullptr;
          }
#line 2689 "parser.tab.cpp"
    break;

  case 129: /* statement: REPEAT LPAREN expression RPAREN block  */
#line 846 "parser.y"
                                                  { delete (yyvsp[-2].astNode); (yyval.astNode)=nullptr; }
#line 2695 "parser.tab.cpp"
    break;

  case 130: /* statement: UNLESS LPAREN expression RPAREN block  */
#line 847 "parser.y"
                                                  { delete (yyvsp[-2].astNode); (yyval.astNode)=nullptr; }
#line 2701 "parser.tab.cpp"
    break;

  case 131: /* statement: CHANCE LPAREN expression RPAREN block  */
#line 848 "parser.y"
                                                  { delete (yyvsp[-2].astNode); (yyval.astNode)=nullptr; }
#line 2707 "parser.tab.cpp"
    break;

  case 132: /* statement: SWAP LPAREN variable COMMA variable RPAREN SEMICOLON  */
#line 850 "parser.y"
                                                                 { delete (yyvsp[-4].astNode); delete (yyvsp[-2].astNode); (yyval.astNode)=nullptr; }
#line 2713 "parser.tab.cpp"
    break;

  case 133: /* statement: semicolon_expression SEMICOLON  */
#line 852 "parser.y"
                                           { (yyval.astNode)=(yyvsp[-1].astNode); }
#line 2719 "parser.tab.cpp"
    break;

  case 134: /* print_statement: PRINT LPAREN expression RPAREN  */
#line 855 "parser.y"
                                                 { (yyval.astNode)=new PrintNode((yyvsp[-1].astNode)); }
#line 2725 "parser.tab.cpp"
    break;

  case 135: /* return_statement: RETURN expression  */
#line 857 "parser.y"
                                     { delete (yyvsp[0].astNode); }
#line 2731 "parser.tab.cpp"
    break;

  case 139: /* block: LBRACE statement_list RBRACE  */
#line 866 "parser.y"
        { 
            if((yyvsp[-1].nodeList))
            {
                for(auto n : *(yyvsp[-1].nodeList))
                    if(n)
                        delete n;
                delete (yyvsp[-1].nodeList);
            }
        }
#line 2745 "parser.tab.cpp"
    break;

  case 140: /* if_statement: IF LPAREN boolean_expression RPAREN statement  */
#line 877 "parser.y"
                                                                                   { delete (yyvsp[-2].astNode); if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); }
#line 2751 "parser.tab.cpp"
    break;

  case 141: /* if_statement: IF LPAREN boolean_expression RPAREN statement ELSE statement  */
#line 878 "parser.y"
                                                                            { delete (yyvsp[-4].astNode); if((yyvsp[-2].astNode)) delete (yyvsp[-2].astNode); if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); }
#line 2757 "parser.tab.cpp"
    break;

  case 142: /* switch_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 881 "parser.y"
                                                                           { delete (yyvsp[-4].astNode); }
#line 2763 "parser.tab.cpp"
    break;

  case 145: /* case_item: CASE expression COLON statement_list  */
#line 888 "parser.y"
            { 
                delete (yyvsp[-2].astNode); 
                if((yyvsp[0].nodeList)) { for(auto n:*(yyvsp[0].nodeList)) if(n) delete n; delete (yyvsp[0].nodeList); } 
            }
#line 2772 "parser.tab.cpp"
    break;

  case 146: /* case_item: DEFAULT COLON statement_list  */
#line 893 "parser.y"
            { 
                if((yyvsp[0].nodeList)) { for(auto n:*(yyvsp[0].nodeList)) if(n) delete n; delete (yyvsp[0].nodeList); } 
            }
#line 2780 "parser.tab.cpp"
    break;

  case 147: /* while_statement: WHILE LPAREN boolean_expression RPAREN statement  */
#line 898 "parser.y"
                                                                   { delete (yyvsp[-2].astNode); if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); }
#line 2786 "parser.tab.cpp"
    break;

  case 148: /* do_statement: DO statement WHILE LPAREN boolean_expression RPAREN SEMICOLON  */
#line 901 "parser.y"
                                                                             { delete (yyvsp[-2].astNode); if((yyvsp[-5].astNode)) delete (yyvsp[-5].astNode); }
#line 2792 "parser.tab.cpp"
    break;

  case 149: /* for_statement: FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_step RPAREN statement  */
#line 905 "parser.y"
              { 
                  if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); 
              }
#line 2800 "parser.tab.cpp"
    break;

  case 150: /* for_init: semicolon_expression  */
#line 910 "parser.y"
                                { if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); }
#line 2806 "parser.tab.cpp"
    break;

  case 152: /* for_cond: non_semicolon_expression  */
#line 914 "parser.y"
                                    { delete (yyvsp[0].astNode); }
#line 2812 "parser.tab.cpp"
    break;

  case 154: /* for_step: semicolon_expression  */
#line 918 "parser.y"
                                { if((yyvsp[0].astNode)) delete (yyvsp[0].astNode); }
#line 2818 "parser.tab.cpp"
    break;


#line 2822 "parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 922 "parser.y"


void yyerror(const char *s) 
{
    std::cout << "Eroare de sintaxa/semantica la linia " << yylineno << ": " << s << std::endl;
}

int main(int argc, char** argv) 
{
    if(argc > 1)
    {
        yyin=fopen(argv[1], "r");
        if(!yyin) 
        {
            std::cerr << "Nu pot deschide fisierul: " << argv[1] << std::endl;
            return 1;
        }
    }
    
    yyparse();
    return 0;
}
