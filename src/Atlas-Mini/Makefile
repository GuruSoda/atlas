.SUFFIXES = .c .cpp

# CXXFLAGS+=-march=native
BOOST=../../../boost
LIBRERIAS=../../../Librerias
SALIDA_EJECUTABLE=../../bin
MIS_LINKS=-lpthread -ldl
MIS_DEFINE=-D__CON_LINEA_ERROR__ -include config.h -DGURUHTTP_LISTAR 

# Para compilar en 64 sobre 32, instalar el paquete g++-multilib
ifeq ($(BITS),64)
    CXXFLAGS+=-m64
else ifeq ($(BITS),32)
        CXXFLAGS+=-m32
endif

ifeq (${DEBUG},1)
 CXXFLAGS+=-ggdb -g3
else 
 CXXFLAGS+=-s -O2
endif

CFLAGS=$(CXXFLAGS)

RAIZ=.
INCLUDED=${BOOST}/ \
	${LIBRERIAS}/ \
	${LIBRERIAS}/argtable/ \
	${LIBRERIAS}/GuruSocket/ \
	${LIBRERIAS}/GuruHttp/ \
	${LIBRERIAS}/GuruCompat/ \
	${RAIZ}/../libs

PARAM_INCLUDE:=$(addprefix "-I", ${INCLUDED})

VPATH=${INCLUDED}

DIR_OBJETOS = ../build/linux/

MIS_LIBS := gettickcount.o xtoa.o 
OBJETOS += $(addprefix ${DIR_OBJETOS}, ${MIS_LIBS})

ARGTABLE := argtable2.o arg_dbl.o arg_end.o arg_file.o arg_int.o arg_lit.o \
arg_rem.o arg_str.o getopt.o getopt1.o
OBJETOS += $(addprefix ${DIR_OBJETOS}, ${ARGTABLE})

PROGRAMA := Atlas-Mini.o
OBJETOS += $(addprefix ${DIR_OBJETOS}, ${PROGRAMA})

atlas-mini: crear_directorios Makefile ${OBJETOS}
	@$(CXX) ${CXXFLAGS} $(LDFLAGS) -o $(SALIDA_EJECUTABLE)/$@ $(OBJETOS) ${MIS_LINKS}
	@echo "Todo terminado????"

${DIR_OBJETOS}%.o: %.cpp
	@echo "Compilando C++ $? -> $@"
	@${CXX} -O2 -x c++ -pipe ${CXXFLAGS} ${MIS_DEFINE} ${PARAM_INCLUDE} -c $? -o $@

${DIR_OBJETOS}%.o:%.c
	@echo "Compilando C $? -> $@"
	@${CC} -O2 -pipe ${CFLAGS} ${PARAM_INCLUDE} ${MIS_DEFINE} -c $? -o $@

deb: atlas-mini
	@$(eval DIR_TEMP:=$(shell mktemp -du --suffix=atlas))
	@$(eval RELEASE:=$(shell date +%Y%m%d.%H%M))
	@$(eval VERSION:=$(shell cat debian/control | grep Version | cut -d ':' -f 2 | tr -d '[:blank:]'))
	@mkdir -p ${DIR_TEMP}/usr/local/bin
	@cp ../../bin/atlas-mini ${DIR_TEMP}/usr/local/bin/
	@cp ../../bin/atlas.css ${DIR_TEMP}/usr/local/bin/
	@cp ../../bin/atlas.mime ${DIR_TEMP}/usr/local/bin/
	@mkdir -p ${DIR_TEMP}/DEBIAN
	@cp debian/control ${DIR_TEMP}/DEBIAN/
	@dpkg -b ${DIR_TEMP} ../../atlas-mini-${VERSION}-${RELEASE}_i386.deb
	@rm -rf ${DIR_TEMP}

clean:
	@rm -f ${OBJETOS}

crear_directorios:
	@mkdir -p ${DIR_OBJETOS}

compilar:
	@echo ${VPATH} ${OBJETOS}

rebuild: clean atlas-mini
	@echo Reconstruccion finalizada.

install:
	@cp ../../bin/atlas-mini /usr/local/bin/
	@cp ../../bin/atlas.css /usr/local/bin/
	@cp ../../bin/atlas.mime /usr/local/bin/

