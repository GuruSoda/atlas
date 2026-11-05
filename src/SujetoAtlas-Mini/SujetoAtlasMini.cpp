///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SujetoAtlasMini.h"

///////////////////////////////////////////////////////////////////////////

SujetoAtlasUI::SujetoAtlasUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	dlg_barraEstado = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Cargar Sitio") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem1->SetBitmaps( wxArtProvider::GetBitmap( wxART_FILE_OPEN, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem1->SetBitmap( wxArtProvider::GetBitmap( wxART_FILE_OPEN, wxART_MENU ) );
	#endif
	m_menu1->Append( m_menuItem1 );
	
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Grabar Sitio") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem3->SetBitmaps( wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem3->SetBitmap( wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_MENU ) );
	#endif
	m_menu1->Append( m_menuItem3 );
	
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Grabar Sitio Como...") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem4->SetBitmaps( wxArtProvider::GetBitmap( wxART_FILE_SAVE_AS, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem4->SetBitmap( wxArtProvider::GetBitmap( wxART_FILE_SAVE_AS, wxART_MENU ) );
	#endif
	m_menu1->Append( m_menuItem4 );
	
	m_menu1->AppendSeparator();
	
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Salir") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem2->SetBitmaps( wxArtProvider::GetBitmap( wxART_QUIT, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem2->SetBitmap( wxArtProvider::GetBitmap( wxART_QUIT, wxART_MENU ) );
	#endif
	m_menu1->Append( m_menuItem2 );
	
	m_menubar1->Append( m_menu1, wxT("Menu") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Iniciar Sitio") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem5->SetBitmaps( wxArtProvider::GetBitmap( wxART_GO_FORWARD, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem5->SetBitmap( wxArtProvider::GetBitmap( wxART_GO_FORWARD, wxART_MENU ) );
	#endif
	m_menu3->Append( m_menuItem5 );
	
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Detener Sitio") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem6->SetBitmaps( wxArtProvider::GetBitmap( wxART_CROSS_MARK, wxART_MENU ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem6->SetBitmap( wxArtProvider::GetBitmap( wxART_CROSS_MARK, wxART_MENU ) );
	#endif
	m_menu3->Append( m_menuItem6 );
	
	m_menubar1->Append( m_menu3, wxT("Sitio") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	dlg_barra_herramientas = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY ); 
	dlg_herramienta_salir = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_QUIT, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Salir"), wxT("Sale de la aplicacion."), NULL ); 
	
	dlg_herramienta_cargar = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_FILE_OPEN, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Cargar"), wxT("Carga la configuracion de un Sitio desde un archivo."), NULL ); 
	
	dlg_herramienta_guardar = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Grabar"), wxT("Guarda el actual sitio HTTP."), NULL ); 
	
	dlg_herramienta_guardarcomo = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_FILE_SAVE_AS, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Grabar Como"), wxT("Guarda en otro archivo el actual Sitio HTTP."), NULL ); 
	
	dlg_barra_herramientas->AddSeparator(); 
	
	dlg_herramienta_arrancar = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_GO_FORWARD, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Arrancar Sitio"), wxT("Arranca el Servidor HTTP."), NULL ); 
	
	dlg_herramienta_detener = dlg_barra_herramientas->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_CROSS_MARK, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Detener Sitio"), wxT("Detiene el Servidor HTTP"), NULL ); 
	
	dlg_barra_herramientas->Realize(); 
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("URL") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("http://"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_dominio = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxT("localhost"), wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	bSizer6->Add( dlg_dominio, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_puerto = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxT("28275"), wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	dlg_puerto->SetMaxLength( 5 ); 
	bSizer6->Add( dlg_puerto, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_dirvirtual = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	bSizer6->Add( dlg_dirvirtual, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_panel5 = new wxPanel( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	dlg_hyperlink = new wxHyperlinkCtrl( m_panel5, wxID_ANY, wxT("http://localhost:28275"), wxT("http://localhost:28275"), wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE|wxHL_DEFAULT_STYLE );
	bSizer8->Add( dlg_hyperlink, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	m_panel5->SetSizer( bSizer8 );
	m_panel5->Layout();
	bSizer8->Fit( m_panel5 );
	sbSizer1->Add( m_panel5, 0, wxEXPAND, 5 );
	
	
	bSizer4->Add( sbSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Directorio Sitio") ), wxVERTICAL );
	
	dlg_directorio_app = new wxDirPickerCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	sbSizer4->Add( dlg_directorio_app, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer4->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Busqueda") ), wxHORIZONTAL );
	
	wxString dlg_opciones_busquedaChoices[] = { wxT("Cargar"), wxT("Listar"), wxT("Cargar+Listar") };
	int dlg_opciones_busquedaNChoices = sizeof( dlg_opciones_busquedaChoices ) / sizeof( wxString );
	dlg_opciones_busqueda = new wxRadioBox( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Opciones"), wxDefaultPosition, wxDefaultSize, dlg_opciones_busquedaNChoices, dlg_opciones_busquedaChoices, 1, wxRA_SPECIFY_ROWS );
	dlg_opciones_busqueda->SetSelection( 0 );
	sbSizer2->Add( dlg_opciones_busqueda, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Archivo a Cargar") ), wxVERTICAL );
	
	dlg_archivo_cargar = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxT("index.html"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( dlg_archivo_cargar, 1, wxEXPAND|wxTOP, 5 );
	
	
	sbSizer2->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( sbSizer2, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer4 );
	m_panel2->Layout();
	bSizer4->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, wxT("Sitio"), true );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Formato Log") ), wxVERTICAL );
	
	dlg_log_habilitado = new wxCheckBox( sbSizer5->GetStaticBox(), wxID_ANY, wxT("Log"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( dlg_log_habilitado, 0, wxALL, 5 );
	
	dlg_formato_log = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxT("%fecha822% | %status% | %ip_request% | %request% | %request.User-Agent%"), wxDefaultPosition, wxDefaultSize, 0 );
	dlg_formato_log->Enable( false );
	
	sbSizer5->Add( dlg_formato_log, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer3->Add( sbSizer5, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Salida Log") ), wxVERTICAL );
	
	dlg_salida_log = new wxListBox( sbSizer6->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_MULTIPLE ); 
	sbSizer6->Add( dlg_salida_log, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer3->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	m_button1 = new wxButton( m_panel3, wxID_ANY, wxT("Guardar Log"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button1, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	m_panel3->SetSizer( bSizer3 );
	m_panel3->Layout();
	bSizer3->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, wxT("Log"), false );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Ancho de Banda") ), wxHORIZONTAL );
	
	dlg_ancho_banda_habilitado = new wxCheckBox( sbSizer7->GetStaticBox(), wxID_ANY, wxT("Habilitar"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( dlg_ancho_banda_habilitado, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_kbytes = new wxSpinCtrl( sbSizer7->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999999, 10240 );
	dlg_kbytes->Enable( false );
	
	sbSizer7->Add( dlg_kbytes, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText4 = new wxStaticText( sbSizer7->GetStaticBox(), wxID_ANY, wxT("KBytes/s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	sbSizer7->Add( m_staticText4, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer11->Add( sbSizer7, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Interfaz de Red") ), wxHORIZONTAL );
	
	dlg_interfaces = new wxComboBox( sbSizer10->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY|wxCB_SORT );
	dlg_interfaces->Append( wxT("0.0.0.0") );
	dlg_interfaces->SetSelection( 0 );
	sbSizer10->Add( dlg_interfaces, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer11->Add( sbSizer10, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	
	bSizer5->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Usuario/Clave") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText5 = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_usuario = new wxTextCtrl( sbSizer9->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( dlg_usuario, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText6 = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, wxT("Clave"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dlg_clave = new wxTextCtrl( sbSizer9->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( dlg_clave, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer9->Add( fgSizer1, 0, 0, 5 );
	
	
	bSizer5->Add( sbSizer9, 0, wxRIGHT|wxLEFT, 5 );
	
	
	m_panel4->SetSizer( bSizer5 );
	m_panel4->Layout();
	bSizer5->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, wxT("Avanzado"), false );
	
	bSizer2->Add( m_notebook1, 1, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onCargar ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onGrabar ) );
	this->Connect( m_menuItem4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onGrabarComo ) );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onSalir ) );
	this->Connect( m_menuItem5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onIniciar ) );
	this->Connect( m_menuItem6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onDetener ) );
	this->Connect( dlg_herramienta_salir->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onSalir ) );
	this->Connect( dlg_herramienta_cargar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onCargar ) );
	this->Connect( dlg_herramienta_guardar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGrabar ) );
	this->Connect( dlg_herramienta_guardarcomo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGrabarComo ) );
	this->Connect( dlg_herramienta_arrancar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onIniciar ) );
	this->Connect( dlg_herramienta_detener->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onDetener ) );
	dlg_dominio->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_puerto->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_dirvirtual->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_opciones_busqueda->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onBusqueda ), NULL, this );
	dlg_log_habilitado->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onLog ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGuardarLog ), NULL, this );
	dlg_ancho_banda_habilitado->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onAnchoDeBanda ), NULL, this );
}

SujetoAtlasUI::~SujetoAtlasUI()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onCargar ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onGrabar ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onGrabarComo ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onSalir ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onIniciar ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onDetener ) );
	this->Disconnect( dlg_herramienta_salir->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onSalir ) );
	this->Disconnect( dlg_herramienta_cargar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onCargar ) );
	this->Disconnect( dlg_herramienta_guardar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGrabar ) );
	this->Disconnect( dlg_herramienta_guardarcomo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGrabarComo ) );
	this->Disconnect( dlg_herramienta_arrancar->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onIniciar ) );
	this->Disconnect( dlg_herramienta_detener->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onDetener ) );
	dlg_dominio->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_puerto->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_dirvirtual->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SujetoAtlasUI::onCambioURL ), NULL, this );
	dlg_opciones_busqueda->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SujetoAtlasUI::onBusqueda ), NULL, this );
	dlg_log_habilitado->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onLog ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onGuardarLog ), NULL, this );
	dlg_ancho_banda_habilitado->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SujetoAtlasUI::onAnchoDeBanda ), NULL, this );
	
}
