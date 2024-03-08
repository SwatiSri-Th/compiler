%option noyywrap
keyword double|auto|break|else|struct|long|switch|case|sizeof
literal int|float|char|string
intNumber [-+]?[0-9]*
floatNumber [-+]?[0-9]*\.[0-9]+
validIdentifier ^[a-zA-Z_]+[a-zA-Z0.9_]*
invalidIdentifier ^([^a-zA-Z_]).*
%%
[\n] printf("***");
{keyword} printf("Keyword:%s\n",yytext);
{literal} printf("Literal:%s\n",yytext);
{intNumber} printf("intNumber:%s\n",yytext);
{floatNumber} printf("floatNumber:%s\n",yytext);
{validIdentifier} printf("validIdentifier:%s\n",yytext);
{invalidIdentifier} printf("invalidIdentifier:%s\n",yytext);
%%
int main()
{
yylex();
return 0;
}
