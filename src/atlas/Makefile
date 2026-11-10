.SUFFIXES = .c .cpp

NOMBRE_EJECUTABLE=atlas
BOOST=../../../boost
LIBRERIAS=../../../Librerias
DIR_OBJETOS = ../build/linux/${NOMBRE_EJECUTABLE}/
SALIDA_EJECUTABLE=../../bin
MIS_LINKS=-lpthread -ldl
MIS_DEFINE=-DGURUHTTP_LISTAR -DGURUHTTP_JSON -DGURULOG_CPP

# Para compilar en 64 sobre 32, instalar el paquete g++-multilib
ifeq ($(BITS),64)
    CXXFLAGS+=-m64
else ifeq ($(BITS),32)
        CXXFLAGS+=-m32
endif

ifeq (${DEBUG},1)
 CXXFLAGS+=-g -rdynamic
else
 CXXFLAGS+=-s -O2
endif

# mismos parametros para compilar C/C++
# CFLAGS=$(CXXFLAGS)

RAIZ=.
INCLUDED=${LIBRERIAS}/ \
	${LIBRERIAS}/GuruSocket/ \
	${LIBRERIAS}/GuruHttp/ \
	${LIBRERIAS}/GuruCompat/ \
	${LIBRERIAS}/jsoncpp/ \
	${RAIZ}/../libs

MIS_LIBS := GuruLog.o GuruSvc.o gettickcount.o GuruConfigV2.o GuruConfigLeer.o jsoncpp.o
OBJETOS += $(addprefix ${DIR_OBJETOS}, ${MIS_LIBS})

ifeq (${TEUSHEN},1)
	OBJ_TEUSHEN := sha1.o sha2.o sha4.o md5.o sqlite3.o 
	OBJETOS += $(addprefix ${DIR_OBJETOS}, ${OBJ_TEUSHEN})

	MIS_DEFINE += -DTEUSHEN_FULL

	INCLUDED += ${BOOST}/ ${LIBRERIAS}/polarssl/include ${LIBRERIAS}/polarssl/library ${LIBRERIAS}/sqlite
endif

ifeq (${ARM},1)
	BOOST_REGEX:=regex.o cpp_regex_traits.o posix_api.o icu.o regex_traits_defaults.o c_regex_traits.o regex_raw_buffer.o fileiter.o usinstances.o instances.o static_mutex.o
	OBJETOS += $(addprefix ${DIR_OBJETOS}, ${BOOST_REGEX})

	MIS_DEFINE+= -DBOOST_ALL_NO_LIB

	INCLUDED += ${BOOST}/ ${BOOST}/libs/regex/src/
else
	CXXFLAGS+= -std=c++11
endif

PARAM_INCLUDE:=$(addprefix "-I", ${INCLUDED})
VPATH=${INCLUDED}

PROGRAMA := main.o
OBJETOS += $(addprefix ${DIR_OBJETOS}, ${PROGRAMA})

${NOMBRE_EJECUTABLE}: crear_directorios Makefile ${OBJETOS}
	@$(CXX) ${CXXFLAGS} $(LDFLAGS) -o $(SALIDA_EJECUTABLE)/$@ $(OBJETOS) ${MIS_LINKS}
	@echo "Todo terminado????"

${DIR_OBJETOS}%.o: %.cpp
	@echo "Compilando C++ $? -> $@"
	@${CXX} -O2 -x c++ -pipe ${CXXFLAGS} ${MIS_DEFINE} ${PARAM_INCLUDE} -c $? -o $@

${DIR_OBJETOS}%.o:%.c
	@echo "Compilando C $? -> $@"
	@${CC} -O2 -s -pipe ${CFLAGS} ${PARAM_INCLUDE} ${MIS_DEFINE} -c $? -o $@

clean:
	@rm -f ${OBJETOS}

crear_directorios:
	@mkdir -p ${DIR_OBJETOS}

compilar:
	@echo ${VPATH} ${OBJETOS}

envdeb:
	@$(eval DST:=/usr/local)

envopt: 
	@$(eval DST:=/opt/atlas)

makedeb: atlas 
	@$(eval DIR_TEMP:=$(shell mktemp -du --suffix=atlas))
	@$(eval RELEASE:=$(shell date +%Y%m%d.%H%M))
	@$(eval VERSION:=$(shell cat debian/control | grep Version | cut -d ':' -f 2 | tr -d '[:blank:]'))
	@mkdir -p ${DIR_TEMP}${DST}/bin
	@mkdir -p ${DIR_TEMP}${DST}/sitios
	@mkdir -p ${DIR_TEMP}${DST}/log
	@mkdir -p ${DIR_TEMP}/DEBIAN
	@mkdir -p ${DIR_TEMP}/etc/init.d
	@cp ../../bin/atlas ${DIR_TEMP}${DST}/bin
	@cp ../../bin/atlas.css ${DIR_TEMP}${DST}/bin
	@cp ../../bin/atlas.mime ${DIR_TEMP}${DST}/bin
	@cp ../../bin/atlas.init ${DIR_TEMP}/etc/init.d/atlas
	@sed 's/^Version:\ [0-9]\..*/Version: ${VERSION}-${RELEASE}/' debian/control > ${DIR_TEMP}/DEBIAN/control 
	@dpkg -b ${DIR_TEMP} ../../atlas-${VERSION}-${RELEASE}_i386.deb
	@rm -rf ${DIR_TEMP}

deb: envdeb makedeb
	@echo "Todo Listo."

debopt: envopt makedeb
	@echo "Todo Listo."

