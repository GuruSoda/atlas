///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SUJETOATLASMINI_H__
#define __SUJETOATLASMINI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SujetoAtlasUI
///////////////////////////////////////////////////////////////////////////////
class SujetoAtlasUI : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* dlg_barraEstado;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu3;
		wxToolBar* dlg_barra_herramientas;
		wxToolBarToolBase* dlg_herramienta_salir; 
		wxToolBarToolBase* dlg_herramienta_cargar; 
		wxToolBarToolBase* dlg_herramienta_guardar; 
		wxToolBarToolBase* dlg_herramienta_guardarcomo; 
		wxToolBarToolBase* dlg_herramienta_arrancar; 
		wxToolBarToolBase* dlg_herramienta_detener; 
		wxPanel* m_panel1;
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxStaticText* m_staticText1;
		wxTextCtrl* dlg_dominio;
		wxStaticText* m_staticText2;
		wxTextCtrl* dlg_puerto;
		wxStaticText* m_staticText3;
		wxTextCtrl* dlg_dirvirtual;
		wxPanel* m_panel5;
		wxHyperlinkCtrl* dlg_hyperlink;
		wxDirPickerCtrl* dlg_directorio_app;
		wxRadioBox* dlg_opciones_busqueda;
		wxTextCtrl* dlg_archivo_cargar;
		wxPanel* m_panel3;
		wxCheckBox* dlg_log_habilitado;
		wxTextCtrl* dlg_formato_log;
		wxListBox* dlg_salida_log;
		wxButton* m_button1;
		wxPanel* m_panel4;
		wxCheckBox* dlg_ancho_banda_habilitado;
		wxSpinCtrl* dlg_kbytes;
		wxStaticText* m_staticText4;
		wxComboBox* dlg_interfaces;
		wxStaticText* m_staticText5;
		wxTextCtrl* dlg_usuario;
		wxStaticText* m_staticText6;
		wxTextCtrl* dlg_clave;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onCargar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGrabar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGrabarComo( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSalir( wxCommandEvent& event ) { event.Skip(); }
		virtual void onIniciar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDetener( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCambioURL( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBusqueda( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGuardarLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAnchoDeBanda( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SujetoAtlasUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sujeto Atlas Mini"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 591,357 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~SujetoAtlasUI();
	
};

#endif //__SUJETOATLASMINI_H__
