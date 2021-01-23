//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : svnxmlparser.h
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
#ifndef SVNXMLPARSER_H
#define SVNXMLPARSER_H

#include "wx/string.h"
#include "wx/arrstr.h"
#include "svninfo.h"

class SvnXML
{
public:
    SvnXML();
    ~SvnXML();

    static void GetFiles(const wxString& input, wxArrayString& modifiedFiles, wxArrayString& conflictedFiles, wxArrayString& unversionedFiles, wxArrayString& newFiles, wxArrayString& deletedFiles, wxArrayString& lockedFiles, wxArrayString& ignoredFiles);

    static void GetSvnInfo(const wxString& input, SvnInfo &svnInfo);
};

#endif //SVNXMLPARSER_H
