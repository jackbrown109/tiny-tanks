#include "mathLib.h"
#include <set>


#ifndef __NODE_H__
#define __NODE_H__

//=================================================================================================================================
//ATTEMPT AT NODE STUFF
//=================================================================================================================================
class Node
{
public:
	//Constructor
	Node();
	//destructor (virtual as we will use node as a base class)
	virtual ~Node();

	//Function to set this node's parent 
	void SetParent(Node* a_parent);

	//Function to add a child to the node
	void AddChild(Node* a_child);
	//Remove a child from our node hierarchy structure
	void RemoveChild(Node* a_child);
	//Where is this node in the world 
	// this requires us to transform (multiply) this node by any parents it may have (and their parents in turn).
	void GetWorldTransform(Matrix3& transform);
	//Get the local transform for our point
	void GetLocalTransform(Matrix3 a_m3Transform);
	//Set our translation
	void SetTranslation(Vector2 a_v2Translation);
	//Rotate this node around it's z axis
	void RotateZ(float a_fRotation);
	//scale this node
	void Scale(float a_fScale);

protected:
	Matrix3 m3PosRot;
private:
	Node* m_pParent;
	std::set<Node*>m_pChildren;

};

#endif //__NODE_H__