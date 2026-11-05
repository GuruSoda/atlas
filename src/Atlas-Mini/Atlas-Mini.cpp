#include <iostream>
#include <argtable/argtable2.h>

#include <GuruHttp/Guruhttp.hpp>
#include <GuruHttp/GuruhttpServidor.hpp>
#include <GuruHttp/GuruhttpInterface.hpp>
#include <GuruHttp/GuruhttpSitioStats.hpp>
#include <GuruSocket/GuruServidorTCP.hpp>
#include <GuruDirectorio.hpp>
#include <GuruSocket/GuruSocket.hpp>
// #include <regex>

#ifdef __GURUWIN32__
	#include <Winsvc.h>
#elif defined __GURULINUX__
	#include <signal.h>
    #include <unistd.h>
#endif

void cambiar_directorio_apps();

#ifdef __GURUWIN32__
	BOOL	Control_Consola(DWORD requerimiento);
	HANDLE	Corriendo;
#elif defined __GURULINUX__
	void 	Control_Consola(int);
	sem_t	Corriendo;
#endif
/*
class test: public GuruSocketServicio {
public:
	test() {};

	void main(void) {

		ostringstream oss;		auto u = (float)rand() / (RAND_MAX + 1) * (2000 - 100) + 100;

		Sleep(static_cast<DWORD>(u));

		oss << "Espere: " << static_cast<DWORD>(u) << "\r\n" << endl;

		enviar << oss.str();

	};

};
*/

//////////////////////////////////////////////////////////////////////
// Para agregar a Atlas-mini en el menu desplegable de windows:
// Escribir: d:\Proyectos\Desarrollo\Atlas\bin\Atlas-Mini.exe --puerto=8008 --localdir="%1"
// En: HKEY_CLASSES_ROOT\Directory\shell\atlas-mini\command, (Predeterminado)
//////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
/*
	pair<uint64_t, uint64_t> rango;

	rango = GuruhttpAlgo::RangeDecode(string("bytes=10-10, 40-50"));
	std::cout << "bytes=10-10, 40-50 -> " << rango.first << ":" << rango.second << endl;

	rango = GuruhttpAlgo::RangeDecode(string("bytes="));
	std::cout << "bytes= -> " << rango.first << ":" << rango.second << endl;

	rango = GuruhttpAlgo::RangeDecode(string("bytes=0-"));
	std::cout << "bytes=0- -> " << rango.first << ":" << rango.second << endl;

	rango = GuruhttpAlgo::RangeDecode(string("bytes=500-768"));
	std::cout << "bytes=500-768 -> " << rango.first << ":" << rango.second << endl;

	rango = GuruhttpAlgo::RangeDecode(string("bytes=500-"));
	std::cout << "bytes=500- -> " << rango.first << ":" << rango.second << endl;

	rango = GuruhttpAlgo::RangeDecode(string("bytes=-500"));
	std::cout << "bytes=-500 -> " << rango.first << ":" << rango.second << endl;

	return 0;
*/
#if defined __PRUEBA_CONECTAR__
//	cout << esIP("1.10.10.30a") << endl;

	size_t inicio = time(NULL);
	try {
//		inicializar_GuruSocket();
//		struct in_addr ia = {0};
//		int salida = inet_aton("192.168.1.1", &ia);

//		int salida = inet_addr("192.168.1.55551");

//		struct hostent*		hosts;

		//	Verificar si la variable servidor tiene un nombre
//		hosts = gethostbyname("192000000.ii.oo");

//		cout << GetLastError();

		FabricaSocketConectar(string("www.planetagurussss.com.ar"), 80);

	} catch (GuruSocketException& e) {
		cout << "Error en conectar: " << e.what() << endl;
	}

	cout << "Total:" << time(NULL)-inicio << endl;
	cout << "Fin" << endl;

	return 0;
#endif

//	try {
//	string line("c:\\programas\\cemasmas\\");
//	std::regex e("cema");
//	if (std::regex_search(line, e)) cout << "Bien!" << endl;
//	} catch (){}
	/*
	GuruBuffer buf;
	char* info = "Soda Stereo";

	buf.reservar(120);
	buf.asignar(reinterpret_cast<uint8_t*>(info), strlen("Soda Stereo"));

	for (GuruBuffer::iterator it=buf.begin();it!=buf.end();++it) {
		cout << *it;
	}

	cout << endl;
	*/

	basic_GuruBuffer<char> a(1025);

	a << 'a';
	a << 'b';
	a << 'c';
	a << 'd';
	a << 'e';


	cout << *a.begin() << endl;

/*
	ifstream archivo("y:\\Descargas\\Computadoras-Crudo.csv");

	GuruTokenEx t;
	ostringstream a;
	while (!archivo.eof()) {
		a << archivo;
		cout << a.str() << endl;
	}

	archivo.close();
*/
	srand( (unsigned)time( NULL ) );
//	cout << sizeof(GuruhttpConf) << endl;

	struct arg_lit* opt_help		= arg_lit0("h","help", "Muestra la ayuda.");
	struct arg_lit* opt_verbose		= arg_lit0("v","verbose", "Muestra informacion por pantalla.");
//	struct arg_int* opt_tiempo		= arg_int0(NULL,"ejecucion", "<n>", "Tiempo en que se ejecutara el web server.");
	struct arg_str* opt_interfaz	= arg_str0("i","interfaz","<IP>", "Interfaz a escuchar (default:0.0.0.0)");
	struct arg_int* opt_puerto		= arg_int0("p","puerto", "<n>", "Puerto que escucha el servidor (default:80)");
	struct arg_int* opt_velocidad	= arg_int0("v","velocidad", "<n>", "Ancho de banda a utilizar en Kbytes (default:0)");

	struct arg_lit* opt_nolistar	= arg_lit0("n","nolistar", "Si lista o no el directorio (default: listar).");
	struct arg_str* opt_dirlocal	= arg_str0("l","localdir","<dir local>", "Directorio local a exportar (default:.)");
	struct arg_str* opt_dirvirtual	= arg_str0("d","virtualdir","<dir virtual>", "Directorio virtual para ingresar (default:/)");
	struct arg_str* opt_host		= arg_str0(NULL,"host","<nombre>", "Nombre del host (default: none)");
	struct arg_str* opt_busqueda	= arg_str0("b","busqueda","<lista archivos>", "Archivos a buscar (default: index.html)");

	struct arg_end* end				= arg_end(20);

	void* argtable[]				= {opt_help,opt_verbose,opt_interfaz,opt_puerto,opt_velocidad,opt_nolistar,opt_dirlocal,opt_dirvirtual,opt_host,opt_busqueda,end};
	int nerrors;

//	opt_tiempo->ival[0] = 0;
	opt_interfaz->sval[0] = "0.0.0.0";
	opt_puerto->ival[0] = 80;
	opt_velocidad->ival[0] = 0;

	nerrors = arg_parse(argc,argv,argtable);

	if (nerrors > 0) {
		arg_print_glossary(stdout,argtable,"  %-25s %s\n");
		return 1;
	}

	if (opt_help->count > 0) {
		arg_print_glossary(stdout,argtable,"  %-25s %s\n");
		return 0;
	}

	GuruhttpDirVirtual	stat;
	stat.sitio("/stats/");
	stat.agregarHost("*");
	stat.interfaz( new GuruhttpSitio<stats>());

	GuruhttpDirVirtual	dir;
	dir.sitio("/");
	dir.agregarBusqueda("index.html");
	dir.agregarHost("*");
	dir.listar(true);
	dir.dirApps(GuruDirectorio::directorio_actual());

//	GuruhttpSitio<GuruhttpServidor> b;
	dir.interfaz(new GuruhttpSitio<GuruhttpServidor>());

//	if (opt_tiempo->count > 0) {}

	if (opt_nolistar->count > 0) dir.listar(false);

	if (opt_dirlocal->count > 0) dir.dirApps(opt_dirlocal->sval[0]);

	if (opt_dirvirtual->count > 0) dir.sitio(opt_dirvirtual->sval[0]);

	if (opt_verbose->count > 0) dir.agregarLog("+", "%fecha822% | %status% | %ip_request% | %request% | %request.User-Agent%");

	if (opt_host->count > 0) {
		GuruToken tk(" ,;|");
		vector<string> tokens;

		if (!tk.extraer(opt_host->sval[0], tokens).empty())
			dir.agregarHost(tokens);
	}

	if (opt_busqueda->count > 0) {
		GuruToken tk(" ,;|");
		vector<string> tokens;

		if (!tk.extraer(opt_busqueda->sval[0], tokens).empty())
			dir.agregarBusqueda(tokens);
	}

	dir.velocidad(opt_velocidad->ival[0]*1024);

	cambiar_directorio_apps();

#ifdef __GURUWIN32__
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)Control_Consola, true);
	Corriendo=CreateSemaphore(NULL, 0, 2, NULL);
#elif defined __GURULINUX__
	signal(SIGPIPE, SIG_IGN);
	signal(SIGTERM, Control_Consola);
	signal(SIGQUIT, Control_Consola);
	signal(SIGINT, Control_Consola);

	sem_init(&Corriendo, 0, 0);
#endif

	GuruServidorTCP<Guruhttp> w(opt_puerto->ival[0], opt_interfaz->sval[0]);

	stat.extra_ptr(static_cast<void*>(&w));

	try {
//		GuruServidorTCP<test> x(8888);

		GuruSingleton<GuruhttpConfig>::instancia()->nuevo_sitio(dir);
		GuruSingleton<GuruhttpConfig>::instancia()->nuevo_sitio(stat);

		inicializar_GuruSocket();

		w.iniciar();
//		x.iniciar();

		arg_freetable(argtable,sizeof(argtable)/sizeof(argtable[0]));

	#ifdef __GURUWIN32__
		WaitForSingleObject(Corriendo, INFINITE);
	#elif defined __GURULINUX__
		sem_wait(&Corriendo);
	#endif

		w.detener();
//		x.detener();

		GuruSingleton<GuruhttpLog>::instancia()->terminar();

	#ifdef __GURUWIN32__
		CloseHandle(Corriendo);
	#elif defined __GURULINUX__
		sem_destroy(&Corriendo);
	#endif
	} catch (GuruSocketServidorException& e) {
		cout << "ERROR:" << e.what() << endl;
	} catch (...) {
		cout << "Hubo una excepcion no atrapada!!!" << endl;
	}

	limpiar_GuruSocket();

	cout << "Finalizando ..." << endl;
	return 0;
}

#ifdef __GURUWIN32__
BOOL Control_Consola(DWORD requerimiento)
#elif defined __GURULINUX__
void Control_Consola(int requerimiento)
#endif
{
#ifdef __GURUWIN32__
	switch( requerimiento ) { 
		case CTRL_C_EVENT: cout << "Cancelado por CTRL-C ..." << endl;
		case CTRL_CLOSE_EVENT: 
		case CTRL_BREAK_EVENT: 
		case CTRL_LOGOFF_EVENT: 
		case CTRL_SHUTDOWN_EVENT: 
							break;
	}

	ReleaseSemaphore(Corriendo, 1, NULL);
	return TRUE;
#elif defined __GURULINUX__
	sem_post(&Corriendo);
#endif
}

void cambiar_directorio_apps()
{
	char exe[MAX_PATH];

#ifdef __GURUWIN32__
	if (!GetModuleFileName(NULL, exe, MAX_PATH)) return ;
#elif defined __GURULINUX__
	if (!readlink("/proc/self/exe", exe, MAX_PATH)) return ;
#endif

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(exe, drive, dir, fname, ext);

	string tmp;

	tmp = drive;
	tmp += dir;

#ifdef __GURUWIN32__
	SetCurrentDirectory(tmp.c_str());
#elif defined __GURULINUX__
	int a = chdir(tmp.c_str());
#endif
}
