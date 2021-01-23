//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "dvtemplatesmodel.h"
#include <wx/dvrenderers.h>
#include <wx/variant.h>

//////////////////////////////////////////
// Implementation
//////////////////////////////////////////

// -------------------------------------------------
// Help method
// -------------------------------------------------
wxVariant DVTemplatesModel::CreateIconTextVariant(const wxString &text, const wxBitmap& bmp)
{
    wxIcon icn;
    icn.CopyFromBitmap( bmp);
    wxDataViewIconText ict(text, icn);
    wxVariant v;
    v << ict;
    return v;
}

// -------------------------------------------------
// The model class
// -------------------------------------------------

DVTemplatesModel::DVTemplatesModel()
    : m_colCount(0)
{
}

DVTemplatesModel::~DVTemplatesModel()
{
    for(size_t i=0; i<m_data.size(); ++i) {
        wxDELETE(m_data.at(i));
    }
    m_data.clear();
}

unsigned int DVTemplatesModel::GetChildren(const wxDataViewItem& item, wxDataViewItemArray& children) const
{
    if(item.GetID() == NULL) {
        // Root
        for(size_t i=0; i<m_data.size(); ++i) {
            children.Add( wxDataViewItem( m_data.at(i) ) );
        }
        return children.size();
    }

    children.Clear();
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node ) {
        for(size_t i=0; i<node->GetChildren().size(); ++i) {
            children.Add( wxDataViewItem( node->GetChildren().at(i) ) );
        }
    }
    return children.GetCount();
}

unsigned int DVTemplatesModel::GetColumnCount() const
{
    return m_colCount;
}

wxString DVTemplatesModel::GetColumnType(unsigned int col) const
{
    if ( !m_data.empty() && m_data.at(0)->GetData().size() > col ) {
        return m_data.at(0)->GetData().at(col).GetType();
    }
    return "string";
}

wxDataViewItem DVTemplatesModel::GetParent(const wxDataViewItem& item) const
{
    if ( IsEmpty() ) {
        return wxDataViewItem(NULL);
    }

    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node ) {
        return wxDataViewItem(node->GetParent());
    }
    return wxDataViewItem(NULL);
}

bool DVTemplatesModel::IsContainer(const wxDataViewItem& item) const
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node ) {
        return node->IsContainer();
    }
    return false;
}

void DVTemplatesModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node && node->GetData().size() > col ) {
        variant = node->GetData().at(col);
    }
}
wxDataViewItem DVTemplatesModel::DoAppendItem(const wxDataViewItem& parent, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData)
{
    DVTemplatesModel_Item* parentNode = reinterpret_cast<DVTemplatesModel_Item*>(parent.m_pItem);
    DoChangeItemType(parent, true);

    DVTemplatesModel_Item* child = new DVTemplatesModel_Item();
    child->SetIsContainer(isContainer);
    child->SetClientObject( clientData );
    child->SetData( data );
    if ( parentNode ) {
        parentNode->AddChild( child );

    } else {
        m_data.push_back( child );
    }

    return wxDataViewItem(child);
}

wxDataViewItem DVTemplatesModel::DoInsertItem(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData)
{
    DVTemplatesModel_Item* child = new DVTemplatesModel_Item();
    child->SetIsContainer(isContainer);
    child->SetClientObject( clientData );
    child->SetData( data );

    // find the location where to insert the new item
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(insertBeforeMe.m_pItem);
    if ( !node )
        return wxDataViewItem();

    wxVector<DVTemplatesModel_Item*>::iterator where = std::find(m_data.begin(), m_data.end(), node);

    if ( where !=  m_data.end() ) {
        // top level item
        m_data.insert( where, child );

    } else {

        if ( !node->GetParent() )
            return wxDataViewItem();

        child->SetParent(node->GetParent());
        where = std::find(node->GetParent()->GetChildren().begin(), node->GetParent()->GetChildren().end(), node);
        if ( where == node->GetParent()->GetChildren().end() ) {
            node->GetParent()->GetChildren().push_back( child );

        } else {
            node->GetParent()->GetChildren().insert(where, child);

        }
    }

    return wxDataViewItem(child);
}

wxDataViewItem DVTemplatesModel::AppendItem(const wxDataViewItem &parent, const wxVector<wxVariant>& data, wxClientData *clientData)
{
    wxDataViewItem ch = DoAppendItem(parent, data, false, clientData);
    ItemAdded(parent, ch);
    return ch;
}

wxDataViewItemArray DVTemplatesModel::AppendItems(const wxDataViewItem &parent, const wxVector<wxVector<wxVariant> >& data)
{
    wxDataViewItemArray items;
    for(size_t i=0; i<data.size(); ++i) {
        items.push_back( DoAppendItem(parent, data.at(i), false, NULL) );
    }
    ItemsAdded(parent, items);
    return items;
}

bool DVTemplatesModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col)
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node && node->GetData().size() > col ) {
        node->GetData().at(col) = variant;
    }
    return true;
}

void DVTemplatesModel::DeleteItem(const wxDataViewItem& item)
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.m_pItem);
    if ( node ) {

        DVTemplatesModel_Item* parent = node->GetParent();
        wxDataViewItem parentItem(parent);
        ItemDeleted(parentItem, item);

        // this will also remove it from its model parent children list
        if ( parent == NULL ) {
            // root item, remove it from the roots array
            wxVector<DVTemplatesModel_Item*>::iterator where = std::find(m_data.begin(), m_data.end(), node);
            if ( where != m_data.end() ) {
                m_data.erase(where);
            }
        }

        // If there are no more children, change the item back to 'normal'
        if ( parent && parent->GetChildren().empty() )
            DoChangeItemType(parentItem, false);

        wxDELETE(node);
    }

    if ( IsEmpty() )
        Cleared();
}

void DVTemplatesModel::DeleteItems(const wxDataViewItem& parent, const wxDataViewItemArray& items)
{
    // sanity
    for(size_t i=0; i<items.GetCount(); ++i) {
        DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(items.Item(i).m_pItem);
        wxUnusedVar(node);
        wxASSERT(node && node->GetParent() == parent.m_pItem);
        DeleteItem(items.Item(i));
    }
}

void DVTemplatesModel::Clear()
{
    wxVector<DVTemplatesModel_Item*> roots = m_data;
    wxVector<DVTemplatesModel_Item*>::iterator iter = roots.begin();
    for(; iter != roots.end(); ++iter) {
        DeleteItem( wxDataViewItem(*iter) );
    }
    m_data.clear();
    Cleared();
}

bool DVTemplatesModel::IsEmpty() const
{
    return m_data.empty();
}

wxClientData* DVTemplatesModel::GetClientObject(const wxDataViewItem& item) const
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( node ) {
        return node->GetClientObject();
    }
    return NULL;
}

void DVTemplatesModel::SetClientObject(const wxDataViewItem& item, wxClientData *data)
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( node ) {
        node->SetClientObject(data);
    }
}

void DVTemplatesModel::UpdateItem(const wxDataViewItem& item, const wxVector<wxVariant>& data)
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( node ) {
        node->SetData( data );
        ItemChanged( item );
    }
}

wxDataViewItem DVTemplatesModel::InsertItem(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, wxClientData *clientData)
{
    wxDataViewItem ch = DoInsertItem(insertBeforeMe, data, false, clientData);
    if ( ch.IsOk() ) {
        DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(ch.GetID());
        ItemAdded(wxDataViewItem(node->GetParent()), ch);
    }
    return ch;
}

wxVector<wxVariant> DVTemplatesModel::GetItemColumnsData(const wxDataViewItem& item) const
{
    if ( !item.IsOk() )
        return wxVector<wxVariant>();

    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( !node ) {
        return wxVector<wxVariant>();
    }
    return node->GetData();
}

bool DVTemplatesModel::HasChildren(const wxDataViewItem& item) const
{
    if ( !item.IsOk() )
        return false;

    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( !node ) {
        return false;
    }
    return !node->GetChildren().empty();
}

void DVTemplatesModel::DoChangeItemType(const wxDataViewItem& item, bool changeToContainer)
{
    DVTemplatesModel_Item* node = reinterpret_cast<DVTemplatesModel_Item*>(item.GetID());
    if ( !node )
        return;

    if ( ( changeToContainer && !node->IsContainer())  || // change an item from non-container to container type
         ( !changeToContainer && node->IsContainer()) ) { // change an item from container to non-container type
#if defined(__WXGTK__) || defined(__WXMAC__)
        // change the item to container type:
        // 1st we need to delete it
        ItemDeleted(wxDataViewItem(node->GetParent()), item);

        // update the node type
        node->SetIsContainer(changeToContainer);
        ItemAdded(wxDataViewItem(node->GetParent()), item);
#else
        node->SetIsContainer(changeToContainer);
#endif
    }
}
