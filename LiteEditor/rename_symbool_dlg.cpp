//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: rename_symbool_dlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "rename_symbool_dlg.h"


// Declare the bitmap loading function
extern void wxCF5E0InitBitmapResources();

static bool bBitmapLoaded = false;


RenameSymbolBase::RenameSymbolBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF5E0InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);

    wxBoxSizer* bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    bSizer1->Add(bSizer4, 0, wxALL|wxEXPAND, 5);

    m_staticText31 = new wxStaticText(this, wxID_ANY, _("New Symbol Name:"), wxDefaultPosition, wxSize(-1, -1), 0);

    bSizer4->Add(m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlNewName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_textCtrlNewName->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlNewName->SetHint(wxT(""));
    #endif

    bSizer4->Add(m_textCtrlNewName, 1, wxALL, 5);

    m_splitter7 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME|wxSP_3DSASH);
    m_splitter7->SetSashGravity(0.5);
    m_splitter7->SetMinimumPaneSize(10);

    bSizer1->Add(m_splitter7, 1, wxALL|wxEXPAND, 5);

    m_splitterPage11 = new wxPanel(m_splitter7, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);

    wxBoxSizer* bSizer2 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage11->SetSizer(bSizer2);

    m_dvListCtrl = new wxDataViewListCtrl(m_splitterPage11, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);

    bSizer2->Add(m_dvListCtrl, 1, wxALL|wxEXPAND, 5);

    m_dvListCtrl->AppendToggleColumn(_("?"), wxDATAVIEW_CELL_ACTIVATABLE, -2, wxALIGN_LEFT);
    m_dvListCtrl->AppendTextColumn(_("Location"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    m_dvListCtrl->AppendTextColumn(_("Position"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    wxBoxSizer* boxSizer53 = new wxBoxSizer(wxHORIZONTAL);

    bSizer2->Add(boxSizer53, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    m_buttonCheckAll = new wxButton(m_splitterPage11, ID_CHECK_ALL, _("&Check All"), wxDefaultPosition, wxSize(-1,-1), 0);

    boxSizer53->Add(m_buttonCheckAll, 0, wxALL|wxEXPAND|wxALIGN_LEFT, 5);

    m_buttonUncheckAll = new wxButton(m_splitterPage11, ID_UNCHECK_ALL, _("&Uncheck All"), wxDefaultPosition, wxSize(-1,-1), 0);

    boxSizer53->Add(m_buttonUncheckAll, 0, wxALL|wxEXPAND|wxALIGN_LEFT, 5);

    m_splitterPage15 = new wxPanel(m_splitter7, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter7->SplitVertically(m_splitterPage11, m_splitterPage15, 0);

    wxBoxSizer* boxSizer3 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage15->SetSizer(boxSizer3);

    m_preview = new wxStyledTextCtrl(m_splitterPage15, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    // Configure the fold margin
    m_preview->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_preview->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_preview->SetMarginSensitive(4, true);
    m_preview->SetMarginWidth    (4, 0);

    // Configure the tracker margin
    m_preview->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_preview->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_preview->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_preview->SetMarginWidth(2, 0);
    m_preview->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    int m_preview_PixelWidth = 4 + 5 *m_preview->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("9"));
    m_preview->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_preview->SetMarginWidth(0,m_preview_PixelWidth);

    // Configure the line symbol margin
    m_preview->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_preview->SetMarginMask(3, 0);
    m_preview->SetMarginWidth(3,0);
    // Select the lexer
    m_preview->SetLexer(wxSTC_LEX_CPP);
    // Set default font / styles
    m_preview->StyleClearAll();
    m_preview->SetWrapMode(0);
    m_preview->SetIndentationGuides(0);
    m_preview->SetKeyWords(0, wxT(""));
    m_preview->SetKeyWords(1, wxT(""));
    m_preview->SetKeyWords(2, wxT(""));
    m_preview->SetKeyWords(3, wxT(""));
    m_preview->SetKeyWords(4, wxT(""));

    boxSizer3->Add(m_preview, 1, wxALL|wxEXPAND, 5);

    m_staticLine55 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);

    bSizer1->Add(m_staticLine55, 0, wxALL|wxEXPAND, 5);

    wxBoxSizer* bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    bSizer1->Add(bSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    m_buttonOk = new wxButton(this, wxID_OK, _("&Rename"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOk->SetDefault();

    bSizer3->Add(m_buttonOk, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxSize(-1, -1), 0);

    bSizer3->Add(m_buttonCancel, 0, wxALL, 5);

    SetName(wxT("RenameSymbolBase"));
    SetSizeHints(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent();
    } else {
        CentreOnScreen();
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler(RenameSymbolBase::OnSelection), NULL, this);
    m_buttonCheckAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnCheckAll), NULL, this);
    m_buttonUncheckAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnUncheckAll), NULL, this);
    m_buttonOk->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnButtonOK), NULL, this);

}

RenameSymbolBase::~RenameSymbolBase()
{
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler(RenameSymbolBase::OnSelection), NULL, this);
    m_buttonCheckAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnCheckAll), NULL, this);
    m_buttonUncheckAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnUncheckAll), NULL, this);
    m_buttonOk->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RenameSymbolBase::OnButtonOK), NULL, this);

}

SelectProjectsDlgBase::SelectProjectsDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF5E0InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer25 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer25);

    m_banner45 = new wxBannerWindow(this, wxID_ANY, wxTOP, wxDefaultPosition, wxSize(-1,-1), wxBORDER_THEME);
    m_banner45->SetBitmap(wxNullBitmap);
    m_banner45->SetText(_("Select Projects"), _("Select the 'rename symbol' project scope"));
    m_banner45->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION), wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    m_banner45->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT));

    boxSizer25->Add(m_banner45, 0, wxALL|wxEXPAND, 5);

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer25->Add(boxSizer33, 1, wxALL|wxEXPAND, 5);

    wxArrayString m_checkListBoxProjectsArr;
    m_checkListBoxProjects = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_checkListBoxProjectsArr, wxLB_SINGLE);

    boxSizer33->Add(m_checkListBoxProjects, 1, wxALL|wxEXPAND, 5);

    wxBoxSizer* boxSizer35 = new wxBoxSizer(wxVERTICAL);

    boxSizer33->Add(boxSizer35, 0, 0, 5);

    m_button37 = new wxButton(this, ID_CHECK_ALL, _("&Check All"), wxDefaultPosition, wxSize(-1,-1), 0);

    boxSizer35->Add(m_button37, 0, wxALL|wxEXPAND, 5);

    m_button39 = new wxButton(this, ID_UNCHECK_ALL, _("&Uncheck All"), wxDefaultPosition, wxSize(-1,-1), 0);

    boxSizer35->Add(m_button39, 0, wxALL|wxEXPAND, 5);

    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer25->Add(boxSizer27, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    m_button29 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button29->SetDefault();

    boxSizer27->Add(m_button29, 0, wxALL, 5);

    m_button31 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);

    boxSizer27->Add(m_button31, 0, wxALL, 5);

    SetName(wxT("SelectProjectsDlgBase"));
    SetSizeHints(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button37->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SelectProjectsDlgBase::OnSelectAll), NULL, this);
    m_button39->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SelectProjectsDlgBase::OnUnSelectAll), NULL, this);

}

SelectProjectsDlgBase::~SelectProjectsDlgBase()
{
    m_button37->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SelectProjectsDlgBase::OnSelectAll), NULL, this);
    m_button39->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SelectProjectsDlgBase::OnUnSelectAll), NULL, this);

}
