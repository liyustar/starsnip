
OPENSSLINC = /usr/local/ssl/include
OPENSSLLIB = /usr/local/ssl/lib
OPENSSLLINKS =  -lssl -lcrypto -ldl

# CPPFLAGS = -I${OPENSSLINC}
CPPFLAGS = -L${OPENSSLLIB}
CPPLINKS = ${OPENSSLLINKS}

OBJ = yooli_analyzer.o lyxUrl.o lyxSocket.o lyxHttp.o lyxSslSocket.o

all: yooli_analyzer

yooli_analyzer: ${OBJ}
	g++ ${CPPFLAGS} -o $@ $^ ${CPPLINKS}

lyxUrl.o: lyxUrl.h
lyxHttp.o: lyxHttp.h lyxUrl.h lyxSocket.h lyxSslSocket.h
lyxSocket.o: lyxSocket.h
lyxSslSocket.o: lyxSslSocket.cpp lyxSslSocket.h lyxSocket.h
	g++ -I${OPENSSLINC} -c -o $@ $<

.PHONY: clean
clean:
	-rm *.o yooli_analyzer


