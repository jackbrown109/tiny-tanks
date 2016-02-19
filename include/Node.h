//
//  BaseNode.h
//  WC_Engine
//
//  Created by Jamie Stewart on 16/06/2013.
//  Copyright (c) 2013 WeeChief Ltd. All rights reserved.
//

#ifndef __BASENODE_H__
#define __BASENODE_H__

#include <set>
#include "mathLib.h"

class CNode
{
public:

	CNode();
	CNode(CNode& copy);
	CNode(CNode* pParent);
	
	virtual ~CNode();
	
	void SetParent      ( CNode* pParent  );
	void RemoveParent   (                       );
	void AddChild       ( CNode* pChild   );
	void RemoveChild    ( CNode* pChild   );
	
	CNode* GetFirstChild();
	CNode* GetNextChild();
	CNode* GetNextChild(CNode* pCurrentChild );
	CNode* GetNextSibling();
	
	//\====================================================================
	//\Inline Setters and Getters
	//\====================================================================
	void            GetWorldTransform   ( CMatrix4& m4Transform );
	
	void            SetPosRot(CMatrix4 &m4);
	void            GetPosRot(CMatrix4 &m4);
	
	void            SetScale( float fScale );
	void            SetScale( CVector3 v3Scale );
	//\====================================================================
	
protected:
	
	CMatrix4				m_m4PosRot;
	
	CNode*					m_pParent;
	std::set<CNode*>		m_children;
	CNode*					m_pCurrentChild;
	
};

//\===============================================================================================================
//\
//\===============================================================================================================
inline void CNode::GetWorldTransform(CMatrix4& m4Transform)
{
	if( m_pParent )
	{
		m_pParent->GetWorldTransform(m4Transform);
		m4Transform =  m_m4PosRot * m4Transform;
	}
	else
	{
		m4Transform = m_m4PosRot;
	}
}

//\===============================================================================================================
//\ Set/Get Current Position & Rotation
//\===============================================================================================================
inline void CNode::GetPosRot(CMatrix4& m4)
{
	m4 = m_m4PosRot;
}

inline void CNode::SetPosRot(CMatrix4 &m4)
{
	m_m4PosRot = m4;
}
//\===============================================================================================================
//\ Set/Get Current Scale
//\===============================================================================================================
inline void CNode::SetScale( float fScale )
{
	m_m4PosRot.Scale(fScale);
}

inline void CNode::SetScale( CVector3 v3Scale )
{
	m_m4PosRot.Scale(v3Scale);
}

#endif //__BASENODE_H__
