CC = clang
archiver = ar
linker = ld
headers = include/
libOut = lib/
src = src/
srcVM = VM/
srcInterpreter = interpreter/
out = build/


.PHONY: init static shared clean

init:
	mkdir $(out)tmp/
	mkdir $(out)lib/
	mkdir $(out)include/
	cp -r $(headers) $(out)

static:
# 	libfunctions
	$(CC) -c -fPIC $(src)functions.c -o $(out)tmp/functions.o -Wall -Wextra
	$(archiver) rcs $(out)lib/libfunctions.a $(out)tmp/functions.o
#	libVM
	$(CC) -c -fPIC $(src)$(srcVM)VM.c -o $(out)tmp/VM.o -Wall -Wextra -I$(out)include
	$(linker) -r $(out)tmp/VM.o -L$(out)lib -lfunctions -o $(out)tmp/VM.linked.o
	$(archiver) rcs $(out)lib/libVM.a $(out)tmp/VM.linked.o

	bison -o $(out)tmp/plang.c -d $(src)$(srcInterpreter)parse.y
	mv $(out)tmp/plang.h $(out)include/plang.h

	flex -o $(out)tmp/lex.yy.c $(src)$(srcInterpreter)lex.l
	$(CC) $(src)$(srcInterpreter)main.c $(out)tmp/plang.c $(out)tmp/lex.yy.c -o $(out)plang -Wl,--no-whole-archive -I$(out)include -L$(out)lib -lfunctions -lVM -Wl,--no-whole-archive -Wl,-rpath=$(out)lib -Wall -Wextra
shared:
	$(CC) -c -fPIC $(src)functions.c -o $(out)tmp/functions.o -Wall -Wextra
	$(CC) -shared -o $(out)lib/libfunctions.so $(out)tmp/functions.o -Wall -Wextra

clean:
	rm -r $(out)
	mkdir $(out)
