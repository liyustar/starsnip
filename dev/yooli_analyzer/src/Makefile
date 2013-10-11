
OPENSSLINC = /usr/local/ssl/include
OPENSSLLIB = /usr/local/ssl/lib
OPENSSLLINKS =  -lssl -lcrypto -ldl

CPPFLAGS = -I${OPENSSLINC} -g
CPPLINKS = ${OPENSSLLINKS}

OBJ = yooli_analyzer.o \
	  lyxUrl.o \
	  lyxSocket.o \
	  lyxHttp.o \
	  lyxSslSocket.o \
	  lyxCookie.o \
	  lyxCookieStorage.o

all: yooli_analyzer

yooli_analyzer: ${OBJ}
	g++ -L${OPENSSLLIB} -o $@ $^ ${CPPLINKS}

lyxUrl.o: lyxUrl.h
lyxHttp.o: lyxHttp.h lyxUrl.h lyxSocket.h lyxSslSocket.h lyxCookie.h lyxCookieStorage.h
lyxSocket.o: lyxSocket.h
lyxSslSocket.o: lyxSslSocket.h lyxSocket.h
lyxCookie.o: lyxCookie.h
lyxCookieStorage.o: lyxCookieStorage.h lyxCookie.h

.PHONY: clean
clean:
	-rm *.o yooli_analyzer


