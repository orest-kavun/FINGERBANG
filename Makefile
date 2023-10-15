cc = gcc

cry: cry.l cry.y 
	bison -d cry.y
	flex cry.l
	cc -o $@ Node.c cry.tab.c lex.yy.c -lfl

clean:
	rm cry.tab.c cry.tab.h lex.yy.c cry