
# 加-ll参数时，不用定义main()函数，就是libl

simple:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out -ll

reg_exp:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out -ll

scan_verb:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out

# not work
word_count:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out

clang_like:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out -ll

temperature_controller:
	lex -o $@.yy.c $@.lex
	yacc -d $@.yy
	gcc $@.yy.c y.tab.c -o $@.out

temperature_controller_ext:
	lex -o $@.yy.c $@.lex
	yacc -d $@.yy
	gcc $@.yy.c y.tab.c -o $@.out

conf_parse:
	lex -o $@.yy.c $@.lex
	yacc -dtv $@.yy
	#yacc -dtv $@.orig.yy
	gcc $@.yy.c y.tab.c -o $@.out

conf_parse_cpp:
	lex -o $@.yy.c conf_parse.lex
	cc -c $@.yy.c -o $@.yy.o
	yacc -dtv $@.yy -o $@.cpp
	g++ $@.yy.o $@.cpp -o $@.out

conf_parse2:
	lex -o $@.yy.c $@.lex
	gcc $@.yy.c -o $@.out -ll

heater:
	lex -o $@.yy.c $@.lex
	yacc -dtv $@.yy
	gcc $@.yy.c y.tab.c -o $@.out
