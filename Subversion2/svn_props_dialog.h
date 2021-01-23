//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2009 by Eran Ifrah
// file name            : svn_props_dialog.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef __svn_props_dialog__
#define __svn_props_dialog__

/**
@file
Subclass of SvnPropsBaseDlg, which is generated by wxFormBuilder.
*/

#include "subversion2_ui.h"
class Subversion2;
/** Implementing SvnPropsBaseDlg */
class SvnPropsDlg : public SvnPropsBaseDlg
{
    Subversion2 *m_plugin;
    wxString     m_url;

public:
    /** Constructor */
    SvnPropsDlg( wxWindow* parent, const wxString& url, Subversion2 *plugin );
    virtual ~SvnPropsDlg();

    wxString GetBugTrackerURL() const;
    wxString GetFRTrackerURL() const;
    wxString GetBugMsg() const;
    wxString GetFRMsg() const;

};

#endif // __svn_props_dialog__
