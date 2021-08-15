/* Mini Programming Language HEADERRRRRRRRRR FOR PARSE TABLE AND RULES 
 * Grubbi Language
 *
 * Bengco, Dana Kirstie
 * Chua, Jericka
 * Tablanza, Krys
 * Waquez, Emerson
 * BSCS 3 - 2
 */

const char *terms[] = {
	/*0*/	"INT",
	/*1*/	"CHAR",
	/*2*/	"STR",
	/*3*/	"REAL",
	/*4*/	"BOOL",
	/*5*/	"INT_VAL",
	/*6*/	"CHAR_VAL",
	/*7*/	"STR_VAL",
	/*8*/	"REAL_VAL",
	/*9*/	"TRUE",
	/*10*/	"FALSE",
	/*11*/	"AND",
	/*12*/	"OR",
	/*13*/	"NOT",
	/*14*/	"EQ",
	/*15*/	"NEQ",
	/*16*/	"GT",
	/*17*/	"GTE",
	/*18*/	"LT",
	/*19*/	"LTE",
	/*20*/	"PLUS",
	/*21*/	"MINUS",
	/*22*/	"MULTI",
	/*23*/	"DIV",
	/*24*/	"MOD",
	/*25*/	"EXP",
	/*26*/	"INPUT",
	/*27*/	"LPRN",
	/*28*/	"VAR_ID",
	/*29*/	"RPRN",
	/*30*/	"SEMI",
	/*31*/	"OUTPUT",
	/*32*/	"NEWLINE",
	/*33*/	"TAB",
	/*34*/	"EQUALS",
	/*35*/	"LENGTH",
	/*36*/	"CMSEP",
	/*37*/	"IF",
	/*38*/	"LBRC",
	/*39*/	"RBRC",
	/*40*/	"ELSIF",
	/*41*/	"ELSE",
	/*42*/	"WHILE",
	/*43*/	"STOP",
	/*44*/	"$",
	/*45*/	"empty"	
};

const char *nterms[] = { 
	/*0*/	"begin",
	/*1*/	"dtype",
	/*2*/	"literal",
	/*3*/	"bool_val",
	/*4*/	"log_op",
	/*5*/	"rel_op",
	/*6*/	"ar_op",
	/*7*/	"program_stmt",
	/*8*/	"input_stmt",
	/*9*/	"output_stmt",
	/*10*/	"output_exp",
	/*11*/	"output_ext",
	/*12*/	"output_concat",
	/*13*/	"ass_stmt",
	/*14*/	"ass_exp",
	/*15*/	"ass_args",
	/*16*/	"ass_args2",
	/*17*/	"dec_stmt",
	/*18*/	"dec_exp",
	/*19*/	"dec_exp2",
	/*20*/	"cond_stmt",
	/*21*/	"cond_exp",
	/*22*/	"cond_list",
	/*23*/	"cond_args",
	/*24*/	"cond_args2",
	/*25*/	"log_args",
	/*26*/	"loop_stmt",
	/*27*/	"loop_prog",
	/*28*/	"loop_exp"
};

// Productions
const char *rules[] = { 
	/*0*/	"program_stmt", //begin
	/*1*/	"INT",
	/*2*/	"CHAR", 
	/*3*/	"STR",
	/*4*/	"REAL", 
	/*5*/	"BOOL", 
	/*6*/	"INT_VAL", 
	/*7*/	"CHAR_VAL", 
	/*8*/	"STR_VAL",
	/*9*/	"REAL_VAL",
	/*10*/	"bool_val", 
	/*11*/	"TRUE", 
	/*12*/	"FALSE", 
	/*13*/	"AND", 
	/*14*/	"OR", 
	/*15*/	"NOT",
	/*16*/	"EQ", 
	/*17*/	"NEQ", 
	/*18*/	"GT", 
	/*19*/	"GTE", 
	/*20*/	"LT", 
	/*21*/	"LTE",
	/*22*/	"PLUS", 
	/*23*/	"MINUS", 
	/*24*/	"MULTI", 
	/*25*/	"DIV", 
	/*26*/	"MOD", 
	/*27*/	"EXP", 
	/*28*/	"input_stmt program_stmt", 
	/*29*/	"output_stmt program_stmt", 
	/*30*/	"ass_stmt program_stmt", 
	/*31*/	"dec_stmt program_stmt", 
	/*32*/	"cond_stmt program_stmt", 
	/*33*/	"loop_stmt program_stmt", 
	/*34*/	"empty",
	/*35*/	"INPUT LPRN VAR_ID RPRN SEMI",
	/*36*/	"OUTPUT LPRN output_exp RPRN SEMI", 
	/*37*/	"output_ext output_concat", 
	/*38*/	"VAR_ID output_concat", 
	/*39*/	"STR_VAL output_ext", 
	/*40*/	"NEWLINE output_ext", 
	/*41*/	"TAB output_ext", 
	/*42*/	"empty",
	/*43*/	"PLUS output_exp", 
	/*44*/	"empty", 
	/*45*/	"VAR_ID ass_exp", 
	/*46*/	"EQUALS ass_args", 
	/*47*/	"VAR_ID ass_args2", 
	/*48*/	"literal ass_args2", 
	/*49*/	"LPRN ass_args RPRN ass_args2", 
	/*50*/	"LENGTH LPRN VAR_ID RPRN SEMI", 
	/*51*/	"ar_op ass_args", 
	/*52*/	"empty",
	/*53*/	"dtype VAR_ID dec_exp",
	/*54*/	"dec_exp2", 
	/*55*/	"EQUALS ass_args", 
	/*56*/	"SEMI", 
	/*57*/	"CMSEP VAR_ID dec_exp", 
	/*58*/	"IF cond_exp cond_list", 
	/*59*/	"LPRN cond_args RPRN LBRC program_stmt RBRC", 
	/*60*/	"ELSIF cond_exp cond_list", 
	/*61*/	"ELSE LBRC program_stmt RBRC", 
	/*62*/	"empty", 
	/*63*/	"VAR_ID rel_op cond_args2",
	/*64*/	"literal rel_op cond_args2", 
	/*65*/	"VAR_ID log_args", 
	/*66*/	"literal log_args",
	/*67*/	"log_op cond_args", 
	/*68*/	"empty",
	/*69*/	"WHILE loop_exp LBRC loop_prog RBRC",
	/*70*/	"program_stmt",
	/*71*/	"STOP SEMI loop_prog", 
	/*72*/	"empty",
	/*73*/	"SEMI",
	/*74*/	"LPRN cond_args RPRN"
	/*75	"synch" //error recovery */
};

int parseTable[29][45] = {
//					  0   1	  2	  3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  
//				  	 int,chr,str,rea,boo,inV,chV,stV,reV,tru,fls,and, or,not, EQ,NEQ, GT,GTE, LT,LTE,  +,  -,  *,  /,  %,  ^, in, (L,vID, )R,sem,out,^nl,tab,  =,len,cms, if, {L, }R,elf,els,whl,stp,  $
/*begin*/			{  0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1,  0, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1,  0, -1, 75},
/*dtype*/			{  1,  2,  3,  4,  5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*literal*/			{ 75, 75, 75, 75, 75,  6,  7,  8,  9, 10, 10, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, -1, 75, 75, 75, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*bool_val*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, 11, 12, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, -1, 75, 75, 75, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*log_op*/			{ -1, -1, -1, -1, -1, 75, 75, 75, 75, 75, 75, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*rel_op*/			{ -1, -1, -1, -1, -1, 75, 75, 75, 75, 75, 75, -1, -1, -1, 16, 17, 18, 19, 20, 21, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*ar_op*/			{ -1, -1, -1, -1, -1, 75, 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, 23, 24, 25, 26, 27, -1, 75, 75, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*program_stmt*/	{ 31, 31, 31, 31, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, 30, -1, -1, 29, -1, -1, -1, -1, -1, 32, -1, 34, -1, -1, 33, -1, 34},
/*input_stmt*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, 75, -1, -1, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*output_stmt*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 36, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*output_exp*/		{ -1, -1, -1, -1, -1, -1, -1, 37, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 37, -1, -1, -1, -1, -1, -1, -1, 38, 75, -1, -1, 37, 37, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*output_ext*/		{ -1, -1, -1, -1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, -1, 40, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*output_concat*/	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 43, -1, -1, -1, -1, -1, -1, -1, -1, 44, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*ass_stmt*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 45, -1, -1, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*ass_exp*/			{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, 75, -1, 75, -1, -1, 46, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*ass_args*/		{ 75, 75, 75, 75, 75, 48, 48, 48, 48, 48, 48, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, 49, 47, 75, -1, 75, -1, -1, -1, 50, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*ass_args2*/		{ 52, 52, 52, 52, 52, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 51, 51, 51, 51, 51, 51, 52, -1, 52, 52, 73, 52, -1, -1, -1, -1, -1, 52, -1, 52, -1, -1, 52, -1, 52},
/*dec_stmt*/		{ 53, 53, 53, 53, 53, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, 75},
/*dec_exp*/			{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, 54, 75, -1, -1, 55, -1, 54, 75, -1, 75, -1, -1, 75, -1, 75},
/*dec_exp2*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, 56, 75, -1, -1, -1, -1, 57, 75, -1, 75, -1, -1, 75, -1, 75},
/*cond_stmt*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, -1, -1, -1, -1, 58, -1, 75, -1, -1, 75, -1, 75},
/*cond_exp*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, 59, 75, -1, -1, 75, -1, -1, -1, -1, -1, 75, -1, 75, 75, 75, 75, -1, 75},
/*cond_list*/		{ 62, 62, 62, 62, 62, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, 62, -1, -1, 62, -1, -1, -1, -1, -1, 62, -1, 62, 60, 61, 62, -1, 62},
/*cond_args*/		{ -1, -1, -1, -1, -1, 64, 64, 64, 64, 64, 64, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 63, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*cond_args2*/		{ -1, -1, -1, -1, -1, 66, 66, 66, 66, 66, 66, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 65, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*log_args*/		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 67, 67, 67, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 68, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
/*loop_stmt*/		{ 75, 75, 75, 75, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 75, -1, -1, -1, -1, -1, 75, -1, 75, -1, -1, 69, -1, 75},
/*loop_prog*/		{ 70, 70, 70, 70, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 70, -1, 70, -1, -1, 70, -1, -1, -1, -1, -1, 70, -1, 72, -1, -1, 70, 71, -1},
/*loop_exp*/		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 74, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1}
//				  	 int,chr,str,rea,boo,inV,chV,stV,reV,tru,fls,and, or,not, EQ,NEQ, GT,GTE, LT,LTE,  +,  -,  *,  /,  %,  ^, in, (L,vID, )R,sem,out,^nl,tab,  =,len,cms, if, {L, }R,elf,els,whl,stp,  $
//					  0   1	  2	  3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  				
};

const char *getError(char *chr)
{
	//return
	
	if(strcmp("begin",chr) == 0){ return " ";}
	else if(strcmp("dtype",chr) == 0){ return "Expected Data Type";}
	else if(strcmp("literal",chr) == 0){ return "expected literal values";}
	else if(strcmp("bool_val",chr) == 0){ return "expected boolean values";}
	else if(strcmp("log_op",chr) == 0){ return "expected logical operation";}
	else if(strcmp("rel_op",chr) == 0){ return "expected relational operator";}
	else if(strcmp("ar_op",chr) == 0){ return "expected arithmetic operator";}
	else if(strcmp("program_stmt" ,chr) == 0){ return "invalid statement";}
	else if(strcmp("input_stmt",chr) == 0){ return "expected input syntax";}
	else if(strcmp("output_stmt" ,chr) == 0){ return "expected output syntax";}
	else if(strcmp("output_exp",chr) == 0){ return "invalid output argument";}
	else if(strcmp("output_ext",chr) == 0){ return "invalid output argument";}
	else if(strcmp("output_concat",chr) == 0){ return "invalid output argument";}
	else if(strcmp("ass_stmt",chr) == 0){ return "invalid variable assignment";}
	else if(strcmp("ass_exp",chr) == 0){ return "invalid statement";}
	else if(strcmp("ass_args",chr) == 0){ return "invalid variable assignment";}
	else if(strcmp("ass_args2",chr) == 0){ return "invalid variable statement";}
	else if(strcmp("dec_stmt",chr) == 0){ return "invalid variable declaration";}
	else if(strcmp("dec_exp",chr) == 0){ return "invalid variable declaration";}
	else if(strcmp("dec_exp2",chr) == 0){ return "invalid variable declaration";}
	else if(strcmp("cond_stmt",chr) == 0){ return "invalid condition statements";}
	else if(strcmp("cond_exp",chr) == 0){ return "invalid condition statements";}
	else if(strcmp("cond_list",chr) == 0){ return "invalid condition statements";}
	else if(strcmp("cond_args",chr) == 0){ return "expected identifier/literal";}
	else if(strcmp("cond_args2",chr) == 0){ return "expected identifier/literal";}
	else if(strcmp("log_args",chr) == 0){ return "expected log operator";}
	else if(strcmp("loop_stmt",chr) == 0){ return "invalid loop statements";}
	else if(strcmp("loop_prog",chr) == 0){ return "invalid statements";}
	else if(strcmp("loop_exp",chr) == 0){ return "invalid condition statements";}
	
	if(strcmp("INT" ,chr) == 0){ return "expected \"int\" symbol";}
	else if(strcmp("STR" ,chr) == 0){ return "expected \"string\" symbol";}
	else if(strcmp("REAL" ,chr) == 0){ return "expected \"real\" symbol";}
	else if(strcmp("CHAR" ,chr) == 0){ return "expected \"char\" symbol";}
	else if(strcmp("BOOL" ,chr) == 0){ return "expected \"bool\" symbol";}
	else if(strcmp("INT_VAL" ,chr) == 0){ return "inserted \"int value\" symbol";}
	else if(strcmp("CHAR_VAL" ,chr) == 0){ return "inserted \"char value\" symbol";}
	else if(strcmp("STR_VAL" ,chr) == 0){ return "inserted \"string value\" symbol";}
	else if(strcmp("REAL_VAL" ,chr) == 0){ return "inserted \"real value\" symbol";}
	else if(strcmp("TRUE" ,chr) == 0){ return "inserted \"true\" symbol";}
	else if(strcmp("FALSE" ,chr) == 0){ return "inserted \"false\" symbol";}
	else if(strcmp("NOT",chr) == 0){ return "inserted \"!\" symbol";}
	else if(strcmp("AND",chr) == 0){ return "inserted \"&&\" symbol";}
	else if(strcmp("OR",chr) == 0){ return "inserted \"||\" symbol";}
	else if(strcmp("GT",chr) == 0){ return "inserted \">\" symbol";}
	else if(strcmp("LT",chr) == 0){ return "inserted \"<\" symbol";}
	else if(strcmp("GTE",chr) == 0){ return "inserted \">=\" symbol";}
	else if(strcmp("LTE",chr) == 0){ return "inserted \"<=\" symbol";}
	else if(strcmp("EQ",chr) == 0){ return "inserted \"==\" symbol";}
	else if(strcmp("NEQ",chr) == 0){ return "inserted \"!=\" symbol";}
	else if(strcmp("PLUS",chr) == 0){ return "inserted \"+\" symbol";}
	else if(strcmp("MULTI",chr) == 0){ return "inserted \"*\" symbol";}
	else if(strcmp("DIV",chr) == 0){ return "inserted \"/\" symbol";}
	else if(strcmp("MOD",chr) == 0){ return "inserted \"%\" symbol";}
	else if(strcmp("EXXP",chr) == 0){ return "inserted \"^\" symbol";}
	else if(strcmp("MIN",chr) == 0){ return "inserted \"-\" symbol";}
	else if(strcmp("LPRN",chr) == 0){ return "inserted/expected \"(\" symbol";}
	else if(strcmp("RPRN",chr) == 0){ return "inserted/expected \")\" symbol";}
	else if(strcmp("LBRC",chr) == 0){ return "inserted/expected \"{\" symbol";}
	else if(strcmp("RBRC",chr) == 0){ return "inserted/expected \"}\" symbol";}
	else if(strcmp("INPUT",chr) == 0){ return "expected \"input\" symbol";}
	else if(strcmp("OUTPUT",chr) == 0){ return "inserted/expected \"output\" symbol";}
	else if(strcmp("VAR_ID",chr) == 0){ return "expected \"identifier\" symbol";}
	else if(strcmp("SEMI",chr) == 0){ return "expected \";\" symbol";}
	else if(strcmp("NEWLINE",chr) == 0){ return "inserted \"^nl\" symbol";}
	else if(strcmp("TAB",chr) == 0){ return "inserted \"^ht\" symbol";}
	else if(strcmp("LENGTH",chr) == 0){ return "inserted \"length\" symbol";}
	else if(strcmp("EQUALS",chr) == 0){ return "inserted \"=\" symbol";}
	else if(strcmp("CMSEP",chr) == 0){ return "inserted \",\" symbol";}
	else if(strcmp("IF",chr) == 0){ return "inserted \"if\" symbol";}
	else if(strcmp("ELSIF",chr) == 0){ return "inserted \"elsif\" symbol";}
	else if(strcmp("ELSE",chr) == 0){ return "inserted \"else\" symbol";}
	else if(strcmp("WHILE",chr) == 0){ return "expected \"while\" symbol";}
	else if(strcmp("STOP",chr) == 0){ return "inserted \"stop\" symbol";}

	else {	return "unrecognized symbol" ;}
}

