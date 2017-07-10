//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: phprefactoringdlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "phprefactoringdlgbase.h"


// Declare the bitmap loading function
extern void wxCrafterGgLOZbInitBitmapResources();

static bool bBitmapLoaded = false;


PHPRefactoringBaseDlg::PHPRefactoringBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterGgLOZbInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizerMain = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizerMain);
    
    wxFlexGridSizer* flexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer2->SetFlexibleDirection( wxBOTH );
    flexGridSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer2->AddGrowableCol(1);
    
    bSizerMain->Add(flexGridSizer2, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText2 = new wxStaticText(this, wxID_ANY, _("PHP Refactoring PHAR file:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    flexGridSizer2->Add(m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_filePickerPhprefactoringPhar = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxFLP_USE_TEXTCTRL|wxFLP_SMALL);
    m_filePickerPhprefactoringPhar->SetToolTip(_("Select the PHP Refactoring Browser phar file location"));
    m_filePickerPhprefactoringPhar->SetFocus();
    
    flexGridSizer2->Add(m_filePickerPhprefactoringPhar, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_checkBoxSkipPreview = new wxCheckBox(this, wxID_ANY, _("Apply changes without previewing"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_checkBoxSkipPreview->SetValue(false);
    
    flexGridSizer2->Add(m_checkBoxSkipPreview, 0, wxALL, WXC_FROM_DIP(5));
    
    m_stdBtnSizer = new wxStdDialogButtonSizer();
    
    bSizerMain->Add(m_stdBtnSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));
    
    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer->AddButton(m_buttonOK);
    
    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer->AddButton(m_buttonCancel);
    m_stdBtnSizer->Realize();
    
    SetName(wxT("PHPRefactoringBaseDlg"));
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
}

PHPRefactoringBaseDlg::~PHPRefactoringBaseDlg()
{
}

PHPRefactoringPreviewBaseDlg::PHPRefactoringPreviewBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterGgLOZbInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer259 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer259);
    
    m_staticText267 = new wxStaticText(this, wxID_ANY, _("Please review the changes before applying them:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    boxSizer259->Add(m_staticText267, 0, wxALL|wxALIGN_LEFT, WXC_FROM_DIP(5));
    
    m_stcPreview = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_stcPreview->SetFocus();
    // Configure the fold margin
    m_stcPreview->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcPreview->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcPreview->SetMarginSensitive(4, true);
    m_stcPreview->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcPreview->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcPreview->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcPreview->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcPreview->SetMarginWidth(2, 0);
    m_stcPreview->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcPreview->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcPreview->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcPreview->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcPreview->SetMarginMask(3, 0);
    m_stcPreview->SetMarginWidth(3,0);
    // Select the lexer
    m_stcPreview->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcPreview->StyleClearAll();
    m_stcPreview->SetWrapMode(0);
    m_stcPreview->SetIndentationGuides(0);
    m_stcPreview->SetKeyWords(0, wxT(""));
    m_stcPreview->SetKeyWords(1, wxT(""));
    m_stcPreview->SetKeyWords(2, wxT(""));
    m_stcPreview->SetKeyWords(3, wxT(""));
    m_stcPreview->SetKeyWords(4, wxT(""));
    
    boxSizer259->Add(m_stcPreview, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_stdBtnSizer261 = new wxStdDialogButtonSizer();
    
    boxSizer259->Add(m_stdBtnSizer261, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(10));
    
    m_button263 = new wxButton(this, wxID_APPLY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button263->SetDefault();
    m_stdBtnSizer261->AddButton(m_button263);
    
    m_button265 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer261->AddButton(m_button265);
    m_stdBtnSizer261->Realize();
    
    SetName(wxT("PHPRefactoringPreviewBaseDlg"));
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
    m_button263->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PHPRefactoringPreviewBaseDlg::OnApplyChanges), NULL, this);
    
}

PHPRefactoringPreviewBaseDlg::~PHPRefactoringPreviewBaseDlg()
{
    m_button263->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PHPRefactoringPreviewBaseDlg::OnApplyChanges), NULL, this);
    
}
