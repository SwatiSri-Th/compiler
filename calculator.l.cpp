%{ 
#define NUM 2 
#define ADD 3 
#define SUB 4 
#define MUL 5 
#define DIV 6 
#define POW 7 
#define SQRT 8 
#define SIN 9 
#define COS 10 
#define TAN 11 
#define LN 12 
#define LOG 13 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
double yylval; 
%} 
digit [0-9]+ 
point \. 
%% 
{digit}({point}{digit})? {
yylval = atof(yytext); 
//   printf("%lf\n", yylval); 
return NUM; 
} 
 
"+"   return ADD; 
"-"   return SUB; 
"*"   return MUL; 
"/"   return DIV; 
"^"   return POW; 
"sqrt"  return SQRT; 
"sin"   return SIN; 
"cos"   return COS; 
"tan"   return TAN; 
"ln"    return LN; 
"log"   return LOG; 
 
%% 
 
int yywrap() { 
  return 1; 
} 
 
double calc(double x, int op, double y) { 
  switch (op) { 
    case ADD: 
      return x + y; 
    case SUB: 
      return x - y; 
    case MUL: 
      return x * y;
        case DIV: 
      return x / y; 
    case POW: 
      return pow(x, y); 
    case SQRT: 
      return sqrt(x); 
    case SIN: 
      return sin(x); 
    case COS: 
      return cos(x); 
    case TAN: 
      return tan(x); 
    case LN: 
      return log(x); 
    case LOG: 
      return log10(x); 
    default: 
      return 0; 
  } 
} 
 
void result(double res) { 
    printf("Result: %.10g\n", res); 
} 
int main() { 
  int op, prev_op = 0, count = 0, mathFnc = 0; 
  double x = 0, y = 0; 
 
  while (op = yylex()) { 
    // printf("OP = %d", op); 
    // printf("%d", count); 
    if (op == NUM) { 
      if (prev_op == 0 || mathFnc == 1) 
        x = yylval; 
      else 
        y = yylval; 
    } else if(op) { 
        if(x == 0)  
            mathFnc = 1; 
        prev_op = op; 
    }  
    if(count == 2 || (count == 1 && mathFnc == 1)){  
        if (prev_op) { 
            x = calc(x, prev_op, y); 
        } 
        break; 
    } 
    ++count; 
  } 
  result(x); 
  return 0; 
} 
