cc = gcc

fingerbang: fingerbang.l fingerbang.y 
	bison -d fingerbang.y
	flex fingerbang.l
	cc -o $@ Node.c fingerbang.tab.c lex.yy.c -lfl

clean:
	rm fingerbang.tab.c fingerbang.tab.h lex.yy.c fingerbang