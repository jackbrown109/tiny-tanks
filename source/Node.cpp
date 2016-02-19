//\=====================================================================================
///
/// @author	Jamie Stewart
///
///
//\=====================================================================================
#include "Node.h"

CNode::CNode() : m_m4PosRot(CMatrix4::IDENTITY)
{
	m_pParent		= nullptr;
	m_pCurrentChild = nullptr;
}

CNode::~CNode()
{
	if( m_pParent )
	{
		m_pParent->RemoveChild(this);
		m_pParent = nullptr;
	}
	
	m_pCurrentChild = nullptr;    
	if( m_children.size() > 0 )
	{
		for( auto iter = m_children.begin(); iter != m_children.end(); ++iter )
		{
			CNode* pChild = (*iter);
			delete pChild;
		}
		m_children.clear();
		
	}
}
//\===============================================================================================================
//\ Adding and removing parents
//\===============================================================================================================
void CNode::SetParent( CNode* a_pParent )
{
	if (a_pParent == this)
		return;

	if (m_pParent != nullptr)
	{
		m_pParent->RemoveChild(this);
	}

	m_pParent = a_pParent;
	m_pParent->AddChild(this);
	
}

void CNode::RemoveParent()
{
	if( m_pParent )
	{
		m_pParent->RemoveChild(this);
		m_pParent = nullptr;
	}
}
//\===============================================================================================================
//\ Adding and removing Children
//\===============================================================================================================
void CNode::AddChild(CNode *a_pChild)
{
	auto iter = m_children.find(a_pChild);
	//Children are stored in a set. One of the features of a set is easy searching for an item
	//this allows us to see if the child already exists in the set of children. 
	//If it exists already we will not add it to the set multiple times.
	if (iter == m_children.end())
	{
		m_children.emplace(a_pChild);
	}
}

void CNode::RemoveChild(CNode* a_pChild)
{
	if( m_pCurrentChild == a_pChild )
	{
		m_pCurrentChild = nullptr;
	}
	auto iter = m_children.find(a_pChild);
	if (iter != m_children.end())
	{
		m_children.erase(iter);
	}
}
//\===============================================================================================================
//\ Retrieving Children
//\===============================================================================================================
CNode* CNode::GetFirstChild()
{
	m_pCurrentChild = (*m_children.begin());
	return m_pCurrentChild;
}

CNode* CNode::GetNextChild()
{
	auto iter = (m_pCurrentChild == nullptr) ? m_children.begin() : m_children.find(m_pCurrentChild);

	if( m_pCurrentChild == nullptr)
	{
		m_pCurrentChild = (*iter);
	}
	else
	{
		auto last = std::prev(m_children.end());

		if (iter != m_children.end() && iter != last)
		{
			++iter;
			m_pCurrentChild = (*iter);
		}
		else
		{
			m_pCurrentChild = nullptr;
		}
	}
	return m_pCurrentChild;
}

CNode* CNode::GetNextChild(CNode* pCurrentChild )
{
	auto iter = m_children.find(pCurrentChild);
	if( iter != m_children.end() && iter != std::prev(m_children.end()) )
	{
		++iter;
		return (*iter);
	}
	return nullptr;
}
//\===============================================================================================================
//\ Get next Sibling
//\===============================================================================================================
CNode* CNode::GetNextSibling()
{
	if( m_pParent )
	{
		return m_pParent->GetNextChild(this);
	}
	return nullptr;
}





