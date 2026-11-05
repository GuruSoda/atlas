#include <GuruCompat.h>
#include <GuruSvc_algo.hpp>
#include <string>
#include <GuruCompat/splitpath.hpp>
#include <GuruSingleton.hpp>
#include <GuruSvc.h>
#include <GuruHConsola.hpp>
#include <GuruSocket/GuruServidorTCP.hpp>
#include <GuruHttp/Guruhttp.hpp>
#include <GuruHttp/GuruhttpServidor.hpp>
#include <GuruHttp/GuruhttpConfig_algo.hpp>
#include <GuruHttp/GuruhttpSitioStats.hpp>
#include <GuruHttp/GuruhttpConfigSite.hpp>

// #include <GuruPool.hpp>
// #include <GuruThreadPool.hpp>
#include <GuruBuffer_algo.hpp>

#if defined __GURULINUX__
#include <execinfo.h>
#include <unistd.h>
#endif

// #define __PRUEBA_TEUSHEN__

#if defined __PRUEBA_TEUSHEN__
#include <GuruInterprete/TeushenEx.hpp>
#endif

class AtlasSvc: public GuruSvc
{
public:
	AtlasSvc(const string& nombre_interno, const string& nombre_externo, bool MsgOnDll = false)
		:GuruSvc(nombre_interno, nombre_externo, MsgOnDll) {};
	virtual ~AtlasSvc(void) {};

	void ParametrosServicio(int cant,char* parametros[]) {}

	void Start() {

		ios_base::sync_with_stdio();
		vector<GuruServidorTCP<Guruhttp>*> instancias;

		try{
			std::string a(GuruDirectorio::directorio_actual());

			GuruHttpConfigAlgo::cargar_conf_http(string("atlas.conf"));

			vector<GuruhttpConf*> configuraciones;
			GuruSingleton<GuruhttpConfig>::instancia()->configuraciones(configuraciones);

			for (vector<GuruhttpConf*>::iterator it=configuraciones.begin();it!=configuraciones.end();++it) {
				GuruHttpConfigAlgo::cargar_sitios((*it)->sitios());

				GuruServidorTCP<Guruhttp>* t = new GuruServidorTCP<Guruhttp>((*it)->puerto(),(*it)->interfaz());

				// sitio para ver los sitios configurados
				GuruhttpDirVirtual	sitios;

				sitios.sitio("/sitios/");
				sitios.agregarHost("*");
				sitios.interfaz(new GuruhttpSitio<GuruHttpConfigSite>());
				sitios.velocidad(0);
				sitios.extra_ptr(NULL);
				sitios.agregarAtributosExtra("Access-Control-Allow-Origin", "*");
				sitios.env("base", "Base de datos del M.A.M.E.");
				GuruSingleton<GuruhttpConfig>::instancia()->nuevo_sitio(sitios);

				// para el sitio de estadisticas
				GuruhttpDirVirtual	stat;
				stat.sitio("/stats/");
				stat.agregarHost("*");
				stat.interfaz( new GuruhttpSitio<stats>());
				stat.extra_ptr(static_cast<void*>(t));
				GuruSingleton<GuruhttpConfig>::instancia()->nuevo_sitio(stat);

				t->iniciar();

				instancias.push_back(t);
			}


			GURULOG_DEBUG("Todas las configuraciones cargadas y puertos escuchando...");
		#ifdef __GURUWIN32__
			WaitForSingleObject(Corriendo, INFINITE);
		#elif defined __GURULINUX__
			while (Ejecutando) sleep(1);
			syslog(LOG_INFO, "%s\n", "Deteniendo el Servicio.");
		#endif
		} catch (GuruSocketServidorException& e) {
			cerr << "GuruSocketException:" << e.what() << endl;
		}catch(std::exception& e) {
			cerr << "Error: " << e.what() << endl;
		#ifdef __GURUWIN32__
	//		const char* parametros[] = {"\n", e.what(), NULL};
	//		GuruSvc::EscribirEvento(EVENTLOG_ERROR_TYPE, SICODNS_ERROR_INESPERADO, parametros);
		#elif defined __GURULINUX__
			syslog(LOG_ERR, "%s\n", e.what());
		#endif
		}

		for (vector<GuruServidorTCP<Guruhttp>*>::iterator it=instancias.begin();it!=instancias.end();++it) {
			(*it)->detener();
			delete *it;
		}

		GuruSingleton<GuruhttpLog>::instancia()->terminar();
	}

	bool Control_Consola(::uint32_t requerimiento) {
		cout << "Cancelado por CTRL-C ..." << endl;
	#ifdef __GURUWIN32__
		SetEvent(Corriendo);
	#endif
		return true;
	}
};

void cambiar_directorio_apps(const char* ruta)
{
	string tmp;

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(ruta, drive, dir, fname, ext );

	tmp = drive;
	tmp += dir;

#ifdef __GURUWIN32__
	SetCurrentDirectory(tmp.c_str());
#elif defined __GURULINUX__
	int a=chdir(tmp.c_str());
	if (a) return ;
#endif
}

class nada {
public:
	nada() {};

	void main (const string& param) {
		cout << param << endl;
	};
};

	struct borrando {
		borrando() {cout << "Contruyendo borrando" << endl;};
		void operator () (::uint32_t a, string b) {
			cout << "a:" << a << " - b:" << b << endl;
		}
	};

#if defined __GURULINUX__
void atrapasenialusr1(int sig) {
  void *array[50];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 50);

  // print out all the frames to stderr
  backtrace_symbols_fd(array, size, STDOUT_FILENO);
}
#endif

// #include <GuruGuardaPtr.hpp>

int main(int cant, char* parametros[])
{
#if defined __PRUEBA_TEUSHEN__
	string prog;

	prog="println(\"Empezamos!\") sql.abrir(\"c:\\\\Desarrollo\\\\ArMame3\\\\bdd\\\\mame202.sqlite\") sql.ejecutar(\"select * from game\") while(sql.extraer()) { println(sql.columna(\"1\"), \" - \", sql.columna(\"3\"))}";

	teushenEx inter;

	std::istringstream ifs(prog);
	try {
		inter.interpretar(ifs, cout);
	} catch (GuruInterprete::Interprete::InterpreteException& e) {
		cout << "Error:" << e.what() << endl;
		} catch (...) { // para que quede atrapado cualquier otra excepcion.
		}

		return 0;
#endif


/*
	inicializar_GuruSocket();

	GuruServidorTCP<Guruhttp> t;

	t.conf_escuchar_agregar(80, "10.64.7.27");
	t.conf_escuchar_agregar(81, "192.168.133.1");
	t.conf_escuchar_agregar(82, "127.0.0.1");
	t.conf_escuchar_agregar(83, "0.0.0.0");

	t.iniciar();

	int a;

	cin >> a;

	limpiar_GuruSocket();
*/
/*
	GuruBufferAlgo::GuruBufferCharStream s;

	s << string("Profugos") << "\n";
	s << "Sobredosis" << 213122 << " - ";
	s << 1234;
	s << string("Temblor");
	s.FinChar();

	cout << s.BufferChar();
*/
/*
	GuruBufferChar buf;

	GuruBufferAlgo::archivo_buffer("c:\\Instaladores\\15 - 1.jpg", buf);

	GuruBufferAlgo::buffer_archivo(buf, "c:\\temp\\15 - 1.jpg");

	GuruBufferAlgo::buffer_archivo(buf.buf(), "c:\\temp\\15 - 1-1.jpg", buf.cantidad_data());
*/
/*
	std::string a("a");
	std::string b("b");
	std::string c("c");
	std::string d("d");
	std::string e("e");

	GuruGuardaPtr<int, std::string>::instancia().ptr(1, &a);
	GuruGuardaPtr<int, std::string>::instancia().ptr(2, &b);
	GuruGuardaPtr<int, std::string>::instancia().ptr(3, &c);
	GuruGuardaPtr<int, std::string>::instancia().ptr(4, &d);
	GuruGuardaPtr<int, std::string>::instancia().ptr(5, &e);

	std::cout << GuruGuardaPtr<int, std::string>::instancia().ptr(1) << std::endl;
*/

/*
	GuruThreadPool<nada> pool(50);

	pool.agregar(string("uno"));
	pool.agregar(string("dos"));
	pool.agregar(string("tres"));
	pool.agregar(string("cuatro"));
	pool.agregar(string("cinco"));
*/
/*
	GuruPool<string> pool(3);

	string* a = pool.obtener();
	string* b = pool.obtener();
	string* c = pool.obtener();
	string* d = pool.obtener();

	pool.liberar(d);
	pool.liberar(b);

	a = pool.obtener();

	return 0;
*/
/*
	GuruCacheLFU<uint32_t, string> cache(4);

	struct borrando borr;

	cache.insertar(1, "uno");
	cache.insertar(2, "dos");
	cache.insertar(3, "tres");
	cache.insertar(4, "cuatro");

	try {
		cout << cache(3) << endl;
		cout << cache(3) << endl;
		cout << cache(1) << endl;
		cout << cache(1) << endl;
		cout << cache(1) << endl;
		cout << cache(2) << endl;
		cout << cache(2) << endl;
		cout << cache(2) << endl;
		cout << cache(2) << endl;
		cout << cache(2) << endl;
		cout << cache(4) << endl;
		cout << cache(4) << endl;
		cout << cache(4) << endl;
		cache.insertar(5, "cinco", borr);
		cache.insertar(6, "seis", borr);
	} catch (GuruCacheException& e) {
		cout << e.what() << endl;
	}

	return 0;
*/
/*
	uint32_t ui=0;

	ui=192;
	ui<<=8;
	ui+=168;
	ui<<=8;
	ui+=1;
	ui<<=8;
	ui+=100;

	// GuruSocket:10.64.7.27 --> 453459978 | invertido --> 171968283

	cout << ui << endl;

	bitset<32> IP((long)ui);
	bitset<32> elbit2(2);

	cout << IP << endl;

	GuruTokenEx ip(".");

	ip.extraer("10.64.7.27/24");

	if (ip.tokens() == 4) {
		GuruTokenEx net("/");
		
		if (net.extraer(ip[3])==2) {
			cout << net[1] << endl;
		}
	}
*/
/*
	string q("asdifuhasidufhasdguaydgfaasdufhaishSSodaSodaStereoasdiufhasiduhfasdfa");
	string b("SodaStereo");

	string::iterator c=q.begin();

	while (c != q.end()) {
		if (*c == *b.begin()) {
			string::iterator it;
			string::iterator it_actual=c;

			for (it=b.begin();it!=b.end();++it,c++) {
				if (*it!=*c) break;
			}

			if (it == b.end()) { // encontre la cadena
				cout << "Existe" << endl;
			} else { // no es la cadena, retrocedo hasta el primero encontrado mas.
				c=it_actual;
			}
		}

		c++;
	}

	return 1;
*/

// GuruConfigLeer conf("c:\\temp\\atlas.conf");
// cout << conf.leer("puerto-80", "Interfaz", "0.0.0.0") << endl;

#if defined __GURULINUX__
	signal(SIGUSR1, atrapasenialusr1); 
#endif
	inicializar_GuruSocket();

//	cambiar_directorio_apps(parametros[0]);

	GuruHConsola guruout;

//	guruout.redirect_cout("system.out");
//	guruout.redirect_cerr("system.err");

	GuruLog::init(GuruLog::level_debug);

	GuruSvcAlgo::iniciar_servicio<AtlasSvc>("AtlasSvc","Atlas", cant, parametros, false);

	guruout.redirect_cout();
	guruout.redirect_cerr();

	limpiar_GuruSocket();

	return 0;
}
