//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: SmartCompletionsUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "SmartCompletionsUI.h"


// Declare the bitmap loading function
extern void wxC6BACInitBitmapResources();

static bool bBitmapLoaded = false;


SmartCompletionsSettingsBaseDlg::SmartCompletionsSettingsBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC6BACInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);

    wxFlexGridSizer* flexGridSizer16 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer16->SetFlexibleDirection( wxBOTH );
    flexGridSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer16->AddGrowableCol(1);

    boxSizer2->Add(flexGridSizer16, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));

    m_staticText22 = new wxStaticText(this, wxID_ANY, _("Enable:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    flexGridSizer16->Add(m_staticText22, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_checkBoxEnabled = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_checkBoxEnabled->SetValue(true);

    flexGridSizer16->Add(m_checkBoxEnabled, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));

    m_staticText18 = new wxStaticText(this, wxID_ANY, _("Clear statistics"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    flexGridSizer16->Add(m_staticText18, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_buttonClear = new wxButton(this, wxID_CLEAR, _("Clear"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_buttonClear->SetToolTip(_("Clear statistics gathered"));

    flexGridSizer16->Add(m_buttonClear, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer6 = new wxStdDialogButtonSizer();

    boxSizer2->Add(m_stdBtnSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer6->AddButton(m_buttonOK);

    m_button10 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer6->AddButton(m_button10);
    m_stdBtnSizer6->Realize();

    SetName(wxT("SmartCompletionsSettingsBaseDlg"));
    SetSize(-1,-1);
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
    m_buttonClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SmartCompletionsSettingsBaseDlg::OnClearStats), NULL, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SmartCompletionsSettingsBaseDlg::OnOK), NULL, this);

}

SmartCompletionsSettingsBaseDlg::~SmartCompletionsSettingsBaseDlg()
{
    m_buttonClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SmartCompletionsSettingsBaseDlg::OnClearStats), NULL, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SmartCompletionsSettingsBaseDlg::OnOK), NULL, this);

}
