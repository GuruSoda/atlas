#include <GuruSocket/GuruSocket.hpp>
#include <GuruSocket/GuruServidorTCP.hpp>
#include <GuruHttp/Guruhttp.hpp>
#include <GuruHttp/GuruhttpServidor.hpp>

#include <wx/wx.h>

#include "SujetoAtlasMini.h"

#include <GuruDirectorio.hpp>
#include <GuruLog.hpp>

#include <jsoncpp/json.h>


// Modificar UI_MainFrame por el nombre de la clase generada por wxFormbuilder dentro de .h
class ui : public SujetoAtlasUI {

	bool cargar_configuracion_desde_archivo(const string& archivo) {
		std::ifstream	archivoconf(archivo.c_str());
		Json::Reader	lector;

		if (!lector.parse(archivoconf, config, false)) {
			std::cout << lector.getFormattedErrorMessages() << endl;
			return false;
		} else {
			this->SetTitle(this->GetTitle() + " - " + archivo);
		}

		return true;
	}

	bool guardar_configuracion_en_archivo(const string& archivo) {
		Json::Value c;

		c["Dominio"] = dlg_dominio->GetLineText(0).ToStdString();
		c["Puerto"] = dlg_puerto->GetLineText(0).ToStdString();
		c["DirVirtual"] = dlg_dirvirtual->GetLineText(0).ToStdString();
		c["Directorio"] = dlg_directorio_app->GetPath().ToStdString();
		c["Busquda"] = dlg_opciones_busqueda->GetSelection();
		c["Archivos"] = dlg_archivo_cargar->GetLineText(0).ToStdString();
		c["LogHabilitado"] = dlg_log_habilitado->GetValue() ? 1 : 0;
		c["FormatoLog"] = dlg_formato_log->GetLineText(0).ToStdString();
		c["ArchoBandaHabilitado"] = dlg_ancho_banda_habilitado->GetValue() ? 1 : 0;
		c["KBytes"] = dlg_kbytes->GetValue();

		ofstream s(archivo);

		s << c.toStyledString();

		s.close();

		this->SetTitle(this->GetTitle() + " - " + archivo);

		return true;
	}

protected:
	Json::Value					config;
	string						archivo_conf;
	GuruServidorTCP<Guruhttp>	http;

	string						titulo;
public:
	ui(wxWindow* parent) :SujetoAtlasUI(parent) {
		dlg_barra_herramientas->EnableTool(dlg_herramienta_detener->GetId(), false);

		titulo = this->GetTitle();

	//	dlg_directorio_app->SetPath(GuruDirectorio::directorio_actual());

		dlg_directorio_app->SetPath("/opt/atlas/www/");

		dlg_opciones_busqueda->SetSelection(1);
		
		dlg_archivo_cargar->Enable(false);

		std::list<string> i;
//		interfaces(i);

		for (std::list<string>::iterator it=i.begin(), itend=i.end();it!=itend;++it) dlg_interfaces->Append(*it);
		cout << "Despues de Interfaces" << endl;
	}

	void onCargar(wxCommandEvent& event) {
		wxFileDialog cargarConfiguracion(this, _("Abrir Archivo .atlas"), "", "", "Atlas files (*.atlas)|*.atlas", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

		if (cargarConfiguracion.ShowModal() == wxID_OK) {
			cargar_configuracion_desde_archivo(cargarConfiguracion.GetFilename().ToStdString());
			archivo_conf = cargarConfiguracion.GetFilename().ToStdString();
		}
	}

	void onGrabar(wxCommandEvent& event) {
		if (archivo_conf.empty()) {
			wxFileDialog guardarConfiguracion(this, _("Guardar Atlas file"), "", "", "Atlas files (*.atlas)|*.atlas", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

			if (guardarConfiguracion.ShowModal() == wxID_OK) {
				archivo_conf  = guardarConfiguracion.GetFilename().ToStdString();
			}
		} else {
			guardar_configuracion_en_archivo(archivo_conf);
		}
	}

	void onGrabarComo(wxCommandEvent& event) {
		wxFileDialog guardarConfiguracion(this, _("Guardar Atlas file"), "", "", "Atlas files (*.atlas)|*.atlas", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		if (guardarConfiguracion.ShowModal() == wxID_OK) {
			guardar_configuracion_en_archivo(guardarConfiguracion.GetPath().ToStdString());
			archivo_conf = guardarConfiguracion.GetFilename().ToStdString();
		}
	}

	void onSalir(wxCommandEvent& event) {
		this->Close();
	}

	void onIniciar(wxCommandEvent& event) {
		try {
			http.agregar_escucha(atoi(dlg_puerto->GetLineText(0).ToStdString().c_str()), dlg_interfaces->GetStringSelection().ToStdString());

			GuruhttpDirVirtual	dir;
			dir.sitio("/");
			dir.agregarBusqueda(dlg_archivo_cargar->GetLineText(0).ToStdString());
			dir.agregarHost(dlg_dominio->GetLineText(0).ToStdString());
			dir.listar(true);

			dir.dirApps(dlg_directorio_app->GetPath().ToStdString());

			dir.interfaz(new GuruhttpSitio<GuruhttpServidor>());

			GuruSingleton<GuruhttpConfig>::instancia()->nuevo_sitio(dir);

			dlg_barra_herramientas->EnableTool(dlg_herramienta_arrancar->GetId(), false);
			dlg_barra_herramientas->EnableTool(dlg_herramienta_detener->GetId(), true);

			http.iniciar();

			deshabilitar_controles();
		} catch (GuruhttpExcepcion& e) {
			wxMessageBox("Servidor HTTP Error: " + wxString(e.what()));
		} catch (GuruSocketServidorException& e) {
			wxMessageBox("Servidor Socket Error:" + wxString(e.what()));
		} catch (std::exception& e) {
			wxMessageBox("Error:" + wxString(e.what()));
		}
	}

	void onDetener(wxCommandEvent& event) {
		try {
			http.detener();

			GuruSingleton<GuruhttpConfig>::instancia()->clear();

			http.clear();

			dlg_barra_herramientas->EnableTool(dlg_herramienta_arrancar->GetId(), true);
			dlg_barra_herramientas->EnableTool(dlg_herramienta_detener->GetId(), false);

			habilitar_controles();
		} catch (GuruhttpExcepcion& e) {
			wxMessageBox(e.what());
		}
	}

	void onBusqueda(wxCommandEvent& event) {

		if (dlg_opciones_busqueda->GetSelection() == 1)
			dlg_archivo_cargar->Enable(false);
		else
			dlg_archivo_cargar->Enable(true);
	}

	void onLog(wxCommandEvent& event) {
		if (dlg_log_habilitado->IsChecked())
			dlg_formato_log->Enable(true);
		else 
			dlg_formato_log->Enable(false);
	}

	void onAnchoDeBanda(wxCommandEvent& event) {
		if (dlg_ancho_banda_habilitado->IsChecked())
			dlg_kbytes->Enable(true);
		else
			dlg_kbytes->Enable(false);
	}

	void onCambioURL(wxCommandEvent& event) {
		wxString link;

		link = "http://" + dlg_dominio->GetLineText(0) + ":" + dlg_puerto->GetLineText(0);
		
		if (!dlg_dirvirtual->GetLineText(0).IsEmpty()) 
			link += "/" + dlg_dirvirtual->GetLineText(0);

		dlg_hyperlink->SetURL(link);

		dlg_barraEstado->SetStatusText(link, 1);

//		dlg_hyperlink->Update();

//		this->TransferDataToWindow();
//		Refresh();

//		this->Update();

//		dlg_hyperlink->Refresh();

//		m_panel5->Layout();

//		dlg_hyperlink->Hide();
//		dlg_hyperlink->Show(false);
//		dlg_hyperlink->Show(true);
	}

	void habilitar_controles() {
		dlg_dominio->Enable(true);
		dlg_puerto->Enable(true);
		dlg_dirvirtual->Enable(true);
		dlg_directorio_app->Enable(true);
		dlg_opciones_busqueda->Enable(true);
		dlg_archivo_cargar->Enable(true);
		dlg_interfaces->Enable(true);
		dlg_log_habilitado->Enable(true);
		dlg_ancho_banda_habilitado->Enable(true);
		dlg_usuario->Enable(true);
		dlg_clave->Enable(true);
	}

	void deshabilitar_controles() {
		dlg_dominio->Enable(false);
		dlg_puerto->Enable(false);
		dlg_dirvirtual->Enable(false);
		dlg_directorio_app->Enable(false);
		dlg_opciones_busqueda->Enable(false);
		dlg_archivo_cargar->Enable(false);
		dlg_interfaces->Enable(false);
		dlg_log_habilitado->Enable(false);
		dlg_ancho_banda_habilitado->Enable(false);
		dlg_usuario->Enable(false);
		dlg_clave->Enable(false);

	}
};

class wxWidgetsApp : public wxApp
{
public:
	wxWidgetsApp() { GuruLog::init(GuruLog::level_debug, cout); };

	virtual ~wxWidgetsApp() { limpiar_GuruSocket(); };

	virtual bool OnInit() {
		if (!wxApp::OnInit()) return false;

		inicializar_GuruSocket();

		ui* dialog = new ui((wxWindow*)NULL);

		dialog->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(wxWidgetsApp::OnClose), NULL, this);

		dialog->Show();

		SetTopWindow(dialog);

		return true;
	}

	void OnClose(wxCloseEvent& event) {
		ExitMainLoop();
	}
};

DECLARE_APP(wxWidgetsApp)

IMPLEMENT_APP(wxWidgetsApp)
