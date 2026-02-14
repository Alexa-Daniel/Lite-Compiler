/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 22 "parser.y"

    #include <string>
    #include <vector>
    #include "ASTNode.h"

#line 55 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_VAL = 258,                 /* INT_VAL  */
    FLOAT_VAL = 259,               /* FLOAT_VAL  */
    STRING_VAL = 260,              /* STRING_VAL  */
    BOOL_VAL = 261,                /* BOOL_VAL  */
    CHAR_VAL = 262,                /* CHAR_VAL  */
    ID = 263,                      /* ID  */
    TYPE_INT = 264,                /* TYPE_INT  */
    TYPE_BOOL = 265,               /* TYPE_BOOL  */
    TYPE_CHAR = 266,               /* TYPE_CHAR  */
    TYPE_FLOAT = 267,              /* TYPE_FLOAT  */
    TYPE_STRING = 268,             /* TYPE_STRING  */
    TYPE_VOID = 269,               /* TYPE_VOID  */
    CLASS = 270,                   /* CLASS  */
    PUBLIC = 271,                  /* PUBLIC  */
    PRIVATE = 272,                 /* PRIVATE  */
    PROTECTED = 273,               /* PROTECTED  */
    CONST = 274,                   /* CONST  */
    IF = 275,                      /* IF  */
    SWITCH = 276,                  /* SWITCH  */
    CASE = 277,                    /* CASE  */
    DEFAULT = 278,                 /* DEFAULT  */
    ELSE = 279,                    /* ELSE  */
    WHILE = 280,                   /* WHILE  */
    FOR = 281,                     /* FOR  */
    DO = 282,                      /* DO  */
    RETURN = 283,                  /* RETURN  */
    BREAK = 284,                   /* BREAK  */
    CONTINUE = 285,                /* CONTINUE  */
    MAIN = 286,                    /* MAIN  */
    PRINT = 287,                   /* PRINT  */
    TRUE = 288,                    /* TRUE  */
    FALSE = 289,                   /* FALSE  */
    ASSIGN = 290,                  /* ASSIGN  */
    INC = 291,                     /* INC  */
    DEC = 292,                     /* DEC  */
    ADD_ASSIGN = 293,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 294,              /* SUB_ASSIGN  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    NOT = 297,                     /* NOT  */
    EQ = 298,                      /* EQ  */
    NEQ = 299,                     /* NEQ  */
    LT = 300,                      /* LT  */
    GT = 301,                      /* GT  */
    LE = 302,                      /* LE  */
    GE = 303,                      /* GE  */
    PLUS = 304,                    /* PLUS  */
    MINUS = 305,                   /* MINUS  */
    MUL = 306,                     /* MUL  */
    DIV = 307,                     /* DIV  */
    MOD = 308,                     /* MOD  */
    LPAREN = 309,                  /* LPAREN  */
    RPAREN = 310,                  /* RPAREN  */
    LBRACE = 311,                  /* LBRACE  */
    RBRACE = 312,                  /* RBRACE  */
    LBRACKET = 313,                /* LBRACKET  */
    RBRACKET = 314,                /* RBRACKET  */
    SEMICOLON = 315,               /* SEMICOLON  */
    COMMA = 316,                   /* COMMA  */
    DOT = 317,                     /* DOT  */
    COLON = 318,                   /* COLON  */
    TILDE = 319,                   /* TILDE  */
    ARROW = 320,                   /* ARROW  */
    AMPER = 321,                   /* AMPER  */
    DECL = 322,                    /* DECL  */
    AS = 323,                      /* AS  */
    UNLESS = 324,                  /* UNLESS  */
    REPEAT = 325,                  /* REPEAT  */
    SWAP = 326,                    /* SWAP  */
    CHANCE = 327,                  /* CHANCE  */
    POWER = 328,                   /* POWER  */
    REPEAT_STR = 329,              /* REPEAT_STR  */
    RANDOM = 330,                  /* RANDOM  */
    COMP = 331,                    /* COMP  */
    APPROX = 332,                  /* APPROX  */
    LOWER_THAN_ELSE = 333          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    std::string* stringVal;
    ASTNode* astNode;
    std::vector<ASTNode*>* nodeList;
    std::vector<std::string>* typeList;

#line 157 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
