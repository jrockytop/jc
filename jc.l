%e 10000
%p 10000
%a 10000
%o 10000
%{
#include "jc.h"
%}
hex		0[xX][0-9a-fA-F]+
oct		0[0-7]+
number		[0-9]
integer 	[0-9]+
decimal		-?(([0-9]+\.?)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
alpha		[a-zA-Z]
nonnumeric	[!#$%&()*+,\-./:;<=>?@\[\\\\]^ {|}~]
u		[uU]
l		[lL]
ul		{u}{l}|{l}{u}
h		[hH]
uh		{u}{h}|{h}{u}
f		[fF]
spc		[\t \n]
spcnr		[\t ]
%%
{hex}{l}		{ push(ul,	hex,	"%lx"); }
{hex}{h}		{ push(s,	hex,	"%hx"); }
{hex}			{ push(ul,	hex,	"%lx" ); }
{oct}{l}		{ push(ul,	oct,	"%lo"); }
{oct}{h}		{ push(s,	oct,	"%ho"); }
{oct}			{ push(u,	oct,	"%o" ); }
{integer}{u}		{ push(u,	dec,	"%u" ); }
-?{integer}{l}		{ push(l,	dec,	"%ld"); }
{integer}{ul}		{ push(ul,	dec,	"%lu"); }
{integer}{uh}		{ push(us,	dec,	"%hu"); }
{integer}{h}		{ push(s,	dec,	"%hd"); }
-?{integer}		{ push(i,	dec,	"%d" ); }
{decimal}{f}		{ push(f,	dec,	"%g" ); }
{decimal}{l}		{ push(ld,	dec,	"%Lg" ); }
{decimal}		{ push(d,	dec,	"%lg" ); }
0?[bB][01]+		{ push(u,	bin,	"%s"  ); }
\'({alpha}|{number})\'	{ push(c,	chr,	"'%c'"); }
\\{oct}			{ push(uc,	uchr,	"\\%o"); }
"+"			{ add(); }
"-"			{ sub(); }
"*"			{ mult(); }
"/"			{ divide(); }
">>"			{ rshift(); }
"<<"			{ lshift(); }
"|"			{ or(); }
"&"			{ and(); }
"%"			{ mod(); }
"~"			{ bit_comp(); }
"^"			{ xor(); }
npow |
sqrt |
nroot |
sin |
cos |
tan |
arcsin |
arccos |
arctan |
bit |
bits |
2root					{ operator(); }
sizeof					{ machine_sizes(); }
sto*(:{integer})?{spcnr}+{alpha}+	{ store_register(); }
sto*(:{integer})?[\n]			{ yytext[strlen(yytext)-1] = '\0';
	fprintf(stderr, "syntax error -- '%s' argument required\n", yytext); }
rcl*(:{integer})?{spcnr}+{alpha}+	{ recall_register(yytext); }
rcl*(:{integer})?[\n]			{ yytext[strlen(yytext)-1] = '\0';
	fprintf(stderr, "syntax error -- '%s' argument required\n", yytext); }
S{alpha}				{ store_stack(); }
l{alpha}				{ copy_register_stack(); }
L{alpha}				{ pop_stack_to_mainstack(); }
d{alpha}?				{ dup_stack(); }
p{alpha}?				{ print_top_value(); }
a{alpha}?				{ print_long_stack(); }
f{alpha}?				{ print_stack(); }
c{alpha}?				{ clear_stack(); }
P{alpha}?				{ pop_stack(); }
x{alpha}?				{ pop_stack(); }
P(:{integer})?				{ pop_stack_level(level(yytext)); }
x(:{integer})?				{ pop_stack_level(level(yytext)); }
s					{ swap_top_vals(); }
r(:{integer})?				{ rotate_stack(level(yytext)); }
j(:{integer})?				{ rotate_stack(level(yytext)); 
					  print_stack(); }
k(:{integer})?				{ rev_rotate_stack(level(yytext)); 
					  print_stack(); }
[Dd][Ee][Cc]:[Aa][Ll][Ll]		{ set_base(dec, -1); }
[Hh][Ee][Xx]:[Aa][Ll][Ll]		{ set_base(hex, -1); }
[Oo][Cc][Tt]:[Aa][Ll][Ll]		{ set_base(oct, -1); }
[Cc][Hh][Rr]:[Aa][Ll][Ll]		{ set_base(chr, -1); }
[Uu][Cc][Hh][Rr]:[Aa][Ll][Ll]		{ set_base(uchr, -1); }
[Bb][Ii][Nn]:[Aa][Ll][Ll]		{ set_base(bin, -1); }
[Dd][Ee][Cc](:{integer})?		{ set_base(dec, level(yytext)); }
[Hh][Ee][Xx](:{integer})?		{ set_base(hex, level(yytext)); }
[Oo][Cc][Tt](:{integer})?		{ set_base(oct, level(yytext)); }
[Cc][Hh][Rr](:{integer})?		{ set_base(chr, level(yytext)); }
[Uu][Cc][Hh][Rr](:{integer})?		{ set_base(uchr, level(yytext)); }
[Bb][Ii][Nn](:{integer})?		{ set_base(bin, level(yytext)); }
\({spc}*char{spc}*\):[Aa][Ll][Ll]	{ set_type(c, -1); }
\({spc}*signed{spc}+char{spc}*\):[Aa][Ll][Ll]	{ set_type(sc, -1); }
\({spc}*unsigned{spc}+char{spc}*\):[Aa][Ll][Ll]	{ set_type(uc, -1); }
\({spc}*short{spc}*\):[Aa][Ll][Ll]	{ set_type(s, -1); }
\({spc}*int{spc}*\):[Aa][Ll][Ll]	{ set_type(i, -1); }
\({spc}*long{spc}*\):[Aa][Ll][Ll]	{ set_type(l, -1); }
\({spc}*unsigned{spc}+short{spc}*\):[Aa][Ll][Ll]	{ set_type(us, -1); }
\({spc}*unsigned{spc}*\):[Aa][Ll][Ll]	{ set_type(u, -1); }
\({spc}*unsigned{spc}+int{spc}*\):[Aa][Ll][Ll]	{ set_type(u, -1); }
\({spc}*unsigned{spc}+long{spc}*\):[Aa][Ll][Ll]	{ set_type(ul, -1); }
\({spc}*float{spc}*\):[Aa][Ll][Ll]	{ set_type(f, -1); }
\({spc}*double{spc}*\):[Aa][Ll][Ll]	{ set_type(d, -1); }
\({spc}*long{spc}+double{spc}*\):[Aa][Ll][Ll]	{ set_type(ld, -1); }
\({spc}*char{spc}*\)(:{integer})?	{ set_type(c, level(yytext)); }
\({spc}*signed{spc}+char{spc}*\)(:{integer})?	{ set_type(sc, level(yytext)); }
\({spc}*unsigned{spc}+char{spc}*\)(:{integer})?	{ set_type(uc,level(yytext)); }
\({spc}*short{spc}*\)(:{integer})?	{ set_type(s, level(yytext)); }
\({spc}*int{spc}*\)(:{integer})?	{ set_type(i, level(yytext)); }
\({spc}*long{spc}*\)(:{integer})?	{ set_type(l, level(yytext)); }
\({spc}*unsigned{spc}+short{spc}*\)(:{integer})?	{ set_type(us, level(yytext)); }
\({spc}*unsigned{spc}*\)(:{integer})?	{ set_type(u, level(yytext)); }
\({spc}*unsigned{spc}+int{spc}*\)(:{integer})?	{ set_type(u, level(yytext)); }
\({spc}*unsigned{spc}+long{spc}*\)(:{integer})?	{ set_type(ul,level(yytext)); }
\({spc}*float{spc}*\)(:{integer})?	{ set_type(f, level(yytext)); }
\({spc}*double{spc}*\)(:{integer})?	{ set_type(d, level(yytext)); }
\({spc}*long{spc}+double{spc}*\)(:{integer})?	{ set_type(ld, level(yytext)); }
"?"					{ help(); }
"h"					{ help(); }
q					{ quit(); }
ctime(:{integer})?			{ do_ctime(level(yytext)); }
{spc}+				{/* ignore white space */}
{integer}:			{/* allows cut'n'paste from with levels */}
[^\t \n]+	{ fprintf(stderr, "syntax error -- '%s'\n", yytext); }
%%
int
main()
{
	init();
	yylex();
	exit(0);
}

