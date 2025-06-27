all:
	bison -d -o parser.tab.cpp parser.y
	flex -o lexer.cpp lexer.l
	g++ main.cpp Value.cpp eval.cpp Environment.cpp parser.tab.cpp lexer.cpp Robot.cpp interpreter.cpp -g -o ta3


#// parser.y: warning: 96 shift/reduce conflicts [-Wconflicts-sr]
#// parser.y: note: rerun with option '-Wcounterexamples' to generate conflict counterexamples